#include<iostream>
using namespace std;

void swap(int &a,int &b)
{
int temp=a;
a=b;
b=temp;
}

void print(int a[],int n)
{
for(int i=0;i<n;i++)
cout<<a[i];
}

void highLow(int a[],int n)
{
for(int i=1;i<n;)
{
if(a[i]<a[i+1])
swap(a[i],a[i+1]);
i+=2;
}
}

int main()
{
int a[]={2,3,5,6,7};
int n= sizeof(a)/sizeof(int);
highLow(a,n);
print(a,n);
return 0;
}
