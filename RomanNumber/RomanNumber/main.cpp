//
//  main.cpp
//  RomanNumber
//
//  Created by Harshit Pareek on 2/21/17.
//  Copyright © 2017 CS2134. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;
enum Number {I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000};

int main()
{
    int num;
    cout << "Enter the decimal number:" << endl;
    cin >> num;
    int n = num;
    int arr[] = {M,D,C,L,X,V,I};
    int i=0;
    while(arr[i] > num)
    {
        i++;
    }
    int countD = 0;
    int countV = 0;
    int countL = 0;
    int countI = 0;
    int countC = 0;
    int countX = 0;
    while(n > 0)
    {
        switch(arr[i])
        {
            case M:
                n -= M;
                cout << "M";
                break;
            case D:
                if(countD > 1)
                {
                    break;
                }
                else
                {
                    n -= D;
                    cout<<"D";
                    countD++;
                    break;
                }
            case C:
                if(countC > 4)
                {
                    break;
                }
                else
                {
                    n -= C;
                    cout<<"C";
                    countC++;
                    break;
                }
            case L:
                if(countL > 1)
                {
                    break;
                }
                else
                {
                    n -= L;
                    cout<<"L";
                    countL++;
                    break;
                }
            case X:
                if(countX > 4)
                {
                    break;
                }
                else
                {
                    n -= X;
                    cout<<"X";
                    countX++;
                    break;
                }
            case V:
                if(countV > 1)
                {
                    break;
                }
                else
                {
                    n -= V;
                    cout<<"V";
                    countV++;
                    break;
                }
            case I:
                if(countI > 4)
                {
                    break;
                }
                else
                {
                    n -= I;
                    cout<<"I";
                    countI++;
                    break;
                }
        }
        if(n < arr[i])
        {
            while(arr[i] > n && i < 6)
            {
                i++;
            }
        }
    }
    cout<<endl;
    return 0;
}
