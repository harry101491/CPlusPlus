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

//
//int minVal(int a, int b)
//{
//    return (a >= b) ? b : a;
//}

// the program to print the min Array with two version

//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int minInArray1(int[], int);
//int minInArray2(int[], int, int);
//
//int main()
//{
//    int arr[10] = {9, -2, 14, 12, 3, 6, 2, 1, -9, 15};
//    int res1, res2, res3, res4;
//    res1 = minInArray1(arr, 10);
////    cout<<"the value of res1 is:"<<res1<<endl;
//    res2 = minInArray2(arr, 0, 9);
//    cout<<res1<<" "<<res2<<endl; //should both be -9
//    res3 = minInArray2(arr, 2, 5);
//    res4 = minInArray1(arr+2, 4); //arr+2 is equivalent to &(arr[2])
//    cout<<res3<<" "<<res4<<endl; //should both be 3
//    return 0;
//}
//
//int minInArray1(int arr[], int size)
//{
//    if(size-1 == 0)
//    {
//        return arr[size-1];
//    }
//    else
//    {
//        int val = arr[size-1];
//        int min = minInArray1(arr, size-1);
//        if(val > min)
//        {
//            return min;
//        }
//        else
//        {
//            return val;
//        }
//    }
//}
//int minInArray2(int arr[], int low, int high)
//{
//    if(low == high)
//    {
//        return arr[low];
//    }
//    else
//    {
//        int val = arr[high-1];
//        int min = minInArray2(arr, low, high-1);
//        if(val > min)
//        {
//            return min;
//        }
//        else
//        {
//            return val;
//        }
//    }
//}

//// the program for the find change problem
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int findChange(int[], int);
//
//int main()
//{
//    int n;
//    cout<<"Enter the size of the array"<<endl;
//    cin >> n;
//    int* arr = new int[n];
//    cout<<"Enter the elements in the array which follows sequance of 1's after sequance of 0's"<<endl;
//    for(int i=0;i<n;i++)
//    {
//        cin >> arr[i];
//    }
//    int val = findChange(arr, n);
//    cout<<"the value of n is:"<<val<<endl;
//    return 0;
//}
//int findChange(int arr[], int size)
//{
//    int low = 0;
//    int high = size-1;
//    while(low <= high)
//    {
//        int mid = ((low+high)/2)+1;
//        if(arr[mid] == 0 && arr[mid+1] == 1)
//        {
//            return mid+1;
//        }
//        else if(arr[mid] == 1 && arr[mid-1] == 0)
//        {
//            return mid;
//        }
//        else if(arr[mid] == 0)
//        {
//            low = mid+1;
//        }
//        else if(arr[mid] == 1)
//        {
//            high = mid-1;
//        }
//    }
//    return -1;
//}
//#include <iostream>
//#include <string>
//
//using namespace std;
//
////void printRuler(int);
////int sumOfSquares(int[], int);
//int findMinRemoval(string);
//int arr[26];
//
//int main()
//{
//    int n;
//    cout<<"Enter the number of strings"<<endl;
//    cin >> n;
//    string* str = new string[n];
//    for(int i=0;i<26;i++)
//    {
//        arr[i] = 0;
//    }
////    int n;
////    cout<<"Enter the number of strings"<<endl;
////    cin >> n;
////    string* arr = new string[n];
//    for(int i=0;i<n;i++)
//    {
//        cin >> str[i];
//    }
//
//    // find the removal of the elements in the string
//    for(int i=0;i<n;i++)
//    {
//        cout<<findMinRemoval(str[i])<<endl;
//    }
//
////    int n;
////    cout<<"Enter an integer"<<endl;
////    cin >> n;
////
////    printRuler(n);
//
//
////    int n;
////    int arr[20];
////    cout<<"Enter the size of array less than 20"<<endl;
////    cin >> n;
////    cout<<"Enter the array"<<endl;
////    for(int i=0;i<n;i++)
////    {
////        cin >> arr[i];
////    }
////    int squareSum = sumOfSquares(arr, n);
////    cout<<"the sum is:"<<squareSum<<endl;
//
//
//    return 0;
//}
//
//int findMinRemoval(string str)
//{
//
//}
//int sumOfSquares(int arr[], int size)
//{
//    if(size == 1)
//    {
//        return (arr[size-1]*arr[size-1]);
//    }
//    else
//    {
//        return (arr[size-1]*arr[size-1]) + sumOfSquares(arr, size-1);
//    }
//}

//void printRuler(int n)
//{
//    if(n == 1)
//    {
//        cout<<"-"<<endl;
//    }
//    else
//    {
//        printRuler(n-1);
//        for(int i=0;i<n;i++)
//        {
//            cout<<"-";
//        }
//        cout<<endl;
//        printRuler(n-1);
//    }
//}


