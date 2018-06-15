#include<stdio.h>

using namespace std;

void move0(int a[],int n)
{
  int i=0;
  for(int j=0;j<n;j++)
  {
    if(a[j]!=0)
    {
      a[i]=a[j];
      i++;
    }
  }
  for(int j=i;j<n;j++)
    a[j]=0;
}

void swap(int &a,int &b)
{
  int temp =a;
  a=b;
  b=temp;
}

void move0_quickpartition(int a[],int n)
{
  int pivot = 0;
  int i = 0;
  for(int j=0;j<n;j++)
  {
    if(a[j]!=0)
    {
      swap(a[i],a[j]);
      i++;
    }
  }
}

void printArray(int a[],int n)
{
  for(int i=0;i<n;i++)
    printf("%d\t",a[i]);
}

int main()
{
  int a[]={2,3,4,5,6,0,8,0,6};
  int n = sizeof(a)/sizeof(a[0]);
  //move0(a,n);
  move0_quickpartition(a,n);
  printArray(a,n);
  return 0;
}
