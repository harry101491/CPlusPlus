//
//  main.cpp
//  hw01
//
//  Created by Harshit Pareek on 9/3/16.
//  Copyright © 2016 CS1124. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

char decrypt(char,int);
void decryptLineAndReverse();

int main(int argc, const char * argv[])
{
    // creating the file stream
    ifstream ifs("/Users/harshitpareek/Downloads/encrypted.txt");
    if(!ifs)
    {
        cerr << "File not able to be opened" << endl;
    }
    int shift;
    vector<string> vecOfString;
    ifs >> shift;
    
    string line;
    getline(ifs,line);
    
    while(getline(ifs,line))
    {
        for(size_t i=0;i<line.length();i++)
        {
            if(line[i] >= 'a' && line[i] <= 'z')
            {
                if(line[i]-shift < 'a')
                {
                    int diff = line[i] - 'a';
                    line[i] = 'z'- (shift-diff-1);
                }
                else
                {
                    line[i] = line[i] - shift;
                }
            }
        }
        vecOfString.push_back(line);
    }
    for(vector<string>::reverse_iterator rIt = vecOfString.rbegin();rIt < vecOfString.rend();rIt++)
    {
        cout<<*rIt <<endl;
    }
    /*for(size_t i = vecOfString.size()-1;i>=0;i--)
    {
        cout<<vecOfString[i]<<endl;
    }*/
    //cout<<"the line is:"<<line<<endl;
    return 0;
}
