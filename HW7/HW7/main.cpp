//
//  main.cpp
//  HW7
//
//  Created by Harshit Pareek on 3/19/17.
//  Copyright © 2017 CS2134. All rights reserved.
//

#include <iostream>

using namespace std;

void printTriangle(int);

int main()
{
    int n;
    cout<<"enter an integer:"<<endl;
    cin >> n;
    printTriangle(n);
    return 0;
}

void printTriangle(int n)
{
    if(n == 1)
    {
        cout<<"*"<<endl;
        cout<<"*"<<endl;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            cout<<"*";
        }
        cout<<endl;
        printTriangle(n-1);
        for(int i=1;i<=n;i++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}
