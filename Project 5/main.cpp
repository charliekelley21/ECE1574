#include "Ingredient.h"
#include "Recipe.h"
#include <fstream>
#include <iostream>
#include <string>

using std::string;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::cout;
using std::istream;
using std::ostream;

void load( string recipe_file, Recipe &r );
void save( string save_file, Recipe r );
void add( Recipe &r, istream &in, ostream &out );
void remove( Recipe &r, int number, ostream &out );
void count( Recipe r, ostream &out );
void find( Recipe r, int number, ostream &out );

int main( int argc, char* argv[] )
{
if ( argc != 2 )
{
		cout << "Usage: recipe_machine <commands file>" << endl;
	}
	else
	{
		string command_file = argv[1];

		ifstream in(command_file);

		Recipe r;

		string command;

		in >> command;
		while( !in.fail() )
		{
			cout << "Command: " << command << " ";
			if ( command == "load" )
			{
				string recipe_file;
				in >> recipe_file;
				load( recipe_file, r );
				cout << recipe_file << endl;
				cout << "\tLoaded: " << r.get_name() << endl;

			}
			else if ( command == "save" )
			{
				string save_file;
				in >> save_file;
				save( save_file, r );
				cout << save_file << endl;
				cout << "\tSaved: " << r.get_name() << endl;
			}
			else if ( command == "display" )
			{
				cout << endl;
				r.show_recipe( cout );
			}
			else if ( command == "add" )
			{
				add( r, in, cout );
			}
			else if ( command == "remove" )
			{
				int number;
				in >> number;
				remove( r, number, cout );
			}
			else if ( command == "count" )
			{
				count( r, cout );
			}
			else if ( command == "find" )
			{
				int number;
				in >> number;
				find( r, number, cout );
			}
			else
			{
				cout << "Derr...I didn't know that command: " << endl;
				in.ignore( 500, '\n' );
			}

			in >> command;
		}
	}
}
/*
 * How is this delimited?
 * delimiter will handle this
 */ 
Ingredient read_ingredient( istream &in, char delimiter )
{
	Ingredient i;

	double amount;
	string measure;
	string name;
	in >> amount;
	in.ignore( 500, delimiter );
	getline( in, measure, delimiter );
	getline( in, name );

	i.update_name( name );
	i.update_amount( amount );
	i.update_measure( measure );

	return i;
}
void load( string recipe_file, Recipe &r )
{
	ifstream in(recipe_file);
	string name;

	in >> name; //get rid of the word "Name:"

	getline( in, name );

	bool stop = false;
	Ingredient i = read_ingredient( in, '\t' );
	while( !in.fail() && in.peek() != '#' && !stop ) 
	{
		r.add_ingredient(i, r.get_ingredient_count() );

		if ( in.peek() == '#' )
			stop = true;
		else
			i = read_ingredient( in, '\t' );
	}

	string steps, step;

	in >> steps; //get rid of the "####"
	in >> steps; // get rid of the word steps;


	
	getline( in, step );
	while( !in.fail() )
	{
		steps += step;
		getline( in, step );
	}

	steps += step;

	r.update_name( name );
	r.update_steps( steps );


	in.close();
}
void save( string save_file, Recipe r )
{
	ofstream out(save_file);
	r.show_recipe( out );
	out.close();
}
void add( Recipe &r, istream &in, ostream &out )
{
	string what_are_we_adding;
	in >> what_are_we_adding;
	out << what_are_we_adding << " " ;
	while( isspace( in.peek() ) ) in.get();
	if ( what_are_we_adding == "name" )
	{
		string name;
		getline( in, name );
		out << name;
		r.update_name( name );
	}
	else if ( what_are_we_adding == "ingredient" )
	{
		Ingredient i = read_ingredient( in, '\t' );
		i.display(out);
		r.add_ingredient( i, r.get_ingredient_count() );
	}
	else if ( what_are_we_adding == "step" )
	{
		string step;
		getline( in, step );
		out << step;
		string steps = r.get_steps();
		steps += step;
		r.update_steps( steps );
	}
	else
	{
		out << "\tAhhh...I'm not sure what you are asking me to add." << endl;
	}
	out << endl;
}
void remove( Recipe &r, int number, ostream &out )
{
	Ingredient i = r.remove_ingredient( number );
	out << "Ingredient removed: ";
	i.display(out);
	out << endl;
}
void count( Recipe r, ostream &out )
{
	out << "Number of ingredients: " << r.get_ingredient_count() << endl;
}
void find( Recipe r, int number, ostream &out )
{
	Ingredient i = r.get_ingredient( number );
	out << "Ingredient found: ";
	i.display(out);
	out << endl;
}
