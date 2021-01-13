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

struct ArrayStorage
{
	int count;
	string array[10];
};

#endif

void arrayStruct(string input, string output);
void file(string &fileName, Widget widgetArray[SIZE], ostream &out);
void show( int searchable, ArrayStorage &AS, ostream &out);