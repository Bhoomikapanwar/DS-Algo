#include<iostream>
using namespace std;

void swap(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}

void max_heapify(int a[],int i,int n)
{

	int largest;
	int l = 2*i +1;
	int r = 2*i +2;
	if ((l <= n) && (a[l] > a[i]))
	   	largest =l;
	else 
	   largest =i;
	if ((r <= n) && (a[r] > a[largest]))
	   largest =r;
	   
	if (largest != i){
		swap( a[i] , a[largest]);
		max_heapify(a, largest, n);	
	}
}

void heapsort(int a[],int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
        max_heapify(a, i, n);
        
	for(int k=n-1;k>=1;k--)
	{
		swap(a[0],a[k]);
		max_heapify(a,0,k-1);
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
	
	heapsort(a,n);
	
	cout<<"Sorted array: ";
	for(int i=0;i<n;i++)
	cout<<a[i];
	return 0;	
}
