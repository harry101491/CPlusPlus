//
//  main.cpp
//  SpacesInString
//
//  Created by Harshit Pareek on 4/8/17.
//  Copyright © 2017 CS2134. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printString(char*, string, int, int);
int length(char*);

int main()
{
    
    char str1[] = "ABCD";
    string dummy;
    int len = length(str1);
    printString(str1,dummy,len, 1);
    return 0;
}

void printString(char* str,string dummy, int size, int n)
{
    if(size == n)
    {
        cout<<str[0];
        cout<<dummy<<endl;
        return;
    }
    else
    {
        // without space
        printString(str, dummy+str[n], size, n+1);
        printString(str, dummy+" "+str[n], size, n+1);
    }
}

int length(char* str)
{
    int i=0;
    while(str[i] != '\0')
    {
        i++;
    }
    return i;
}
