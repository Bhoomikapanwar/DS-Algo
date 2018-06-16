#include<iostream>

using namespace std;

int min(int a,int b)
{
  return (a<b)? a : b;
}

int binarySearchRecursive(int a[],int start, int end, int key)
{
  if(start>end)
    return -1;
  int mid = start +(end-start)/2;
  if(a[mid]==key)
    return mid;
  else if(key<a[mid])
  binarySearchRecursive(a,start,mid-1,key);
  else
  binarySearchRecursive(a,mid+1,end,key);
}

int exponentialSearch(int a[],int n,int key)
{
  int k=1;
  while(k<n && a[k]<key)
  k*=2;
  return binarySearchRecursive(a,k/2,min(k,n-1),key);
}

int main()
{
  //ExponentialSearch used for unbounded/infinite arrays
  int a[]={2,3,4,5,6,7};
  int key = 7;
  int n = sizeof(a)/sizeof(a[0]);
  int index = exponentialSearch(a,n,key);
  if(index!=-1)
    cout<<"\nElement found at index: "<<index;
  else
    cout<<"\nElement not found";
  return 0;
}
