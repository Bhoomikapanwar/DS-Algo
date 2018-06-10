#include<iostream>

using namespace std;

void sort(int arr[],int n)
{
  int count = 0;
  for(int i=0;i<n;i++)
  {
    if(arr[i]==0)
    count ++;
  }
  for(int i=0;i<n;i++)
  {
    if(i<count)
    arr[i]=0;
    else
    arr[i]=1;
  }
}

void swap(int &a,int &b)
{
  int temp = a;
  a=b;
  b=temp;
}

void partition(int arr[],int n)
{
  int pivot = 1;
  int i=0;
  for(int j=0;j<n;j++)
  {
    if(arr[j]<pivot)
    {
      swap(arr[i],arr[j]);
      i++;
    }
  }
}

void printArray(int arr[],int n)
{
  for(int i=0;i<n;i++)
  cout<<arr[i];
}

void dutch(int arr[],int n)
{
  int pivot = 1,j=0;
  int start=0;
  int end = n-1;
  while(j<=end)
  {
    if(arr[j]<pivot)
    {
      swap(arr[j],arr[start]);
      start++;
      j++;
    }
    else if(arr[j]==pivot)
    {
      j++;
    }
    else
    {
      swap(arr[j],arr[end]);
      end--;
    }
  }
}


int main()
{
  int arr[] = {0,2,0,1,0,2,0,1,1};
  int n = sizeof(arr)/sizeof(arr  [0]);
  //sort(arr,n);
  //partition(arr,n);
  dutch(arr,n);
  printArray(arr,n);
  return 0;
}
