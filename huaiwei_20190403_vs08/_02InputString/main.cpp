/**
题目描述：
对输入字符串检查是否有非法字符，输出合法字符（去重）和非法字符（不去重），
对合法字符循环左移10次，再进行排序输出。

输入描述：
1.合法字符集为‘0’-‘9’，‘a’-‘z’，‘A’-‘Z’，其余为非法字符（空格
为分界符），有非法字符的为非法输入。
2.字符串个数不超过100，每个字符串个数不超过64.
3.连续的空字符串（空格/制表符/回车/换行）作为一个空格处理，作为分界符，字
符串起始字符不为空。
4.输入每行只有一个字符串。
5.输入以空行结束。

输出描述：
1.输出合法字符串（去重）。
2.输出所有非法字符串。
3.去重合法字符串循环左移10次。
4.去重合法字符串按ASCII字符表从小到大排序。

注意事项：
每输出一个字符串后用空格跟下一个字符串隔离，作为输出的所有字符串之间只有
一个空格。

解题思路：
1.vector<string> 存放输入的字符串。
2.getline(cin,string),输入字符串。
3.字符串根据合法字符集与连续空字符串分为合法字符串数组与非法字符串数组。
    设置legal标志位，合法为1，非法为0，根据标志位区分字符串是否合法
4.对合法字符串数组进行去重、连续空字符串转换为空格。
（1）先用temp缓存vector<string>中当前字符串，将原字符串清空，处理一个字
     符串之后，加入清空之后的原字符串中。
（2）连续空字符处理，打印时直接跳过。
5.字符串循环左移n位，策略如下：
    reverse(s.begin(), s.begin() + n);
    reverse(s.begin() + n, s.end());
    reverse(s.begin(), s.end());
6.sort函数直接排序。
7.输出过程中，空字符串直接跳过，其他正常输出。


*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;
const int moveSize = 10;
void coutVector(vector<string> &v);
void moveLeft(string&, int);//字符串循环左移n位
void moveLeftData(vector<string>& data);//字符串数组循环左移n位
void stringTrim(vector<string>& data);//去重，将空格/制表/换行/回车 换成空格
void sortData(vector<string>& data);//字符串排序
void deletMark(string& s, string mark);//删除字符串的某个字符
void deletDataMark(vector<string>& data, string mark);//删除某一个字符
void intputData(vector<string>& data, vector<string>& legalData, vector<string>& illegalData);
//将输入的数据分别存入合法字符串数组与非法字符串数组

void coutVector(vector<string> &v)
{
	if (v.empty())
		cout << "vector is empty!" << endl;
	vector<string>::iterator iter;
	string::iterator sIter;
	for (iter = v.begin(); iter != v.end(); ++iter)
	{
		if ((*iter) == "")//空字符串不打印
		{
			continue;
		}
		else
		{
			sIter = (*iter).begin();//删除字符串首尾空字符
			if ((*sIter) == ' ')
			{
				//cout << "begin space";
				(*iter).erase(sIter);
			}
			sIter = (*iter).end() - 1;
			if ((*sIter) == ' ')
			{
				//cout << "end space";
				(*iter).erase(sIter);
			}			
			cout << *iter << " ";
		}
	}
	cout << endl;
}
void moveLeft(string& s, int n)
{//字符串循环左移n位
	if (s.empty() || n <= 0)
		return;
	int length = s.size();
	n %= length;
	if (!n)
		return;
	reverse(s.begin(), s.begin() + n);
	//cout << s << endl;
	reverse(s.begin() + n, s.end());
	//cout << s << endl;
	reverse(s.begin(), s.end());
}
void moveLeftData(vector<string>& data)
{
	if (data.empty())
		cout << "vector is empty!" << endl;
	vector<string>::iterator iter;
	for (iter = data.begin(); iter != data.end(); ++iter)
	{
		moveLeft(*iter, moveSize);
	}
}
void stringTrim(vector<string>& data)
{//去重，将空格/制表/换行/回车 换成空格
	vector<string> dataTemp;
	vector<string>::iterator iter;
	string::iterator sIter;
	vector<string>::iterator tempIter;
	string s;
	int n = 0;//计数器
	dataTemp = data;
	for (iter = data.begin(); iter != data.end(); ++iter)
	{
		(*iter).clear();
	}
	data.clear();
	for (iter = dataTemp.begin(); iter != dataTemp.end(); ++iter)
	{
		tempIter = find(data.begin(), data.end(), (*iter));
		if (tempIter < data.begin() || tempIter >= data.end())//去重
		{
			s = (*iter);			//先将字符串删除，然后将处理后的字符串重新填回来
			(*iter).clear();
			for (sIter = s.begin(); sIter != s.end(); ++sIter)
			{
				if ((*sIter >= '0' && *sIter <= '9') || (*sIter >= 'a' && *sIter <= 'z') ||
					(*sIter >= 'a' && *sIter <= 'z'))
				{
					//if (-1 == (*iter).find(*siter))//去重
					//{
					(*iter) += (*sIter);
						n = 0;//读取到字符，则空字符串不连续，计数器置零
					//}
				}
				else
				{
					n++;
					if (n > 1)//连续空格，则舍弃
					{
						continue;
						n = 0;
					}
					(*iter) += ' ';//换成空格
				}
						 				
			}
			s.clear();
			data.push_back((*iter));
		}		
	}
}
void sortData(vector<string>& data)
{//字符串排序
	if (data.empty())
		cout << "vector is empty!" << endl;
	sort(data.begin(), data.end());
	//vector<string>::iterator iter;
	//for (iter = data.begin(); iter != data.end(); ++iter)
	//{
	//	sort((*iter).begin(), (*iter).end());
	//}
}
void deletMark(string& s, string mark)
{//删除字符串的某个字符
	size_t length = mark.size();
	size_t pos;
	while (1)
	{
		pos = s.find(mark);
		if (pos == string::npos)
			return;
		s.erase(pos, length);
	}
}
void deletDataMark(vector<string>& data, string mark)
{
	if (data.empty())
		cout << "vector is empty!" << endl;
	vector<string>::iterator iter;
	for (iter = data.begin(); iter != data.end(); ++iter)
	{
		deletMark(*iter,mark);
	}
}
void intputData(vector<string>& data,vector<string>& legalData,vector<string>& illegalData)
{//将输入的数据分别存入合法字符串数组与非法字符串数组
	bool legal;//判断字符串是否合法
	string legalString = "";
	vector<string>::iterator iter;
	string::iterator sIter;
	for (iter = data.begin(); iter != data.end(); ++iter)
	{
		for (sIter = (*iter).begin(); sIter != (*iter).end(); ++sIter)
		{
			legal = (*sIter >= '0' && *sIter <= '9') || (*sIter >= 'a' && *sIter <= 'z') ||
				(*sIter >= 'A' && *sIter <= 'Z') || *sIter == ' ' || *sIter == '\n' || *sIter == '\t' ||
				*sIter == '\r';
			if (!legal)
			{
				illegalData.push_back(*iter);
				break;
			}

			else
			{
				continue;
			}
		}
		if (legal)
			legalData.push_back(*iter);
		legalString.clear();
	}
}
int main()
{
	vector<string> data;
	vector<string> legalData;
	vector<string> illegalData;
	string line;
	while (getline(cin, line))
	{
		data.push_back(line);
		line.clear();
	}
	cout << "data : " << endl;
	coutVector(data);
	cout << endl << endl;


	intputData(data,legalData,illegalData);
	

	cout << "legalData :" << endl;
	coutVector(legalData);
	cout << endl << endl;


	cout << "illegalData :" << endl;
	coutVector(illegalData);
	cout << endl << endl;


	stringTrim(legalData);
	cout << "legalData trim:" << endl;
	coutVector(legalData);
	cout << endl << endl;


	moveLeftData(legalData);
	cout << "legalData moveLeft:" << endl;
	coutVector(legalData);
	cout << endl << endl;


	deletDataMark(legalData," " );
	sortData(legalData);
	cout << "legalData sort:" << endl;
	coutVector(legalData);

	return 0;
}