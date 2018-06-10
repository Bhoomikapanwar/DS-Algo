#include<iostream>
#include<unordered_map>

using namespace std;

void findPair(int a[],int n, int sum)
{
  unordered_map<int, int> map;
  for(int i=0;i<n;i++)
  {
    if(map.find(sum-a[i])!=map.end())
    {
      cout<<"Pair found: "<<map[sum-a[i]]<<","<<i;
      return;
    }
    map[a[i]]=i;
  }
  cout<<"Pair not found";
}

int main()
{
  int *a,n,sum;
  cout<<"Enter the number of elements: ";
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>a[i];
  cout<<"Enter the sum: ";
  cin>>sum;
  findPair(a,n,sum);
  return 0;
}
