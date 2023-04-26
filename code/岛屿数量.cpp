#include<bits/stdc++.h>
using namespace std;
struct Islands{
	public:
		Islands(int m,int n);
		int result;
		void dfs(int a[15][15],int x,int y);
		bool isisland(int a[15][15],int x,int y);
		void solve(int a[15][15]);
	private:
		int array[100][100];
		int row;
		int col;
};

Islands::Islands(int m,int n)
{
	row=m;
	col=n;
	result=0;
}

void Islands::solve(int a[15][15])
{
	for(int i=0;i<row;i++)
            for(int j=0;j<col;j++){
                if(a[i][j]==1){         //�ҵ����µ�
                    result++;
                    dfs(a,i,j);
                }
            }
}

void Islands::dfs(int a[15][15],int x,int y)
{
	a[x][y]=0;
	if(x==row-1&&y==col-1)
	return ;
	if(x-1>=0 && a[x-1][y]==1)    //������
            dfs(a,x-1,y);
    if(x+1<row && a[x+1][y]==1)   //������
            dfs(a,x+1,y);
    if(y-1>=0 && a[x][y-1]==1)       //������ 
            dfs(a,x,y-1);
    if(y+1<col && a[x][y+1]==1)    //������
            dfs(a,x,y+1);
}

int main()
{
	int m,n;
	cin>>m>>n;
	
	int array[15][15];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>array[i][j];
		}
	}
	Islands island(m,n);
	island.solve(array);
	cout<<island.result;
	return 0;
}
