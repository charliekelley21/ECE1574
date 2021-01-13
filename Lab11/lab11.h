#ifndef _ARRAYSTRUCT_
#define _ARRAYSTRUCT_

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

using std::string;
using std::ifstream;
using std::ofstream;
using std::endl;

const int SIZE = 10;

struct Widget
{
	string name;
	int quantity;
	double cost;
};

#endif

void widgetManager( string input, string output );
void load( string &fileName, Widget widgetArray[SIZE], ostream &out, int &count );
void showMeTheWidget( int index, Widget widgetArray[SIZE], ostream &out, int &count);