#include<stdio.h>
#define SIZE 10				//SIZE的值要随输入的N的值得改变而改变 
void Helix(int a[][SIZE],int n,int turn)
{
	int i,j;
	static int num=1;
		i=turn;
		for(j=turn;j<n;j++){
			if(a[i][j]==0){
			a[i][j]=num;
			num++;
		}
		}
		j=n-1-turn;
		for(i=turn+1;i<n;i++){
			if(a[i][j]==0){
			a[i][j]=num;
			num++;
		}
		}
		i=n-1-turn;
		for(j=n-2-turn;j>=turn;j--){
			if(a[i][j]==0){
			a[i][j]=num;
			num++;
		}
		}
		j=turn;
		for(i=n-1-turn;i>=turn;i--){
			if(a[i][j]==0){
				a[i][j]=num;
				num++;
			}
		}
		if(num>n*n){
			return;
		}
		turn++;
		Helix(a,n,turn);
		
}
int main(void)
{
	int N,k,p,cot=0;
	scanf("%d",&N);
	
	int arr[N][N];
	for(k=0;k<N;k++){
		for(p=0;p<N;p++){
			arr[k][p]=0;
		}
	}
	Helix(arr,N,0);
	for(k=0;k<N;k++){
		cot=0;
		for(p=0;p<N;p++){
			cot++;
			printf("%d",arr[k][p]);
			printf(" ");
			if(cot==N){
				printf("\n");
			}
		}
	}
	return 0;
}
	

