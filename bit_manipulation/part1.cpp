#include<stdio.h>
#include<bitset>

using namespace std;

void evenOdd(int a)
{
  if(a&1)
  printf("Number is odd\n");
  else
  printf("Number is even\n");
}

void sameSign(int a,int b)
{
  //printf("%b\n",bitset<32>(a));
  //printf("%b\n",bitset<32>(b));
  if((a^b)<0)
    printf("Diff sign\n");
  else
    printf("Same sign\n");
}

void addOne(int a)
{
  printf("Added one : %d",-~a);
}

void swap(int &a,int &b)
{
  if(a!=b)
  {
    a = a^b;
    b = a^b;
    a = a^b;
  }
}


int main()
{
  int a=5,b=4;
  evenOdd(a);
  sameSign(a,b);
  addOne(a);
  swap(a,b);
  //addOne(b);
  return 0;
}
