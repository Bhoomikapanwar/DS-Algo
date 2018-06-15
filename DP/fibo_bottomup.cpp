#include<stdio.h>
using namespace std;

int fib(int num)
{
  if(num<=1)
    return num;
  int prev=0, cur=1,newfib;
  for(int i=2;i<=num;i++)
  {
    newfib = prev+cur;
    prev=cur;
    cur=newfib;
  }
  return newfib;
}

int main()
{
  printf("%d\n", fib(8));
  return 0;
}
