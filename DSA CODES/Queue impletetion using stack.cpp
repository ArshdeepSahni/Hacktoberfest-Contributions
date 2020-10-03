#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct Queue
{
	stack<int> s1, s2; //here in stack two stcks are declared in same data type int, and given name by s1 and s2 resp
	
	void enqueue(int x)
	{
		//Move all elements from s1 to s2
		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
		// Push item into s1
		s1.push(x);
		
		//Push everything back too the s1
		while(!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
		
	}
	
	int dequeue()
	{
		if(s1.empty())
		{
			cout<<"Qqueue is Empty"<<endl;
			exit(0);
		}
		
		int x = s1.top();
		s1.pop();
		return x;
	}

};

int main()
{
	Queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	
	cout<< q.dequeue()<<"/n";
	cout<< q.dequeue()<<"/n";
	cout<< q.dequeue()<<"/n";
	
	return 0;
	
}
