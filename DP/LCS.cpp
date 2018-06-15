#include<iostream>
#include<stdio.h>

using namespace std;

int max(int a,int b)
{
  int max = a;
  if(b>max)
  max = b;
  return max;
}

int LCS(string X, string Y)
{
  int m = X.length();
  //cout<<"m"<<m;
  int n = Y.length();
  //cout<<"n"<<n;
  int LCS[m+1][n+1];
  for(int i=0;i<=m;i++)
    LCS[i][0]=0;

  for(int j=0;j<=n;j++)
    LCS[0][j]=0;

  for(int i=1;i<=m;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(X[i-1]==Y[j-1])
      LCS[i][j]=1+LCS[i-1][j-1];
      else
      LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
    }
  }
  return LCS[m][n];
}

int main()
{
  string X="XMJYAUZ";
  string Y="MZJAWXU";
  printf("%d\n",LCS(X,Y));
  return 0;
}
