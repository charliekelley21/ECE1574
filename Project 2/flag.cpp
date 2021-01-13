/*
*  Purpose for program:
*  
*  
*  
*
*  Programmer: Charles Kelley
*  Date: October 5, 2018
*
*  Honor Code: I have neither given nor received any unauthorized assistance with this program.
*/

#include "flag.h"


ifstream in2("flags.csv");
string flagName;
int flagLandMass;
int zone;
int area;
int population;
int language;
int religion;
int bars;
int stripes;
int colours;
int red, green, blue, gold, white, black, orange;
string mainHue;
int circles;
int crosses;
int saltires;
int quarters;
int sunstars;
int crescent;
int triangle;
int icon;
int animate;
int text;
string topLeftColour;
string botRightColour;

void getFlag( ifstream& in2, string& flagName, int& flagLandMass, int& zone, int& area, int& population,
	int& language, int& religion, int& bars, int& stripes, int& colours, int& red, int& green, int& blue, int& gold, int& white, int& black,
	int& orange, string& mainHue, int& circles, int& crosses, int& saltires, int& quarters, int& sunstars, int& crescent, int& triangle, 
	int& icon, int& animate, int& text, string& topLeftColour, string& botRightColour)
{
	in2 >> flagName;			in2.ignore();
	in2 >> flagLandMass;		in2.ignore();
	in2 >> zone;				in2.ignore();
	in2 >> area;				in2.ignore();
	in2 >> population;			in2.ignore();
	in2 >> language;			in2.ignore();
	in2 >> religion;			in2.ignore();
	in2 >> bars;				in2.ignore();
	in2 >> stripes;				in2.ignore();
	in2 >> colours;				in2.ignore();
	in2 >> red;					in2.ignore();
	in2 >> green;				in2.ignore();
	in2 >> blue;				in2.ignore();
	in2 >> gold;				in2.ignore();
	in2 >> white;				in2.ignore();
	in2 >> black;				in2.ignore();
	in2 >> orange;				in2.ignore();
	in2 >> mainHue;				in2.ignore();
	in2 >> circles;				in2.ignore();
	in2 >> crosses;				in2.ignore();
	in2 >> saltires;			in2.ignore();
	in2 >> quarters;			in2.ignore();
	in2 >> sunstars;			in2.ignore();
	in2 >> crescent;			in2.ignore();
	in2 >> triangle;			in2.ignore();
	in2 >> icon;				in2.ignore();
	in2 >> animate;				in2.ignore();
	in2 >> text;				in2.ignore();
	in2 >> topLeftColour;		in2.ignore();
	in2 >> botRightColour;		
}

