#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Cat
{
	string name;
	string color;
	int weight;
};

void addCat(ifstream&,vector<Cat>& v);

int main()
{
	return 0;
}
 void addCat(ifstream& ifs, vector<Cat>& v)
 {
 	Cat c;
 	while(ifs >> c.name >> c.weight >> c.color)
 	{
 		v.push_back(c);
 	}
 }