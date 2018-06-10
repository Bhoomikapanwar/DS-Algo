#include<iostream>
#include<unordered_set>
using namespace std;

bool find(int a[], int n)
{
	int sum;
	unordered_set<int> set;
	for(int i=0;i<n;i++){
	sum=sum+a[i];
	if(set.find(sum)!=set.end())
	return true;
	set.insert(sum);
	}
	return false;
}
int main()
{
	int a[]= {2,3,4,5,4};
	int n= sizeof(a)/sizeof(int);
	if(find(a,n))
		cout<<"Subarray with 0 sum exists";
	else
		cout<<"Subarray does not exist";
	return 0;
}
