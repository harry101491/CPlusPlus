//
//  main.cpp
//  HackerRank
//
//  Created by Harshit Pareek on 9/13/16.
//  Copyright © 2016 CS1124. All rights reserved.
//

#include <iostream>
#include <exception>
#include <vector>
#include <cmath>

using namespace std;

struct Workshop
{
    int start_time;
    int duration;
    int end_time;
};

struct Available_Workshops
{
    int n;
    Workshop* arr;
    Available_Workshops()
    {
        n = 0;
        arr = nullptr;
    }
};

Available_Workshops* initialize(int start_time[],int duration[],int n)
{
    Available_Workshops* workshops = new Available_Workshops();
    workshops->n = n;
    workshops->arr = new Workshop[n];
    for(int i=0;i<n;i++)
    {
        workshops->arr[i].start_time = start_time[i];
        workshops->arr[i].duration = duration[i];
        workshops->arr[i].end_time = start_time[i] + duration[i];
    }
    return workshops;
}

int CalculateMaxWorkshops(Available_Workshops* ptr)
{
    int count = 1;
    for(int i=0;i<(ptr->n)-1;)
    {
        for(int j=i+1;j<ptr->n;j++)
        {
            if(ptr->arr[j].start_time > ptr->arr[i].end_time)
            {
                count++;
                i = j;
                break;
            }
        }
    }
    return count;
}
int main()
{
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];
    
    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }
    
    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
