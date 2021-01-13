/*
*  Purpose for program
*  This program will allow to prices to be enter, the lower is considered the cost
*  of something, the higher the amount paid and the program will output the change
*  due in coins.
*
*  Programmer: Charles Kelley
*  Date: September 20, 2018
*
*  Honor Code: I have neither given nor received any unauthorized assistance with this program.
*/

#include "lab5.h"

void mathCalculator()
{


    string command;
    double argument1, argument2, answer;

    cin >> command;//prime
	cout << "Command Argument1 [Argument2] Answer" << endl;

    while( !cin.fail() )//test
    {
        if ( command == "exponential")
		{
			cin >> argument1;
			answer = exp( argument1 );
			cout << "exponential " << argument1 << " " << answer <<endl;
		}
		else if ( command == "natural-log" )
		{
			cin >> argument1;
			answer = log( argument1 );
			cout << "natural-log " << argument1 << " " << answer <<endl;
		}
		else if ( command == "log" )
		{
			cin >> argument1;
			answer = log10( argument1 );
			cout << "log " << argument1 << " " << answer <<endl;
		}
		else if ( command == "raised-to-the-power" )
		{
			cin >> argument1;
			cin >> argument2;
			answer = pow( argument1, argument2 );
			cout << "raised-to-the-power " << argument1 << " ";
			cout << argument2 << " " << answer <<endl;
		}
		else if ( command == "square-root" )
		{
			cin >> argument1;
			answer = sqrt( argument1 );
			cout << "square-root " << argument1 << " " << answer <<endl;
		}
		else if ( command == "ceiling" )
		{
			cin >> argument1;
			answer = ceil( argument1 );
			cout << "ceiling " << argument1 << " " << answer <<endl;
		}
		else if ( command == "floor" )
		{
			cin >> argument1;
			answer = floor( argument1 );
			cout << "floor " << argument1 << " " << answer <<endl;
		}
		else
		{
			cin >> argument1;
			cout << "Unknown command: " << command <<endl;

		}

        cin >> command;//re-prime
    }

}

