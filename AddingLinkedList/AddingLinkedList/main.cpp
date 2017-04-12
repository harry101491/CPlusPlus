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
Node* makeNumber();
Node* sumList(Node*, Node*);

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
    Node* sumHead = sumList(head1, head2);
    printList(sumHead);
    return 0;
}
Node* sumList(Node* firstHead, Node* secondHead)
{
    int carry = 0;
    Node* prev = nullptr;
    Node* temp;
    Node* sumHead = nullptr;
    while(firstHead != nullptr || secondHead != nullptr)
    {
        int sum = carry + ((firstHead) ? firstHead->data : 0) + ((secondHead) ? secondHead->data : 0);
        if(sum >= 10)
        {
            carry = 1;
            sum = sum % 10;
        }
        else
        {
            carry = 0;
        }
        temp = new Node();
        temp->data = sum;
        if(sumHead != nullptr)
        {
            prev->next = temp;
        }
        else
        {
            sumHead = temp;
        }
        prev = temp;
        if(firstHead)
        {
            firstHead = firstHead->next;
        }
        if(secondHead)
        {
            secondHead = secondHead->next;
        }
    }
    return sumHead;
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
