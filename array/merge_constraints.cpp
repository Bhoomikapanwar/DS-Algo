#include<iostream>
using namespace std;

void swap(int &a,int &b)
{
  int temp = a;
  a=b;
  b=temp;
}


// VERY IMPORTANT ( PLEASE DO NOT IGNORE )
int rearrange(int a[],int n)    //Do not use partition logic of quick sort as it does not preserves the sorted order of elements
{
  int pivot = 0;
  int i = 0;
  for(int j = 0;j<n;j++)
  {
    if(a[j]!=0)
      {
        swap(a[i],a[j]);
        i++;
      }
  }
  return i;
}

/*int rearrange(int a[],int n)
{
  int k = 0;
  for(int i =0;i<n;i++)
  {
    if(a[i]!=0)
      a[k++]=a[i];
  }
  int position = k;
  for(;k<n;k++)
  {
    a[k]=0;
  }
  return position;
}*/

void printArray(int a[],int n)
{
  cout<<"\n";
  for(int i=0;i<n;i++)
    cout<<a[i];
}
void mergeConstraints(int a[],int b[],int n1,int n2)
{
  int m = rearrange(a,n1);
  cout<<"\nm: "<<m;
  printArray(a,n1);
  int i=m-1,j=n2-1,k=n1-1;
  while(i>=0&&j>=0)
  {
    if(a[i]>b[j])
      a[k--] = a[i--];
    else
      a[k--] = b[j--];
  }
  while(j>=0)
  {
    a[k--] = b[j--];
  }
}


int main()
{
  int a[] = {0,3,0,5,0,6,8,0,0};
  int b[] = {1,2,4,10,15};
  int n1 = sizeof(a)/sizeof(a[0]);
  cout<<"Size A: "<<n1;
  int n2 = sizeof(b)/sizeof(b[0]);
  cout<<"Size B: "<<n2;
  mergeConstraints(a,b,n1,n2);
  printArray(a,n1);
  //printArray(b,n2);
}
