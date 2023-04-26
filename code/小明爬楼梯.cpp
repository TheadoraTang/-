#include<iostream>
using namespace std;
class Step{
	public:
		Step();
		void methods(int sum);
		int result;
	private:
		int Plus[4]={0,1,2,3};
		int plus;
		
}; 

Step::Step()
{
	result=0;
	plus=15;
}

void Step::methods(int sum)
{
	if(sum==plus)
	{
		result++;
		return;
	}
	if(sum<plus)
	{
		methods(sum+Plus[1]);
		methods(sum+Plus[2]);
		methods(sum+Plus[3]); 
	}
}

int main()
{
	Step test;
	test.methods(0);
	cout<<test.result;
	return 0;
 } 
