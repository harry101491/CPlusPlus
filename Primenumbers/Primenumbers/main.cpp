//
//  main.cpp
//  Primenumbers
//
//  Created by Harshit Pareek on 10/6/16.
//  Copyright © 2016 CS2134. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>

using namespace std;

int main()
{
    int n = 360;
    int num = n;
    map<int, int> mapOfInts;
    mapOfInts[2] = 0;
    mapOfInts[3] = 0;
    for(int i = 2; i < n; i++)
    {
        for(int j = 2; j*j<=i;j++)
        {
            if(i%j == 0)
            {
                break;
            }
            else if(j+1 > sqrt(i))
            {
                mapOfInts[i] = 0;
            }
        }
    }
    for(map<int,int>::iterator i = mapOfInts.begin();i != mapOfInts.end() && num != 0;)
    {
        if(num % i->first == 0)
        {
            i->second++;
            num = num/i->first;
            i = mapOfInts.begin();
            
        }
        else
        {
            i++;
        }
    }
    cout <<"factor: power:"<<endl;
    for(map<int,int>::iterator i = mapOfInts.begin();i != mapOfInts.end();i++)
    {
        if(i->second != 0)
        {
            cout<<i->first<<" \t\t "<<i->second<<endl;
        }
    }
    return 0;
}
