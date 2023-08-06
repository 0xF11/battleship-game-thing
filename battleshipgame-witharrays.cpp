#include <iostream>
#include <limits>


void errorhandler()
{
	(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
	int restart{};
	restart:

	bool battleships[4][4]
	{
		{1,1,0,1},
		{0,1,0,1},
		{0,0,0,1},
		{0,0,1,0},
	};

	int shooter{};
	int roundsplayed{};
	std::cout << "Man your stations men! Its time to take out some ships! \n\n";
	while (shooter < 7)
	{
		// ERROR HANDLING (GAME) START 
		if (!std::cin)
		{
			if (std::cin.eof()) // user somehow escapes 
			{
				exit(0);// close program
			}
			std::cin.clear(); // puts user back into an operational mode
			errorhandler(); // gets rid of any errors above and ignores extra variable input past the first variable
		}
		// ERROR HANDLING (GAME) END


		// GAME START
		int row, column; // initalizes row and column for use later
		std::cout << "------------------------------------\n";

		std::cout << "Enter the row you want to target! \n";
		std::cin >> row; // Intake the row the user wants to hit
		std::cout << "You're aiming for row " << row << " Now choose the column you want to hit. \n";
		std::cin >> column; // intakes the column the user wants to hit

		if (battleships[row][column]) // assigns battleships array numbers to row and column
		{
			battleships[row][column] = 0; // if the user hits a battleship it will set our boolean to false 
			std::cout << "Hit! Nice work meatbag!\n"; // lets user know they hit something 
			++shooter; // adds to the shooter count (amount of times the player has hit the target)
		}
		else 
		{
			std::cout << "\nYou missed. Way to go doucebag.\n"; // Otherwise let the player know theyve missed
			
		}
		++roundsplayed; // adds to the round counter
		if (roundsplayed == 15) // if the player actually fucking sucks output this line of code
		{
			std::cout << "You're gonna get us killed with this horrible shooting! C'mon maggot! You're shooting like a girl.\n";

		}


	}

	std::cout << "Good job kid, We won the war thanks to you!\n";
	std::cout << "---------------------------------------------\n";
	std::cout << "If you would like to play again please type y, if not type n or close the application.\n";
	// GAME END

	// REPLAYERROR HANDLING START

	if (!std::cin)
	{
		if (std::cin.eof()) // user leaves line somehow
		{
			exit(0); // end program early
		}

		std::cin.clear();
		errorhandler(); // clears variables used past first variable and handles errors
	}
	// REPLAYERROR HANDLING END	

	// REPLAY START
	char replay{};
	std::cin >> replay;
	if (replay == 'y')
	{
		goto restart;
	}
	else
	{
		return 0;
	}
	// REPLAY END

	return 0;


}
