#include<iostream>
#include<stdlib.h>
using namespace std;

void swap(int &a,int &b)
{
  int temp = a;
  a=b;
  b=temp;
}

void printArray(int a[],int n)
{
  for(int i=0;i<n;i++)
  cout<<a[i];
}

void shuffle(int a[],int n)
{
  for(int i=n-1;i>=0;i--)
  {
    int j = rand() % (i+1); //To generate numbers btw 0 and i(including i)
    swap(a[j],a[i]);
  }
}

void shuffle_opp(int a[],int n)
{
  for(int i=0;i<n;i++)
  {
    int j = i+ rand() % (n-i);
    swap(a[j],a[i]);
  }
}

int main()
{
  int a[] = {1,2,3,4,5,6};
  int n = sizeof(a)/sizeof(a[0]);
  //shuffle(a,n);
  srand(time(NULL)); //seeding
  shuffle_opp(a,n);
  printArray(a,n);
  return 0;
}
