//
//  main.cpp
//  HW8New
//
//  Created by Harshit Pareek on 4/7/17.
//  Copyright © 2017 CS2134. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class Organism;
class Doodlebug;
class Ant;

class World
{
public:
    friend class Organism;
    friend class Doodlebug;
    friend class Ant;
    friend ostream& operator<<(ostream& o, World instance);
    friend istream& operator>>(istream& i, World instance);
    World();
    ~World();
    void printGrid();
    void timeStep();
    void setGrid(int x, int y, Organism* pOrg);
    Organism* getGrid(int x, int y);
    
private:
    int x;
    int y;
    Organism* grid[20][20];
};
class Organism
{
public:
    friend class World;
    friend ostream& operator<<(ostream& o, Organism instance);
    friend istream& operator>>(istream& i, Organism instance);
    Organism();
    Organism(World *wrld, int x, int y);
    ~Organism();
    char getType();
    virtual void move();
    virtual void breed();
    virtual bool starved();
    
    
protected:
    char type;
    int x;
    int y;
    int breedCount;
    bool moved;
    World* world;
    
};
class Ant:public Organism
{
public:
    friend class World;
    Ant();
    Ant(World *world, int x, int y);
    ~Ant();
    void move();
    void breed();
    
private:
    bool moved;
};
class Doodlebug:public Organism
{
public:
    friend class World;
    Doodlebug();
    Doodlebug(World *world, int x, int y);
    ~Doodlebug();
    void move();
    void breed();
    bool starved();
    
private:
    bool moved;
    int starveCount;
};
//World Constructor
World::World()
{
    srand(time(0));
    for (int i = 0; i <20; i++)
    {
        for (int j = 0; j <20; j++)
        {
            grid[i][j] = NULL;
        }
    }
    for (int i = 0; i <99; i++)
    {
        x = (rand() % 19);
        y = (rand() % 19);
        grid[x][y] = new Ant;
    }
    for (int i = 0; i < 5; i++)
    {
        x = (rand() % 19);
        y = (rand() % 19);
        grid[x][y] = new Doodlebug;
    }
    //cout << "The world is constructed!" << endl;
}
//World Deconstructor
World::~World()
{
    int i, j;
    for (i = 0; i<20; i++)
    {
        for (j = 0; j<20; j++)
        {
            if (grid[i][j] != NULL) delete (grid[i][j]);
        }
    }
    //cout << "The world is deconstructed!" << endl;
}
//Organism Constructor
Organism::Organism()
{
    world = NULL;
    moved = false;
    breedCount = 0;
    x = 0;
    y = 0;
    type = 'O';
    //cout << "The organism is constructed!" << endl;
}
Organism::Organism(World *world, int x, int y)
{
    world->setGrid(x, y, this);
    this->world = world;
    moved = false;
    breedCount = 0;
    this->x = x;
    this->y = y;
}
//Organism Deconstructor
Organism::~Organism()
{
    //cout << "The organism is deconstructed!" << endl;
}
//Ant Constructor
Ant::Ant()
{
    type = 'o';
    //cout << "The ant is constructed!" << endl;
}
Ant::Ant(World *world, int x, int y) : Organism(world, x, y)
{
}
//Ant Deconstructor
Ant::~Ant()
{
    //cout << "The ant is deconstructed!" << endl;
}
//Doodlebug Constructor
Doodlebug::Doodlebug()
{
    type = 'X';
    //cout << "The doodlebug is constructed!" << endl;
}
Doodlebug::Doodlebug(World *world, int x, int y) : Organism(world, x, y)
{
}
//Doodlebug Deconstructor
Doodlebug::~Doodlebug()
{
    //cout << "The doodlebug is deconstructed!" << endl;
}
//World << overload
ostream& operator<<(ostream& o, World instance)
{
    o << instance.x;
    return o;
}
//World >> overload
istream& operator >> (istream& i, World instance)
{
    i >> instance.x;
    return i;
}
//Organism << overload
ostream& operator<<(ostream& o, Organism instance)
{
    o << instance.type;
    return o;
}
//Organism >> overload
istream& operator >> (istream& i, Organism instance)
{
    i >> instance.x;
    return i;
}
//World Functions
void World::printGrid()
{
    for (int i = 0; i <20; i++)
    {
        for (int j = 0; j <20; j++)
        {
            if (grid[i][j] == NULL)
                cout << '-';
            else cout << (*grid[i][j]);
        }
        cout << endl;
    }
}
Organism* World::getGrid(int x, int y)
{
    return grid[x][y];
}
void World::setGrid(int x, int y, Organism* pOrg)
{
    grid[x][y] = pOrg;
}
void World::timeStep()
{
    //set moved to false
    for (int i = 0; i<20; i++)
        for (int j = 0; j<20; j++)
        {
            if (grid[i][j] != NULL) grid[i][j]->moved = false;
        }
    //move Doodlebugs
    for (int i = 0; i<20; i++)
        for (int j = 0; j<20; j++)
        {
            if ((grid[i][j] != NULL) && (grid[i][j]->getType() == 'X'))
            {
                if (grid[i][j]->moved == false)
                {
                    grid[i][j]->moved = true;
                    grid[i][j]->move();
                }
            }
        }
    //move Ants
    for (int i = 0; i<20; i++)
        for (int j = 0; j<20; j++)
        {
            if ((grid[i][j] != NULL) && (grid[i][j]->getType() == 'o'))
            {
                if (grid[i][j]->moved == false)
                {
                    grid[i][j]->moved = true;
                    grid[i][j]->move();
                }
            }
        }
    //Starve Doodlebugs
    for (int i = 0; i<20; i++)
        for (int j = 0; j<20; j++)
        {
            if ((grid[i][j] != NULL) &&
                (grid[i][j]->getType() == 'X'))
            {
                if (grid[i][j]->starved())
                {
                    delete (grid[i][j]);
                    grid[i][j] = NULL;
                }
            }
        }
    //Breed
    for (int i = 0; i<20; i++)
        for (int j = 0; j<20; j++)
        {
            if ((grid[i][j] != NULL) && (grid[i][j]->moved == true))
                grid[i][j]->breed();
        }
}
//Organism functions
char Organism::getType()
{
    return type;
}
void Organism::move()
{
    
}
void Organism::breed()
{
    
}
bool Organism::starved()
{
    return 0;
}
//Ant functions
void Ant::move()
{
    int direction = rand() % 4;
    if (direction == 0)
    {
        if ((y>0) && (world->getGrid(x, y - 1) == NULL))
        {
            world->setGrid(x, y - 1, this);
            world->setGrid(x, y, NULL);
            y--;
        }
    }
    else if (direction == 1)
    {
        if ((y<19) && (world->getGrid(x, y + 1) == NULL))
        {
            world->setGrid(x, y + 1, this);
            world->setGrid(x, y, NULL);
            y++;
        }
    }
    
    else if (direction == 2)
    {
        if ((x>0) && (world->getGrid(x - 1, y) == NULL))
        {
            world->setGrid(x - 1, y, this);
            world->setGrid(x, y, NULL);
            x--;
        }
    }
    else
    {
        if ((x<19) && (world->getGrid(x + 1, y) == NULL))
        {
            world->setGrid(x + 1, y, this);
            world->setGrid(x, y, NULL);
            x++;
        }
    }
    
}
void Ant::breed()
{
    breedCount++;
    if (breedCount == 3)
    {
        breedCount = 0;
        if ((y>0) && (world->getGrid(x, y - 1) == NULL))
            Ant *a1 = new Ant(world, x, y - 1);
        else if ((y<19) && (world->getGrid(x, y + 1) == NULL))
            Ant *a1 = new Ant(world, x, y + 1);
        else if ((x>0) && (world->getGrid(x - 1, y) == NULL))
            Ant *a1 = new Ant(world, x - 1, y);
        else if ((x<19) && (world->getGrid(x + 1, y) == NULL))
            Ant *a1 = new Ant(world, x + 1, y);
    }
}
//Doodlebug functions
//eat ants
void Doodlebug::move()
{
    if ((y > 0) && (world->getGrid(x, y - 1) != NULL) &&
        (world->getGrid(x, y - 1)->getType() == 'o'))
    {
        delete (world->grid[x][y - 1]);
        world->grid[x][y - 1] = this;
        world->setGrid(x, y, NULL);
        starveCount = 0;
        y--;
        return;
    }
    else if ((y < 19) && (world->getGrid(x, y + 1) != NULL) &&
             (world->getGrid(x, y + 1)->getType() == 'o'))
    {
        delete (world->grid[x][y + 1]);
        world->grid[x][y + 1] = this;
        world->setGrid(x, y, NULL);
        starveCount = 0;
        y++;
        return;
    }
    else if ((x > 0) && (world->getGrid(x - 1, y) != NULL) &&
             (world->getGrid(x - 1, y)->getType() == 'o'))
    {
        delete (world->grid[x - 1][y]);
        world->grid[x - 1][y] = this;
        world->setGrid(x, y, NULL);
        starveCount = 0;
        x--;
        return;
    }
    else if ((x < 19) && (world->getGrid(x + 1, y) != NULL) &&
             (world->getGrid(x + 1, y)->getType() == 'o'))
    {
        delete (world->grid[x + 1][y]);
        world->grid[x + 1][y] = this;
        world->setGrid(x, y, NULL);
        starveCount = 0;
        x++;
        return;
    }
}
//breed
void Doodlebug::breed()
{
    breedCount++;
    if (breedCount == 8)
    {
        breedCount = 0;
        if ((y>0) && (world->getGrid(x, y - 1) == NULL))
            Doodlebug *d1 = new Doodlebug(world, x, y - 1);
        else if ((y<19) && (world->getGrid(x, y + 1) == NULL))
            Doodlebug *d1 = new Doodlebug(world, x, y + 1);
        else if ((x>0) && (world->getGrid(x - 1, y) == NULL))
            Doodlebug *d1 = new Doodlebug(world, x - 1, y);
        else if ((x<19) && (world->getGrid(x + 1, y) == NULL))
            Doodlebug *d1 = new Doodlebug(world, x + 1, y);
    }
}
//starve
bool Doodlebug::starved()
{
    if (starveCount > 3)
        return true;
    else return false;
}

