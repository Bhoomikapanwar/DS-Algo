#include<iostream>
#include<stack>

using namespace std;

bool dup(string str)
{
  stack<char> s;
  for(int i=0;i<str.length();i++)
    if(str[i]!=')')
    {
      s.push(str[i]);
    }
    else if(str[i]==')')
    {
      if(s.top()=='(')
        return true;
      while(s.top()!='(')
      {
        s.pop();
      }
        s.pop();
    }
    return false;
}
int main()
{
  string str="((x+y))+z";
  if(dup(str))
    cout<<"Dup present";
  else
    cout<<"No dup";
  return 0;
}
