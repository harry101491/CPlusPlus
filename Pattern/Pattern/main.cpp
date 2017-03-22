//
//  main.cpp
//  Pattern
//
//  Created by Harshit Pareek on 2/22/17.
//  Copyright © 2017 CS2134. All rights reserved.
//

#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter a positive integer"<<endl;
    cin>>n;
    for(int i=n;i>0;i--)
    {
        for(int j=0;j<n-i;j++)
        {
            cout<<" ";
        }
        for(int k=0;k<(2*i)-1;k++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=n-i; j>0;j--)
        {
            cout<<" ";
        }
        for(int k=0;k<(2*i)-1;k++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}
