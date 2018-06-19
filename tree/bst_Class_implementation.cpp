#include<stdio.h>
#include<iostream>
#include<queue>

using namespace std;

struct node{
  int data;
  node * left;
  node * right;
};

class BST{
  node * root;
public:
  BST(){
    root = NULL;
  }
  void insert(int data);
  void insert(node* root,node *newNode);
  void preorder();
  void preorder(node *root);
  void levelOrder();
  void levelOrder(node * root);
  void ancestor(int key);
  bool ancestor(node *root, int key);
};

void BST::insert(int data)
{
  node * newNode = new node;
  if(!newNode)
  {
    printf("Node could not be created\n");
    return;
  }
  //printf("\nNode created\n");
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  if(!root)
  {
    //cout<<"Root inserted";
    root = newNode;
    return;
  }
  else
  {
      insert(root,newNode);
  }
}

void BST::insert(node *root,node* newNode)
{
  queue<node*> q;
  q.push(root);
  while(!q.empty())
  {
    node * cur = q.front();
    q.pop();
    if(cur->left)
      q.push(cur->left);
    else
      {
        //cout<<"\nNode inserted at left";
        cur->left = newNode;
        return;
      }
    if(cur->right)
      q.push(cur->right);
    else
      {
        //cout<<"\nNode inserted at right";
        cur->right = newNode;
        return;
      }
  }
}

void BST::levelOrder()
{
  if(!root)
  {
    cout<<"Tree is empty";
    return;
  }
  levelOrder(root);
}

void BST::levelOrder(node *root)
{
  queue<node*> q;
  q.push(root);
  while(!q.empty())
  {
    node* cur = q.front();
    q.pop();
    cout<<cur->data<<" ";
    if(cur->left)
      q.push(cur->left);
    if(cur->right)
      q.push(cur->right);
  }
}

void BST::ancestor(int key)
{
  cout<<"\nPrinting ancestors... ";
  ancestor(root,key);
}

bool BST::ancestor(node *root,int key)
{
  if(!root)   //Base case
    return false;

  if(root->data == key)
    return true;

  bool left = ancestor(root->left,key);
  bool right = false;
  if(!left)
  {
    right = ancestor(root->right,key);
  }
  if(left || right)
    cout<<root->data;
  return (left || right);
}

void BST::preorder()
{
  if(!root)
  {
    cout<<"Tree is empty";
    return;
  }
  else
    preorder(root);
}

void BST::preorder(node *root)
{
  if(!root)
    return;
  cout<<root->data;
  preorder(root->left);
  preorder(root->right);
}

int main()
{
  BST tree;
  tree.insert(5);
  tree.insert(6);
  tree.insert(3);
  tree.insert(8);
  tree.insert(9);
  tree.insert(2);
  tree.levelOrder();
  tree.ancestor(9);
  //tree.preorder();
  return 0;
}
