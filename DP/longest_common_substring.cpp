#include<iostream>
#include<string>
#include<cstring>

using namespace std;

string longestCommonSubstring(string X,string Y)
{
  int m = X.length();
  int n = Y.length();
  int maxlength = 0;
  int endingIndex = m;
  int LCS[m+1][n+1];
  //memset(LCS,0,sizeof(LCS));
  for(int i=0;i<=m;i++)
    for(int j=0;j<=n;j++)
    {
      if(i==0||j==0)
      LCS[i][j]=0;
      else
      {
        if(X[i-1]==Y[j-1])
          LCS[i][j]=LCS[i-1][j-1]+1;
      }
      if(LCS[i][j]>maxlength)
      {
        maxlength = LCS[i][j];
        endingIndex = i;
      }
    }
  return X.substr(endingIndex-maxlength,maxlength);
}

int main()
{
  string X = "ABC";
  string Y = "BABA";
  string commonSubstring = longestCommonSubstring(X,Y);
  cout<<commonSubstring;
  return 0;
}
