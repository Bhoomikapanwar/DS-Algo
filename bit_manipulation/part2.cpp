#include<stdio>

//Using concept of kth bit 1<<(k-1  )

using namespace std;

void unsetKbit(int &a)
{
  a = a & ~(1<<(k-1));
}

void setKbit(int &a)
{
  a = a | (1<<(k-1));
}

void checkKbit(int a)
{
  if(a&(1<<(k-1))!=0)
    printf("Kth bit is set\n");
  else
    printf("Kth bit is not set\n");
}

void toggle(int &a)
{
  a = a ^ (1<<(k-1));
}

int main()
{
  int a = 5;
  setKbit(a);
  unsetKbit(a);
  checkKbit(a);
  toggle(a);
  return 0;
}