void name( string name_string, ifstream& in2, string& flagName, ofstream& out, string output_file )
{
	int foundFlag = 0;
	int flagNumber = 1;
	//ofstream out_append;
	out.open (output_file, ios::app);
	//out.open(output_file, std::ios::app);
	
	getFlag(in2, flagName, flagLandMass, zone, area, population, language, religion, bars, stripes, colours, red, green, blue, gold, white, black, orange, mainHue, circles, crosses, saltires, quarters, sunstars, crescent, triangle, icon, animate, text, topLeftColour, botRightColour);
	while( !in2.fail() )
	{
		if( flagName.find( name_string ))
		{
			foundFlag = 1;
			out << "Flag: " << flagNumber;
			output_flag(flagName, flagLandMass, zone, area, population, language, religion, bars, stripes, colours, red, green, blue, gold, white, black, orange, mainHue, circles, crosses, saltires, quarters, sunstars, crescent, triangle, icon, animate, text, topLeftColour, botRightColour, out);
		}
		getFlag(in2, flagName, flagLandMass, zone, area, population, language, religion, bars, stripes, colours, red, green, blue, gold, white, black, orange, mainHue, circles, crosses, saltires, quarters, sunstars, crescent, triangle, icon, animate, text, topLeftColour, botRightColour);
		flagNumber = flagNumber + 1;
	}
	if( foundFlag == 0 )
	{
		out << "Sorry no flags with part of its name " << name_string << " found." << endl;
	}
}
//-----------------------------------------
void colors( string color_string, int&red, int& green, int& blue, int& gold, int& white, int& black, int& orange, ifstream& in2, ofstream& out, string output_file )
{
	int foundFlag = 0;
	int flagNumber = 1;
	getFlag(in2, flagName, flagLandMass, zone, area, population, language, religion, bars, stripes, colours, red, green, blue, gold, white, black, orange, mainHue, circles, crosses, saltires, quarters, sunstars, crescent, triangle, icon, animate, text, topLeftColour, botRightColour);	while( !in2.fail() )
	while ( !in2.fail() )
	{
		//ofstream out_append;
		//out.open (output_file, ios::app);
		//out.open(output_file, std::ios::app);
		int color_mask = colorMask( color_string );
		int flag_mask = flagColorMask(red, green, blue, gold, white, black, orange);
		//if( flag_mask == color_mask)
		//{
			foundFlag = 1;
			out << "Flag: " << flagNumber;
			output_flag(flagName, flagLandMass, zone, area, population, language, religion, bars, stripes, colours, red, green, blue, gold, white, black, orange, mainHue, circles, crosses, saltires, quarters, sunstars, crescent, triangle, icon, animate, text, topLeftColour, botRightColour, out);
		//}
		getFlag(in2, flagName, flagLandMass, zone, area, population, language, religion, bars, stripes, colours, red, green, blue, gold, white, black, orange, mainHue, circles, crosses, saltires, quarters, sunstars, crescent, triangle, icon, animate, text, topLeftColour, botRightColour);
		flagNumber = flagNumber + 1;
	}
	if( foundFlag == 0 )
	{
		out << "Sorry no flags with just " << color_string << " found." << endl;
	}
}
//-----------------------------------------
void landmass( string landmass_string, int& flagLandMass, ifstream& in2, ofstream& out, string output_file )
{
	int foundFlag = 0;
	//ofstream out_append;
	//out.open ( output_file, ios::app);
	//out.open(output_file, std::ios::app);
	int flagNumber = 1;
	getFlag(in2, flagName, flagLandMass, zone, area, population, language, religion, bars, stripes, colours, red, green, blue, gold, white, black, orange, mainHue, circles, crosses, saltires, quarters, sunstars, crescent, triangle, icon, animate, text, topLeftColour, botRightColour);
	while( !in2.fail() )
	{
		string landMassString;
		if( flagLandMass == 1 )
		{ landMassString = "N.America"; }
		if( flagLandMass == 2 )
		{ landMassString = "S.America"; }
		if( flagLandMass == 3 )
		{ landMassString = "Europe"; }
		if( flagLandMass == 4 )
		{ landMassString = "Africa"; }
		if( flagLandMass == 5 )
		{ landMassString = "Asia"; }
		if( flagLandMass == 6 )
		{ landMassString = "Oceania"; }
		if( landMassString.find( landmass_string ) )
		{
			foundFlag = 1;
			out << "Flag: " << flagNumber;
			output_flag(flagName, flagLandMass, zone, area, population, language, religion, bars, stripes, colours, red, green, blue, gold, white, black, orange, mainHue, circles, crosses, saltires, quarters, sunstars, crescent, triangle, icon, animate, text, topLeftColour, botRightColour, out);
		}
		getFlag(in2, flagName, flagLandMass, zone, area, population, language, religion, bars, stripes, colours, red, green, blue, gold, white, black, orange, mainHue, circles, crosses, saltires, quarters, sunstars, crescent, triangle, icon, animate, text, topLeftColour, botRightColour);
		flagNumber = flagNumber + 1;
		
	}
	if( foundFlag == 0 )
		{
			out << "Sorry no flags in area " << landmass_string << " found." << endl;
		}
}
//-----------------------------------------
void flags( string input, string output )
{
	ifstream in(input);
	ofstream out;
	out.open(output);
	
	string command;
	
	in >> command; //prime
	in.ignore();
	while( !in.fail() )
	{
		out << "Command: " << command << " ";
		string argument;
		
		if ( command == "name" )
		{
			cout << "name command" << endl;
			getline( in, argument, '\n' );
			out << argument << endl;
			name( argument, in2, flagName, out, output );
			
		}
		else if ( command == "landmass" )
		{
			cout << "landMass command" << endl;
			in >> argument;
			out << argument << endl;
			landmass(argument, flagLandMass, in2, out, output);
		}
		else if ( command == "colors" )
		{
			cout << "colors command" << endl;
			getline( in, argument, '\n');
			out << argument << endl;
			colors(argument, red, green, blue, gold, white, black, orange, in2, out, output);
		}
		
		in >> command; //reprime
	}
	in.close();
	out.close();
}
//------------------------------------------
int colorMask( string color_string )
{
	const int mask_end = 10000000;
	const int red_mask = 1000000;
	const int green_mask = 100000;
	const int blue_mask = 10000;
	const int gold_mask = 1000;
	const int white_mask = 100;
	const int black_mask = 10;
	const int orange_mask = 1;
	
	int red = -1, green = -1, blue = -1, gold = -1, white = -1, black = -1, orange = -1;
	
	int mask = mask_end;
	if ( color_string.find( "red" ) != -1 )
	{
		mask = mask + red_mask;
	}
	if ( color_string.find( "green" ) != -1 )
	{
		mask = mask + green_mask;
	}
	if ( color_string.find( "blue" ) != -1 )
	{
		mask = mask + blue_mask;
	}
	if ( color_string.find( "gold" ) != -1 )
	{
		mask = mask + gold_mask;
	}
	if ( color_string.find( "white" ) != -1 )
	{
		mask = mask + white_mask;
	}
	if ( color_string.find( "black" ) != -1 )
	{
		mask = mask + black_mask;
	}
	if ( color_string.find( "orange" ) != -1 )
	{
		mask = mask + orange_mask;
	}
	return mask;
}

