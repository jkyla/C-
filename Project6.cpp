//Kyla Johnson
//COP2000 0M1
//This game simulates a game of chance

#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

class Game
{
private:
	int balance; // holds the current balance
	int random; // holds the rolled value from random generator
	char answer; //holds the value if the user wants to roll again (y or n)

	void validateBalance(); //validates input balance from user
	void validateAgain(); // validates the y or n answer

public:
	//Game: Game constructor for class Game
	Game()
	{
		srand((unsigned)time(0));
		this->balance = 0;
	}
	void setBalance(int bal); // reads the starting balance from user
	void roll(); //calls the random generator to return value between 1-6
	void display(); //displays the results (even or odd)
	void again(); // determines if the user wants to play again or quit
};

/***********************************Method Definitions***************************************/


void Game::setBalance(int bal)    // sets the integer passed from the user into private variable balance and then calls the validate function
{
	this->balance = bal;    
	validateBalance();
}


void Game::roll()
{
	
	int rolledValue = (rand() % 6 + 1); // rolls the generator and returns a random number between 6 and 1, sets it to private variable random
	this->random = rolledValue; //sets the generated value to member variable random
	
	if (balance >= 1) {
		if (rolledValue % 2 == 0)  //adds 1 to the user balance if rolled number is even
			balance += 1;
		else
			balance -= 1; //subtracts 1 from user balance if rolled number is odd
	}
	display();
	if (balance >= 1) {
		again(); // calls the again function to ask the user if they want to continue playing
	}
	else {
		cout << " Sorry, you lose. Better luck next time! " << endl;
	}
}

void Game::display() // displays the results of the roll and resets the balance
{

	if (random % 2 == 0) {
		cout << random << " is even, you win $1" << endl;
		cout << "Your current balance is " << balance << endl;
	}
	else {
		cout << random << " is odd, you lose $1" << endl;
		cout << "Your current balance is :$" << balance << endl;
	}
}

void Game::again() //determines the balance and asks the user to play again
{
	
	cout << "Would you like to play again? Enter y for yes or n for no" << endl;
	cin >> answer; // retrieves the user answer
	
	validateAgain(); // calls the validate again function to determine if the game continues
	if (answer == 'y' || answer == 'Y') {
		roll();
	}
	
}

void Game::validateBalance() //validates the user input to ensure that it is a number input greater than 1
{

	while (true) {
		if (balance < 1) {
			cout << "  Invalid input. Please enter a value greater than or equal to 1  " << endl;
			cin >> balance;
		}
		else {
			break;
		}
	}
}

void Game::validateAgain() //validates the user answer 
{

	while (true) {
		if (answer != 'Y'
			&& answer != 'y'
			&& answer != 'N'
			&& answer != 'n') {
			cout << " Invalid input. Please try again. " << endl;
			again();
		}
		else
			break;
	}
}




/***********************Driver**************************************/

int main()
{
	using namespace std;
	
	//instantiate an object of class Game
	Game play;

	//initialize local variable for input from user
	int startBal;

	startBal = getBalance(); //calls the function to get input from user

	play.setBalance(startBal); //sends the user input to set balance in the class

	play.roll(); // calls the function to roll the generator and start the game

	system("pause");
	return 0;
	
}

/********function definition*********************************/
int getBalance() //asks the user to enter starting balance
{
	using namespace std;
	int bal;

	cout << "Enter your starting balance. Must be a value greater than 1 to play. " << endl;
	cin >> bal;
	return bal;
}










