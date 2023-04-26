#include<iostream>
using namespace std;

struct Node {
	Node *next;
	Node();
	int entry;
	Node(int item, Node *add_on = NULL);
};

Node::Node( )
{
	next = NULL;
}

Node::Node(int item, Node *add_on)
{
	entry = item;
	next = add_on;
}

enum Error_code{overflow,emptylist,notexist,notfound,success};

class LinkList{
	public:
		Error_code add(int &item);
		Error_code remove(int &item);
		Error_code find(int &item);
		Error_code clear();
		int empty();
		void print();
		LinkList();
	private:
	Node *head;
};

LinkList::LinkList()
{
	head=NULL;
}

Error_code LinkList::add(int &item)
{
	Node *new_node = new Node (item, head);
	if(new_node==NULL)return overflow;
	head=new_node;
	return success;
 } 
 
Error_code LinkList::find(int &item)
{
	if(head==NULL)
	{
		return emptylist;
	}
	Node *cur=head;
	while(cur!=NULL)
	{
		if(cur->entry==item)
		{
			return success;
		}
		cur=cur->next;
	}
	return notexist;
}

Error_code LinkList::remove(int &item)
{
	if(head==NULL)
	{
		return emptylist;
	}
	Node *pre=NULL,*cur=head; 
	while(cur!=NULL)
	{
		if(cur->entry==item)
		{
			if(pre==NULL)
			{
				head=head->next;
			}
			else
			{
				pre->next=cur->next;
			}
			delete cur;
			cur=NULL;
			return success;
		}
		pre=cur;
		cur=cur->next;
	}
	return notexist;
}

Error_code LinkList::clear()
{
	Node *cur=head,*pre=cur;
	while(cur)
	{
		pre=cur;
		cur=cur->next;
		delete pre;
		pre = NULL;
	}
	head=NULL;
}

int LinkList::empty()
{
	if(head==NULL)
	return 1;
	return 0;
}

void LinkList::print()
{
	if(empty())
	{
		return;
	}
	Node *cur= head;
	while(cur->next)
	{
		cout<<cur->entry<<" ";
		cur=cur->next;
	}
	cout<<cur->entry;
}

int main()
{
	int N;
	cin>>N;
	string op;
	int num;
	Error_code err[100];
	int count[100]={0};
	LinkList *ll=new LinkList();
	int i;
	for(i=0;i<N;i++)
	{
		cin>>op;
		
		if(op=="add")
		{
			cin>>num;
			ll->add(num);
		}
		else if(op=="remove")
		{
			cin>>num;
			ll->remove(num);
		}
		else if(op=="find")
		{
			cin>>num;
			count[i]=1;
			err[i]=ll->find(num);
		}
		else if(op=="clear")
		{
			ll->clear();
		}
	}
	
	for(i=0;i<N;i++)
	{
		if(count[i]!=0)
		{
		   if(err[i]==success)
		   {
			  cout<<"1"<<endl;
		   }
		   else 
		   {
			  cout<<"0"<<endl;
		   }			
		}
	}
	
	if(ll->empty())
	{
		cout<<"empty linklist"<<endl;
	}
	
	else
	{
		ll->print();
	}
	return 0;
}
