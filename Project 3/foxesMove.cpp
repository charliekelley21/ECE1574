foxesMove()
{
	for (int z=0;z<foxCount; z++;)
	{
		if ( !gameDone )
		{
			double FX = foxes[z][0];
			double FY = foxes[z][1];
			double dist1 = 999;
			double dist2 = 999;
			double dist3 = 999;
			double dist4 = 999;
			double dist5 = 999;
			double dist6 = 999;
			double dist7 = 999;
			double dist8 = 999;
			int distMarker;
			double minDist = 999;
	
			//determining where to move 	//calculating distnace of each possible move
	
			//1
			if( FY != 0 && (gameBoard[ FY - 1][FX] != BUSH ||  gameBoard[ FY - 1][FX] != HOLE))
			{
				dist1 = distance( FX, (FY-1), rabbitX, rabbitY);
			}
			if ( dist1 < minDist )
			{
				distMarker = 1;
				minDist = dist1;
			}
			//2
			if( FY != 0 && FX != (collumns - 1) && (gameBoard[ FY - 1][FX+ 1] != BUSH ||  gameBoard[ FY - 1][FX + 1] != HOLE) )
			{
				dist2 = distance( (FX+1), (FY-1), rabbitX, rabbitY);
				if ( dist2 < minDist )
				{
					distMarker = 2;
					minDist = dist2;
				}
			}
			//3
			if( FX != (collumns - 1) && (gameBoard[FY][FX + 1] != BUSH ||  gameBoard[FY][FX + 1] != HOLE) )
			{
				dist3 = distance( (FX+1), FY, rabbitX, rabbitY);
				if ( dist3 < minDist )
				{
					distMarker = 3;
					minDist = dist3;
				}
			}
			//4
			if( FX != (collumns - 1) && FY != (rows - 1) && (gameBoard[FY+1][FX+1] != BUSH || gameBoard[FY+1][FX+1] != HOLE) )
			{
				dist4 = distance( (FX+1) , (FY+1), rabbitX, rabbitY);
				if ( dist4 < minDist )
				{
					distMarker = 4;
					minDist = dist4;
				}
			}
			//5
			if( FY != (rows - 1) && (gameBoard[FY+1][FX] != BUSH || gameBoard[FY+1][FX] != HOLE) )
			{
				dist5 = distance( (FX) , (FY+1), rabbitX, rabbitY);
				if ( dist5 < minDist )
				{
					distMarker = 5;
					minDist = dist5;
				}
			}
			//6
			if( FX != 0 && FY != (rows - 1) && (gameBoard[FY+1][FX-1] != BUSH || gameBoard[FY+1][FX-1] != HOLE) )
			{
				dist6 = distance( (FX-1) , (FY+1), rabbitX, rabbitY);
				if ( dist6 < minDist )
				{
					distMarker = 6;
					minDist = dist6;
				}
			}
			//7
			if( FX != 0 && (gameBoard[FY][FX-1] != BUSH || gameBoard[FY][FX-1] != HOLE) )
			{
				dist7 = distance( (FX-1) , FY, rabbitX, rabbitY);
				if ( dist7 < minDist )
				{
					distMarker = 7;
					minDist = dist7;
				}
			}
			//8
			if( FX != 0 && FY != 0 && (gameBoard[FY-1][FX-1] != BUSH || gameBoard[FY-1][FX-1] != HOLE) )
			{
				dist8 = distance( (FX-1) , (FY-1), rabbitX, rabbitY);
				if ( dist8 < minDist )
				{
					distMarker = 8;
					minDist = dist8;
				}
			}
	
			//moving fox[z]
	
			switch( distMarker )
			{
				case 1: 
				gameBoard[FY][FX] = BLANK;
				foxes[z][1] = foxes[z][1] - 1;
				break;
				case 2: 
				gameBoard[FY][FY] = BLANK;
				foxes[z][1] = foxes[z][1] - 1;
				foxes[z][0] = foxes[z][0] + 1;
				break;
				case 3: 
				gameBoard[FY][FX] = BLANK;
				foxes[z][0] = foxes[z][0] + 1;
				break;
				case 4: 
				gameBoard[FY][FX] = BLANK;
				foxes[z][1] = foxes[z][1] + 1;
				foxes[z][0] = foxes[z][0] + 1;
				break;
				case 5: 
				gameBoard[FY][FX] = BLANK;
				foxes[z][1] = foxes[z][1] + 1;
				break;
				case 6: 
				gameBoard[FY][FX] = BLANK;
				foxes[z][1] = foxes[z][1] + 1;
				foxes[z][0] = foxes[z][0] - 1;
				break;
				case 7:
				gameBoard[FY][FX] = BLANK;
				foxes[z][0] = foxes[z][0] - 1;
				break;
				case 8:
				gameBoard[FY][FX] = BLANK;
				foxes[z][1] = foxes[z][1] - 1;
				foxes[z][0] = foxes[z][0] - 1;
				break;
			}
			if ( gameBoard[FY][FX] == RABBIT )
			{
				gameBoard[foxes[z][1]][foxes[z][0]] = EATEN
				gameDone = true;
			}
			else
			{
				gameBoard[foxes[z][1]][foxes[z][0]] = FOX;
			}
		}
	}
}