#include<iostream>
using namespace std;
 
int main()
{
	int a[]={5,6,1,9,4,1,3,7};
	int n=sizeof(a)/sizeof(a[0]);
	int k=10;		//range is 0 to 9
	
	int c[k]={0};
	int b[n];
	
	for(int j=0;j<n;j++)
	c[a[j]]=c[a[j]]+1;
	
	for(int i=0;i<k;i++)
	cout<<c[i]<<" ";
	
	cout<<"\n";
	
	for(int i=1;i<k;i++)
	c[i]=c[i]+c[i-1];
	
	for(int i=0;i<k;i++)
	cout<<c[i]<<" ";
	
	cout<<"\n";
	
	for(int j=n-1;j>=0;j--)
	{
		b[ (c[a[j]])-1]=a[j];
		c[a[j]]--;	
	}
	
	cout<<"Sorted array: ";
	for(int i=0;i<n;i++)
	{
	a[i]=b[i];
	cout<<a[i];
	}
	
	return 0;	
} 
