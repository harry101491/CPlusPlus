//
//  main.cpp
//  PrintRuler
//
//  Created by Harshit Pareek on 3/24/17.
//  Copyright © 2017 CS2134. All rights reserved.
//

#include <iostream>
#include <ctime>
using namespace std;

int costOfJumps(int arr[], int arrSize, int index, int &cost);

int main(){
    int arr[6];
    int arrSize = 6;
    int i;
    int index = 0;
    arr[0] = 0;
    srand(time(0));
    int cost = 0;
    
    for(i = 1; i < arrSize; i++)
        arr[i] = (rand()% 99 + 1);
    
    cout<<"The Board, Made Up of "<<arrSize<<" Columns, is As Follows:"<<endl;
    for(i = 0; i < arrSize; i++)
        cout<<arr[i]<<'\t';
    cout<<endl;
    cout<<endl;
    
    cout<<"The Lowest Cost to Jump Across the Board is:"<<endl;
    cout<<costOfJumps(arr, arrSize, index, cost)<<endl;
    cout<<endl;
    
    return 0;
}
int costOfJumps(int arr[], int arrSize, int index, int &cost){
    if(index == (arrSize - 1)){
        cost += arr[index];
    }
    else{
        if(index == (arrSize - 3)){
            index += 2;
            costOfJumps(arr, arrSize, index, cost);
        }
        else if(index == (arrSize - 2)){
            index++;
            costOfJumps(arr, arrSize, index, cost);
        }
        else{
            if(arr[index + 1] < arr[index + 2]){
                cost += arr[index + 1];
                index++;
                costOfJumps(arr, arrSize, index, cost);
            }
            else{ // (arr[index + 1] >= arr[index + 2])
                cost += arr[index + 2];
                index += 2;
                costOfJumps(arr, arrSize, index, cost);
            }
        }
    }
    return cost;
}
