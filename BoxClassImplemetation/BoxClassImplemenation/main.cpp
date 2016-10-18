//
//  main.cpp
//  Preprocessor
//
//  Created by Harshit Pareek on 9/10/16.
//  Copyright © 2016 CS1124. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int BoxesCreated,BoxesDestroyed;

class Box
{
private:
    int l;
    int b;
    int h;
public:
    Box():l(0),b(0),h(0)
    {
        BoxesCreated++;
    }
    Box(int l,int b,int h): l(l),b(b),h(h)
    {
        BoxesCreated++;
    }
    Box(const Box& box)
    {
        l = box.l;
        b = box.b;
        h = box.h;
    }
    ~Box()
    {
        BoxesDestroyed++;
    }
    int getLength()
    {
        return l;
    }
    int getBreadth()
    {
        return b;
    }
    int getHeight()
    {
        return h;
    }
    long long CalculateVolume()
    {
        return l*b*h;
    }
    bool operator < (Box& box)
    {
        if(l < box.l)
        {
            return true;
        }
        else if(b < box.b && l == box.l)
        {
            return true;
        }
        else if(h < box.h && l == box.l && b == box.b)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
ostream& operator << (ostream& out, Box box)
{
    out << box.getLength() << " " << box.getBreadth() << " " << box.getHeight() << endl;
    return out;
}
void check2()
{
    int n;
    cin>>n;
    Box temp;
    for(int i=0;i<n;i++)
    {
        int type;
        cin>>type;
        if(type ==1)
        {
            cout<<temp<<endl;
        }
        if(type == 2)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            temp=NewBox;
            cout<<temp<<endl;
        }
        if(type==3)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            if(NewBox<temp)
            {
                cout<<"Lesser"<<endl;
            }
            else
            {
                cout<<"Greater"<<endl;
            }
        }
        if(type==4)
        {
            cout<<temp.CalculateVolume()<<endl;
        }
        if(type==5)
        {
            Box NewBox(temp);
            cout<<NewBox<<endl;
        }
        
    }
}

int main()
{
    BoxesCreated = 0;
    BoxesDestroyed = 0;
    check2();
    cout<<"Boxes Created : "<<BoxesCreated<<endl<<"Boxes Destroyed : "<<BoxesDestroyed<<endl;
}



