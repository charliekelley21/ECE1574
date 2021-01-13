 /*
*  Purpose for program:
*  This program is designed to take an input
*  file and use designed functions to move 
*  between units and write to an output file.
*
*  Programmer: Charles Kelley
*  Date: October 3, 2018
*
*  Honor Code: I have neither given nor received any unauthorized assistance with this program.
*/

#include "lab7.h"

const double CTOF = 5.0/9.0;
const double FTOC = 9.0/5.0;
const double CTOI = 2.54;
const double KTOM = 1.609344;
//------------------------------------------------
void fromSeconds( int time, int& minutes, int& seconds)
{
	int holder;
	if ( time >= 60 )
	{
		minutes = (time - (time % 60 )) / 60;
		holder = time % 60;
	}
	else
	{
		minutes = 0;
	}
	if ( holder > 0 )
	{
		seconds = holder;
	}
}
int toSeconds( int hours, int minutes, int seconds )
{
	int totalTime;
	totalTime = ( hours * 3600 ) + ( minutes * 60 ) + seconds;
	return totalTime;
}
//------------------------------------------------
double toCelsius( double degrees )
{
	double answer;
	answer = CTOF * ( degrees - 32.0 );
	return answer;
}
double toFahrenheit( double degress )
{
	double answer;
	answer = ( degress * FTOC ) + 32.0;
	return answer;
}
//------------------------------------------------
double toInches( double centimeters )
{
	double answer;
	answer = centimeters / CTOI;
	return answer;
}
double toCentimeters( double inches )
{
	double answer;
	answer = inches * CTOI;
	return answer;
}
//------------------------------------------------
double toMiles( double kilometers )
{
	double answer;
	answer = kilometers / KTOM;
	return answer;
}
double toKilometers( double miles )
{
	double answer;
	answer = miles * KTOM;
	return answer;
}
//------------------------------------------------
void conversions( string input, string output )
{
	ifstream in(input);
	ofstream out(output);
	
	string command;
	double num1, num2, num3;
	int minutes, seconds;
	
	in >> command >> num1; //prime
	while( !in.fail() )
	{
		out << "Command: " << command << " " << num1 << " ";
		double answer;
		if ( command == "to-seconds" )
		{
			in.ignore();
			in >> num2;
			in.ignore();
			in >> num3;
			out << num2 << " " << num3 << " ";
			out << toSeconds( num1, num2, num3 ) << endl;
		}
		else if ( command == "from-seconds" )
		{
			fromSeconds( num1, minutes, seconds );
			out << minutes << ":" << seconds << endl;
		}
		else if ( command == "to-Celsius" )
		{
			out << toCelsius( num1 ) <<endl;
		}
		else if ( command == "to-Fahrenheit" )
		{
			out << toFahrenheit( num1 ) <<endl;
		}
		else if ( command == "to-inches" )
		{
			out << toInches( num1 ) <<endl;
		}
		else if ( command == "to-centimeters" )
		{
			out << toCentimeters( num1 ) <<endl;
		}
		else if ( command == "to-miles" )
		{
			out << toMiles( num1 ) <<endl;
		}
		else if ( command == "to-kilometers" )
		{
			out << toKilometers( num1 ) <<endl;
		}
		in >> command >> num1; //reprime
	}
	in.close();
	out.close();
}