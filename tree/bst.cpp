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
      s.push(cur->left);
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

void level_itr(node *root)
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

void post_itr(node *root)
{
  if(root==NULL)
    return;
  stack <node*> s;
  s.push(root);
  node * cur;
  node * prev = NULL;
  while(!s.empty())
  {
    cur = s.top();
    s.pop();
    if(!prev || prev->left==cur || prev->right==cur)
    {
      if(cur->left)
        s.push(cur->left);
      if(cur->right)
        s.push(cur->right);
    }
    else if(cur->left==prev)
    {
      if(cur->right)
        s.push(cur->right);
    }
    else if(cur->right==prev)
    {
      cout<<cur->data;
    }
  }
  prev = cur;
}

bool identical(node *root1,node* root2)
{
  if(root1==NULL&&root2==NULL)
    return true;
  if(root1==NULL || root2 == NULL)
    return false;
  return root1->data == root2->data && identical(root1->left,root2->left) && identical(root1->right,root2->right);
}

bool identical_itr(node *root1,node *root2)
{
  if(root1==NULL && root2 ==NULL)
    return true;
  if(root1==NULL || root2 == NULL)
    return false;
  stack<pair<node*,node*>> s;
  s.push({root1,root2});
  while(!s.empty())
  {
    node * x = s.top().first;
    node * y = s.top().second;
    s.pop();
    if(x->data==y->data)

  }

}

int main()
{
  node * root1 = NULL;
  node * root2 = NULL;
    insert(root1,5);
    insert(root1,6);
    insert(root1,7);

    post_itr(root1);

    insert(root2,5);
    insert(root2,6);
    insert(root2,8);
    if(identical(root1,root2))
      cout<<"Identical";
    else
      cout<<"Not identical";

    //cout<<"Root: "<<root->data<<endl;
    //pre(root1);
    //pre(root2);
    //pre_itr(root);
    return 0;
}
