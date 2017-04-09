//
//  main.cpp
//  AddingLinkedList
//
//  Created by Harshit Pareek on 4/8/17.
//  Copyright © 2017 CS2134. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* createNewNode(int);
void printList(Node*);
Node* findPosition(Node*);
Node* makeNumber();
Node* sumList(Node*, Node*, Node*, Node*, Node*);

int main()
{
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    head1 = makeNumber();
    head2 = makeNumber();
    cout<<"the first number is: "<<endl;
    printList(head1);
    cout<<"the second number is: "<<endl;
    printList(head2);
    // make fast and slow pointers for the list1 and list2
    Node* fast1 = head1->next;
    Node* slow1 = head1;
    Node* fast2 = head2->next;
    Node* slow2 = head2;
    Node* sumHead = nullptr;
    sumHead = sumList(fast1, slow1, fast2, slow2, sumHead);
    printList(sumHead);
    return 0;
}
Node* sumList(Node* fast1, Node* slow1, Node* fast2, Node* slow2, Node* sumHead)
{
    if(fast1 == nullptr && fast2 == nullptr)
    {
        sumHead = new Node();
        sumHead->data = 0;
        sumHead->next = nullptr;
        Node* newNode = new Node();
        int val = slow1->data + slow2->data + sumHead->data;
        if(val >= 10)
        {
            sumHead->data = val-10;
            newNode->data = 1;
            newNode->next = sumHead;
            sumHead = newNode;
        }
        else
        {
            sumHead->data = val;
            newNode->data = 0;
            newNode->next = sumHead;
            sumHead = newNode;
        }
        return sumHead;
    }
    else if(fast1 == nullptr && fast2 != nullptr)
    {
        return sumList(fast1, slow1, fast2->next, fast2, sumHead);
    }
    else if(fast1 != nullptr && fast2 == nullptr)
    {
        return sumList(fast1->next, fast1, fast2, slow2, sumHead);
    }
    else
    {
        sumHead = sumList(fast1->next, fast1, fast2->next, fast2, sumHead);
        int val1 = slow1->data + slow2->data + sumHead->data;
        Node* newNode = new Node();
        if(val1 >= 10)
        {
            sumHead->data = val1-10;
            newNode->data = 1;
            newNode->next = sumHead;
            sumHead = newNode;
        }
        else
        {
            sumHead->data = val1;
            newNode->data = 0;
            newNode->next = sumHead;
            sumHead = newNode;
        }
        return sumHead;
    }
}
Node* createNewNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}
Node* findPosition(Node* head)
{
    if(head == nullptr)
    {
        return nullptr;
    }
    else
    {
        Node* p = head;
        while(p->next != nullptr)
        {
            p = p->next;
        }
        return p;
    }
}
void printList(Node* head)
{
    if(head == nullptr)
    {
        return;
    }
    else
    {
        Node* p = head;
        while(p != nullptr)
        {
            cout<<p->data;
            p = p->next;
        }
        cout<<endl;
    }
}
Node* makeNumber()
{
    Node* head = nullptr;
    int dataPoint;
    cout<<"Enter the elements to add and add -1 for exit:"<<endl;
    cin>>dataPoint;
    while (dataPoint != -1)
    {
        if(head != nullptr)
        {
            Node* p = findPosition(head);
            p->next = createNewNode(dataPoint);
        }
        else
        {
            head = createNewNode(dataPoint);
        }
        cin >> dataPoint;
    }
    return head;
}
