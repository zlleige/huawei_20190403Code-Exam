/***
Ŀ�꣺�ж����������飬�����Ǻϲ���һ���µ����顣
����ÿ���鰴˳��ȡ���̶����ȵ����ݺϲ����µ������У�ȡ�������
��ɾ������������в���̶����Ȼ���Ϊ�գ���ȡ��ʣ�ಿ�ֵ����ݵ���
�������У�������һ�С�
������������һ����ÿ�ζ�ȡ�Ĺ̶�����
��2-n������Ҫ�ϲ������飬��ͬ�������û��з��ָ�������
���ö��ŷָ���
������������һ���µ����飬�ö��ŷָ���
����
���룺
3
2,5,6,7,9,5,7
1,7,4,3,4
�����
2��5��6��1��7��4��7��9��5��3��4��7

***/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>  //atoi()

using namespace std;

//��ӡ����
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


//��ӡ����
void PrintVector( vector<vector<int>>  &vDate,int count=3,string split=",")
{
	int group=vDate.size(); //����������������
	if(group <= 0) return;
	//���Ա�����i��ÿ�����3*i,3*i+1,3*i+2,ֱ��ÿ���е�����Ϊ��
	int column=0;  //��¼������
	unsigned int rowFlag=0; //�����ж�ÿ�������Ƿ������� ֱ�� rowFlag=vDate.size()
	vector<bool> isOutOver(group,false); //ÿ�������Ƿ�������
	while(rowFlag < vDate.size()) 
	{
		//������
		for(int i=0;i< group;i++) 
		{
			if(!isOutOver.at(i)) //����Ƿ�������
			{
				int nums=vDate.at(i).size()-column; //��ǰ��ʣ������
				if(nums<=3)  
				{
					isOutOver[i]=true;		//��ձ�־
					rowFlag++;
				}
				else nums=3;						//������ �������
				//�������
				for(int j=0;j<nums;j++)
				{
					cout<<vDate.at(i).at(column+j);
					//�����ǰ�л���������>count �����ߵ�ǰ�������ɵ�������δ��ɣ�Ӧ������ֺ�
					if(column+j < vDate.at(i).size()-1||isOutOver[i] && rowFlag< vDate.size())  cout<<split;
				}
			}
		}
		column+=count; //��������
	}
	cout<<endl; //�����ɻ���
}

int main() 
{
	//����̶�����
	int count=0;
	cin >> count;
	//���������ַ��� 
	string strInput,strTemp; 
	vector<vector<int>>  vDate; //��������������
	vector<int> vTemp; //�浱ǰ�����һ������
	while(getline(cin,strInput))
	{
		if(!strInput.empty())
		{
			vTemp.clear();
			//�ָ��ַ������õ�����
			stringstream  input(strInput);
			while(getline(input,strTemp,',')) vTemp.push_back(atoi(strTemp.c_str())); //strTemp������
			vDate.push_back(vTemp);
			//PrintVector(vDate," "); //���Դ�ӡ��������
			//��ӡ���
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

