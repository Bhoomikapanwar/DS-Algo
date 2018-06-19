#include<iostream>

using namespace std;

int replace0(int a[],int n)
{
  int count = 0, maxcount = 0;
  int prevZeroIndex = -1, maxZeroIndex  = -1;
  for(int i=0;i<n;i++)
  {
    if(a[i]==1)
      count++;
    else
    {
      count = i-prevZeroIndex; //No of 1's between two subsequent 0's including current 0
      prevZeroIndex = i;
    }
    if(count>maxcount)
    {
      maxcount = count;
      maxZeroIndex = prevZeroIndex;
    }
  }
  return maxZeroIndex;
}

int main()
{
  int a[] = {0,0,1,0,1,1,1,0,1,1};
  int n = sizeof(a)/sizeof(a[0]);
  cout<<"0 to be replaced by 1 is at index: "<<replace0(a,n);
  return 0;
}
