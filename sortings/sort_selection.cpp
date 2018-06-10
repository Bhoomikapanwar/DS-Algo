#include<iostream>
using namespace std;

int main()
{
	int n,min,temp,pos;
	cout<<"Enter the no.elements: ";
	cin>>n;
	int a[n];
	cout<<"Enter the elements of the array: ";
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	for(int i=0;i<(n-1);i++){			//selection Sort
		min=a[i];
		for(int j=i+1;j<n;j++)
			if(a[j]<min){
				min=a[j];
				pos=j;
			}
		temp=a[i];
		a[i]=a[pos];
		a[pos]=temp;
	}
	
	cout<<"Sorted array: ";
	for(int i=0;i<n;i++)
	cout<<a[i];
	
	return 0;
}
