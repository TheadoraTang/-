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


//思想是 小学数学加法进位的思想 
#include<bits/stdc++.h> 
using namespace std;
string s1,s2;
int ans[1000010];
int a[1000010],b[1000010];//a  b  数组用来装输入的数字 从低位到高位 。比如 :输入 123  数组装的是321 
int main(){
	cin>>s1>>s2;
	int len1=s1.size(),len2=s2.size();//分别 记录长度 
	for(int j=0,i=len1-1;i>=0;i--){//将输入的内容  从数字的低位开始存入 比如 输入 123   那么a数组前三位装的就是 321  
		a[j++]=s1[i]-'0';
	}							
	for(int j=0,i=len2-1;i>=0;i--){//同上 
		b[j++]=s2[i]-'0';
	}
	int carry=0;//进位   
	int len=0;//用于记录运算结果的长度 
	for(int i=0;i<max(len1,len2);i++){ //这里的 i 的范围要小于  最大长度   这个应该能理解吧 
		int t=a[i]+b[i]+carry;//低位与低位相加，在加上进位    这里好好回忆下小学数学就会明白 
		ans[len++]=t%10;// 这里的t有可能大于9  所以要存入个位额       
		carry=t/10;	//这里就是求进位的那个了  比如 开始 是6+9  那么t等于15  通过小学知识得  要进位 1 对吧  这里carry就表示进位 
	}  
	if(carry!=0){//如果最终的进位不是0的话 那么他就是我们最终结果的最高位 
		ans[len++]=carry;
	}
	for(int i=len-1;i>=0;i--){//好的，终于是要完成了哈  这里就输出结果 是逆序输出额 （这里晓得为啥子噻 ） 
		cout<<ans[i];
	}							
	return 0;
} 

