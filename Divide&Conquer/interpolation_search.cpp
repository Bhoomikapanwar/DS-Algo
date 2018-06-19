#include<iostream>

using namespace std;

int interpolationSearch(int a[],int n, int key)
{
  int start = 0, end = 1;
  while(start<=end)
  {
    int mid = start + (key-a[start])*(end-start)/(a[end]-a[start]);
    if(a[mid]==key)
      return mid;
    else if(key<a[mid])
      end = mid-1;
    else
      start = mid+1;
  }
  return -1;
}

int main()
{
  int a[]={2,3,4,5,6,7};
  int key = 7;
  int n = sizeof(a)/sizeof(a[0]);
  int index = interpolationSearch(a,n,key);
  if(index!=-1)
    cout<<"\nElement found at index: "<<index;
  else
    cout<<"\nElement not found";
  return 0;
  }
