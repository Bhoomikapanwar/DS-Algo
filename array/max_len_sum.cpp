#include<iostream>
#include<unordered_map>

using namespace std;

int maxLenSubarray_map(int a[],int n,int s)
{
  unordered_map<int,int> map;
  int sum = 0,len = 0,ending_index = -1;
  //map[0] = -1;
  for(int i = 0;i<n;i++)
  {
    sum = sum+a[i];
    if(map.find(sum)==map.end())
      map[sum] = i;

    if(map.find(sum-s)!=map.end() && len < i - map[sum-s])
    {
      len = i -map[sum-s];
      ending_index = i;
    }
  }
  cout<<"\nStarting index: "<< ending_index - len + 1<<"ending_index: "<<ending_index;
}

int maxLenSubarray_naive(int a[], int n, int sum)
{
  int s,maxlen=0,ending_index=-1;
  for(int i=0;i<n;i++)
  {
    s = 0;
    for(int j = i;j<n;j++)
    {
      s = s + a[j];
      if(s==sum)
        {
          if(maxlen < j-i+1)
          {
            maxlen = j-i+1;
            ending_index = j;
          }
        }
    }
  }
  cout<<"Subarray is: "<<ending_index-maxlen+1<<"...."<<ending_index;
}

int main()
{
  int a[] = {5,6,-5,5,3,5,3,-2,0};
  int n = sizeof(a)/sizeof(a[0]);
  int sum = 8;
  maxLenSubarray_naive(a,n,sum);
  //maxLenSubarray_map(a,n,sum);
  return 0;
}
