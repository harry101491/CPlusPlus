//
//  main.cpp
//  Deque
//
//  Created by Harshit Pareek on 11/2/16.
//  Copyright © 2016 CS2134. All rights reserved.
//

#include <iostream>
#include <deque>
using namespace std;
void printKMax(int arr[], int n, int k){
    //Write your code here.
    int index;
    for(int i=0;i<n-k+1;i++)
    {
        index = i+k-1;
        for(int j=i;j<=index;j++)
        {
            cout<<arr[j]<<endl;
        }
    }
}
int main(){
    
    int t;
    cin >> t;
    while(t>0) {
        int n,k;
        cin >> n >> k;
        int i;
        int arr[n];
        for(i=0;i<n;i++)
            cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}
