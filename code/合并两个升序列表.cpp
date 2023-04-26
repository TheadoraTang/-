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
		int empty();
		void print();
		LinkList();
        Node *head;
};

LinkList::LinkList()
{
	head=new Node(-1,NULL);
}

Error_code LinkList::add(int &item)
{
	Node *p=head;
	while(p->next!=NULL)
	{
		p=p->next;
	 } 
	Node *new_node = new Node (item, NULL);
	p->next=new_node;
	return success;
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
	Node *cur= head->next;
	while(cur->next)
	{
		cout<<cur->entry<<" ";
		cur=cur->next;
	}
	cout<<cur->entry;
}


int main()
{
	int N,M;
	cin>>N;
	int number;
	LinkList *L1=new LinkList();
	LinkList *L2=new LinkList();
	LinkList *L3=new LinkList();
	
	for(int i=0;i<N;i++)
	{
		cin>>number;
		L1->add(number);
	}
	
	cin>>M;
	for(int i=0;i<M;i++)
	{
		cin>>number;
		L2->add(number);
	}	
	
	Node *p1=L1->head->next,*p2=L2->head->next;
	
	while(p1!=NULL&&p2!=NULL)
	{
	    Node *pr;
		if(p1->entry>=p2->entry) pr=p2;
		if(p2->entry>p1->entry) pr=p1;
		
	    L3->add(pr->entry);		
		if(pr->entry==p1->entry)
		{
			p1=p1->next;
		}
		else
		{
			p2=p2->next;
		}
	}	
	
	if(p1==NULL)
	{
		while(p2!=NULL)
		{ 
		   L3->add(p2->entry);
		   p2=p2->next;
		} 
	}	
	
	if(p2==NULL)
	{
		while(p1!=NULL)
		{ 
		   L3->add(p1->entry);
		   p1=p1->next;
		} 
	}
	
	L3->print();
	return 0;
}




/*#include<iostream>
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
		Error_code insertpre(int &pre,int &item);
		Error_code insertlast(int &last,int &item);
		Error_code remove(int &item);
		int empty();
		void print();
		LinkList();
        Node *head;
};

LinkList::LinkList()
{
	head=new Node(-1,NULL);
}

Error_code LinkList::add(int &item)
{
	Node *p=head;
	while(p->next!=NULL)
	{
		p=p->next;
	 } 
	Node *new_node = new Node (item, NULL);
	p->next=new_node;
	return success;
}

Error_code LinkList::insertlast(int &last,int &item)
{
	Node *p=head;
	while(p->next->entry!=last)
	{
		p=p->next;
	}
	Node *new_node = new Node (item,p->next);
	p->next=new_node;
	return success;
}

Error_code LinkList::insertpre(int &pre,int &item)
{
	Node *p=head;
	while(p->entry!=pre)
	{
		p=p->next;
	}
	Node *new_node = new Node (item, p->next);
	p->next=new_node;
	return success;
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
	Node *cur= head->next;
	while(cur->next)
	{
		cout<<cur->entry<<" ";
		cur=cur->next;
	}
	cout<<cur->entry;
}


int main()
{
	int N,M;
	cin>>N;
	int number;
	LinkList *L1=new LinkList();
	LinkList *L2=new LinkList();
	
	for(int i=0;i<N;i++)
	{
		cin>>number;
		L1->add(number);
	}
	
	cin>>M;
	for(int i=0;i<M;i++)
	{
		cin>>number;
		L2->add(number);
	}	
	
	Node *p1=L1->head->next,*p2=L2->head->next;
	
	while(p1!=NULL&&p2!=NULL)
	{
		if(p1->entry>=p2->entry)
		{
			L1->insertlast(p1->entry,p2->entry);
			p2=p2->next;
		} 
		
		else if(p2->entry>p1->entry)
		{
			while(p1->entry<p2->entry&&p1->next!=NULL)
			{
				p1=p1->next;
			}
			
			if(p1->next==NULL&&p1->entry>p2->entry)
			{
				L1->insertlast(p1->entry,p2->entry);
				p2=p2->next;
			}
			
			else if(p1->next==NULL&&p1->entry<=p2->entry)
			{
				L1->insertpre(p1->entry,p2->entry);
			    p2=p2->next;
			}
			else if(p1->next!=NULL)
			{
			    L1->insertlast(p1->entry,p2->entry);
			    p2=p2->next;				
			}

		}
        
	}
	

	if(p2!=NULL)
	{
		while(p2!=NULL)
		{
			L1->add(p2->entry);
		    p2=p2->next;
		}
		
	}
	
	
	L1->print();
	
	return 0;
}*/
