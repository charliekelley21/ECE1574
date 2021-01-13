/*
*  Purpose for program:
*  
*  create program to combine structs and arrays to 
*  create a dynamic shopping list
*  
*
*  Programmer: Charles Kelley
*  Date: November 12, 2018
*
*  Honor Code: I have neither given nor received any unauthorized assistance with this program.
*/

#include "shopping.h"


void shopping_list( string input, string output)
{
	ifstream in(input);
	ofstream out(output);
	string command;
	
	int count = 0;
	int SIZE = 10;
	ListItem *shoppingList = new ListItem[SIZE];
	
	in >> command; //prime
	
	while ( !in.fail() )
	{
		if (command == "load")
		{
			string file;
			in >> file;
			load( file, shoppingList, count, out, SIZE );
		}
		else if (command == "add")
		{
			string id_add;
			string description_add;
			int quantity_add;
			double cost_add;
			char moneySign;
			
			in >> id_add;
			in.ignore( 500, '\t' );
			getline( in, description_add, '\t');
			in >> quantity_add;
			in.ignore( 500, '\t' );
			in >> moneySign;
			in >> cost_add;
			add( shoppingList, id_add, description_add, quantity_add, cost_add, count, out, SIZE );
		}
		else if (command == "remove")
		{
			string id_remove;
			in >> id_remove;
			remove( id_remove, out, shoppingList, count, SIZE );
		}
		else if (command == "find")
		{
			string id_find;
			in >> id_find;
			find( id_find, out, shoppingList, count, SIZE);
		}
		else if (command == "total")
		{
			total( out, shoppingList, count, SIZE);
		}
		else if (command == "save")
		{
			string filename_save;
			in >> filename_save;
			save(filename_save, out, shoppingList, count, SIZE );
		}
		in >> command; //reprime
	}
}
//------------------------------------------------
void load( string fileName, ListItem* &shoppingList, int &count, ostream &out2, int &SIZE )
{
	SIZE = 10;
	shoppingList = new ListItem[SIZE];	
	
	ifstream in2(fileName);
	ListItem temp;
	
	//prime
	while( in2.peek() == '#' && !in2.fail() ) 
	{
		in2.ignore( 500, '\n' );
	}
	in2 >> temp.id;
	
	//test & process
	while ( !in2.fail() )
	{
		char moneySign;
		
		in2.ignore( 500, '\t' );
		getline( in2, temp.description, '\t');
		in2 >> temp.quantity;
		in2.ignore( 500, '\t' );
		in2 >> moneySign;
		in2 >> temp.cost;
		if ( count == SIZE )
		{ 
			grow( shoppingList, SIZE );
		}
		shoppingList[count] = temp;
		count += 1;
			
		//reprime
		while( in2.peek() == '#' && !in2.fail() ) 
		{
			in2.ignore( 500, '\n' );
		}
		in2 >> temp.id;
	}
	out2 << "Command: load " << fileName << endl;
	out2 << '\t' << "Loaded: " << count << endl;
}
//------------------------------------------------
void remove( string id_remove, ostream &out2, ListItem* &shoppingList, int &count, int &SIZE )
{
	out2 << setprecision(2) << fixed;
	out2 << "Command: remove " << id_remove << endl;
	int start_remove;
	bool found = false;
	for ( int k=0; k<count; k++ )
	{
		if ( shoppingList[k].id == id_remove )
		{
			out2 << '\t' << shoppingList[k].id << '\t' << shoppingList[k].description << '\t' << shoppingList[k].quantity << "\t$" << shoppingList[k].cost << endl;
			found = true;
			start_remove = k;
			//removing from array
			for ( int l=start_remove;l<count-1;l++)
			{
			shoppingList[l] = shoppingList[l+1];
			}
			//---------------------
			count -= 1;
			k = count;
		}
	}
	if ( !found )
	{
		out2 << '\t' << "Sorry id " << id_remove << " not removed." << endl;
	}
}
//-------------------------------------------------
void add( ListItem* &shoppingList, string id_add, string description_add, int quantity_add, double cost_add, int &count, ostream &out2, int &SIZE )
{
	if ( count == SIZE )
	{
		grow( shoppingList, SIZE );
	}
	ListItem temp;
	temp.id = id_add;
	temp.description = description_add;
	temp.quantity = quantity_add;
	temp.cost = cost_add;
	shoppingList[count] = temp;
	count += 1;
	out2 << "Command: add	adding--> " << temp.id << " " << temp.description << " ";
	out2 << setprecision(2) << fixed;
	out2 << temp.quantity << " $" << temp.cost << endl;
	out2 << '\t' << "Item added." << endl;
}
//------------------------------------------------
void find(string id, ostream &out2, ListItem* &shoppingList, int &count, int &SIZE )
{
	out2 << "Command: find " << id << endl;
	bool found = false;
	for( int i=0; i<count; i++)
	{
		if( shoppingList[i].id == id )
		{
			found = true;
			out2 << setprecision(2) << fixed;
			out2 << '\t' << shoppingList[i].id << " " << shoppingList[i].description;
			out2 << " " << shoppingList[i].quantity << " $" << shoppingList[i].cost << endl;
			i = count;
		}
	}
	if ( !found )
	{
		out2 << '\t' << "Sorry id " << id << " not found." << endl;
	}
}
//------------------------------------------------
void total( ostream &out2, ListItem* &shoppingList, int &count, int &SIZE )
{
	out2 << "Command: total" << endl;
	double total_cost = 0;
	for ( int j=0; j<count; j++)
	{
		total_cost += shoppingList[j].cost;
	}
	out2 << setprecision(2) << fixed;
	out2 << '\t' << "Total: $" << total_cost << endl;
}
//------------------------------------------------
void save( string fileName, ostream &out2, ListItem* &shoppingList, int &count, int &SIZE)
{
	ofstream out3(fileName);
	out3 << setprecision(2) << fixed;
	out2 << "Command: save " << fileName << endl;
	for ( int i=0; i < count; i++)
	{
		out3 << shoppingList[i].id << '\t' << shoppingList[i].description << '\t' << shoppingList[i].quantity << "\t$" << shoppingList[i].cost << endl;
	}
}
//-------------------------------------------------
void grow( ListItem* &shoppingList, int &SIZE )
{
	ListItem* temp = shoppingList; //get a copy
	shoppingList = new ListItem[SIZE * 2]; //make a new larger array
	for ( int i=0; i<SIZE; i++ )
		shoppingList[i] = temp[i]; //copy old array to new array
	delete [] temp;
	SIZE *= 2;
	temp = nullptr;
}


