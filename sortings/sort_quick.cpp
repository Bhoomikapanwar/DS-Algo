#include<iostream>
#include<algorithm>

using namespace std;

int partition(int a[], int low, int high)
{
	int pivot=a[high];
	int p=low;
	for(int i=low;i<high;i++)
	{
		if(a[i]<=pivot)
		{
			swap(a[i],a[p]);
			p++;
		}
	}
	swap(a[p],a[high]);
	return p;
}

void quicksort(int a[],int low,int high)
{
	if(low>=high)
	return;
	int p=partition(a,low,high);
	quicksort(a,low,p-1);
	quicksort(a,p+1,high);
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
	quicksort(a,0,n-1);
	
	cout<<"Sorted array: ";
	
	for(int i=0;i<n;i++)
	cout<<a[i]<" ";
	return 0;
}
