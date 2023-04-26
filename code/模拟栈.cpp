#include<iostream>
#include<cstring>

enum Error_code{underflow,overflow,success};
const int maxstack = 10;
class MyStack{
	public:
		MyStack();
		bool empty();
		Error_code top(char &item);
		Error_code pop();
		Error_code push(char &item);
	private:
		int count;
		char entry[maxstack];
};

MyStack::MyStack(){
	count=0;
	memset(entry,0,sizeof(entry));
} 

bool MyStack::empty()
{
	bool outcome=true;
	if(count>0)
	{
		outcome=false;
	}
	return outcome;
}

Error_code MyStack::pop(){
	if(count==0){
		return underflow;
	}
	count--;
	return success;
}

Error_code MyStack::top(char &item){
	if(count==0){
		return underflow;
	}
	item = entry[count-1];
	return success;
}

Error_code MyStack::push(char &item){
	if(count>=maxstack){
		return overflow;
	}
	
	entry[count++]=item;
	return success;
}
using namespace std;
int main(){
	MyStack stack;
	int k;
	cin>>k;
	for(int i=0;i<k;i++){
		string s;
		cin>>s;
		if(s=="push"){
			char c;
			cin>>c;
			stack.push(c);
		}
		else {
			stack.pop();
		}
	}
	char tmp; 
	while(!stack.empty()){
		stack.top(tmp);
		cout<<tmp<<" ";		
		stack.pop();
	}
	
	return 0;
}
