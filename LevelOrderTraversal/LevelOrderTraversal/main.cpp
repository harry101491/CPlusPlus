//
//  main.cpp
//  LevelOrderTraversal
//
//  Created by Harshit Pareek on 11/3/16.
//  Copyright © 2016 CS2134. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};
// Inserting a node in the BST
TreeNode* InsertNode(TreeNode* root, int data)
{
    if(root == nullptr)
    {
        TreeNode* newNode;
        newNode = new TreeNode(data);
        root = newNode;
    }
    else
    {
        
        if(root->data > data)
        {
            root->left = InsertNode(root->left, data);
        }
        else
        {
            root->right = InsertNode(root->right, data);
        }
    }
    return  root;
}
// preorder printing in the tree
void preOrderPrinting(TreeNode* root)
{
    if(root == nullptr)
    {
        //cout << endl;
        return;
    }
    else
    {
        cout << root->data << " ";
        preOrderPrinting(root->left);
        preOrderPrinting(root->right);
    }
}
// level order traversal in the tree
void levelOrder(TreeNode* root)
{
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty())
    {
        if(que.front() != nullptr)
        {
            cout << que.front()->data << " ";
            que.push(que.front()->left);
            que.push(que.front()->right);
            que.pop();
        }
        else
        {
            que.pop();
        }
    }
}
int main()
{
    TreeNode* root = nullptr;
    //cout << "hi how are you?" << endl;
    root = InsertNode(root, 5);
    root = InsertNode(root, 2);
    root = InsertNode(root, 7);
    root = InsertNode(root, 6);
    root = InsertNode(root, 1);
    root = InsertNode(root, 3);
    //preOrderPrinting(root);
    levelOrder(root);
    cout << endl;
    /*queue<int> que;
    que.push(5);
    que.push(6);
    que.push(7);
    while(!que.empty())
    {
        int num = que.front();
        que.pop();
        cout<<"number is:" << num << endl;
    }*/
    return 0;
}
