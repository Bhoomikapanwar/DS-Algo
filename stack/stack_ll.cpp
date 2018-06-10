#include<iostream>

using namespace std;

struct node
{
	int data;
	node* next;
};

class Stack
{
	node *top;
	int size;
public:
	Stack(){
		top=NULL;
		size=0;
	}
	void push(int ele);
	int pop();
	int peek();
	int stackSize();
	bool isEmpty();
};

bool Stack::isEmpty()
{
	if(top==NULL)
		return true;
	else
		return false;
}

void Stack::push(int ele)
{
	cout<<"Creating node";
	node *newNode = new node();
	newNode->data=ele;


	if(isEmpty())
	{
		cout<<"First node";
		newNode->next=NULL;
		top=newNode;
	}
	else
	{
		cout<<"Other nodes pushed";
		newNode->next=top;
		top=newNode;
	}
	size++;
}

int Stack::pop()
{
	if(isEmpty())
	{
		cout<<"Stack is empty";
		return -1;
	}
	else
	{
		cout<<"Node popped";
		int x = top->data;

		top = top->next;
		size--;
		return x;
	}
}

int Stack::peek()
{
	if(isEmpty())
	{
		cout<<"Stack empty";
		return -1;
	}
	else
		return top->data;
}

int Stack::stackSize()
{
	return size;
}

int main()
{
	Stack s;
	s.push(2);
	s.push(3);
	s.push(4);
	cout<<"Popped element: "<<s.pop();
	cout<<"Stack size: "<<s.stackSize();
	cout<<"Top element: "<<s.peek();
	return 0;
}
