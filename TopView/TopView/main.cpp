//
//  main.cpp
//  TopView
//
//  Created by Harshit Pareek on 10/21/16.
//  Copyright © 2016 CS2134. All rights reserved.
//

#include <iostream>
#include <cstddef>
#include <vector>

using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            }
            else {
                Node* cur;
                if(data <= root->data){
                    cur = insert(root->left, data);
                    root->left = cur;
                }
                else{
                    cur = insert(root->right, data);
                    root->right = cur;
                }
                
                return root;
            }
        }
    void print(Node* root)
    {
        if(root == NULL)
        {
            return;
        }
        else
        {
            print(root->left);
            cout<<root->data<<" ";
            print(root->right);
        }
    }
    void topView(Node* root)
    {
        if(root == nullptr)
        {
            return;
        }
        vector<int> stack;
        Node* p = root;
        while(p != nullptr)
        {
            stack.push_back(p->data);
            p = p->left;
        }
        for(vector<int>::reverse_iterator rIt = stack.rbegin(); rIt != stack.rend();rIt++)
        {
            cout<<*rIt<<" ";
        }
        stack.clear();
        p = root->right;
        while(p != nullptr)
        {
            stack.push_back(p->data);
            p = p->right;
        }
        for(vector<int>::iterator it = stack.begin(); it != stack.end();it++)
        {
            cout<<*it<<" ";
        }
    }
    
};
int main() {
    Solution myTree;
    Node* root = nullptr;
    int t;
    int data;
    
    cin >> t;
    
    while(t-- > 0){
        cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.topView(root);
    cout<<endl;
    return 0;
}
