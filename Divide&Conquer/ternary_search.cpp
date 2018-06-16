#include<iostream>
#include<stdio.h>

using namespace std;

int ternarySearch(int a[],int n,int key)
{
  //cout<<"Size of array: "<<n;
  int start = 0, end = n-1;
  while(start<end)
  {
    int midLeft = start + (end-start)/3;
    int midRight = end - (end -start)/3;
    if(a[midLeft]==key)
      return midLeft;
    else if(a[midRight]==key)
      return midRight;
    else if(key<a[midLeft])
      end = midLeft-1;
    else if(key>a[midRight])
      start = midRight+1;
    else
      start = midLeft+1;
      end = midRight-1;
    }
  return -1;
}

int main()
{
  int a[] = {2,4,5,6,7};
  int key = 4;
  int n = sizeof(a)/sizeof(a[0]);
  int index = ternarySearch(a,n,key);
  if(index!=-1)
    cout<<"\nElement found at index: "<<index;
  else
    cout<<"\nElement not found";
  //binarySearchRecursive(a,key);
  return 0;
}
