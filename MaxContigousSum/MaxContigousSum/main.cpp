//
//  main.cpp
//  MaxContigousSum
//
//  Created by Harshit Pareek on 10/28/16.
//  Copyright © 2016 CS2134. All rights reserved.
//
/*
 * 1 For this program we have to implement the contigous maximum subsequance for the given array and we have to do it in the linear time (O(n)) by the help kedne's algorithm.
 * 2 For the second part of the program we will find out the maximum product of contigous subarray. We want to have the time complexity to be O(n) and space compelexity to be O(1).
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int arr[] = {6,-3,-10,0,2};
    int flag = true;
    int max_product_so_far = 0;
    int max_product_end_here = 1;
    for(int i=0;i<5;i++)
    {
        if(arr[i] < 0)
        {
        }
        else
        {
            flag = false;
        }
    }
    if(flag)
    {
        
    }
    else
    {
        
    }
    for(int i=0;i<5;i++)
    {
        
    }
    
    
    // the contigous subsequance maximum sum(Note: this will only work for the if any of the possible sum is > 0
    /*int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int max_so_far = 0;
    int max_ending_here = 0;
    
    for(int i=0;i<8;i++)
    {
        max_ending_here = max_ending_here + arr[i];
        if(max_ending_here < 0)
        {
            max_ending_here = 0;
        }
        else if(max_ending_here > max_so_far)
        {
            max_so_far = max_ending_here;
        }
    }
    
    cout <<"the value of max_so_far is the value of max sum:"<<max_so_far<<endl;
    */
    // the non-contigous subsequance maximum sum.
    
    return 0;
}
