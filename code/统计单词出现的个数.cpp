#include<iostream>
#include<cstring> 
using namespace std;

int main()
{
	char str[50]; //字符串个数不可超过50个字符
	int a[28]={0}; //存放每个字母出现的次数，下标从0到25分别与字母a至z对应
	
	cin>>str; //输入字符串
	int len=strlen(str); //用整型变量len存放输入的字符串的长度，若想使用此句，需包含头文件<cstring>
	
	//修改每个字母对应的出现次数
	for(int i=0;i<len;i++)
		a[str[i]-'a']++; //例如，出现字母c，c-'a'为2，则a[2]增长1
	
	//输出出现次数不为零的字母及其出现次数
	for(int j=0;j<26;j++)
	{
		if(a[j]!=0)
			cout<<char(j+'a')<<": "<<a[j]<<endl;
	}
	
	system("pause");
	return 0;
}

