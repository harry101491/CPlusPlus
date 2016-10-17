#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

template <typename Object, typename Comparable>
const Object& findMax(const vector<Object>& vec, Comparable com)
{
    int maxIndex = 0;
    for(int i = 0;i<vec.size();i++)
    {
        if(com(vec[maxIndex],vec[i]))
        {
            maxIndex = i;
            
        }
    }
    return vec[maxIndex];
}
template <typename Object>
const Object& findMax(const vector<Object>& vec)
{
    return findMax(vec,less<Object>());
}
class ComparableClass
{
public:
    bool operator()(const string& lhs,const string& rhs)
    {
        return strcmp(lhs.c_str(), rhs.c_str()) > 0 ? true : false;
    }
};


/*template <typename Object, typename Comparable>
const Object& findMax(const vector<Object>& vec, Comparable com)
{
    int maxIndex = 0;
    for(int i = 0;i<vec.size();i++)
    {
        if(com.isLessThan(vec[maxIndex],vec[i]))
        {
            maxIndex = i;
            
        }
    }
    return vec[maxIndex];
}

class ComparableClass
{
public:
    bool isLessThan(const string& lhs,const string& rhs)
    {
        return strcmp(lhs.c_str(), rhs.c_str()) > 0 ? true : false;
    }
};
*/
/*Comparable& findMax(const vector<Comparable>& com)
{
    int maxIndex = 0;
    for(int i=0;i<com.length();i++)
    {
        if(com[maxIndex] < com[i])
        {
            maxIndex  = i;
        }
    }
    return com[maxIndex];
}*/
 
int main()
{
    vector<string> vecOfString  = {"ZEBRA","alligator","bear"};
    cout<<"the max will be:"<<findMax(vecOfString, ComparableClass())<<endl;
    cout<<"the max1 will be:"<<findMax(vecOfString)<<endl;
    return 0;
}