int main()
{
    
    //cout << "World:" << endl;
    //World w1;
    //cout << "w1.x:" << w1 << endl;
    //cout << "Organism" << endl;
    //Organism o1;
    //cout << "o1.type:" << o1 << endl;
    //cout << endl;
    //cout << "Ant" << endl;
    //Ant a1;
    //cout << endl;
    //cout << "Doodlebug" << endl;
    //Doodlebug d1;
    //cout << endl;
    
    //grid[1][1] = new Ant;
    //cout << (*grid[1][1]);
    string s;
    World w;
    
    while (true)
    {
        w.printGrid();
        w.timeStep();
        cout << endl << "Press enter for next step" << endl;
        getline(cin, s);	
    }
    return 0;
}

//#include <iostream>
//#include <vector>
//#include <string>
//#include <cstdlib>
//#include <ctime>
//
//using namespace std;
//
//#define SIZE 20
//#define INITANTS 100
//#define INITDOODLEBUGS 5
//
//class Ants;
//class DoodleBugs;
//class Organism;
//
//
//class Organism
//{
//private:
//    int XCoordinate;
//    int YCoordinate;
//public:
//    Organism(int xCoord, int yCoords);
//    virtual void move(){}
//    virtual void breed(){}
//    int getXCoord() const;
//    void setXCoord(int);
//    int getYCoord() const;
//    void setYCoord(int);
//    bool isValid(int xCoord, int yCoord);
//};
//
//Organism:: Organism(int xCoord, int yCoord)
//{
//    this->XCoordinate = xCoord;
//    this->YCoordinate = yCoord;
//}
//
//int Organism::getXCoord() const
//{
//    return this->XCoordinate;
//}
//int Organism::getYCoord() const
//{
//    return this->YCoordinate;
//}
//void Organism::setXCoord(int xCoord)
//{
//    this->XCoordinate = xCoord;
//}
//void Organism::setYCoord(int yCoord)
//{
//    this->YCoordinate = yCoord;
//}
//
//
//class Ants : public Organism
//{
//private:
//    const int breedSteps = 3;
//    int breedCounter;
//public:
//    Ants(int xCoord, int yCoords);
//    void move();
//    void breed()
//    {
//        
//    }
//};
//
//Ants::Ants(int xCoord, int yCoord) : Organism(xCoord,yCoord)
//{
//    breedCounter = 0;
//}
//
//void Ants:: move()
//{
//    int currXCoord = this->getXCoord();
//    int currYCoord = this->getYCoord();
//    int randNumber = rand()%4;
//    switch (randNumber) {
//        // left
//        case 0:
//            if(isValid(currXCoord-1, currYCoord))
//            {
//                this->setXCoord(currXCoord-1);
//                this->setYCoord(currYCoord);
//                
//            }
//            else
//            {
//                break;
//            }
//            break;
//        // right
//        case 1:
//            break;
//        // up
//        case 2:
//            break;
//        // down
//        case 3:
//            break;
//            
//        default:
//            break;
//    }
//}
//
//class DoodleBugs : public Organism
//{
//private:
//    const int breedSteps = 10;
//    const int starveSteps = 3;
//public:
//    DoodleBugs(int xCoord, int yCoord);
//    void move()
//    {
//        
//    }
//    void breed()
//    {
//        
//    }
//    void strave();
//};
//
//DoodleBugs::DoodleBugs(int xCoord, int yCoord): Organism(xCoord, yCoord)
//{}
//
//class World
//{
//private:
//    int grid[SIZE][SIZE];
//    vector<Ants> ants;
//    vector<DoodleBugs> doodleBugs;
//public:
//    World();
//    void initializeWorld();
//    void moveDoodleBug(DoodleBugs&,int, int);
//    void moveAnt(Ants&, int, int);
//    void eatAnt(Ants&, int, int);
//    void starveDoodleBug(DoodleBugs&, int, int);
//    void breedAnt(Ants&, int, int);
//    void breedDoodleBug(Ants&, int, int);
//    bool isWorldEnded();
//    void printWorld();
//};
//
//World :: World()
//{
//    // initialize the random seed;
//    srand ((unsigned)time(0));
//    initializeWorld();
//}
//void World :: initializeWorld()
//{
//    // all are empty
//    for(int i=0;i<SIZE;i++)
//    {
//        for(int j=0;j<SIZE;j++)
//        {
//            grid[i][j] = '-';
//        }
//    }
//    // put 5 doodleBugs and 100 ants in the world
//    for(int i=0;i<INITANTS;)
//    {
//        int xCoord = rand() % SIZE;
//        int yCoord = rand() % SIZE;
//        if(grid[xCoord][yCoord] == '-')
//        {
//            Ants ant(xCoord,yCoord);
//            grid[xCoord][yCoord] = 'o';
//            ants.push_back(ant);
//            i++;
//        }
//    }
//    for(int i=0;i<INITDOODLEBUGS;)
//    {
//        int xCoord = rand() % SIZE;
//        int yCoord = rand() % SIZE;
//        if(grid[xCoord][yCoord] == '-')
//        {
//            DoodleBugs doodleBug(xCoord,yCoord);
//            grid[xCoord][yCoord] = 'X';
//            doodleBugs.push_back(doodleBug);
//            i++;
//        }
//    }
//}
//void World::moveDoodleBug(DoodleBugs& bug, int xCoord, int yCoord)
//{
//    if(grid[xCoord][yCoord] == '-')
//    {
//        grid[bug.getXCoord()][bug.getYCoord()] = '-';
//        bug.setYCoord(yCoord);
//        bug.setXCoord(xCoord);
//        grid[xCoord][yCoord] = 'X';
//    }
//    else if(grid[xCoord][yCoord] == 'o')
//    {
//        
//    }
//}
//void World::moveAnt(Ants& ant, int xCoord, int yCoord)
//{
//    
//}
//bool World::isWorldEnded()
//{
//    return false;
//}
//void World::printWorld()
//{
//    for(int i=0;i<SIZE;i++)
//    {
//        for(int j=0;j<SIZE;j++)
//        {
//            cout<<(char)grid[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//}
//
//int main()
//{
//    World myWorld;
//    myWorld.printWorld();
//    return 0;
//}
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

