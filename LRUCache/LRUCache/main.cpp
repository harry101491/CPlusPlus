//
//  main.cpp
//  LRUCache
//
//  Created by Harshit Pareek on 10/16/16.
//  Copyright © 2016 CS2134. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>

using namespace std;

struct Node{
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
    Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
    
protected:
    map<int,Node*> mp; //map the key to the node in the linked list
    int cp;  //capacity
    Node* tail; // double linked list tail pointer
    Node* head; // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0; //get function
    //virtual void print() = 0;
    
};

class LRUCache : public Cache
{
public:
    LRUCache(int capacity)
    {
        cp = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
    }
    void set(int key,int value)
    {
        if(mp.size() == 0) // when the cache is empty
        {
            // new node
            Node* p = new Node(key,value);
            
            // inserting into the map at beginning
            map<int,Node*>::iterator begin = mp.begin();
            mp.insert(begin,pair<int,Node*>(key,p));
            
            // linking it with the doubly linked list
            head->next = p;
            tail->prev = p;
            p->next = tail;
            p->prev = head;
        }
        else if(mp.find(key) == mp.end() && mp.size() > 0 && mp.size() < cp) // miss no key present
        {
            // new node
            Node* p = new Node(key,value);
            
            // inserting in the beginning
            map<int,Node*>::iterator begin = mp.begin();
            mp.insert(begin,pair<int,Node*>(key,p));
            
            // linking it with the doubly linked list
            p->next = head->next;
            p->prev = head;
            head->next->prev = p;
            head->next = p;
        }
        else if(mp.find(key) == mp.end() && mp.size() > 0 && mp.size() >= cp) // miss but there is no space
        {
            // deleting the least recently used element
            mp.erase(tail->prev->key);
            
            // delete node from the last in doubly linked list
            Node* p = tail->prev;
            tail->prev = p->prev;
            p->prev->next = tail;
            delete p;
            
            // new node
            Node* p_new = new Node(key,value);
            
            // inserting in the beginning
            map<int,Node*>::iterator begin = mp.begin();
            mp.insert(begin,pair<int,Node*>(key,p_new));
            
            // linking it with the doubly linked list
            p_new->next = head->next;
            p_new->prev = head;
            head->next->prev = p_new;
            head->next = p_new;
        }
        else if(mp.find(key) != mp.end()) // hit the key is already present there
        {
            if(head->next->key == key)
            {
                // already in correct position
            }
            else
            {
                // deleting the key from any other position of the list
                mp.erase(key);
                
                // deleting from the linked list also
                map<int,Node*>::iterator pos = mp.find(key);
                Node* p = pos->second;
                p->next->prev = p->prev;
                p->prev->next = p->next;
                delete p;
                
                // inserting in the beginning
                Node* p_new = new Node(key,value);
                
                map<int,Node*>::iterator begin = mp.begin();
                mp.insert(begin,pair<int,Node*>(key,p_new));
                
                // linking it with the doubly linked list
                p_new->next = head->next;
                p_new->prev = head;
                head->next->prev = p_new;
                head->next = p_new;
            }
        }
    }
    int get(int key)
    {
        if(mp.find(key) != mp.end()) // hit there is key present
        {
            map<int,Node*>::iterator pos = mp.find(key);
            int value = pos->second->value;
            if(head->next->key == key)
            {
                // already in correct position
                return value;
            }
            else
            {
                // deleting the key from any other position of the list
                mp.erase(key);
                
                // deleting from the linked list also
                Node* p = pos->second;
                p->next->prev = p->prev;
                p->prev->next = p->next;
                delete p;
                
                // inserting in the beginning
                Node* p_new = new Node(key,value);
                
                map<int,Node*>::iterator begin = mp.begin();
                mp.insert(begin,pair<int,Node*>(key,p_new));
                
                // linking it with the doubly linked list
                p_new->next = head->next;
                p_new->prev = head;
                head->next->prev = p_new;
                head->next = p_new;
                return value;
            }
        }
        else
        {
            return -1;
        }
    }
    /*
     class LRUCache:public Cache{
     public:
     LRUCache(int i):Cache(){
     cp = i;
     head = nullptr;
     tail = nullptr;
     }
     void set(int k,int v){
     if(cp <= 0)return;
     if(mp.size() == 0){
     Node *node = new Node(k,v);
     InsertIntoHead(node);
     mp.insert(make_pair(k,node));
     }
     else if(mp.find(k)!=mp.end()){
     auto it = mp[k];
     it->value = v;
     InsertIntoHead(it);
     }
     else if(mp.size() < cp){
     Node *node = new Node(k,v);
     InsertIntoHead(node);
     mp.insert(make_pair(k,node));
     }
     else{
     auto it = tail;
     mp.erase(it->key);
     LinkedListDelete(it);
     delete it;
     Node *node = new Node(k,v);
     InsertIntoHead(node);
     mp.insert(make_pair(k,node));
     }
     }
     int get(int k){
     if(mp.find(k) != mp.end()){
     InsertIntoHead(mp[k]);
     return mp[k]->value;
     }
     else return -1;
     }
     private:
     void LinkedListDelete(Node* node){
     if(!node)return;
     if(node-> prev)
     {
     node->prev->next = node->next;
     }
     if(node->next)
     {
     node->next->prev = node->prev;
     }
     if(node == head)
     {
     head = node->next;
     }
     if(node == tail)
     {
     tail = node->prev;
     }
     }
     void InsertIntoHead(Node* node)
     {
     if(!node)return;
     LinkedListDelete(node);
     if(head)
     head->prev = node;
     node->next = head;
     node->prev = nullptr;
     if(!tail) tail = node;
     head = node;
     }
     };
     */
    /*void print()
    {
        // printing of map
        cout<<"--------------the printing of the map-------------"<<endl;
        for(map<int,Node*>::iterator it = mp.begin();it != mp.end();it++)
        {
            cout<<" key value: "<<it->first<<" Node's key "<<it->second->key<<" Node's value "<<it->second->value<<endl;
        }
        // printing of doubly linked list
        //cout<<"head key and head value is:"<<head->key<<head->value<<endl;
        cout<<"--------------the printing of the doubly linked list-------------"<<endl;
        Node* p = head->next;
        while(p->next != nullptr)
        {
            cout<<"key:"<<p->key<<" value: "<<p->value<<endl;
            p = p->next;
        }
    }*/
};

int main()
{
    int n, capacity,i;
    cin >> n >> capacity;
    LRUCache l(capacity);
    for(i=0;i<n;i++) {
        string command;
        cin >> command;
        if(command == "get") {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        }
        else if(command == "set") {
            int key, value;
            cin >> key >> value;
            l.set(key,value);
        }
    }
    return 0;
}
