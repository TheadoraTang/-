#include<iostream>
#include<cstring> 
using namespace std;

int main()
{
	char str[50]; //�ַ����������ɳ���50���ַ�
	int a[28]={0}; //���ÿ����ĸ���ֵĴ������±��0��25�ֱ�����ĸa��z��Ӧ
	
	cin>>str; //�����ַ���
	int len=strlen(str); //�����ͱ���len���������ַ����ĳ��ȣ�����ʹ�ô˾䣬�����ͷ�ļ�<cstring>
	
	//�޸�ÿ����ĸ��Ӧ�ĳ��ִ���
	for(int i=0;i<len;i++)
		a[str[i]-'a']++; //���磬������ĸc��c-'a'Ϊ2����a[2]����1
	
	//������ִ�����Ϊ�����ĸ������ִ���
	for(int j=0;j<26;j++)
	{
		if(a[j]!=0)
			cout<<char(j+'a')<<": "<<a[j]<<endl;
	}
	
	system("pause");
	return 0;
}

