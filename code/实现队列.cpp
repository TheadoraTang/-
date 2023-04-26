#include<bits/stdc++.h>
using namespace std; 
enum  Error_code{underflow, overflow, success};
const int maxqueue = 8;
class CirQueue {
public:
   CirQueue();
   bool empty() ;
   Error_code serve();
   Error_code append(int &item);
   Error_code retrieve(int &item);
   bool full();
   int size() ;
   void clear();
   Error_code serve_and_retrieve(int &item);
private:
   int count;
   int front, rear;
   int entry[maxqueue];
};

CirQueue::CirQueue()
{
   count = 0;
   rear = maxqueue - 1;
   front = 0;
}

bool CirQueue::empty() 
{
   return count == 0;
}

Error_code CirQueue::append(int &item)
{
   if (count >= maxqueue) return overflow;
   count++;
   rear = ((rear + 1) == maxqueue) ? 0 : (rear + 1); 
   entry[rear] = item;
   return success;
}

Error_code CirQueue::serve()
{
   if (count <= 0) return underflow;
   count--;
   front = ((front + 1) == maxqueue) ? 0 : (front + 1);
   return success;
}

Error_code CirQueue::retrieve(int &item) 
{
   if (count <= 0) return underflow;
   item = entry[front];
   return success;
}

int CirQueue::size() 
{
   return count;
}

bool CirQueue::full() 
{
  return count==maxqueue;
}

void CirQueue::clear()
{
   count = 0;
   rear = maxqueue-1;
   front = 0;
}

Error_code CirQueue::serve_and_retrieve(int &item)
{
	  if (count <= 0) return underflow;
         item = entry[front];
         count--;
         front = ((front + 1) == maxqueue) ? 0 : (front + 1);
         return success;;
}

int main()
{
	CirQueue C;
	int N;
	cin>>N;
	int j;
	int number;
	
	for(int i=0;i<N;i++)
	{
		cin>>number;
	    C.append(number);	
	}
	if(N>8)
	{
	cout<<"This queue is overflow!"<<endl; 	
	while(!C.empty())
	{
		int t;
		C.serve_and_retrieve(t);
		cout<<t;
		j++;
		if(j!=8)
		cout<<" ";
	 } 	
	}
    else{
	while(!C.empty())
	{
		int t;
		C.serve_and_retrieve(t);
		cout<<t<<" ";
	 }     	
	}
		
	return 0;
}
