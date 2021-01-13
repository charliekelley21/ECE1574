#ifndef _ARRAYSTRUCT_
#define _ARRAYSTRUCT_

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

using std::string;
using std::ifstream;
using std::istream;
using std::ofstream;
using std::ostream;
using std::endl;


struct ListItem
{
	string id;
	string description;
	int quantity;
	double cost;
};

#endif

void shopping_list( string input, string output);
void load( string fileName, ListItem* &shoppingList, int &count, ostream &out2, int &SIZE );
void add( ListItem* &shoppingList, string id_add, string description_add, int quantity_add, double cost_add, int &count, ostream &out2, int &SIZE );
void remove( string id_remove, ostream &out2, ListItem* &shoppingList, int &count, int &SIZE);
void find( string id, ostream &out2, ListItem* &shoppingList, int &count, int &SIZE );
void total( ostream &out2, ListItem* &shoppingList, int &count, int &SIZE);
void save( string fileName, ostream &out2, ListItem* &shoppingList, int &count, int &SIZE);
void grow( ListItem* &shoppingList, int &SIZE );