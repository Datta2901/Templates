#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node *next;
};

class Stack
{
    public:
        node *front;
        public:
        Stack()
        {
            front = NULL;
        }
        void push(int);
        void pop();
        int top();
        bool isempty();
};

void Stack :: push(int d)
{
	node *temp;
	temp = new node();
	temp->data = d;
	if(front == NULL)
	{
		temp->next = NULL;
	}
	else
	{
		temp->next = front;
	}
	front = temp;
}

void Stack :: pop()
{
	if(front == NULL)
		cout << "UNDERFLOW\n";
	
	else
	{
		node *temp = front;
		front = front->next;
		delete(temp);
	}
}

int Stack :: top()
{
    if(front == NULL){
        return -1;
    }
	return front->data;
}

bool Stack :: isempty(){
    if(front == NULL){
        return false;
    }else{
        return true;
    }
}