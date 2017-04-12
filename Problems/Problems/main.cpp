//
//  main.cpp
//  Problems
//
//  Created by Harshit Pareek on 4/12/17.
//  Copyright © 2017 CS2134. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int reverseNumber(int);

int main()
{
    int num;
    cout<<"Enter a number to reverse: "<<endl;
    cin >> num;
    cout << "the reversed number is: "<< reverseNumber(num)<<endl;
    return 0;
}

int reverseNumber(int num)
{
    int n = 0;
    bool flag = false;
    if(num < 0)
    {
        num = num*-1;
        flag = true;
    }
    while(num != 0)
    {
        int val = num%10;
        n = n*10 + val;
        num = num/10;
    }
    if(flag)
    {
        return -n;
    }
    else
    {
        return n;
    }
}
