#include<bits/stdc++.h>
using namespace std;
class Subset{
	public:
		Subset(int n_,int k_);
		void dfs(int cur_set_pos,int cur_subset_size);//当前访问集合大小，子集合大小 
		int result;
	private:
		int n;//集合大小 
		int k;//子集合大小 
};

Subset::Subset(int n_,int k_)
{
	n=n_;//在主函数的时候输入给到private里 
	k=k_;
	result=0;
}

void Subset::dfs(int cur_set_pos,int cur_subset_size)
{
	if(cur_set_pos==n)
	{
		if(cur_subset_size==k)
		{
			result++;
		}
		return;		
	}
//	如果当前子集合大小小于给定子集合大小，或者集合中剩余元素的个数大于等于子集合的剩余空间进入语句。
	if(cur_subset_size<=k && n-cur_set_pos>=k-cur_subset_size) 
	{
		//集合中的当前元素放到子集合中
		dfs(cur_set_pos+1,cur_subset_size+1);
		//如果下一个元素不放入子集合中也至少可以下一次放到子集合中，进入语句（假如n=3，k=2，当cur_set_pos=2，cur_subset_size=1时，下一次再不放就不会符合条件，所以不可以进入该语句.
		if(n-cur_set_pos-1>=k-cur_subset_size)
		{
			//集合中的当前元素不放到子集合中
			dfs(cur_set_pos+1,cur_subset_size);//cur_subset_size加1即为把下一个元素加入 
		}
	}
}

int main()
{
	int n,k;
	cin>>n>>k;
	Subset subset(n,k);
	subset.dfs(0,0);
	cout<<subset.result;
	return 0;
}
