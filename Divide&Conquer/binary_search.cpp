#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

int binarySearchIterative(int a[],int n,int key)
{
  //cout<<"Size of array: "<<n;
  int start = 0, end = n-1;
  while(start<=end)
  {
    int mid = start + (end-start)/2;
    if(a[mid]==key)
      return mid;
    else if(key<a[mid])
      end = mid-1;
    else
      start = mid+1;
  }
  return -1;
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

int main()
{
  int a[] = {2,4,5,6,7};
  int key = 6;
  int n = sizeof(a)/sizeof(a[0]);
    if(binary_search(begin(a),end(a),key))
      cout<<"Element found";
    else
      cout<<"Element not found";
  //int index = binarySearchIterative(a,n,key);
  /*int index = binarySearchRecursive(a,0,n-1,key);
  if(index!=-1)
    cout<<"\nElement found at index: "<<index;
  else
    cout<<"\nElement not found";
  */
  return 0;
}
