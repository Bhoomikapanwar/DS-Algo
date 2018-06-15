#include<iostream>
#include<unordered_map>

using namespace std;

int fib(int num)
{
  unordered_map<int,int> lookup;
  if(num<=1)
    return num;
  if(lookup.find(num)==lookup.end())
    lookup[num]=fib(num-1)+fib(num-2);
  return lookup[num];
}

int main()
{
  cout<<"Fib: "<<fib(5);
  return 0;
}
