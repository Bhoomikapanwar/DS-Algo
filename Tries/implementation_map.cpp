#include<iostream>
#include<unordered_map>

using namespace std;

struct Trie
{
  bool isLeaf;
  unordered_map<char,Trie*> map;
};

class Trie_tree
{
  Trie *head;
public:
  Trie_tree(){
    head = NULL;
  }
  Trie * getNewNode();
  void insert(char *str);
  bool search(char *str);
};


Trie * Trie_tree::getNewNode()
{
  Trie * newNode = new Trie;
  newNode->isLeaf = false;
}

void Trie_tree::insert(char *str)
{
  if(head==NULL)
    head = getNewNode();
  Trie * cur = head;
  while(*str)
  {
    if(cur->map.find(*str)==cur->map.end())
      cur->map[*str]=getNewNode();

    cur = cur->map[*str];
    str++;
  }
  cur->isLeaf = true;
}

bool Trie_tree::search(char *str)
{
  if(head == NULL)
    return false;

  Trie * cur = head;
  while(*str)
  {
    cur =  cur->map[*str];
    if(cur==NULL)
      return false;
    str++;
  }
  return cur->isLeaf;
}


int main()
{
  Trie_tree tree;
  tree.insert("Hello");
  tree.insert("Hey");
  tree.insert("Hi");
  if(tree.search("Him"))
    cout<<"String found";
  else
    cout<<"Not found";
  return 0;
}
