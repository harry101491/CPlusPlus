//
//  main.cpp
//  Lower_Bound
//
//  Created by Harshit Pareek on 11/2/16.
//  Copyright © 2016 CS2134. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int sumOfBitDifference(int* arr, int n)
{
    int ans = 0; // initialize the answer
    
    for(int i=0;i<32;i++)
    {
        int count = 0;
        for(int j=0;j<n;j++)
        {
            if(arr[j] & (1 << i))
            {
                count++;
            }
        }
        ans += count*(n-count)*2;
    }
    return ans;
}

int main()
{
    int arr[] = {1, 3, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << sumOfBitDifference(arr,n) << endl;
    return 0;
}


/*#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
//#include <stringstream>

using namespace std;

int callA=0;
int callB=0;
int callC=0;

class A
{
protected:
    
    void func(int  & a)
    {
        a=a*2;
        callA++;
    }
};

class B
{
protected:
    void func(int & a)
    {
        a=a*3;
        callB++;
    }
};

class C
{
protected:
    void func(int & a)
    {
        a=a*5;
        callC++;
    }
};

class D : public A,B,C
{
    
    int val;
public:
    //Initially val is 1
    D()
    {
        val=1;
    }
    
    
    //Implement this function
    void update_val(int new_val)
    {
        while(new_val % 2 == 0){
            A::func(val);
            new_val = new_val / 2;
        }
        while(new_val % 3 == 0){
            B::func(val);
            new_val = new_val / 3;
        }
        while(new_val % 5 == 0){
            C::func(val);
            new_val = new_val / 5;
        }
        cout << "the new value is: " << new_val << endl;
    }
    //For Checking Purpose
    void check(int); //Do not delete this line.
};


void D::check(int new_val)
{
    update_val(new_val);
    cout<<"Value = "<<val<<endl<<"A's func called "<<callA<<" times "<<endl<<"B's func called "<<callB<<" times "<<endl<<"C's func called "<<callC<<" times"<<endl;
}


int main()
{
    D d;
    int new_val;
    cin>>new_val;
    d.check(new_val);
    
}*/
/*int main()
{
    *//**
     * This code founds the lower bound for a number in the vector. lower_bound gives a range of numbers
     * [first,last) for which < compare does not happen. So Actually it is returning the first iterator 
     * of the element for which either the value is equal or greater. Same thing happens in the upper_
     * bound but for the > operator.
     */
    /*int n;
    cin >> n;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin >> vec[i];
    }
    int q;
    cin >> q;
    int num;
    for(int i=0;i<q;i++){
        cin >> num;
        
    }
    vector<int>::iterator it = lower_bound(vec.begin(),vec.end(),num);
    cout << "value of the iterator is:"<<*it<<endl;*/
    
    /**
     * Code for set implementation in the hacker rank.
     */
    /*ios::fmtflags old_flags = cout.flags(); // this tries to save the old settings of the flags in output stream
    cout.flags(old_flags); // this will restore the old setting after the formatting is complete.
    */
    //long old_precision = cout.precision();
    //cout<<"old precision value :" << old_precision << endl;
    //cout<< right << setw(13) << "Harshit" << endl;
    //double num = 2006.008;
    //cout << setw(15) << setfill('_') << right << "+" << setprecision(6) << num << endl;
    //cout << hex << "0x" << num << endl;
    /*stringstream strStream;
    if( num > 0)
    {
        strStream << '+' << num;
        string newString = strStream.str();
        cout << setw(15) << setfill('_') << right << newString << endl;
        strStream.flush();
    }
    else
    {
        cout << setw(15) << setfill('_') << right << num << endl;
    }

    
    return 0;
}
*/
