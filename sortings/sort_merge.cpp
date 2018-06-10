#include<iostream>
using namespace std;

int c[10];

void merge(int a[],int m, int low, int high)
{
	int n=high-low+1;
	int c[n];
	int k=low, i=low, j=m+1;
	while((i<=m)&&(j<=high)){
		if(a[i]<a[j])
		c[k++]=a[i++];
		else
		c[k++]=a[j++];
	}
	
	while(i<=m){
		c[k++]=a[i++];
	}
	
	while(j<=high)
	{
		c[k++]=a[j++];
	}
	
	for(int i=low;i<=high;i++)
	{
		a[i]=c[i];
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}

void mergesort(int a[],int low,int high )
{
	if(low>=high)
	return;
	if(low<high)
	{
		int m=low+((high-low)/2);
		mergesort(a,low,m);
		mergesort(a,m+1,high);
		merge(a,m,low,high);
	}
	
}

int main()
{
	int n;
	cout<<"Enter the no.elements: ";
	cin>>n;
	int a[n];
	cout<<"Enter the elements of the array: ";
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	mergesort(a,0,n-1);
	
	cout<<"Sorted array: ";
	for(int i=0;i<n;i++)
	cout<<a[i]<" ";
	
	return 0;
}
