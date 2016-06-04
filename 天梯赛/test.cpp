#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main()
{
	//string ss("Helloword!_Helloword!");
	char num[10]={'1','2','2','3','4','1','2','2','3','4'};
	//cout<<ss<<endl;
	/*sort( ss.begin(),ss.end());//排序
	cout<<ss<<endl;
	ss.erase(unique(ss.begin(),ss.end()),ss.end());//unique()把重复的元素移到最后并返回去重后最后一个元素地址*/
	unique(num,num+10);

	cout<<num<<endl;
	return 0;
}