int flagColorMask(int& red, int& green, int& blue, int& gold, int& white, int& black, int& orange)
{
	const int mask_end = 10000000;
	const int red_mask = 1000000;
	const int green_mask = 100000;
	const int blue_mask = 10000;
	const int gold_mask = 1000;
	const int white_mask = 100;
	const int black_mask = 10;
	const int orange_mask = 1;
	int flagMask = mask_end;
	if ( red == 1 )
	{
		flagMask = flagMask + red_mask;
	}
	if ( green == 1 )
	{
		flagMask = flagMask + green_mask;
	}
	if ( blue ==1 )
	{
		flagMask = flagMask + blue_mask;
	}
	if ( gold == 1 )
	{
		flagMask = flagMask + gold_mask;
	}
	if ( white == 1 )
	{
		flagMask = flagMask + white_mask;
	}
	if ( black == 1 )
	{
		flagMask = flagMask + black_mask;
	}
	if ( orange ==1 )
	{
		flagMask = flagMask + orange_mask;
	}
	return flagMask;
}

void output_flag(string& flagName, int& flagLandMass, int& zone, int& area, int& population,
	int& language, int& religion, int& bars, int& stripes, int& colours, int& red, int& green, int& blue, int& gold, int& white, int& black,
	int& orange, string& mainHue, int& circles, int& crosses, int& saltires, int& quarters, int& sunstars, int& crescent, int& triangle, 
	int& icon, int& animate, int& text, string& topLeftColour, string& botRightColour, ofstream& out)
{
	//ofstream out_append;
	out.open ("output.txt", std::ios::app);
	cout << "outputflag working" << endl;
	out << flagName << " ";
	switch( flagLandMass )
	{
		case 1: 
		out << "N.America ";
		break;
		case 2: 
		out << "S.America ";
		break;
		case 3: 
		out << "Europe ";
		break;
		case 4: 
		out << "Africa ";
		break;
		case 5: 
		out << "Asia ";
		break;
		case 6: 
		out << "Oceania ";
		break;
	}
	switch( zone )
	{
		case 1: 
		out << "NE ";
		break;
		case 2: 
		out << "SE ";
		break;
		case 3: 
		out << "SW ";
		break;
		case 4: 
		out << "NW ";
		break;
	}
	out << area << " 1000KM^2 ";
	out << population << "MIL ";
	switch( language )
	{
		case 1: 
		out << "English ";	break;
		case 2: 
		out << "Spanish ";	break;
		case 3: 
		out << "French ";	break;
		case 4: 
		out << "German ";	break;
		case 5: 
		out << "Slavic ";	break;
		case 6: 
		out << "Other Indo-European ";	break;
		case 7:
		out << "Chinese ";	break;
		case 8:
		out << "Arabic ";	break;
		case 9:
		out << "Japanese/Turkish/Finnish/Magyar ";	break;
		case 10:
		out << "Other ";	break;
	}
	switch( religion )
	{
		case 0:
		out << "Catholic ";
		break;
		case 1: 
		out << "Other Christian ";
		break;
		case 2: 
		out << "Muslim ";
		break;
		case 3: 
		out << "Buddhist ";
		break;
		case 4: 
		out << "Hindu ";
		break;
		case 5: 
		out << "Ethnic ";
		break;
		case 6: 
		out << "Marxist ";
		break;
		case 7:
		out << "Other ";
		break;
	}
	out << endl;
	out << "Bars: " << bars;
	out << " Stripes: " << stripes;
	out << " Colors: " << colors;
	if( red == 1 )
	{
		out << "red ";
	}
	if( green == 1 )
	{
		out << "green ";
	}
	if( blue == 1 )
	{
		out << "blue ";
	}
	if( gold == 1 )
	{
		out << "yellow ";
	}
	if( white == 1 )
	{
		out << "white ";
	}
	if( black == 1 )
	{
		out << "black ";
	}
	if( orange == 1 )
	{
		out << "orange ";
	}
	out << "Main hue: " << mainHue << endl;
	out << "Shapes: ";
	if( circles > 0 )
	{
		out << "Circles ";
	}
	if( crosses > 0 )
	{
		out << "Crosses ";
	}
	if( saltires > 0 )
	{
		out << "Saltires ";
	}
	if( quarters > 0 )
	{
		out << "Quarters ";
	}
	if( sunstars > 0 )
	{
		out << "Sunstars ";
	}
	if( crescent > 0 )
	{
		out << "Crescent ";
	}
	if( triangle > 0 )
	{
		out << "Triangles ";
	}
	if( icon > 0 )
	{
		out << "Icon ";
	}
	if( animate > 0 )
	{
		out << "Animate ";
	}
	if( text > 0 )
	{
		out << "Text ";
	}
	out << endl << "Top Left: " << topLeftColour << " Bottom Right: " << botRightColour << endl;
}








