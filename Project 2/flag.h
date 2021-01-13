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

void flags( string input, string output );
void name( string name_string, ifstream& in2, string& flagName, ofstream& out, string output_file );
void colors( string color_string, int&red, int& green, int& blue, int& gold, int& white, int& black, int& orange, ifstream& in2, ofstream& out, string output_file );
void landmass( string landmass_string, string& flagLandMass, ifstream& in2, ofstream& out, string output_file );
void getFlag( ifstream& in2, string& flagName, int& flagLandMass, int& zone, int& area, int& population,
	int& language, int& religion, int& bars, int& stripes, int& colours, int& red, int& green, int& blue, int& gold, int& white, int& black,
	int& orange, string& mainHue, int& circles, int& crosses, int& saltires, int& quarters, int& sunstars, int& crescent, int& triangle, 
	int& icon, int& animate, int& text, string& topLeftColour, string& botRightColour);
int colorMask( string color_string );
int flagColorMask(int& red, int& green, int& blue, int& gold, int& white, int& black, int& orange);
void output_flag(string& flagName, int& flagLandMass, int& zone, int& area, int& population,
	int& language, int& religion, int& bars, int& stripes, int& colours, int& red, int& green, int& blue, int& gold, int& white, int& black,
	int& orange, string& mainHue, int& circles, int& crosses, int& saltires, int& quarters, int& sunstars, int& crescent, int& triangle, 
	int& icon, int& animate, int& text, string& topLeftColour, string& botRightColour, ofstream& out);