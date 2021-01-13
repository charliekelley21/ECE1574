/*
*  Purpose for program:
*  
*  create a program to practice Classes
*  set up an ingredient class to store in recipes
*  
*
*  Programmer: Charles Kelley
*  Date: December 3, 2018
*
*  Honor Code: I have neither given nor received any unauthorized assistance with this program.
*/


#include "Ingredient.h"

Ingredient::Ingredient()
{
	name = string();
	amount = double();
	measure = string();
}
void Ingredient::update_name(string new_name)
{
	name = new_name;
}
void Ingredient::update_amount(double new_amount)
{
	amount = new_amount;
}
void Ingredient::update_measure(string new_measure)
{
	measure = new_measure;
}
string Ingredient::get_name() const
{
	return name;
}
double Ingredient::get_amount() const
{
	return amount;
}
string Ingredient::get_measure() const
{
	return measure;
}
void Ingredient::display(std::ostream &out) const
{
	out << amount << '\t' << measure << '\t' << name;
}




