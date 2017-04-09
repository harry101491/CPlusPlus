//
//  main.cpp
//  AllNodeKDis
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
void printK(Node*, int);
int printAllKTarget(Node*, Node*, int);

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
    //printInorder(root);
    printAllKTarget(root, root->left->right->right, 3);
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
        cout<<p->data<<" ";
        printInorder(p->right);
    }
}
// print all the nodes from the root with distance k
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

// the function to print out the all the nodes at the distance k
int printAllKTarget(Node* root, Node* target, int k)
{
    if(root == nullptr)
    {
        return -1;
    }
    else if(root == target)
    {
        printK(target, k);
        return 0;
    }
    int valL = printAllKTarget(root->left, target, k);
    
    if(valL != -1)
    {
        // the k distance from the target is equal to the root
        if(valL+1 == k)
        {
            cout<<root->data<<" ";
        }
        else
        {
            int distanceRemaining = k-valL-2;
            printK(root->right, distanceRemaining);
        }
        return 1+valL;
    }
    
    int valR = printAllKTarget(root->right, target, k);
    
    if(valR != -1)
    {
        if(valR+1 == k)
        {
            cout<<root->data<<" ";
        }
        else
        {
            int distanceRemaining = k-valR-2;
            printK(root->left, distanceRemaining);
        }
        return 1+valR;
    }
    
    return -1;
}
