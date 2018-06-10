#include<iostream>
#include<stack>

using namespace std;

struct node{
  int data;
  node *left;
  node *right;
};

node * createNewNode(int data)
{
  node *newNode = new node;
  newNode->data= data;
  newNode->left=NULL;
  newNode->right=NULL;
  return newNode;
}

void insert(node * &root,int data)
{
  node * newNode = createNewNode(data);
  if(root==NULL)
    {
      root = newNode;
      //cout<<"Root: "<<root->data;
      return;
    }
  if(data < root->data)
    insert(root->left,data);
  else
    insert(root->right,data);
}

void in(node *root)
{
  if(root==NULL)
    return;
  else
  in(root->left);
  cout<<root->data;
  in(root->right);
}

void pre(node *root)
{
  if(root==NULL)
    return;
  else
  cout<<root->data;
  pre(root->left);
  pre(root->right);
}

void post(node *root)
{
  if(root==NULL)
    return;
  else
  post(root->left);
  post(root->right);
cout<<root->data;
}

void pre_itr(node *root)
{
  if(root==NULL)
    return;
  stack<node*> s;
  s.push(root);
  while(!s.empty())
  {
    node *cur = s.top();
    s.pop();
    cout<<cur->data;
    if(cur->right)
      s.push(cur->right);
    if(cur->left)
      s.push(cur->push);
  }
}

void in_itr(node * root)
{
  if(root==NULL)
    return;
  node * cur = root;
  stack<node*> s;
  while(!s.empty()||cur!=NULL)
  {
    if(cur!=NULL)
    {
      s.push(cur);
      cur=cur->left;
    }
    else
    {
      cur = s.top();
      s.pop();
      cur = cur->right;
    }
  }
}

void level_itr()
{
  if(root==NULL)
    return;
  stack<node*> s;
  s.push(root);
  while(!s.empty())
  {
    node * cur = s.top();
    s.pop();
    cout<<cur->data;
    if(cur->right)
    s.push(cur->right);
    if(cur->left)
    s.push(cur->left);
  }
}

int main()
{
  node * root = NULL;
    insert(root,5);
    insert(root,6);
    insert(root,7);
    cout<<"Root: "<<root->data<<endl;
    //pre(root);
    pre_rec(root);
    return 0;
}
