//
//  main.cpp
//  MaxProfit
//
//  Created by Harshit Pareek on 7/7/16.
//  Copyright © 2016 CS1124. All rights reserved.
//

#include <iostream>
using namespace std;


int main()
{
    char name[] = {'g','e','e','e','s','f','o'};
    for(int i=0;name[i] != '\0';i++)
    {
        for(int j=0;name[j]!='\0';j++)
        {
            if(i == j)
            {
                // do nothing
            }
            else
            {
                char charLowerI = tolower(name[i]);
                char charLowerJ = tolower(name[j]);
                if(charLowerI == charLowerJ)
                {
                    name[j] = ' ';
                }
            }
        }
    }
    cout<<name<<endl;
    return 0;
}
/*
int main()
{
    int matrix[3][3] = {{7,2,5},{3,10,6},{4,9,1}};
    int n = 3;
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<matrix[i][j];
        }
        cout<<"\n";
    }
    for(int i=0; i<n ; i++)
    {
        for(int j=0;j<n;j++)
        {
            //System.out.println("i,j : "+matrix[i][j]+"j,i : "+matrix[j][i]);
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    cout<<"After the Transpose"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<matrix[i][j];
        }
        cout<<"\n";
    }
    
}
*/
/*
void arrayProduct(int*,int);
int main()
{
    int arr[] = {1,7,4,3};
    int len = 4;
    cout<<"The array before the multiplication"<<endl;
    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<<" ";
    }
    arrayProduct(arr,len);
    cout<<"The array after the multiplication"<<endl;
    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}

void arrayProduct(int*  arr,int len)
{
    int product = 1;
    int arr1[] = {1,7,4,3};
    for(int i = 0;i < len; i++)
    {
        product = 1;
        for(int j = 0;j < len ; j++)
        {
            if(i == j)
            {
                // do nothing
            }
            else
            {
                product = product*arr1[j];
            }
            //arr[i] = product;
        }
        arr[i] = product;
        //System.out.println("The value of product at "+i+" is "+product+" and the array "+arr[i]);
    }
}
*/
/*int maxProfit = 0;
int minPrice = 0;
void getProfit(int*,int);
int main(int argc, const char * argv[]) {
    int stocks[] = {10, 7, 5, 8, 11, 9};
    minPrice = stocks[0];
    getProfit(stocks, 1);
    cout<<"The value of maxProfit is:"<<maxProfit<<endl;
    return 0;
}
void getProfit(int stocks[],int current)
{
    if(current == 6)
    {
        return;
    }
    if(minPrice > stocks[current])
    {
        minPrice = stocks[current];
    }
    if(maxProfit < (stocks[current]-minPrice))
    {
        maxProfit = stocks[current]-minPrice;
    }
    getProfit(stocks, current+1);
}*/