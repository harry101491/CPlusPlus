//
//  main.cpp
//  MinHeapifyBST
//
//  Created by Harshit Pareek on 6/16/16.
//  Copyright © 2016 CS1124. All rights reserved.
//

#include <iostream>
using namespace std;

struct TreeNode // TreeNode Data Structure
{
    int key; // key value
    TreeNode* left; // left Subtree
    TreeNode* right; // right Subtree
    TreeNode(int key)
    {
        this->key = key;
        this->left = nullptr;
        this->right = nullptr;
    }
};
// utility function to check that the subtree is identical or not
bool isIdentical(TreeNode** root1,TreeNode** root2)
{
	if(*root1 == nullptr && *root2 == nullptr)
	{
		return true;
	}
	else if(*root1 == nullptr || *root2 == nullptr)
	{
		return false;
	}
	else
	{
		return ((*root1)->key == (*root2)->key) && isIdentical(&((*root1)->left),&((*root2)->left)) && isIdentical(&((*root1)->right),&((*root2)->right));
	}
}
// function to traverse the Tree T in a preorder fashion
bool traverse(TreeNode** T,TreeNode** S)
{
	if(*S == nullptr)
	{
		return true;
	}
	if(*T == nullptr)
	{
		return false;
	}
	if(isIdentical(T,S))
	{
		return true;
	}
	return traverse(&((*T)->left),S) || traverse(&((*T)->right),S);
}
void InsertNode(TreeNode** root,int key)
{
    TreeNode* newNode = new TreeNode(key);
    if(*root == nullptr)
    {
        *root = newNode;
    }
    else
    {
        if((*root)->key >= key)
        {
            InsertNode(&(*root)->left, key);
        }
        else
        {
            InsertNode(&(*root)->right, key);
        }
    }
}
void printPreOrder(TreeNode** root)
{
    if(*root == nullptr)
    {
        
    }
    else
    {
        cout<<(*root)->key<<" ";
        printPreOrder(&(*root)->left);
        printPreOrder(&(*root)->right);
    }
}
int main()
{
    cout<<"----------------------------- Finding one tree is Subtree to another ----------------"<<endl;
    TreeNode* root1 = nullptr;
    TreeNode* root2 = nullptr;
    InsertNode(&root1, 26);
    InsertNode(&root1, 10);
    InsertNode(&root1, 4);
    InsertNode(&root1, 5);
    InsertNode(&root1, 18);
    InsertNode(&root1, 27);
    InsertNode(&root2, 10);
    InsertNode(&root2, 4);
    InsertNode(&root2, 5);
    InsertNode(&root2, 18);
    cout<<"the preorder for root 1"<<endl;
    printPreOrder(&root1);
    cout<<endl;
    cout<<"the preorder for root 2"<<endl;
    printPreOrder(&root2);
    cout<<endl;
    cout<<"In given two trees second one is subtree of first one or not"<<endl;
    if(traverse(&root1,&root2))
    {
    	cout<<"yes second is subtree of first one"<<endl;
    }
    else
    {
    	cout<<"no second one is not subtree of first one"<<endl;
    }
    return 0;
}
