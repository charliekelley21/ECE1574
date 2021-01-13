void load( string fileName, ListItem shoppingList[SIZE], int &count, ostream &out2 )
{
	ifstream in2(fileName);
	
	//prime
	while( in.peek() == '#' && !in.fail() ) 
	{
		in.ignore( 500, '\n' );
	}
	in >> temp.id
	
	//test & process
	while ( !in2.fail() )
	{
		char moneySign;
		ListItem temp;
		
		//getline( in2, temp.id, '\t');
		//in2 >> temp.id;
		in2.ignore( 500, '\t' );
		getline( in2, temp.description, '\t');
		in2 >> temp.quantity;
		in2.ignore( 500, '\t' );
		in2 >> moneySign;
		in2 >> temp.cost;
		if ( count == SIZE )
		{ 
			//grow();
		}
		shoppingList[count] = temp;
		count += 1;
			
		//reprime
		while( in.peek() == '#' && !in.fail() ) 
		{
			in.ignore( 500, '\n' );
		}
		in >> temp.id
	}
}
	
	
	
	
	
	
	
	
	
	
	
	while ( !in2.fail() )
	{
		if (in2.peek() == '#')
		{
			in2.ignore( 500, '\n' );
		}
		else
		{
			char moneySign;
			ListItem temp;
			
			//getline( in2, temp.id, '\t');
			//in2 >> temp.id;
			in2.ignore( 500, '\t' );
			getline( in2, temp.description, '\t');
			in2 >> temp.quantity;
			in2.ignore( 500, '\t' );
			in2 >> moneySign;
			in2 >> temp.cost;
			if ( count == SIZE )
			{ 
				//grow();
			}
			shoppingList[count] = temp;
			count += 1;
		}
	}
	int showNum = count - 1;
	out2 << "Command: load " << fileName << endl;
	out2 << '\t' << "Loaded: " << showNum << endl;
}