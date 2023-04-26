#include<iostream>
#include<cstring>
using namespace std;
const int maxrow=6,maxcol=6;
class Life{
	public:
		void initialize();//用于赋值 
		void print();//用于打印结果 
		void update();//用于进行多次变化 
	private:
		int grid[maxrow+2][maxcol+2];
		int neighbor_count(int row,int col);//计算周围有多少个存活的 
};

void Life::initialize(){
	memset(grid,0,sizeof(grid));
	int row, col;
	//无限循环，直到出现-1，-1为止。以此向数组中输入数字 
	while(true){
	    cin>>row>>col;
	    if(row==-1&&col==-1)	
	       break;
	    grid[row][col]=1 ;
	}
}

void Life::update(){
	int tmp[maxrow+2][maxcol+2];
	memset(tmp, 0 , sizeof(tmp));
	for(int i = 1;i <= maxrow;i ++){
		for(int j = 1;j<=maxcol;j ++)
		{
			int cnt =neighbor_count(i,j);
			//对于存活的来说 
			if(grid[i][j]==1){
				if(cnt == 2||cnt == 3){
					tmp[i][j]=1;
				}else {
					tmp[i][j]=0;
				}
			}//活着的周围有2,3个活的即存活，0 1 >=4死亡 
			//对于不存活的来说，只有周围有三个活着的才能继续存活，其余死亡 
			else {
				if(cnt == 3){
					tmp[i][j]=1;
				}else{
					tmp[i][j]=0;
				}
			}
		}
	}
	for(int i=1;i<=maxrow;i++)
	{
		for(int j=1;j<=maxcol;j++)
		{
			grid[i][j]=tmp[i][j];
		}
	}
}

int Life::neighbor_count(int row,int col){
	int cnt=0;
	//该位置的上一行和下一行，前一列和后一列，最后需减掉自身，以此计算有多少个存活的 
	for(int i=row-1;i<=row+1;i++){
		for(int j=col-1;j<=col+1;j++){
		   cnt += grid[i][j];			
		}
	}
	cnt-=grid[row][col];
	return cnt;
}

//打印变幻后的矩阵 
void Life::print(){
	for(int i=1;i<=maxrow;i++){
		for(int j=1;j<maxcol;j++){
			cout<<grid[i][j]<<" ";
		}
		cout<<grid[i][maxcol]<<endl;
	}
}
int main(){
	int k;
	cin>>k;
	Life game;
	game.initialize();
	for(int i=0;i<k;i++)
	{
		game.update();
	}
	game.print() ;
	return 0;
}
