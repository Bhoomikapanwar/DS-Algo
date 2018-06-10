#include<iostream>

using namespace std;

#define SIZE 10	//default capacity of stack

class stack{
	int *a;
	int top;
	int capacity;
	
public:
	stack(int size = SIZE);
	
	void push(int);
	int pop();
	int peek();
	
	int size();
	bool isEmpty();
	bool isFull();
};

stack::stack(int size)
{
	a = new int[size];
	capacity = size;
	top = -1;
}

void stack::push(int ele)
{
	if(!isFull()){
		top++;
		a[top]=ele;
		cout<<"Ele inserted";
	}
	else
	cout<<"Overflow";
}

int stack::pop(){
	if(!isEmpty()){
		int x = a[top];
		top--;
		cout<<"Ele popped";
		return x;
	}
	else
	cout<<"Underflow";
}

int stack::peek(){
	if(!isEmpty())
		return a[top];
	else
		cout<<"Empty Stack";
}
bool stack::isFull()
{
	if((top+1)==capacity)
		return true;
	else
		return false;
}

bool stack::isEmpty(){
	if(top==-1)
		return true;
	else
		return false;
}

int stack::size()
{
	if(isEmpty())
		cout<<"Empty stack";
	return top+1;
}

int main()
{
	stack s(10);
	s.push(2);
	s.push(4);
	s.push(6);
	s.peek();
	s.pop();
	cout<<"Top element: "<<s.peek();
	cout<<"Size: "<<s.size();
	return 0;
}
