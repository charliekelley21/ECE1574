#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

using std::string;
using std::ifstream;
using std::ofstream;
using std::cin;
using std::cout;
using std::endl;

void fromSeconds( int time, int& minutes, int& seconds);
int toSeconds( int hours, int minutes, int seconds );

double toCelsius( double degrees );
double toFahrenheit( double degress );

double toInches( double centimeters );
double toCentimeters( double inches );

double toMiles( double kilometers );
double toKilometers( double miles );

void conversions( string input, string output );