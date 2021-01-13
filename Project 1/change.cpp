/*
*  Purpose for program
*  This program will allow to prices to be enter, the lower is considered the cost
*  of something, the higher the amount paid and the program will output the change
*  due in coins.
*
*  Programmer: Charles Kelley
*  Date: September 13, 2018
*
*  Honor Code: I have neither given nor received any unauthorized assistance with this program.
*/

#include "change.h"

void change()
{
    double amount1, amount2, bill, paid;
	double diff;
    int change;

    cin >> amount1 >> amount2;
	
	bill = amount1;
	paid = amount2;
	if ( amount1 > amount2 )
	{
		bill = amount2;
		paid = amount1;
	}
	cout << setprecision(2) << fixed;
	cout << "Bill: $" << bill << endl;
	cout << "Paid: $" << paid << endl;
	
	diff = paid - bill;
	cout << "Change Due: $" << diff << endl;
	change = int( round( (diff * 100) ) );
	//Dollars
	if ( change >= 100 )
	{
		int dollars = (change - (change % 100) ) / 100;
		cout << "	Dollars: " << dollars << endl;
		
		change = int( round( change - (dollars * 100)));
	}
	//quarters
	if ( change >= 25 )
	{
		int quarters = (change - (change % 25) ) / 25;
		cout << "	Quarters: " << quarters << endl;
		
		change = int( round( change - (quarters * 25)));
	}
	//dimes
	if ( change >= 10 )
	{
		int dimes = (change - (change % 10) ) / 10;
		cout << "	Dimes: " << dimes << endl;
		
		change = int( round( change - (dimes * 10)));
	}
	//nickels
	if ( change >= 5 )
	{
		int nickels = (change - (change % 5) ) / 5;
		cout << "	Nickels: " << nickels << endl;
		
		change = int( round( change - (nickels * 5)));
	}
	//pennies
	if ( change > 0.1 )
	{
		cout << "	Pennies: " << change << endl;
	}
}