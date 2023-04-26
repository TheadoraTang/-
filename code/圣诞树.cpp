#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout<<"想要几层的圣诞树呀？"; 
	cin>>n;
	cout<<endl;
 	for(int i=0;i<n;i++)
	 {
 		for(int k=1;k<=i+2;k++)
		{
        	for(int j=1;j<=2*n-2*k+2;j++)
        	cout<<"  ";
        	for(int j=1;j<=4*k-3;j++)
        	cout<<" "<<'*';
        	cout<<endl;
    	}
	}
	for(int k=1;k<=n+1;k++)
	{
        for(int j=1;j<=(4*n+1)/2-1;j++)
        cout<<"  ";
        for(int j=1;j<=3;j++)
        cout<<" "<<'*';
        cout<<endl;
    }
    	cout<<endl;
	cout<<"   "<<"Merry Christmas! 圣诞快乐!天天开心！"<<endl;
	return 0;
}
