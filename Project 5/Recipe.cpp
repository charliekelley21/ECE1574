#include "Recipe.h"

Recipe::Recipe()
{
	size = 10;
	count = 0;
	list = new Ingredient[size];
}
bool Recipe::add_ingredient(Ingredient i, int location)
{
	if (location <= count && location >= 0 )
	{
		if ( count == size )
			grow();
		if (location = count)
			list[location] = i;
		else
		{
			make_hole(location);
			list[location] = i;
		}
		count++;
		return true;
	}
	else
		return false;
}
Ingredient Recipe::remove_ingredient(int location)
{
	if (location < count && location >= 0)
	{
		Ingredient temp = list[location];
		cover_up(location);
		count--;
		return temp;
	}
	else
	{
		return Ingredient();
	}
}
void Recipe::update_name(string new_name)
{
	name = new_name;
}
void Recipe::update_steps(string new_steps)
{
	steps = new_steps;
}
Ingredient Recipe::get_ingredient(int location) const
{
	if ( location < count && location >= 0)
		return list[location];
	else
		return Ingredient();
}
int Recipe::get_ingredient_count() const
{
	return count;
}
string Recipe::get_name() const
{
	return name;
}
string Recipe::get_steps() const
{
	return steps;
}
void Recipe::show_recipe( std::ostream &out ) const
{
	out << "Name: " << name << endl;
	for (int i = 0; i<count; i++)
	{
		list[i].display(out);
		out << endl;
	}
	out << "####" << endl;
	out << endl;
	out << "Steps: " << endl;
	out << steps << endl;
}
void Recipe::grow()
{
	Ingredient* temp = list; //get a copy
	list = new Ingredient[size * 2]; //make a new larger array
	for ( int i=0; i<size; i++ )
		list[i] = temp[i]; //copy old array to new array
	delete [] temp;
	size *= 2;
	temp = nullptr;
}
void Recipe::cover_up( int location )
{
	for (int i=location; i<count-1; i++)
		list[i] = list[i+1];
}
void Recipe::make_hole(int location)
{
	for (int i=count; i>location; i--)
		list[i] = list[i-1];
}




















