#include<stdio.h>
#include<unordered_map>

using namespace std;

int majority(int a[],int n)
{
  unordered_map<int,int> map;
  //memset(map,0);
  for(int i=0;i<n;i++)
  {
    map[a[i]]+=1;
    if(map[a[i]]>n/2)
    return a[i];
  }
  return -1;
}

int majority_boyer_moore(int a[],int n)
{
  int m,count=0 ;
  for(int i=0;i<n;i++)
  {
    if(count==0)
    {
      m = a[i];
      count = 1;
    }
    else
    {
      if(m==a[i])
        count++;
      else
        count--;
    }
  }
  if(count>0)
    return m;
  else
    return -1;
}

int main()
{
  int a[] = {2,8,7,2,2,5,2,3,1,2,2};
  int n = sizeof(a)/sizeof(a[0]);
  //int num = majority(a,n);
  int num = majority_boyer_moore(a,n);
  if(num==-1)
    printf("No majority element found\n");
  else
    printf("Majority element is: %d", num);
  return 0;
}
