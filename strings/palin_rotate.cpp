#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

bool ispalindrome(string str, int start, int end)
{
  while(start<end)
  {
    if(str[start]!=str[end])
    {
      return false;
    }
    start++;
    end--;
  }
  //cout<<"Oh yes";
  return true;
}

bool isrotpal(string str)
{
    for(int i=0;i<str.length();i++)
    {
      rotate(str.begin(),str.begin()+1,str.end());
      cout<<"Possible rotation: "<<str<<endl;
      if(ispalindrome(str,0,str.length()-1))
      {
        cout<<str;
        return true;
      }
    }
    return false;
}

int main()
{
  string str ="ABCDCBA";
  rotate(str.begin(),str.begin()+2,str.end());
  cout<<"Rotated string: "<<str<<endl;
  if(isrotpal(str))
    cout<<"Rotated string is a palindrome: "<<str;
  else
    cout<<"Rotated string is not a palindrome";
  return 0;
}
