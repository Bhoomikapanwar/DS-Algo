#include<iostream>
#include<unordered_map>
using namespace std;

void find(int a[], int n)
{
	int sum;
	unordered_multimap<int,int> map;
	for(int i=0;i<n;i++)
	{
	sum=sum+a[i];
	if(map.find(sum)!=map.end())
	{
	auto it = map.find(sum);
	while(it!=map.end() && it->first == sum)
	{
	cout<<"Subarray: "<<(it->second)+1<<","<<i;
	it++;
	}
	}

	map.insert(pair<int,int>(sum,i));
}
}

int main()
{
	int a[]= {2,3,4,5,-5,4};
	int n= sizeof(a)/sizeof(int);
	find(a,n);
	return 0;
}
