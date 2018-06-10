#include<iostream>
#include<stack>
using namespace std;

int main(){
	stack<int> s;
	s.push(2);
	s.push(3);
	s.push(6);
	s.pop();
	cout<<"Top"<<s.top();
	cout<<"Size"<<s.size();
	if(s.empty())
		cout<<"Empty stack";
		
	return 0;
}
