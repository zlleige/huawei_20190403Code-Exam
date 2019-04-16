/***
目标：有多组整数数组，将它们合并成一个新的数组。
规则：每个组按顺序取出固定长度的内容合并到新的数组中，取完的内容
会删除掉，如果改行不足固定长度或者为空，则取出剩余部分的内容到新
的数组中，继续下一行。
输入描述：第一行是每次读取的固定长度
第2-n行是需要合并的数组，不同的数组用换行符分隔，数组
内用逗号分隔。
输出描述：输出一个新的数组，用逗号分隔。
样例
输入：
3
2,5,6,7,9,5,7
1,7,4,3,4
输出：
2，5，6，1，7，4，7，9，5，3，4，7

***/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>  //atoi()

using namespace std;

//打印数据
void PrintVector( vector<vector<int>>  &vDate,string slip)
{
	for(vector<vector<int>>::iterator v_it=vDate.begin();v_it!=vDate.end();v_it++)
	{
		for(vector<int>::iterator it=v_it->begin();it!=v_it->end();it++)
		{
			cout << *it<<slip;
		}
		cout <<endl;
	}
}


//打印数据
void PrintVector( vector<vector<int>>  &vDate,int count=3,string split=",")
{
	int group=vDate.size(); //获得输入的数据组数
	if(group <= 0) return;
	//可以遍历列i，每次输出3*i,3*i+1,3*i+2,直到每个行的数据为空
	int column=0;  //记录列索引
	unsigned int rowFlag=0; //用于判断每行数据是否输出完成 直到 rowFlag=vDate.size()
	vector<bool> isOutOver(group,false); //每行数据是否输出完成
	while(rowFlag < vDate.size()) 
	{
		//遍历行
		for(int i=0;i< group;i++) 
		{
			if(!isOutOver.at(i)) //检查是否输出完成
			{
				int nums=vDate.at(i).size()-column; //当前行剩余数据
				if(nums<=3)  
				{
					isOutOver[i]=true;		//清空标志
					rowFlag++;
				}
				else nums=3;						//有余量 输出三个
				//输出数据
				for(int j=0;j<nums;j++)
				{
					cout<<vDate.at(i).at(column+j);
					//如果当前行还有余量（>count ）或者当前行输出完成但是总体未完成，应该输出分号
					if(column+j < vDate.at(i).size()-1||isOutOver[i] && rowFlag< vDate.size())  cout<<split;
				}
			}
		}
		column+=count; //列索引加
	}
	cout<<endl; //输出完成换行
}

int main() 
{
	//输入固定长度
	int count=0;
	cin >> count;
	//接受输入字符串 
	string strInput,strTemp; 
	vector<vector<int>>  vDate; //存所有输入数组
	vector<int> vTemp; //存当前输入的一条数据
	while(getline(cin,strInput))
	{
		if(!strInput.empty())
		{
			vTemp.clear();
			//分割字符串，得到整数
			stringstream  input(strInput);
			while(getline(input,strTemp,',')) vTemp.push_back(atoi(strTemp.c_str())); //strTemp存数据
			vDate.push_back(vTemp);
			//PrintVector(vDate," "); //测试打印所有数据
			//打印输出
			PrintVector(vDate,count,",");
		}
	}
	system("pause");
	return 0;
}


/****

string raw_data("3, 4, 5, 76"), tmp;
vector<string> data;
stringstream input(raw_data);

while (getline(input, tmp, ',')) data.push_back(tmp);
for (vector<string>::iterator it=data.begin();it!= data.end();it++)  cout << atoi((*it).c_str()) << endl;


void split(const string& s,vector<int>& sv,const char flag = ' ') {
sv.clear();
istringstream iss(s);
string temp;

while (getline(iss, temp, flag)) {
sv.push_back(stoi(temp));
}
return;
}
*/

