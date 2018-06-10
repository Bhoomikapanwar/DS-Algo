#include<iostream>
using namespace std;

int main()
{
	int n,temp;
	cout<<"Enter the no.elements: ";
	cin>>n;
	int a[n];
	cout<<"Enter the elements of the array: ";
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	for(int i=(n-1);i>0;i--)			//bubble sort
	{
		for(int j=0;j<i;j++)
		{
			if(a[j+1]<a[j])
			{
			temp=a[j+1];
			a[j+1]=a[j];
			a[j]=temp;
			}
		}
	}
	
	cout<<"Sorted array: ";
	for(int i=0;i<n;i++)
	cout<<a[i];
	return 0;
}
