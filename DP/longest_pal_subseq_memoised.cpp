#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>

using namespace std;

int max(int a,int b)
{
  return (a>b) ? a:b;
}

int longestPalindrome(string X,int i,int j,int m)
{
  int LP[m][m];
  if(i==0)
  memset(LP,0,sizeof(LP));
  if(i>j)
    return 0;
  if(i==j)
   return 1;

  if(LP[i][j]==0)
  {
    //cout<<"Hey";
    if(X[i]==X[j])
    LP[i][j] = longestPalindrome(X,i+1,j-1,m)+2;
    else
    LP[i][j] = max(longestPalindrome(X,i,j-1,m),longestPalindrome(X,i+1,j,m));
  }
  return LP[0][m-1];
}

int main()
{
  string X = "ABBDCACB";
  int m = X.length();
  int LP[m][m];
  cout<<"Longest Palindrome is: "<< longestPalindrome(X,0,m-1,m);
  return 0;
}
