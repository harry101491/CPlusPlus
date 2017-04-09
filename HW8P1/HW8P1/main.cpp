//
//  main.cpp
//  HW8P1
//
//  Created by Harshit Pareek on 4/6/17.
//  Copyright © 2017 CS2134. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

#define SIZE 20
#define INITANTS 100
#define INITDOODLEBUGS 5

class Ants;
class DoodleBugs;
class Organism;

class World
{
private:
    int grid[SIZE][SIZE];
    vector<Ants> ants;
    vector<DoodleBugs> doodleBugs;
public:
    World();
    void initializeWorld();
    void moveDoodleBugs();
    void moveDoodleBugs();
    bool isWorldEnded();
    void printWorld();
};

World :: World()
{
    // initialize the random seed;
    srand (time(0));
    initializeWorld();
}
void World :: initializeWorld()
{
    // all are empty
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            grid[i][j] = '-';
        }
    }
    // put 5 doodleBugs and 100 ants in the world
    for(int i=0;i<INIT;i)
}
class Organism
{
private:
    int XCoordinate;
    int YCoordinate;
public:
    Organism();
    virtual void move();
    virtual void breed();
};

class Ants : public Organism
{
private:
    const int breedSteps = 3;
public:
    void move();
    void breed();
};

class DoodleBugs : public Organism
{
private:
    const int breedSteps = 10;
    const int starveSteps = 3;
public:
    void move();
    void breed();
    void strave();
};










//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//class Money
//{
//public:
//    friend Money operator + (const Money& amount1, const Money& amount2);
//    friend Money operator - (const Money& amount1, const Money& amount2);
//    friend bool operator == (const Money& amount1, const Money& amount2);
//    friend bool operator < (const Money& amount1, const Money& amount2);
//    Money(long dollars, long cents);
//    Money(long dollars);
//    Money();
//    double getMoney() const;
//    friend istream& operator >> (istream& input, Money& amount);
//    friend ostream& operator << (ostream& output, const Money& amount);
//private:
//    long allCents;
//};
//
//Money::Money()
//{
//    allCents = 0;
//}
//Money::Money(long dollars, long cents)
//{
//    //conversion of dollars
//    long newCents = dollars*100;
//    allCents = newCents+cents;
//}
//Money::Money(long dollars)
//{
//    long newCents = dollars*100;
//    allCents = newCents;
//}
//
//Money operator+(const Money& amount1, const Money& amount2)
//{
//    return Money(amount1.getMoney()+amount2.getMoney());
//}
//
//Money operator-(const Money& amount1, const Money& amount2)
//{
//    return Money(amount1.getMoney()-amount2.getMoney());
//}
//
//bool operator == (const Money& amount1, const Money& amount2 )
//{
//    if(amount1.getMoney() == amount2.getMoney())
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}
//
//bool operator < (const Money& amount1, const Money& amount2)
//{
//    return (amount1.getMoney() < amount2.getMoney()) ? true : false;
//}
//
//double Money::getMoney() const
//{
//    return (double)(allCents)/100.0;
//}
//
//istream& operator >> (istream& input, Money& amount)
//{
//    char ch1, ch2;
//    double am;
//    input>>ch1;
//    if(ch1 == '-')
//    {
//        input>>ch2;
//        input>>am;
//        cout<<"the value of am is :"<<am<<endl;
//        amount.allCents = am*100.0;
//        
//    }
//    else if(ch1 == '$')
//    {
//        input >> am;
//        cout<<"the value of am is: "<<am<<endl;
//        amount.allCents = am*100.0;
//        
//    }
//    return input;
//}
//
//ostream& operator<< (ostream& output, const Money& amount)
//{
//    output<<"$"<<amount.allCents;
//    return output;
//}
//
//// the code for checkbook balancing problem
//class Check
//{
//private:
//    
//    int checkNumber;
//    Money amount;
//    int isCashed;
//public:
//    
//    // constructors of the class check
//    Check(int checkNumber, double amount, int isCashed);
//    Check();
//    // accessor and mutators
//    friend istream& operator>> (istream& input, Check& check);
//    friend ostream& operator<< (ostream& output, const Check& check);
//    int getCheckNumber() const;
//    Money& getMoney() const;
//    int isCashedorNot() const;
//    void setCheckNumber(int number);
//    void setAmount(const Money& amount);
//    void setIsCashed(int isCashed);
//};
//
//Check::Check()
//{
//    Check(0,0,0);
//}
//class CheckBook
//{
//private:
//    
//    double oldBalance;
//    double newBalance;
//    double actualBalance;
//    vector<double> deposits;
//    int noOfCashedChecks;
//    int noOfUnCashedChecks;
//    vector<Checks> cashed;
//    vector<Checks> unCashed;
//public:
//    
//    CheckBook();
//    CheckBook(double,double);
//    void sortArray(vector<Check>&);
//    double getDifference() const;
//    friend ostream& operator<< (ostream& out, const CheckBook& checkBook);
//    friend istream& operator>> (istream& in, CheckBook& checkBook);
//    ifstream& readFile(string name);
//};
