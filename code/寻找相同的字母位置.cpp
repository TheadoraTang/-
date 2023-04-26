#include<bits/stdc++.h>
using namespace std;
const int maxqueue=8;
enum Error_code{overflow,underflow,success};

struct Pos{
	int x;
	int y;
};

class Queue{
	public:
		Queue();
		bool empty();
		Error_code serve();
		Error_code retrieve(Pos &item);
		Error_code append(Pos &item);
		bool full()
		{
			return count==maxqueue;
		}
		Error_code serve_and_retrieve(Pos &item);
	private:
		int count,rear,front;
		Pos entry[maxqueue];
};

Queue::Queue()
{
	count=0;
	front=0;
	rear=maxqueue-1;
	memset(entry,0,sizeof(entry));
}

Error_code Queue::append(Pos &item)
{
	if(count>=maxqueue)
	{
		return overflow;
	}
	else
	{
		count++;
		rear=((rear+1)==maxqueue)? 0:(rear+1);
		entry[rear]=item;
		return success;
	}
}

bool Queue::empty()
{
	return count==0;
}
Error_code Queue::serve()
{
	if(empty())
	return underflow;
	count--;
	front=((front+1)==maxqueue)? 0:(front+1);
	return success;
}

Error_code Queue::serve_and_retrieve(Pos &item)
{
	if(empty())
	return underflow;
	item=entry[front];
	count--;
	front=((front+1)==maxqueue)? 0:(front+1);
	return success;	
}

Error_code Queue::retrieve(Pos &item)
{
	if(empty())
	return underflow;
	item=entry[front];
	count--;
	front=((front+1)==maxqueue)? 0:(front+1);
	return success;
}

const int maxrow=10,maxcol=10;

int main()
{
    char mat[maxrow][maxcol];
	Queue numbers;
	int m,n;
	cin>>m>>n;
	int x,y;
	cin>>x>>y;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>mat[i][j];
		}
	}
	int mask[maxrow][maxcol];
	memset(mask,0,sizeof(mask));
	char target=mat[x][y];
	int dx[4]={0,0,1,-1};//方向矩阵 
	int dy[4]={1,-1,0,0};
	mask[x][y]=1;
	Pos res={-1,-1};
	Pos number={x,y};
	numbers.append(number);//左值不能改变右值 
	while(!numbers.empty())
	{
		Pos tmp;
		numbers.serve_and_retrieve(tmp);
		
		if(mat[tmp.x][tmp.y]==target&&!(tmp.x==x&&tmp.y==y))
		{
			res.x=tmp.x;
			res.y=tmp.y;
			break;
		}
		
		for(int i=0;i<4;i++)
		{
			int new_x=tmp.x+dx[i];
			int new_y=tmp.y+dy[i];
            Pos temp={new_x,new_y};
			if(new_y>=0&&new_x>=0&&new_y<n&&new_x<m&&mask[new_x][new_y]==0)
			{
				numbers.append(temp);
				mask[new_x][new_y]=1;
			}
		}
	}
	cout<<res.x<<" "<<res.y;
	return 0;
 } 
