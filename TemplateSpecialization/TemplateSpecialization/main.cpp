//
//  main.cpp
//  TemplateSpecialization
//
//  Created by Harshit Pareek on 10/15/16.
//  Copyright © 2016 CS2134. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum class Fruit {apple, orange, pear };
enum class Color {red, green, orange };

template <typename T>
struct Traits
{
    static string name(int index)
    {
        if(static_cast<T>(2) == T::orange)
        {
            if(index == 0)
            {
                return "red";
            }
            else if(index == 1)
            {
                return "green";
            }
            else if(index == 2)
            {
                return "orange";
            }
            else
            {
                return "unknown";
            }
        }
        else if (static_cast<T>(1) == T::orange)
        {
            if(index == 0)
            {
                return "apple";
            }
            else if(index == 1)
            {
                return "orange";
            }
            else if(index == 2)
            {
                return "pear";
            }
            else
            {
                return "unknown";
            }
        }
    }
    
};
int main()
{
    int t = 0; std::cin >> t;
    
    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
    return 0;
}
