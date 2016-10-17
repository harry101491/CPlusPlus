//
//  main.cpp
//  hw2
//
//  Created by Harshit Pareek on 9/9/16.
//  Copyright © 2016 CS1124. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Warriors
{
    string warriorName;
    int strength;
    bool isDead;
};

void battle (Warriors&, Warriors&);
void status (vector<Warriors>&);

int main(int argc, const char * argv[])
{
    ifstream ifs("/Users/harshitpareek/Downloads/warriors.txt");
    if(!ifs)
    {
        cerr<<"file could not be opened"<<endl;
        exit(1);
    }
    
    vector<Warriors> vecOfWarriors;
    string command;
    
    while(ifs >> command)
    {
        if(command == "Warrior")
        {
            Warriors newWarrior;
            ifs >> newWarrior.warriorName >> newWarrior.strength;
            newWarrior.isDead = false;
            vecOfWarriors.push_back(newWarrior);
        }
        else if(command == "Battle")
        {
            size_t warriorIndex = 0;
            size_t opponentIndex = 0;
            string name;
            string opponentName;
            ifs >> name >> opponentName;
            for(size_t i = 0;i<vecOfWarriors.size();i++)
            {
                if(vecOfWarriors[i].warriorName == name)
                {
                    warriorIndex = i;
                }
                else if(vecOfWarriors[i].warriorName == opponentName)
                {
                    opponentIndex = i;
                }
                else
                {
                    continue;
                }
            }
            battle(vecOfWarriors[warriorIndex],vecOfWarriors[opponentIndex]);
        }
        else if(command == "Status")
        {
            status(vecOfWarriors);
        }
    }
    return 0;
}
void battle(Warriors& warrior, Warriors& opponent)
{
    cout<<warrior.warriorName<<"  battles  "<<opponent.warriorName<<endl;
    if(warrior.strength == opponent.strength && warrior.strength != 0 && opponent.strength != 0)
    {
        warrior.strength = 0;
        opponent.strength = 0;
        warrior.isDead = true;
        opponent.isDead = true;
        cout<<"Mutual Annhiliation:"<<warrior.warriorName<<" and "<<opponent.warriorName<<" die at each other's hand"<<endl;
    }
    else if(warrior.strength == 0 && opponent.strength != 0)
    {
        cout<<"He is dead , "<<opponent.warriorName<<endl;
    }
    else if(opponent.strength == 0 && warrior.strength != 0)
    {
        cout<<"He is dead , "<<warrior.warriorName<<endl;
    }
    else if(warrior.strength > opponent.strength)
    {
        warrior.strength -= opponent.strength;
        opponent.strength = 0;
        opponent.isDead = true;
        cout<<warrior.warriorName<<"  defeates  "<<opponent.warriorName<<endl;
    }
    else if (warrior.strength < opponent.strength)
    {
        opponent.strength -= warrior.strength;
        warrior.strength = 0;
        warrior.isDead = true;
        cout<<opponent.warriorName<<" defeats "<<warrior.warriorName<<endl;
    }
    else if (warrior.strength == opponent.strength && warrior.strength == 0 && opponent.strength == 0)
    {
        cout<<"Oh, No! They're both dead!! Yuck!!"<<endl;
    }
}
void status (vector<Warriors>& vec)
{
    cout<<"There are "<<vec.size()<<" warriors"<<endl;
    for(Warriors warrior : vec)
    {
        cout<<"Warrior :"<<warrior.warriorName<<", strength :"<<warrior.strength<<endl;
    }
}
