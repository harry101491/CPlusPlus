//
//  main.cpp
//  2134HW1
//
//  Created by Harshit Pareek on 9/23/16.
//  Copyright © 2016 CS2134. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

const size_t CAPACITY = 16;

template <class T>
class DynArray
{
private:
    vector<T> vec;
    size_t cap;
    size_t s;
public:
    DynArray();
    DynArray(size_t);
    DynArray(DynArray&);
    ~DynArray();
    void push_back(const T&);
    void pop_back();
    size_t size();
    DynArray& operator = (DynArray&);
    T& operator [] (size_t);
    void capacity();
    void resize();
};

template<class T>
DynArray<T>::DynArray()
{
    s = 0;
    cap = CAPACITY;
    vec = vector<T>(cap);
}
template<class T>
DynArray<T>::DynArray(size_t size)
{
    cap = size;
    s = 0;
    vec = vector<T>(size);
}
template<class T>
DynArray<T>::DynArray(DynArray& arr)
{
    if(arr.s == 0)
    {
        DynArray();
    }
    else
    {
        this->cap = arr.c;
        this->s = arr.s;
        vec = vector<T>(arr);
    }
}
template<class T>
DynArray<T>::~DynArray()
{
    this->s = 0;
    this->cap = 0;
    ~vector<T>(vec);
}

/*template <typename T>
const T& maxFun(const T& a, const T& b)
{
    return a>b ? a : b;
}
*/
/*class CombinationLock
{
private:
    vector<int> combination;
    enum state {o='o',c='c'};
    state currentState;
public:
    CombinationLock(int first,int second, int third)
    {
        combination.push_back(first);
        combination.push_back(second);
        combination.push_back(third);
        currentState = state::c;
    }
    CombinationLock(CombinationLock& x) = delete;
    CombinationLock& operator = (CombinationLock& y) = delete;
    void open(int first,int second,int third)
    {
        if(combination[0] == first && combination[1] == second && combination[2] == third && currentState == state::c)
        {
            currentState = state::o;
            cout<<"The combination is correct"<<endl;
        }
        else
        {
            cout<<"The combination is not correct. Please, try again"<<endl;
        }
    }
    void changeCombo(int first, int second, int third)
    {
        if(currentState == state::o)
        {
            combination[0] = first;
            combination[1] = second;
            combination[2] = third;
            currentState = state::c;
            cout<<"the combination is changed"<<endl;
        }
        else
        {
            cout<<"please, open the lock first and then change the combination"<<endl;
        }
    }
    void print() const
    {
        cout<<"the combination is:"<<endl;
        for(size_t i=0;i<combination.size();i++)
        {
            cout<<combination[i]<<endl;
        }
    }
};
*/

int main()
{
    /*int a = 30;
    int b = 20;
    cout<<"the max value when the type is int is:"<<maxFun(a,b)<<endl;
    float a1 = 30.0;
    float b1 = 20.0;
    cout<<"the max value when the type is float is:"<<maxFun(a1,b1)<<endl;
    double a2 = 40.0;
    double b2 = 23.0;
    cout<<"the max value when the type is double is:"<<maxFun(a2,b2)<<endl;
     */
    /*CombinationLock lock(2,3,4);
    //CombinationLock lock1(lock);
    CombinationLock lock1(3,4,5);
    //lock = lock1;
    lock.open(2,3,4);
    lock.changeCombo(4, 5, 6);
    lock.print();*/
    return 0;
}
