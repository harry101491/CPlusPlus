//
//  main.cpp
//  Testing
//
//  Created by Harshit Pareek on 9/1/16.
//  Copyright © 2016 CS1124. All rights reserved.
//

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

#define toStr(x) x
#define io(x) "cin>>"+x
#define i 0

using namespace std;

class Cat
{
private:
    const string name;
    const string color;
    double weight;
public:
    Cat(const string& name,const string& color, double weight):name(name),color(color),weight(weight){}
    void display() const
    {
        cout<<"the properties of the cat is: \n"<<"name : "<<name<<endl<<"color : "<<color<<endl<<"weight : "<<weight<<endl;
    }
};

/*class Vorlon
{
private:
    const string myName;
    size_t myValue;
public:
    Vorlon(const string& name, size_t value) : myValue(value),myName(name){
    }
    void display() const
    {
        cout<<"the name of the vorlon is:"<<myName<<endl;
        cout<<"the value of the vorlon is:"<<myValue<<endl;
    }
};

void simpleFunction(const Vorlon& vorlon)
{
    vorlon.display();
}
*/

int main(int argc, const char * argv[])
{
    int n;
    cin >> n;
    vector<int> v(n);
    return 0;
}