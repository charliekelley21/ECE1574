int main()
{
	ifstream in("flags.csv");
	string name;
	int landMass;
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
	
	getline( in, name, ',');
	while ( !in.fail() )
	{
		in >> landMass;
		in.ignore();
		in >> zone;
		in.ignore();
		in >> area;
		in.ignore();
		in >> population;
		in.ignore();
		in >> language;
		in.ignore();
		in >> religion;
		in.ignore();
		in >> bars;
		in.ignore();
		in >> stripes;
		in.ignore();
		in >> colours;
		in.ignore();
		in >> red;
		in.ignore();
		in >> green;
		in.ignore();
		in >> blue;
		in.ignore();
		in >> gold;
		in.ignore();
		in >> white;
		in.ignore();
		in >> black;
		in.ignore();
		in >> orange;
		in.ignore();
		in >> mainHue;
		in.ignore();
		in >> circles;
		in.ignore();
		in >> crosses;
		in.ignore();
		in >> saltires;
		in.ignore();
		in >> quarters;
		in.ignore();
		in >> sunstars;
		in.ignore();
		in >> crescent;
		in.ignore();
		in >> triangle;
		in.ignore();
		in >> icon;
		in.ignore();
		in >> animate;
		in.ignore();
		in >> text;
		in.ignore();
		in >> topLeftColour;
		in.ignore();
		in >> botRightColour;
		in.ignore();
		
		getline( in, name, ','); //reprime
	}
}