#include<iostream>
#include<algorithm>
using namespace std;
int max(int a, int b)
{
  int max = a;
  if(b>max)
    max=b;
  return max;
}

int longestPalindrome(string str)
{
  int n = str.length();
  int l[n-1][n-1];
  for(int i=0;i<n;i++)    //For length one
  {
      l[i][i] = 1;
  }

  for(int length=2;length<=n;length++)    //For length l
  {
    for(int i=0;i<=n-length;i++)
    {
      int j = i +(length-1);
      if(i!=j)
      {
      if(length==2 && str[i]==str[j])
      l[i][j]=2;
      else if (str[i]==str[j])
      l[i][j] = l[i+1][j-1] + 2;
      else
      l[i][j] = max(l[i][j-1],l[i+1][j]);
      }
      //cout<<"l["<<i<<"]["<<j<<"]: "<<l[i][j]<<endl;
    }
  }
  return l[0][n-1];
}

bool rotatedPalindrome(string str)
{
    cout<<str+str;
    if(longestPalindrome(str+str)==2*(str.length()))
      return true;
    return false;
}


int main()
{
  string str = "ABBA";
  rotate(str.begin(),str.begin()+2,str.end());
  if(rotatedPalindrome(str))
    cout<<"Rotated string is a palindrome";
  else
  cout<<"Not a palindrome";
  //cout<<"Length of the string: "<<longestPalindrome(str);
  return 0;
}
