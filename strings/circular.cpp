#include<iostream>
#include<stdio.h>
using namespace std;

bool move(string str)
{
  int x=0,y=0,x_step=0,y_step=1;
  for(int i=0;i<str.length();i++)
  {

    if(str[i]=='M')
    {
      y=y+y_step;
      x=x+x_step;
      printf("x %d:",x );

      printf("y %d:",y );
      cout<<endl;
    }
    else if(str[i]=='L')
    {
      y_step=0;
      x_step=-1;
    }
    else
    {
      y_step=0;
      x_step=1;
    }
  }
  if((x==0)&&(y==0))
    return true;
  else
    return false;
}

int main()
{
  string str = "MMRMMRMMRMM";
  if(move(str))
    printf("Move is circular");
  else
    printf("Move is not circular");
  return 0;
}
