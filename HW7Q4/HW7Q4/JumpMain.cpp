//
//  main.cpp
//  HW7Q4
//
//  Created by Harshit Pareek on 3/24/17.
//  Copyright © 2017 CS2134. All rights reserved.
//

#include <iostream>

using namespace std;

int jumpIt(int[], int, int, int);

int main()
{
    int n;
    int arr[20];
    cout << "Enter the size of the array jump array less than 20"<<endl;
    cin >> n;
    cout<<"Enter the array elements with one less size"<<endl;
    arr[0] = 0;
    for(int i=1;i<n;i++)
    {
        cin >> arr[i];
    }
    int minCost = jumpIt(arr, n, 0, 0);
    cout <<"the minimum cost is:"<< minCost << endl;
    return 0;
}

int jumpIt(int arr[], int size, int counter, int minCost)
{
    if(counter == size-1 || counter == size-2)
    {
        return minCost;
    }
    else
    {
        if(minCost + arr[counter+1] > minCost+arr[counter+2])
        {
            minCost = jumpIt(arr, size, counter+2,(minCost+arr[counter+2]));
        }
        else
        {
            minCost = jumpIt(arr, size, counter+1,(minCost+arr[counter+1]));
        }
    }
    return minCost;
}
