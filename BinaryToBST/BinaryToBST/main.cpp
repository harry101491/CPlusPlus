//
//  main.cpp
//  BinaryToBST
//
//  Created by Harshit Pareek on 3/21/17.
//  Copyright © 2017 CS2134. All rights reserved.
//

#include <iostream>
#include <algorithm>

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
bool isBST(Node*);
Node* deepestNode(Node*);
int height(Node*);

int main()
{
    Node* root = nullptr;
    root = insertNode(1);
    root->left = insertNode(2);
    root->right = insertNode(3);
    root->left->left = insertNode(4);
    root->left->right = insertNode(5);
    root->right->left = insertNode(6);
    root->right->right = insertNode(7);
    root->right->right->right = insertNode(8);
    //printInorder(root);
    cout<<"the deepest node of the tree is: "<<deepestNode(root)->data<<endl;
//    if(isBST(root))
//    {
//        cout<<"the given tree is BST"<<endl;
//    }
//    else
//    {
//        cout<<"the given tree is not a BST"<<endl;
//    }
//    cout<<endl;
    return 0;
}
// the function to prove that the given binary tree is BST or not.
bool isBST(Node* p)
{
    if(p->left == nullptr && p->right == nullptr)
    {
        return true;
    }
    else if(p->right == nullptr)
    {
        if(p->left->data < p->data)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(p->left == nullptr)
    {
        if(p->right->data > p->data)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        bool current = false;
        if(p->data > p->left->data && p->data < p->right->data)
        {
            current = true;
        }
        bool left = isBST(p->left);
        bool right = isBST(p->right);
        return ((left) && (right) && (current));
    }
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
Node* deepestNode(Node* root)
{
    if(root->left == nullptr && root->right == nullptr)
    {
        return root;
    }
    else
    {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if(leftHeight >= rightHeight)
        {
            return deepestNode(root->left);
        }
        else
        {
            return deepestNode(root->right);
        }
    }
}

int height(Node* root)
{
    if(root == nullptr)
    {
        return 0;
    }
    else
    {
        int childHeight = max(height(root->left), height(root->right));
        return 1+childHeight;
    }
}
