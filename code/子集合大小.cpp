#include<bits/stdc++.h>
using namespace std;
class Subset{
	public:
		Subset(int n_,int k_);
		void dfs(int cur_set_pos,int cur_subset_size);//��ǰ���ʼ��ϴ�С���Ӽ��ϴ�С 
		int result;
	private:
		int n;//���ϴ�С 
		int k;//�Ӽ��ϴ�С 
};

Subset::Subset(int n_,int k_)
{
	n=n_;//����������ʱ���������private�� 
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
//	�����ǰ�Ӽ��ϴ�СС�ڸ����Ӽ��ϴ�С�����߼�����ʣ��Ԫ�صĸ������ڵ����Ӽ��ϵ�ʣ��ռ������䡣
	if(cur_subset_size<=k && n-cur_set_pos>=k-cur_subset_size) 
	{
		//�����еĵ�ǰԪ�طŵ��Ӽ�����
		dfs(cur_set_pos+1,cur_subset_size+1);
		//�����һ��Ԫ�ز������Ӽ�����Ҳ���ٿ�����һ�ηŵ��Ӽ����У�������䣨����n=3��k=2����cur_set_pos=2��cur_subset_size=1ʱ����һ���ٲ��žͲ���������������Բ����Խ�������.
		if(n-cur_set_pos-1>=k-cur_subset_size)
		{
			//�����еĵ�ǰԪ�ز��ŵ��Ӽ�����
			dfs(cur_set_pos+1,cur_subset_size);//cur_subset_size��1��Ϊ����һ��Ԫ�ؼ��� 
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
