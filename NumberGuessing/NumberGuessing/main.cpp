//
//  main.cpp
//  NumberGuessing
//
//  Created by Harshit Pareek on 2/22/17.
//  Copyright © 2017 CS2134. All rights reserved.
//
#include<iostream>
using namespace std;

int main() {
    
    int num1, num2, num3, num4;
    int sum1, sum2, sum3, sum4;
    cout << "Please enter a number of coins:\n";
    cout << "# of Quarters:\n";
    cin >> num1;
    sum1 = num1 * 25;
    
    cout << "# of Dimes:\n";
    cin >> num2;
    sum2 = num2 * 10;
    
    cout << "# of Nickles:\n";
    cin >> num3;
    sum3 = num3 * 5;
    
    cout << "# of Pennies:\n";
    cin >> num4;
    sum4 = num4;
    
    int totDol, cent;
    totDol = (sum1 + sum2 + sum3 + sum4) / 100;
    cent = (sum1 + sum2 + sum3 + sum4) % 100;
    
    cout << "The total is" << totDol << "dollars and" << cent << "cents.\n";
    
    return 0;
}
/*#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX_CHANCE 5
#define RANGE_MIN 1
#define RANGE_MAX 100

using namespace std;

int main()
{
    srand((int)time(0));
    int chances = MAX_CHANCE;
    int rangeMin = RANGE_MIN;
    int rangeMax = RANGE_MAX;
    int randomNum = (rand()%100) + 1;
    cout <<"I thought of a number between " << rangeMin << " and  "<<rangeMax<<"! Try to guess it."<<endl;
    do
    {
        int guess;
        cout<<"Range:["<<rangeMin<<","<<rangeMax<<"], Number of guesses left :"<<chances<<endl;
        cout<<"Your guess:";
        cin >> guess;
        if(guess == randomNum)
        {
            cout<<"Congrats! you have guessed the number in "<<chances<<" guesses"<<endl;
            break;
        }
        else if(randomNum > guess)
        {
            cout<< "Wrong ! my number is bigger."<<endl;
            chances--;
            rangeMin = guess;
        }
        else
        {
            cout<<"Wrong! my number is smaller. "<<endl;
            chances--;
            rangeMax = guess;
        }
    }while(chances > 0);
    if(chances == 0)
    {
        cout<<"Thanks for playing my number is:"<<randomNum<<endl;
    }
    else
    {
        cout<<"Thanks for playing and congrats for guessing it correctly!!"<<endl;
    }
    return 0;
}
*/
