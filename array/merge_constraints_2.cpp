#include<iostream>
using namespace std;

void swap(int &a,int &b)
{
  int temp = a;
  a=b;
  b=temp;
}

void mergeConstraints(int a[],int b[],int n1,int n2)
{
  int k=0,j=0;      //k is the next available position
  for(int i=0;i<n1;)
  {
    if(a[i]!=0)
    {
      if(a[i]<b[k])
      {
        a[k++]=a[i++];
      }
      else
      {
        a[k++]=b[j++];
      }
    }
    else
      i++;
  }

  while(j<n2)
  {
    a[k++]=b[j++];
  }
}

void printArray(int a[],int n)
{
  cout<<"\n";
  for(int i=0;i<n;i++)
    cout<<a[i];
}

int main()
{
  int a[] = {0,2,0,3,0,5,6,0,0};
  int b[] = {1,8,9,10,15};
  int n1 = sizeof(a)/sizeof(a[0]);
  cout<<"Size A: "<<n1;
  int n2 = sizeof(b)/sizeof(b[0]);
  cout<<"Size B: "<<n2;
  cout<<"Hey";
  mergeConstraints(a,b,n1,n2);
  printArray(a,n1);
  //printArray(b,n2);
  return 0;
}
