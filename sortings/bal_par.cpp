#include<iostream>
#include<stack>

using namespace std;

bool bal_par(string str)
{
  stack <char> s;
  for(int i=0;i<str.length();i++)
  {
    if(str[i]=='('||str[i]=='['||str[i]=='{')
    {
      //cout<<"Pushed: "<<str[i]<<"......";
      s.push(str[i]);
    }
    else if(str[i]==')'||str[i]==']'||str[i]=='}')
    {
      if(s.empty()){
        //cout<<"Empty";
        return false;
      }
      else if(s.top()=='('&& str[i]==')'||
              s.top()=='{'&& str[i]=='}'||
              s.top()=='['&& str[i]==']')
        s.pop();
      else
        return false;
    }
  }
  if(s.empty())
    return true;
}

int main()
{
  string str="{([{[][]()}])}";
  //cout<<"Enter the string of paranthesis: ";
  //cin>>str;
  if(bal_par(str))
    cout<<"Balanced";
  else
    cout<<"Not Balanced";
  return 0;

}
