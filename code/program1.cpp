#include<bits/stdc++.h>
using namespace std;
#define reg register
#define db double
#define ll long long
string s[1050],ss;
int n,a[1050];
bool used;

int main()
{
	while(cin>>ss){
		for(reg int i=1;i<=ss.length();i++){//capital to smaller
			if(ss[i-1]>='A'&&ss[i-1]<='Z')
			ss[i-1]=ss[i-1]-'A'+'a';
		}
		if(ss.length()==1&&(ss[0]>'z'||ss[0]<'a'))continue;//marks
		for(reg int i=1;i<=n;i++){
			if(s[i]==ss){
				a[i]++;
				used=true;
				break;
			}
		}
		if(used){
			used=false;
			continue;
		}
		n++;
		s[n]=ss;
		a[n]=1;
	}
	for(reg int i=1;i<=n;i++){
		if(s[i][s[i].length()-1]==','||s[i][s[i].length()-1]=='.'){
			for(reg int j=1;j<s[i].length();j++)
			printf("%c",s[i][j-1]);
		}
		else cout<<s[i]<<"\t";
		printf("%d\t",a[i]);
		if(i%5==0)
		cout<<endl;
	}
	
	
    return 0;
}
