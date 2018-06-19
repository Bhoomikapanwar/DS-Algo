#include<iostream>
#include<stack>
#include<stdio.h>

using namespace std;

struct node
{
    int data;
    node * left;
    node * right;
};

/*class BT
{
//public:
  //node * root;
public:
  //BT()
  //{
    //root = NULL;
    //root->left = NULL;
    //root->right= NULL;
  //}
  void insert(node * root,int data);
  void pre(node * root);
};*/

void pre(node * root)
{
  if(root==NULL)
  {
    cout<<"Hey";
    return;
  }
  //printf("%d\n",root->data);
  cout<<root->data;
  pre(root->left);
  pre(root->right);
}

void insert(node * &root, int data)
{
  if(root==NULL)
  {
    cout<<"Creating new Node";
    node *newNode = new node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    root = newNode;
    return;
  }
  insert(root->left,data);
  insert(root->right,data);
}


/*bool BST::insert(node*root, node *newNode)    //Insertion in Binary Tree can not be done using recursion(This recursion is following depth first approach)
{
  if(!root->left)
  {
      //cout<<"Left";
      root->left = newNode;
      return true;
  }
  if(!root->right)
  {
      //cout<<"Right";
      root->right = newNode;
      return true;
  }
  else{
    bool insLeft = insert(root->left,newNode);
    if(!insLeft)
    {
    bool insRight = insert(root->right,newNode);
    return insRight;
    }
    return insLeft;
  }
}*/


int main()
{
    node * root = NULL;
    //BT bin;
    insert(root,5);
    //insert(root,6);
    //insert(root,7);
    //cout<<root->data;
    pre(root);
    return 0;
}
