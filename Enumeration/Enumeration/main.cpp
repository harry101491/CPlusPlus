//
//  main.cpp
//  Enumeration
//
//  Created by Harshit Pareek on 9/14/16.
//  Copyright © 2016 CS1124. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
//#include <set>
//#include <list>

using namespace std;

int main()
{
    /*map<char,int> myMap;
    map<char,int>::iterator it;
    
    myMap['a'] = 50;
    myMap['b'] = 100;
    myMap['c'] = 200;
    myMap['d'] = 300;

    it = myMap.find('b');
    if(it != myMap.end())
    {
        myMap.erase(it);
    }
    */
    //cout<<"value for a is:"<<myMap.find('d')->second<<endl;
    /*multiset<int> myMultiset;
    multiset<int>::iterator it;
    
    for(int i=1;i<=5;i++)
    {
        myMultiset.insert(i);
    }
    
    it = myMultiset.insert(2);
    */
    //cout<<"the value of iterator is:"<<*it<<endl;
    /*set<int> setOfInts;
    set<int>::iterator it;
    pair<set<int>::iterator,bool> rtr;
    
    for(int i=1;i<=5;i++)
    {
        setOfInts.insert(i);
    }
    
    rtr = setOfInts.insert(2);
    
    if(rtr.second == false)
    {
        it = rtr.first;
    }
    
    int arr[] = {5,2,6};
    
    setOfInts.insert(arr, arr+3);
    
    for(it = setOfInts.begin();it != setOfInts.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;*/
    //cout << "the value of iterator is:"<<*it<<endl;
    /*list<int> listOfInt;
    list<int>::iterator it;
    
    for(int i=1;i<=5;i++)
    {
        listOfInt.push_back(i);
    }
    it = listOfInt.begin();
    //cout<<"before pointing is at :"<<*it<<endl;
    ++it;
    //cout<<"it is pointing at :"<<*it<<endl;
    
    listOfInt.insert(it,20);
     */
    /*
    for(multiset<int>::iterator i = myMultiset.begin(); i != myMultiset.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
     */
    return 0;
}





/*#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum class Fruit {apple, orange, peer};
enum class Color {red, green, orange};

int main()
{
    Fruit f = orange;
    switch(f)
    {
        case apple :
            cout<<"apple"<<endl;
            break;
        case orange :
            cout<<"orange"<<endl;
            break;
        case peer :
            cout<<"peer"<<endl;
            break;
        default:
            cout<<"Default case:"<<endl;
    }
    return 0;
}
template<typename T>
struct Traits
{
    static T type;
    static string name(int index)
    {
        type = static_cast<T>(index);
        return toString(type);
    }
};

int main()
{
    int t = 0;
    cin >> t;
    for(int i=0;i!=t;i++)
    {
        int index1;
        cin >> index1;
        int index2;
        cin >> index2;
        cout<<Traits<Color>::name(index1) << " ";
        cout<<Traits<Fruit>::name(index2) << "\n";
    }
    return 0;
}*/
