#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>

using namespace std;

int max(int a, int b)
{
  return (a>b) ? a:b;
}

int longestPalindrome(string X)
{
  int m = X.length();
  int LP[m][m];
  memset(LP,0,sizeof(LP));

  for(int i=0;i<m;i++)
    LP[i][i]=1;

  for(int length = 2;length<=m;length++)
  {
    for(int i=0;i<=m-length;i++)
    {
      int j = i+length-1;
      if(X[i]==X[j])
        LP[i][j]=LP[i+1][j-1]+2;
      else
        LP[i][j]=max(LP[i+1][j],LP[i][j-1]);
    }
  }
  return LP[0][m-1];
}

int main()
{
  string X= "ABBDCACB";
  cout<<"Palindrome of length: "<<longestPalindrome(X);
  return 0;
}
