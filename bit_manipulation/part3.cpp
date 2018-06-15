#include<stdio>
#include<math.h>
using namespace std;

//Using concept of unsetting right most set bit n & (n-1)

void powerOf2(int n)
{
  if(n&(n-1)==0)
    printf("Number is power of 2\n");
  else
    printf("Number is power of 2\n");
}

int posRightSet(int n)
{
  if(n&1)
    return 1;
  n = n ^ n&(n-1);
  int pos = 0;
  while(n)
  {
    n = n>>1;
    pos++;
  }
  return pos;
}

int posRightSet2(int n)
{
  if(n&1)
    return 1;
  n= n&-n;
  return log(n)+1;
  /*pos = 0;
  while(n)
  {
    n = n>>1;
    pos++
  }*/
}

int onlySetBitPos(int n)
{
  if(n & (n-1)!=0)
    return -1;
  return log(n)+1;
}

bool countSetBits(int n)    //PARITY
{
  bool parity  = false;
  while(n)
  {
    if(n&1)
    party = !parity;
    n = n>>1;
  }
}

bool countSetBitsOpt(int n)
{
  bool parity = false;
  while(n)
  {
    n = n&(n-1);
    parity = !parity;
  }
}

int main()
{
  int n = 7;
  countSetBits(n);
  countSetBitsOpt(n);
  return 0;
}
