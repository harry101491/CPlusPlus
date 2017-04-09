//
//  main.cpp
//  HW6
//
//  Created by Harshit Pareek on 3/16/17.
//  Copyright © 2017 CS2134. All rights reserved.


#include <iostream>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

void printArray(int tempArr[], int arrSize);
void resizeArray(int*& arr, int currentSize, int newSize);

int minInd(int arr[], int size);
void sortArray(int*& arr, int size);

int main() {
    int arrSize, newSize;
    int newInteger;
    int *arr;
    
    cout<<"How many integers in your array?"<<endl;
    cin>>arrSize;
    
    arr = new int[arrSize];
    
    for (int ind = 0; ind <= arrSize - 1; ind++) {
        cout<<"Enter (non-zero) integer: ";
        cin>>arr[ind];
    }
    
    cout<<"Your sorted array is: ";
    sortArray(arr, arrSize);
    printArray(arr, arrSize);
    
    cout<<"Now, please enter a new integer: ";
    cin>>newInteger;
    
    newSize = arrSize + 1;
    resizeArray(arr, arrSize, newSize);
    
    arrSize = newSize;
    arr[arrSize - 1] = newInteger;
    
    cout<<"Your new sorted array is: ";
    sortArray(arr, arrSize);
    printArray(arr, arrSize);
    
    delete []arr;
    return 0;
}

void printArray(int tempArr[], int arrSize){
    for (int i = 0; i <= arrSize - 1; i++) {
        cout<<tempArr[i]<<" ";
    }
    cout<<endl;
}

void sortArray(int*& arr, int size){
    //bubble sort from the lowest to the highest of a given array
    int *temp;
    for (int ind = 0; ind <= size - 1; ind++) {
        for (int ind2 = 0; ind2 <= (size - 1) - ind; ind2++) {
            if (arr[ind2] > arr[ind2 + 1]) {
                {
                    swap(arr[ind2], arr[ind2 + 1]);
                }
            }
        }
    }
    //shift the array back one address to the left after the implementation of above algorithm
    for (int i = 0; i <= size - 1; i++) {
        arr[i] = arr[i+1];
    }
    
    temp = new int[size];
    for (int i = 0; i <= size - 1; i++) {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
}

void resizeArray(int*& arr, int currentSize, int newSize){
    int *temp = new int[newSize];
    for (int i = 0; i <= currentSize; i++) {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
}
//// Question 1;
//#include <iostream>
//#include <cstring>
//
//const int SIZE=20;
//
//using namespace std;
//
//char* reverseString (char*);
//int main()
//{
//    char str[SIZE];
//    cout<<"Enter the string with the max character(20)"<<endl;
//    cin.getline(str,SIZE);
//    cout<<"the length of string str:"<<strlen(str)<<endl;
//    char* reverse = reverseString(str);
//    cout<<"the reverse string is:"<<reverse<<endl;
//    return 0;
//}
//
//char* reverseString(char* str)
//{
//    char *first,*end;
//    first = str;
//    end = str + (strlen(str)-1);
//    while(first < end)
//    {
//        char temp;
//        temp = *first;
//        *first = *end;
//        *end = temp;
//        first++;
//        end--;
//    }
//    return str;
//}

//// Question 2
//#include <iostream>
//
//using namespace std;
//
//int* insertNumber(int*, int, int);
//
//int main()
//{
//    int size;
//    cout<<"Enter the size of the array"<<endl;
//    cin>>size;
//    // dynamically allocating the integer array
//    int* intArray = new int[size];
//    for(int i=0;i<size;i++)
//    {
//        cin >> intArray[i];
//    }
//    int num;
//    cout<<"enter the number to insert"<<endl;
//    cin >> num;
//    int* resize = insertNumber(intArray, size, num);
//    cout<<"the resized array is:"<<endl;
//    for(int i=0;i<size+1;i++)
//    {
//        cout<<resize[i]<<" ";
//    }
//    cout<<endl;
//    return 0;
//}
//int* insertNumber(int* intArray, int size, int num)
//{
//    int* resizeArray = new int[size+1];
//    // first find the position of the number. We assume that the numbers is in ascending order
//    int i = 0;
//    while(intArray[i] < num)
//    {
//        //put that element in the resize array
//        resizeArray[i] = intArray[i];
//        i++;
//    }
//    int j = i;
//    int m = size;
//    while(m > i)
//    {
//        resizeArray[m] = intArray[m-1];
//        m--;
//    }
//    resizeArray[j] = num;
//    return resizeArray;
//}

////Question 3
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//void createHistogram(const vector<int>&);
//
//int main()
//{
//    vector<int> vecOfInteger;
//    cout<<"Enter the integer array with the -1 as sentinal value:"<<endl;
//    int num;
//    while(num != -1)
//    {
//        cin >> num;
//        vecOfInteger.push_back(num);
//    }
//    createHistogram(vecOfInteger);
//    return 0;
//}
//
//void createHistogram(const vector<int>& vec)
//{
//    // find the maximum in the array
//    int max = 0;
//    for(int i=0;i<vec.size();i++)
//    {
//        if(vec[i] > max)
//        {
//            max = vec[i];
//        }
//    }
//    cout<<"the value of max is:"<<max<<endl;
//    int* hist = new int[max+1];
//    for(int i=0;i<max+1;i++)
//    {
//        hist[i] = 0;
//    }
//    
//    for(int i=0;i<vec.size();i++)
//    {
//        if(vec[i] >= 0)
//        {
//            ++hist[vec[i]];
//        }
//    }
//    //printing the histogram
//    for(int i=0;i<max+1;i++)
//    {
//        if(hist[i] > 0)
//        {
//            cout<<"Number of "<<i<<"'s: " <<hist[i]<<endl;
//        }
//    }
//}
