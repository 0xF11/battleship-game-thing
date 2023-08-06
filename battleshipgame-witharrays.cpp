#include <iostream>
#include <limits>

int errorhandler() // handles errors incase user inputs invalid variables
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
	int beggining;
	beggining: // allows user to restart the game if theydesire
	bool shipnumbers[5][5] // ship allignment
	{
		{1,0,0,1,0},
		{0,0,1,0,0},
		{0,0,0,1,0},
		{0,1,0,0,0},
		{0,0,0,0,1}
	};

	int hitammount{ 0 }; // hits
	int numberofturns{ 0 }; // turns



	while (hitammount < 6) // while ships are still alive
	{

		// error handling
		if (!std::cin)
		{
			if (std::cin.eof()) // user breaks out of line
			{
				exit(0);
			}
			std::cin.clear(); // sets user back to op mode
			errorhandler(); // handles errors
		}

		int row, column;// allows input for the row and the column
		std::cout << "Select your coordinates soldier!"; 

		std::cout << "\nWhat row would you like to attack! - Choose between 0 and 4\n";
		std::cin >> row; // intake row

		std::cout << "You are choosing to attack row " << row << " now, pick which colum in that row you're attacking: \n";
		std::cin >> column; // intake column

		if (shipnumbers[row][column])
		{
			shipnumbers[row][column] = 0; // If someone hits a ship set it to 0

			std::cout << "Nice shot! \n"; // Let player know they hit something.
			++hitammount; // add to hit ammount (makes sure game doesnt end prematurely)
		}
		else
		{
			std::cout << "You missed...\n"; // tell the player if they missed something
		}

		++numberofturns; // ad dto number of turns for final message
		errorhandler();
	}
	std::cout << "\n--------------------------------------------------------------------------------------------------------\n";
	std::cout << "\n--------------------------------------------------------------------------------------------------------";
	std::cout << "\n--------------------------------------------------------------------------------------------------------\n\n";
	std::cout << "Awesome! You where a winner at " << numberofturns << "The lowest possible turns you can win in is 6! \n";
	

  // restart game
		char yn{ 'a' };
		std::cout << "Play again? y/n";
		std::cin >> yn; 
		if (yn == 'y')
		{
			goto beggining;
		}
		if (yn == 'n')
		{
			return 0;
		}
		return 0;
	
}
