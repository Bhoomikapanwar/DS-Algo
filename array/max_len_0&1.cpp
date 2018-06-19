#include<iostream>
#include<unordered_map>

using namespace std;

void maxLenSubarray01(int a[],int n)
{
  unordered_map<int,int> map;
  int maxlen = 0, ending_index = -1 , count0 = 0, count1 =0;
  for(int i=0;i<n;i++)
  {
    if(a[i]==0)
      {
        count0++;
        if(map.find(count0)==map.end())
        map[count0] = i;
      }
    else if(a[i]==1)
    {
      count1++;
      if(map.find(count1)!=map.end() && maxlen < i-map[count1]+1)
      {
        maxlen = i-map[count1]+1;
        ending_index = i;
      }
    }
  }
  if(ending_index!=-1)
    cout<<"\nStarting index: "<< ending_index-maxlen+1 <<" Ending_index: "<<ending_index;
  else
    cout<<"No such Subarray";
}

int main()
{
  int a[] = {0,0,1,0,1,0,0,0,1};
  int n = sizeof(a)/sizeof(a[0]);
  maxLenSubarray01(a,n);
  return 0;
}
