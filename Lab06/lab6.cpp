/*
*  Purpose for program
*  This program will allow the user to access four functions
*  that can determine the mean, sum of squares, varience, and 
*  standard deviation of four numbers.
*
*  Programmer: Charles Kelley
*  Date: September 28, 2018
*
*  Honor Code: I have neither given nor received any unauthorized assistance with this program.
*/

#include "lab6.h"

//functions
double mean( int x1, int x2, int x3, int x4 )
{
	double answer, sum;
	sum = double( x1 + x2 + x3 + x4 );
	answer = sum / 4;
	
	return answer;
}

double sumOfSquares( double d1, double d2, double d3, double d4 )
{
	double answer;
	answer = pow( d1, 2) + pow( d2, 2)+ pow( d3, 2) + pow( d4, 2);
	
	return answer;
}

double variance( int x1, int x2, int x3, int x4 )
{
	double answer, average;
	double x11, x22, x33, x44;
	average = mean( x1, x2, x3, x4 );
	x11 = x1 - average;
	x22 = x2 - average;
	x33 = x3 - average;
	x44 = x4 - average;
	answer = sumOfSquares( x11, x22, x33, x44 )/4;
	
	return answer;
}

double stdDev( int x1, int x2, int x3, int x4 )
{
	double answer;
	answer = sqrt( variance( x1, x2, x3, x4 ) );
	
	return answer;
}
void standardDeviation( string input, string output )
{
	ifstream in(input);
	ofstream out(output);
	
	string command;
	int num1, num2, num3, num4;
	
	in >> command >> num1 >> num2 >> num3 >> num4; //prime
	while( !in.fail() )
	{
		out << "Command: " << command << " ";
		out << num1 << " " << num2 << " " << num3 << " " <<num4 <<endl;
		double answer;
		if ( command == "mean" )
		{
			answer = mean( num1, num2, num3, num4 );
			out << "Mean: " << answer << endl;
		}
		else if ( command == "standard-deviation" )
		{
			answer = stdDev( num1, num2, num3, num4 );
			out << "Standard Deviation: " << answer << endl;
		}
		else if ( command == "sum-of-squares" )
		{
			answer = sumOfSquares( num1, num2, num3, num4 );
			out << "Sum of Squares: " << answer << endl;
		}
		else if ( command == "variance" )
		{
			double answer = variance( num1, num2, num3, num4 );
			out << "Variance: " << answer << endl;
		}
		in >> command >> num1 >> num2 >> num3 >> num4; //reprime
	}
	in.close();
	out.close();
}


