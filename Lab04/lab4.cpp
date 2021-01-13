#include "lab4.h"

void quadradic()
{

    	double a, b, c, discrim, answer1, answer2;
	
    	cin >> a >> b >> c;
	
	discrim = ( b * b ) - ( 4 * a * c );
	
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;

	if ( discrim < 0 )
	{
		double imaginary;
		answer1 = ( -1 * b ) / ( 2 * a );
		imaginary = sqrt( -1 * discrim ) / ( 2 * a );
		cout << "Two imaginary solutions." << endl;
		cout << "x1 = " << answer1 << " + " << imaginary << "i" << endl;
		cout << "x2 = " << answer1 << " - " << imaginary << "i" << endl;
	}
	else if ( discrim == 0 )
	{
		answer1 = ( -1 * b ) / ( 2 * a );
		cout << "One real solution." << endl;
		cout << "x = " << answer1 << endl;
	}
	else
	{
		answer1 = (( -1 * b ) + sqrt( discrim ) ) / ( 2 * a );
		answer2 = (( -1 * b ) - sqrt( discrim ) ) / ( 2 * a );
		cout << "Two real solutions." << endl;
		cout << "x1 = " << answer1 << endl;
		cout << "x2 = " <<answer2 << endl;
	}
	
}