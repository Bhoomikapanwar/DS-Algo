#include<stdio.h>
#include<numeric>
using namespace std;

int equilibrium(int a[],int n)
{
  int index,right=0;
  int left[n];
  left[0]=a[0];
  for(int i=1;i<n;i++)
      left[i]=left[i-1]+a[i];

  for(int i=n-1;i>=1;i--)
  {
    right=right+a[i];
    if(left[i-1]==right)
      return i;
  }
  return -1;
}

int equi_opti(int a[],int n)
{
  int right=0,total;
  //for(int i=0;i<n;i++)
    //total += a[i];
  total = accumulate(a,a+n,0);
  printf("%d\n",total);
  for(int i=n-1;i>=0;i--)
  {
    if(right == total-(right+a[i]))
      return i;
    right +=a[i];
  }
  return -1;
}

int main()
{
  int a[] = {0,-3,5,-4,-2,3,1,0};
  int n = sizeof(a)/sizeof(a[0]);
  int index = equi_opti(a,n);
  if(index==-1)
    printf("Equilibrium not found");
  else
    printf("Equilibrium found at index: %d",index);
  return 0;
}
