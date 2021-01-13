/*
*  Purpose for program:
*  
*  create program to combine structs and arrays
*  
*
*  Programmer: Charles Kelley
*  Date: November 2, 2018
*
*  Honor Code: I have neither given nor received any unauthorized assistance with this program.
*/

#include "lab11.h"


void widgetManager(string input, string output)
{
	ifstream in(input);
	ofstream out(output);
	Widget widgetArray[SIZE];
	
	string command;
	int count = 0;
	
	in >> command;
	while ( !in.fail() )
	{
		if ( command == "load" )
		{
			string fileName;
			in >> fileName;
			load(fileName, widgetArray, out, count);
		}
		else if ( command == "showMeTheWidget" )
		{
			int index;
			in >> index;
			showMeTheWidget(index, widgetArray, out, count);
		}
		in >> command;
	}
}

void load( string &fileName, Widget widgetArray[SIZE], ostream &out, int &count )
{
	out << "Command: load " << fileName << endl;
	ifstream in2(fileName);
	Widget storage;
	in2 >> storage.name;
	in2 >> storage.quantity;
	in2 >> storage.cost;
	widgetArray[count] = storage;
	count += 1;
	while ( !in2.fail() && count > 0 && count < SIZE )
	{
		Widget iterate;
		in2 >> iterate.name;
		in2 >> iterate.quantity;
		in2 >> iterate.cost;
		widgetArray[count] = iterate;
		count += 1;
	}
	int showNum;
	if (count < 10)
	{
		showNum = count - 1;
	}
	else
	{
		showNum = 10;
	}
	out << '\t' << "Loaded: " << showNum << endl;
}	
void showMeTheWidget( int index, Widget widgetArray[SIZE], ostream &out, int &count)
{
	out << "Command: showMeTheWidget " << index << endl;
	if( index < 0 || index >= count )
	{
		out << '\t' << "Sorry, bad widget number " << index << endl;
	}
	else
	{
		out << '\t' << "Name: " << widgetArray[index].name << endl;
		out << '\t' << "Quantity: " << widgetArray[index].quantity << endl;
		out << '\t' << "Cost: $" << widgetArray[index].cost << endl;
	}
}