#include<iostream>
#include<stack>
#include<stdio.h>

using namespace std;

void decode(string str)
{
stack<int> s;
int no = 1,temp,count=0;
s.push(1);
for(int i=0;i<str.length();)
{
if(str[i]=='I')
{
  no++;
  s.push(no);
  i++;
}
else
{
  count = 0;
while(str[i]=='D'&& i<str.length())
{
no++;
i++;
count++;
}
count++;
temp = no;
s.pop();
while(count)
{
  s.push(no);
  no--;
  count--;
}
no = temp;
}
}

while(!s.empty())
{
cout<<s.top();
s.pop();
}
}

int main()
{
string str = "IDIDII";
decode(str);
return 0;
}
