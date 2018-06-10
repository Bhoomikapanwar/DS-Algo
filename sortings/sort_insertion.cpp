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
	
	for(int i=0;i<(n-1);i++){				//insertion sort
	int j=i+1;
	while((j>=0)&&(a[j]<a[j-1])){
		if(a[j]<a[j-1]){
			temp=a[j];
			a[j]=a[j-1];
			a[j-1]=temp;
		}
		j--;
	}
	}
	
	cout<<"Sorted array: ";
	for(int i=0;i<n;i++)
	cout<<a[i];
	return 0;
}
