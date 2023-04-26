#include<iostream>
#include<cstring>
using namespace std;
#define MaxSize 1000

class Stack
{
    private:
       char data[MaxSize];
       int top;
    public:
       Stack();
       bool Empty();
       bool Push(char &ch);//��&��֤�ܸı�ch��ֵ 
       bool Pop(char &ch);
};

Stack::Stack()//��� 
{
    top=-1;
}

bool Stack::Empty()
{
    return (top == -1);//�ж��Ƿ�Ϊ��ջ 
}

bool Stack::Push(char &ch)
{
    if(top == MaxSize-1)  
	   return false;   //ջ��
    top++;
    data[top]= ch;//��ͷ��ʼ���� 
    return true;
}

bool Stack::Pop(char &ch)
{
    if(top == -1)  
	   return false;   //ջ��
    ch = data[top--];//��ջ����ʼ��������һ������ģ�ÿ�ε����ң� 
    return true;
}

bool Match(char str[],int n)
{
    int i=0;
    char ch;
    Stack s;
    while(i<n)
    {
        if(str[i] == '(' || str[i] == '[' || str[i] == '{')
            s.Push(str[i]);
        else 
        {
            if(str[i] == ')')
            {
                if(!s.Pop(ch)) 
				 return false;
                if(ch!='(') 
				 return false;
            }
            if(str[i] == ']')
            {
                if(!s.Pop(ch)) 
				 return false;
                if(ch!='[') 
				 return false;
            }
            if(str[i] == '}')
            {
                if(!s.Pop(ch)) 
				 return false;
                if(ch!='{') 
				 return false;
            }
        }
        i++;
    }
    if(s.Empty())   //�����ջ��˵��ƥ�䣬ÿһ�������Ŷ���pop�� 
	   return true;    
    else 
	   return false;  
}

int main()
{
    char str[MaxSize];
    cin>>str;
    int n = strlen(str);
    if(Match(str,n)==true)
        cout<<"0";
    else
        cout<<"1";
        return 0; 
}

/*#include<iostream>
#include<cstring>
using namespace std;
enum Error_code{underflow,overflow,success};
const int maxstack = 100;
class MyStack{
	public:
		MyStack();
		bool empty();
		Error_code top(char &item);
		Error_code push(char &item);
		Error_code pop();
	private:
		int count;
	    char entry[maxstack];
};

bool MyStack::empty()
{
	bool outcome=true;
	if(count>0)
	{
		outcome=false;
	}
	return outcome;
}
MyStack::MyStack(){
	count=0;
	memset(entry,0,sizeof(entry));
} 

Error_code MyStack::pop(){
	if(empty()){
		return underflow;
	}
	count--;
	return success;
}

Error_code MyStack::top(char &item){
	if(empty()){
		return underflow;
	}
	item = entry[count-1];
	return success;
}

Error_code MyStack::push(char &item){
	if(count==maxstack){
		return overflow;
	}
	
	entry[count]=item;
	count++;
	return success;
}

int main(){
	MyStack stack;
	string s;
	cin>>s;
	bool match =true;
	for(int i=0;i<100;i++){
		if(s[i]=='('||s[i]=='['){
			stack.push(s[i]);
		}
		else if(s[i]==')'||s[i]==']'){
			char c;
			stack.top(c);
			stack.pop();
			if((s[i]==')'&&c=='(')||s[i]==']'&&c=='[')
			{
				continue;
			}
			else{
				match=false;
				break;
			}	
		}
	}
	if(stack.empty()){
		match=true;
	}
	else{
			match=false;
		}
	if(match){
		cout<<"0";
	}
	else{
		cout<<"1";
	}
	return 0;
}*/
