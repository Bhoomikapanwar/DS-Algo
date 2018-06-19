#include<iostream>
#include<stdio.h>

using namespace std;
#define maxlength 20
int LCS[maxlength][maxlength];

int max(int a,int b)
{
  int max = a;
  if(b>max)
  max = b;
  return max;
}


string printLCS(string X,string Y,int i,int j)
{
  if(i==0||j==0)
    return string("");
  if(X[i-1]==Y[j-1])
  return printLCS(X,Y,i-1,j-1) + X[i-1];
  else if(LCS[i-1][j]>LCS[i][j-1])
  return printLCS(X,Y,i-1,j);
  else
  return printLCS(X,Y,i,j-1);
}

string printLCSIterative(string X,string Y,int m,int n)   //Self-written
{
  string subs="";
  int i=m,j=n;
  while(i!=0&&j!=0)
  {
      if(X[i-1]==Y[j-1])
      {
        cout<<"\n"<<X[i-1];
        subs  = subs + X[i-1];
        i--;
        j--;
      }
      else
      {
        if(LCS[i-1][j]>LCS[i][j-1])
        i--;
        else
        j--;
      }
  }
  return subs;
}

int longestCommonSubsequence(string X, string Y)
{
  int m = X.length();
  //cout<<"m"<<m;
  int n = Y.length();
  //cout<<"n"<<n;
  //int LCS[m+1][n+1];

  for(int i=0;i<=m;i++)
  {
    for(int j=0;j<=n;j++)
    {
      if(i==0||j==0)
      LCS[i][j]=0;
      else
      {
        if(X[i-1]==Y[j-1])
        LCS[i][j]=LCS[i-1][j-1]+1;
        else
        LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
      }
    }
  }
  //cout<<"Subsequence is: "<<printLCS(X,Y,m,n);
  cout<<"Subsequence is: "<<printLCSIterative(X,Y,m,n);
  return LCS[m][n];
}

int main()
{
  string X="XMJYAUZ";
  string Y="MZJAWXU";
  printf("\nLength of string is: %d",longestCommonSubsequence(X,Y));
  return 0;
}
