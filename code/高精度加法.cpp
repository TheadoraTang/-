#include<bits/stdc++.h>
using namespace std;
int max(int m,int n)
{
	if(m>n)
	return m;
	else
	return n;
}
int main()
{
	string a,b;
	char ch;
	int count_a=0,count_b=0;
	cin>>a>>b;
	count_a=a.length();
	count_b=b.length();
	int jinwei=0;
	int i;
	int MAX=max(count_a,count_b);
	int d[100];
	for(i=0;i<=MAX-1;i++)
	{
		if(count_a<=0&&count_b>0)
		d[i]=a[count_b-1]-'0';
		
		else if(count_b<=0&&count_a>0)
		d[i]=a[count_a-1]-'0';
		
		else if(count_a>0&&count_b>0)
		d[i]=a[count_a-1]-'0'+b[count_b-1]-'0';
		
		if(jinwei!=0)
		{
			d[i]+=jinwei;
			jinwei=0; 
		}	
			
		if(d[i]>=10&&i!=MAX-1)
		{
			int number=d[i];
			d[i]=d[i]%10;
			jinwei+=number/10;
		}
		count_a--;
		count_b--;
	}
	for(i=MAX-1;i>=0;i--)
	{
		cout<<d[i];
	}
	return 0;
}


//˼���� Сѧ��ѧ�ӷ���λ��˼�� 
#include<bits/stdc++.h> 
using namespace std;
string s1,s2;
int ans[1000010];
int a[1000010],b[1000010];//a  b  ��������װ��������� �ӵ�λ����λ ������ :���� 123  ����װ����321 
int main(){
	cin>>s1>>s2;
	int len1=s1.size(),len2=s2.size();//�ֱ� ��¼���� 
	for(int j=0,i=len1-1;i>=0;i--){//�����������  �����ֵĵ�λ��ʼ���� ���� ���� 123   ��ôa����ǰ��λװ�ľ��� 321  
		a[j++]=s1[i]-'0';
	}							
	for(int j=0,i=len2-1;i>=0;i--){//ͬ�� 
		b[j++]=s2[i]-'0';
	}
	int carry=0;//��λ   
	int len=0;//���ڼ�¼�������ĳ��� 
	for(int i=0;i<max(len1,len2);i++){ //����� i �ķ�ΧҪС��  ��󳤶�   ���Ӧ�������� 
		int t=a[i]+b[i]+carry;//��λ���λ��ӣ��ڼ��Ͻ�λ    ����úû�����Сѧ��ѧ�ͻ����� 
		ans[len++]=t%10;// �����t�п��ܴ���9  ����Ҫ�����λ��       
		carry=t/10;	//����������λ���Ǹ���  ���� ��ʼ ��6+9  ��ôt����15  ͨ��Сѧ֪ʶ��  Ҫ��λ 1 �԰�  ����carry�ͱ�ʾ��λ 
	}  
	if(carry!=0){//������յĽ�λ����0�Ļ� ��ô�������������ս�������λ 
		ans[len++]=carry;
	}
	for(int i=len-1;i>=0;i--){//�õģ�������Ҫ����˹�  ����������� ����������� ����������Ϊɶ���� �� 
		cout<<ans[i];
	}							
	return 0;
} 

