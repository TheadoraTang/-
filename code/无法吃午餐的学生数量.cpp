
#include <bits/stdc++.h>
#include <stack>
#include <queue>
using namespace std;

bool Function(int t[])
{
	for(int i=0;i<sizeof(t);i++)
	{
		if(t[i]!=t[i+1])
		return false;
	}
	return true;
}

stack <int> sandwiches;
queue <int> students;
int main()
{
	int n;
	cin >> n;
	int i=0;
	int number;
	for(i=0;i<n;i++)
	{
		cin >> number;
		students.push(number);
	}
	int a[1000];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=n-1;i>=0;i--)
	{
		sandwiches.push(a[i]);
	}
	int outcome=0;
	
	while(1)
	{
		int a,b;
		a=students.front();
		b=sandwiches.top();
		if(a==b)
		{
			students.pop();
			sandwiches.pop();
			outcome=0;
		}
		else
		{
			students.pop();
			students.push(a);
			outcome++;
		}
		if(outcome>=students.size()||students.size()==0)
		break;
	}
	cout << students.size();
	return 0;
}
