#include <iostream>
using namespace std;
enum Error_code
{
	underflow,overflow,success//0,1,2
};
const int maxstack=100;
class Mystack
{
	public:
		Mystack();
		bool empty();
		Error_code push(char &item);//ÈëÕ» 
		Error_code pop();
		Error_code top(char &item);//³öÕ» 
	private:
		int count;
		char entry[maxstack];
};
Mystack::Mystack()
{
	count=0;
}
bool Mystack::empty()
{
	bool outcome=true;
	if(count>0)
	{
		outcome=false;
	}
	return outcome;
}
Error_code Mystack::push(char &item)
{
	Error_code outcome=success;
	if(count>=maxstack)
	{
		outcome=overflow;
	}
	else
	{
		entry[count++]=item;
	}
	return outcome;
}
Error_code Mystack::pop()
{
	Error_code outcome=success;
	if(count==0)
	{
		outcome=underflow;
	}
	else
	{
		--count;
	}
	return outcome;
}
Error_code Mystack::top(char &item)
{
	Error_code outcome=success;
	if(count==0)
	{
		outcome=underflow;
	}
	else
	{
		item=entry[count-1];
	}
	return outcome;
}
int main()
{
	int n;
	char item;
	Mystack strings;
	cout << " Type in an integer n followed by n characters." << endl
	<< " The characters will be printed in reverse order." << endl;
	cin >> n;
	int i=0;
	for(i=0;i<n;i++)
	{
		cin >> item;
		strings.push(item);
	}
	cout << endl << endl;
	while(!strings.empty())
	{
		strings.top(item);
		cout << item << " ";
		strings.pop();
	}
	cout << endl;
	return 0;
}
