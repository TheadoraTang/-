#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const int maxsize= 10;

class EightQueue{
	public:
		EightQueue(int n_size);
		int n_result;
		void dfs(int row);
		
		bool can_place(int row,int cur_col);
	private:
        void print();
		int n_size_;
		int pos_[maxsize];
		
};

EightQueue::EightQueue(int n_size)
{
	n_size_=n_size;
	memset(pos_,-1,sizeof(pos_));
	n_result=0;
}

bool EightQueue::can_place(int row,int cur_col)
{
	for(int i=0;i<row;i++)
	{
		if(pos_[i]==cur_col||abs(row-i)==abs(pos_[i]-cur_col))
		{
			return false;
		}
	}
	return true;
}

void EightQueue::dfs(int row)
{
	if(row==n_size_)
	{
		n_result++;
		if(n_result<=3)
		print();
		return;
	}
	
	for(int i=0;i<n_size_;i++)
	{
		if(can_place(row,i))
	   {
		  pos_[row]=i;
		  dfs(row+1);
	   }
	}
	
}

void EightQueue::print()
{
	for(int i=0;i<n_size_-1;i++)
	{
		cout<<pos_[i]+1<<" ";
	}
	cout<<pos_[n_size_-1]+1<<endl;
}

int main()
{
	int n;
	cin>>n;
	EightQueue eq=EightQueue(n);
	eq.dfs(0);
	cout<<eq.n_result<<endl;
	return 0;
}
