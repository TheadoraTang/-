#include<iostream>
#include<cstring>
using namespace std;
const int maxrow=6,maxcol=6;
class Life{
	public:
		void initialize();//���ڸ�ֵ 
		void print();//���ڴ�ӡ��� 
		void update();//���ڽ��ж�α仯 
	private:
		int grid[maxrow+2][maxcol+2];
		int neighbor_count(int row,int col);//������Χ�ж��ٸ����� 
};

void Life::initialize(){
	memset(grid,0,sizeof(grid));
	int row, col;
	//����ѭ����ֱ������-1��-1Ϊֹ���Դ����������������� 
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
			//���ڴ�����˵ 
			if(grid[i][j]==1){
				if(cnt == 2||cnt == 3){
					tmp[i][j]=1;
				}else {
					tmp[i][j]=0;
				}
			}//���ŵ���Χ��2,3����ļ���0 1 >=4���� 
			//���ڲ�������˵��ֻ����Χ���������ŵĲ��ܼ������������� 
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
	//��λ�õ���һ�к���һ�У�ǰһ�кͺ�һ�У��������������Դ˼����ж��ٸ����� 
	for(int i=row-1;i<=row+1;i++){
		for(int j=col-1;j<=col+1;j++){
		   cnt += grid[i][j];			
		}
	}
	cnt-=grid[row][col];
	return cnt;
}

//��ӡ��ú�ľ��� 
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
