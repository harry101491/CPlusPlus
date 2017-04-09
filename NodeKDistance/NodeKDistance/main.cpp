//
//  main.cpp
//  NodeKDistance
//
//  Created by Harshit Pareek on 3/22/17.
//  Copyright © 2017 CS2134. All rights reserved.
//

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* insertNode(int);
void printInorder(Node*);
void printK(Node* ,int);
Node* searchNode(Node*, int);
void printKTarget(Node*, int, int);

int main()
{
    Node* root = nullptr;
    root = insertNode(20);
    root->left = insertNode(8);
    root->right = insertNode(22);
    root->left->left = insertNode(4);
    root->left->right = insertNode(12);
    root->left->right->left = insertNode(10);
    root->left->right->right = insertNode(14);
    printKTarget(root, 8, 2);
    //Node* p = searchNode(root, 8);
    //if(!p)
    //{
    //    cout<<"Item is not in the tree"<<endl;
    //}
    //else
    //{
    //    cout<<"the data element in the tree is:"<<p->left->data<<endl;
    //}
    //printInorder(root);
    //printK(root, 0);
    cout<<endl;
    return 0;
}

Node* insertNode(int data)
{
    Node* newNode = nullptr;
    newNode = new Node(data);
    return newNode;
}

void printInorder(Node* p)
{
    if(p == nullptr)
    {
        return;
    }
    else
    {
        printInorder(p->left);
        cout<<p->data;
        printInorder(p->right);
    }
}

void printK(Node* p, int k)
{
    if(p == nullptr)
    {
        return;
    }
    else if(k == 0)
    {
        cout<<p->data<<" ";
    }
    else
    {
        printK(p->left, k-1);
        printK(p->right, k-1);
    }
}

Node* searchNode(Node* p, int data)
{
    if(p == nullptr)
    {
        // the element is not found
        return nullptr;
    }
    else if(p->data == data)
    {
        return p;
    }
    else
    {
        Node* left = searchNode(p->left, data);
        Node* right = searchNode(p->right, data);
        if(!left && right)
        {
            return right;
        }
        else
        {
            return left;
        }
        
    }
}

void printKTarget(Node* p, int data, int k)
{
  if(p == nullptr)
  {
      return;
  }
  else
  {
      Node* p1 = searchNode(p, data);
      if(p1 == nullptr)
      {
          cout<<"the data element is not present in the tree"<<endl;
          return;
      }
      else
      {
          printK(p1, k);
      }
  }
}
