#include<stdio.h>
#include<string>
#include<cstring>

using namespace std;

int max(int a,int b,int c)
{
  int max = a;
  if(b>max)
  max=b;
  if(c>max)
  max=c;
  return max;
}

int LCS(string X,string Y,string Z)
{
  int m = X.length();
  int n = Y.length();
  int o = Z.length();
  int LCS[m+1][n+1][o+1];
  for(int i=0;i<=m;i++)
    for(int j=0;j<=n;j++)
      for(int k=0;k<=o;k++)
      {
        if(i==0||j==0||k==0)
        LCS[i][j][k]=0;
        else
        {
          if(X[i-1]==Y[j-1] && Y[j-1]==Z[k-1])
            LCS[i][j][k]=LCS[i-1][j-1][k-1]+1;
          else
            LCS[i][j][k]=max(LCS[i-1][j][k],LCS[i][j-1][k],LCS[i][j][k-1]);
        }
      }
  return LCS[m][n][o];
}


int main()
{
  string X = "XYZ";
  string Y = "XYZA";
  string Z = "XAY";
  printf("LCS: %d ",LCS(X,Y,Z));
  return 0;
}
