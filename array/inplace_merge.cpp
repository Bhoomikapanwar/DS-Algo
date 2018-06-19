#include<iostream>

using namespace std;

void swap(int &a,int &b)
{
  int temp=a;
  a=b;
  b=temp;
}

void printArray(int a[],int n)
{
  cout<<"\n";
  for(int i=0;i<n;i++)
    cout<<a[i];
}


void inplaceMerge(int a[],int b[],int n1,int n2)
{
  for(int i=0;i<n1;i++)
  {
    if(a[i]>b[0])
    {
      swap(a[i],b[0]);
      int first = b[0],j=1;
      for(;(j<n2) && (a[j]<first);j++)
      {;
        b[j-1]=b[j];
      }
      b[j-1]=first;
    }
  }
}

int main()
{
  int a[]={2,5,8,9};
  int b[]={1,4,6,7};
  int n1 = sizeof(a)/sizeof(a[0]);
  cout<<"Size A: "<<n1;
  int n2 = sizeof(b)/sizeof(b[0]);
  cout<<"Size B: "<<n2;
  inplaceMerge(a,b,n1,n2);
  printArray(a,n1);
  printArray(b,n2);
  return 0;
}
