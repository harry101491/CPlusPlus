//
//  main.cpp
//  MergeSort
//
//  Created by Harshit Pareek on 9/28/16.
//  Copyright © 2016 CS2134. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void divideStep(int*, int, int);
void merge(int*, int, int, int);

int main()
{
    int arr[] = {3,16,17,8,9,2,24};
    divideStep(arr,0,7);
    return 0;
}

void divideStep(int* arr, int start, int length)
{
    int high = length - 1;
    int mid = (high+start)/2;
    if(high == start)
    {
        return;
    }
    divideStep(arr, start, mid-1);
    divideStep(arr, mid+1, high);
    merge(arr, start, mid, high);
}

void merge(int* arr, int start, int mid, int high)
{
    int mid1 = mid+1;
    int* arr1 = new int[(high-start+1)];
    while(start <= mid && mid1 <= high)
    {
        if(arr[start]<arr[mid1])
        {
            arr1[start] = arr[start];
            start++;
        }
    }
}
