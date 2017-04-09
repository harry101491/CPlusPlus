//
//  main.cpp
//  NStudent
//
//  Created by Harshit Pareek on 4/3/17.
//  Copyright © 2017 CS2134. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int totalSeconds(int[], int, int);

int main()
{
    int n, totNumber;
    cin >> totNumber;
    int* ans = new int[totNumber];
    for(int i=0;i<totNumber;i++)
    {
        cin >> n;
        int* arr = new int[n];
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
        }
        ans[i] = totalSeconds(arr, n, n);
    }
    for(int i=0;i<totNumber;i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}

int totalSeconds(int arr[], int size, int length)
{
    if(length == 1)
    {
        return 0;
    }
    else
    {
       if(arr[size-length] == 1)
       {
           return 0 + totalSeconds(arr, size, length-1);
       }
       else
       {
            int i = size-(length-1);
            int counter = 0;
            for(;i<size;i++)
            {
                if(arr[i] == 1)
                {
                    counter++;
                }
                else if(arr[i] == 0)
                {
                    break;
                }
            }
            return counter + totalSeconds(arr, size, length-1);
        }
    }
}
