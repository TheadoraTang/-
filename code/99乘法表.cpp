#include<iostream>
using namespace std;

int main()
{
	int a[10][10]={0};
	for(int i=1;i<10;i++)
	{
		a[i][0]=i;
	 } 
	for(int j=1;j<10;j++)
	{
		a[0][j]=j;
	}
	
	cout<<"*";
	for(int i=1;i<10;i++)
	{
		for(int j=1;j<10;j++)
		{
			if(j>=i)
			{
				a[i][j]=i*j;
			}
		}
	}
	
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(a[i][j]!=0)
			{
				cout<<a[i][j]<<"\t";
			}
			if(a[i][j]==0)
			{
				printf(" \t");
			}
			if(j==9)
			cout<<endl;
		}
	}
}


