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
		Error_code find(int &item,Node *&res_node);
		Error_code clear();
		Error_code get_front(int &res);
		int empty();
		int size();
		LinkList();
		Node *get_next(Node *node);
	private:
	Node *head;
};

LinkList::LinkList()
{
	head=new Node();
	head->next=head;
}

Error_code LinkList::add(int &item)
{
	Node *new_node = new Node (item, head->next);
	if(new_node==NULL)
	return overflow;
	head->next=new_node;
	return success;
 } 

Error_code LinkList::find(int &item,Node *&res_node)
{
	res_node = NULL;
	Node *cur=head->next;
	while(cur!= head)
	{
		if(cur->entry==item)
		{
			res_node=cur;
			return success;
		}
		cur=cur->next;
	}
	return notfound;
}

Error_code LinkList::remove(int &item)
{
	Node *cur=head->next;
	Node *prev=NULL;
	if(cur==head)
	return emptylist;
	while(cur!=head)
	{
		if(cur->entry==item)
		{
			if(prev==NULL)
			{
				head->next=cur->next;
				delete cur;
				cur=NULL;
			}
			else
			{
				prev->next=cur->next;
				delete cur;
				cur=NULL;
			}
			return success;
		}
		prev=cur;
		cur=cur->next;
	}
	return notfound;
}

Error_code LinkList::get_front(int &res)
{
	if(empty())
	{
		return emptylist;
	}
	res=head->next->entry;
	return success;
}

Error_code LinkList::clear()
{
	Node *cur=head,*pre=NULL;
	while(cur)
	{
		pre=cur;
		cur=cur->next;
		delete pre;
		pre = NULL;
	}
	head=NULL;
	return success ;
}

int LinkList::empty()
{
	return (head->next==head);
}

int LinkList::size()
{
	int res=0;
	Node *cur=head->next;
	while(cur!=head)
	{
		res++;
		cur=cur->next;
	}
	return res;
}

Node *LinkList::get_next(Node *node)
{
	if(empty())
	{
		return NULL;
	}
	if(node->next==head)
	{
		return node->next->next;
	}
	return node->next;
}

int main()
{
	int n,m;
	cin>>n>>m;
	LinkList *ll=new LinkList(); 
	while(n>0)
	{
		ll->add(n);
		n--;
	 } 
	 int i=1;
	 Node *cur;
	 ll->find(i,cur);
	 while(ll->size()!=1)
	 {
	 	for(i=1;i<=m-1;i++)
	 	{
	 		cur=ll->get_next(cur);
		 }
		 Node *pre=cur;
		 cur=ll->get_next(cur);
		 ll->remove(pre->entry);
	 }
	int res;
	ll->get_front(res);
	cout<<res<<endl;
	return 0;
}
