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

double stdDev( int x1, int x2, int x3, int x4 );
double mean( int x1, int x2, int x3, int x4 );
double variance( int x1, int x2, int x3, int x4 );
double sumOfSquares( double d1, double d2, double d3, double d4 );
void standardDeviation( string input, string output );