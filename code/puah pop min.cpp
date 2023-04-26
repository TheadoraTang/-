//���һ��ջʽ�ṹ��Ҫ��ʵ��Push(��ջ)��Pop(��ջ)��Min(����ջ�е���Сֵ)���ֲ����� ����5, 6, 9, 2 ���ĸ����ݸ���˵�����ջ����ƣ������ջ����ջ��ȡ��Сֵ�Ĳ�����
#include<bits/stdc++.h> 
#define maxstack 100
using namespace std;
enum Error_code {
	underflow,overflow,success
};
class Stack{
	public:
		Stack();
		bool Empty()
		{
			return count==0;
		}
		Error_code pop();
		Error_code push(int &n);
		Error_code min(int &m);
	private:
		int count;
		int a[maxstack];
		
}; 

Stack::Stack()
{
	count=0;
	memset(a,0,sizeof(a));
}

Error_code Stack::pop()
{
	if(Empty())
	{
		return underflow;
	}
	count--;
	return success;
}

Error_code Stack::push(int &n) 
{
	if(count>=maxstack)
	{
		return overflow;
	}
	a[count]=n;
	if(count>0&&n>a[count-1])
	{
		pop();
	}
	count++;
	return success;
} 


Error_code Stack::min(int &m)
{
	if(Empty())
	{
		return underflow;
	}
	m=a[count-1];
	return success;
}

int main()
{
	Stack stack;
	char ch;
	int N,i;
	cin>>N;
	int a[1000];
	for(i=0;i<N;i++)
	{
		cin>>a[i];
		stack.push(a[i]);
	}
	int m;
    stack.min(m);
    cout<<m;
	return 0;
}
