//
//  main.cpp
//  HW5
//
//  Created by Harshit Pareek on 3/7/17.
//  Copyright © 2017 CS2134. All rights reserved.
//
#include <string>
#include <math.h>
#include <iostream>
using namespace std;

bool isAnagram(string w1, string w2);

int main(){
    string word1, word2;
    
    cout<<"Please enter a word: "; getline(cin, word1); cout<<endl;
    cout<<"Please enter a second word: "; getline(cin, word2); cout<<endl;
    
    if (isAnagram(word1, word2) == true){
        cout<<word1<<", and "<<word2<<" are anagrams to each other"<<endl;
    }
    else{
        cout<<"The words are not anagrams to each other"<<endl;
    }
}

bool isAnagram(string w1, string w2){
    int w1_sum, w2_sum;
    
    for (int ind = 0; ind <= w1.length() - 1; ind++) {
        w1_sum += (int)w1[ind]; //add the asci values to compare
    }
    
    for (int ind = 0; ind <= w1.length() - 1; ind++){
        if ((int)w1[ind] >= 97 && (int)w1[ind] <= 122){
            w1_sum = w1_sum - 32; //make the spelling all upper case
        }
        
    }
    
    for (int ind = 0; ind <= w2.length() - 1; ind ++){
        w2_sum += (int)w2[ind];
    }
    
    for (int ind = 0; ind <= w2.length() - 1; ind++){
        if ((int)w2[ind] >= 97 && (int)w2[ind] <= 122){
            w2_sum = w2_sum - 32;
        }
    }
    
    if (w1_sum == w2_sum) {
        return true;
    }
    else{
        return false;
    }
}

//#include <iostream>
//#include <stdlib.h>
//
//using namespace std;
//
//#define PIN_NUMBER 12345
//#define MAX_SIZE 5
//
//int main()
//{
//    int randomArray[10];
//    for(int i=0;i<10;i++)
//    {
//        randomArray[i] = rand()%3+1;
//    }
//    return 0;
//}
//void splitParity(int[], int);
//void printArray(int[],int);
//
//int main()
//{
//    int size;
//    cout<<"Enter the arraySize"<<endl;
//    cin >> size;
//    int* arr = new int[size];
//    cout<<"Enter the array elements"<<endl;
//    for(int i=0;i<size;i++)
//    {
//        cin >> arr[i];
//    }
//    splitParity(arr, size);
//    return 0;
//}
//void splitParity(int arr[], int size)
//{
//    int low = 0; // odd checker
//    int high = size-1; // even checker
//    while(low < high)
//    {
//        if(arr[low] % 2 != 0)
//        {
//            low++;
//        }
//        else if(arr[high] % 2 == 0)
//        {
//            high --;
//        }
//        else
//        {
//            int temp = arr[low];
//            arr[low] = arr[high];
//            arr[high] = temp;
//            low++;
//            high--;
//        }
//    }
//    printArray(arr, size);
//}
//void printArray(int arr[],int size)
//{
//    cout<<"the array after modification is:"<<endl;
//    for(int i=0;i<size;i++)
//    {
//        cout<<arr[i]<<"\t";
//    }
//    cout<<endl;
//}
