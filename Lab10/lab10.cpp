/*
*  Purpose for program:
*  
*  create program to combine structs and arrays
*  
*
*  Programmer: Charles Kelley
*  Date: October 26, 2018
*
*  Honor Code: I have neither given nor received any unauthorized assistance with this program.
*/

#include "lab10.h"


void arrayStruct(string input, string output)
{
	ArrayStorage AS;
	AS.count = 0;
	
	ifstream in(input);
	ofstream out(output);
	
	string fileName;
	string command;
	
	in >> command;
	while ( !in.fail() )
	{
		if ( command == "file" )
		{
			string fileName;
			in >> fileName;
			file(fileName, AS, out);
		}
		else if ( command == "show" )
		{
			int search;
			in >> search;
			show(search, AS, out);
		}
		in >> command;
	}
	
}

void file(string &fileName, ArrayStorage &AS, ostream &out)
{
	ifstream in2(fileName);
	
	in2 >> AS.array[AS.count];
	AS.count += 1;
	
	while ( !in2.fail() && AS.count >= 0 && AS.count < SIZE)
	{
		//AS.count += 1;
		in2 >> AS.array[AS.count];
		AS.count += 1;
		//getline(in2, AS.array[AS.count], '\n');
	}
	int showNum;
	if (AS.count < 10)
	{
		showNum = AS.count - 1;
	}
	else
	{
		showNum = 10;
	}
	out << "Command file " << fileName << endl;
	out << "Loaded " << showNum << endl;
}

void show( int searchable, ArrayStorage &AS, ostream &out)
{
	out << "Command show " << searchable << " ";
	if ( searchable >= 0 && searchable < AS.count )
	{
		out << AS.array[searchable];
	}
	else
	{
		out << "bad location";
	}
	out << endl;
}