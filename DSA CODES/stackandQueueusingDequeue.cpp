#include <bits/stdc++.h>

using namespace std;

struct DqueNode{ //structure for node of dequeue
	int value;
	DqueNode* next;
	DqueNode* prev;	
};

//Implementation of dequeue class
class Deque{
	private:
		DqueNode* head;
		DqueNode* tail;
		
	public:
	Deque()
	{
		head = tail = NULL;
	}
	
	bool isEmpty()//if list is empty
	{
		if(head == NULL)
			return true;
		return false;
	}
	
	//for counting no of nodes in list
	int size()
	{
		if(!isEmpty()){
			DqueNode* temp = head;
			int len = 0;
			while(temp != NULL){
				len++;
				temp = temp->next;
			}
			return len;
		}
		return 0;
	}
	//Insertion at first position
	void insert_first(int element)
	{
		DqueNode* temp = new DqueNode[sizeof(DqueNode)];
		temp->value = element;
		
		//if element is forst element
		if(head == NULL){
			head = tail= temp;
			temp->next =temp->prev = NULL;
		}
		else
		{
			head->prev = temp;
			temp->next = head;
			temp->prev = NULL;
			head = temp;
		}
	}
	
	//insertion at last position
	void insert_last(int element)
	{
		//allocating of node of Dqueue type
		DqueNode* temp = new DqueNode[sizeof(DqueNode)];
		temp->value = element;
		
		//if element is the first element
		if(head == NULL){
			head = tail = temp;
			temp->next= temp->prev = NULL;
			
		}
		else {
			tail->next = temp;
			temp->next = NULL;
			temp->prev = tail;
			tail = temp;
		}
	}
	
	//remove element at the first position
	void remove_first()
	{
		//if list is not empty
		if(!isEmpty()){
			DqueNode* temp = head;
			head = head->next;
			head->prev = NULL;
			free(temp);
			return;
		}
		cout<<"Lsit is empty" << endl;
	}
	// remove element at the last position 
    void remove_last() 
    { 
        // if list is not empty 
        if (!isEmpty()) { 
            DqueNode* temp = tail; 
            tail = tail->prev; 
            tail->next = NULL; 
            free(temp); 
            return; 
        } 
        cout << "List is Empty" << endl; 
    } 
	//display elements in deque
	void display()
	{
		//if list is not empty
		if (!isEmpty()){
			DqueNode* temp = head;
			while (temp != NULL){
				cout<< temp->value << " ";
				temp = temp->next;
			}
			cout << endl;
			return;
		}
		cout << "List is Empty" << endl;
	}
			
};

//class to implement stack using Deque
class Stack : public Deque{
	public:
	//push to push element at top of stack
	//using insert at last function of deque
	void push(int element)
	{
		insert_last(element);
	}
	//pop to remove element at top of stack
	//using remove at last function of deque
	void pop()
	{
		remove_last();
	}
};

//class to implement queue using dequeue
class Queue : public Deque{
	public:
		//enqueue to insert element at last
		//using insert at lasst function of dequeue
		void enqueue(int element)
		{
			insert_last(element);
		}
		//dequeue to remove element from first
		//using remove at first function of deque
		void dequeue(){
			remove_first();
		}
};


int main()
{
	//object of stack
	Stack stk;
	stk.push(1);
	stk.push(2);
	cout<<"Stack: ";
	stk.display();
	
	//pop element
	stk.pop();
	cout << "Stack: ";
	stk.display();
	 // object of Queue 
    Queue que; 
  
    // insert 12 and 13 in queue 
    que.enqueue(12); 
    que.enqueue(13); 
    cout << "Queue: "; 
    que.display(); 
  
    // delete an element from queue 
    que.dequeue(); 
    cout << "Queue: "; 
    que.display(); 
  
    cout << "Size of Stack is " << stk.size() << endl; 
    cout << "Size of Queue is " << que.size() << endl; 
    return 0; 
	
	
}
