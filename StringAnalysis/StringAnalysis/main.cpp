//
//  main.cpp
//  StringAnalysis
//
//  Created by Harshit Pareek on 11/4/16.
//  Copyright © 2016 CS2134. All rights reserved.
//

// finding the maximum occurance of the character is O(n) as 26 is constant.
// we are taking only the 26 but always try and use 256 character.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int arrOfCharacter[26];

int main()
{
    string arr = "sample string";
    for(int i=0;i<26;i++)
    {
        arrOfCharacter[i] = 0;
    }
    for(int i=0;i<26;i++)
    {
        //cout << "hi" << endl;
        for(int j=0;j<arr.size();j++)
        {
            if(arr[j] == (char)'a'+i)
            {
                arrOfCharacter[i]++;
            }
        }
    }
    int max = 0;
    int index = 0;
    for(int i=0;i<26;i++)
    {
        //cout << "the value at the index : " << (char)('a'+i) << " is " << arrOfCharacter[i] << endl;
        
        if(max < arrOfCharacter[i])
        {
            max = arrOfCharacter[i];
            index = i;
            //cout << "the max value is :" << max << " the index is: "<< index << endl;
        }
    }
    
    cout <<" the element who has the maximum occurance is: " << (char)('a'+index) << endl;
    return 0;
}
