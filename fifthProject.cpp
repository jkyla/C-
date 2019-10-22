//Kyla Johnson
//COP2000.OM1
//Project 5 - This project determines which of a company's four divisions (North, South, East, West) has the greatest sales for the quarter.

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//function prototypes

float getSales(string); // asks the user to input sales value per division
void validate(float); // validates the user input for each sales value
void findHighest(float N, float E, float S, float W); // determines the highest sales figure 

int main()
{

	float sales; //user input

	cout << "Today we will find which division earned the highest sales for the quarter.\n " << endl;

	//calling the getSales function for each division to store its value in variables N, E, S, W
	float N = getSales("North");
	float E = getSales("East");
	float S = getSales("South");
	float W = getSales("West");

	//calling the function findHighest to display results
	findHighest(N, E, S, W);

}

/*********************************
This function is used to determine
the quarterly sales figures per
division and validates the user
input before returning the value
back to main
*********************************/

float getSales(string division)
{
	using std::cout;
	using std::cin;

	float sales;
	
	cout << "Enter the quartely sales figure for the " << division << " Division " << endl; // ask the user to input sales value
	cin >> sales;

	validate(sales); //calls the validate function to validate user input 

	return sales; // returns valid value for sales back to main and stores the value in variables N, E, S, W
}

/******************************
This function validates the user
input and loops until a valid
input is entered
*******************************/

void validate(float sales)
{
	using std::cin;
	using std::cout;
	using std::endl;

	while (!cin || sales < 0.00) // validates input to verify if the user inputs a negative or character value
	{
		cout << " Invalid input, please enter a number greater than 0. " << endl; 
		cin.clear(); //reset to good read
		fseek(stdin, 0, SEEK_END); //flush the input buffer
		cin >> sales; // loops and allows the user to input another value until read valid, then returns to getSales()
	}
}

/*******************************
This function finds the highest
grossing division and displays
the results
*******************************/

void findHighest(float N, float E, float S, float W)
{
	float highest; // variable created to define which sales input holds the largest value

	cout << "\nThe division with the highest sales for the quarter is the ";

	if (N > E && N > S && N > W)
	{
		highest = N;
		cout << "North" << " Division. " << endl;      /**********************/
	}												   // Compares the values stored in N, E, S, W and then assigns 
	else if (E > N && E > S && E > W)				   // the variable highest to a division when the statement reads true
	{
		highest = E;
		cout << "East" << " Division. " << endl;
	}
	else if (S > N && S > E && S > W)
	{
		highest = S;
		cout << "South" << " Division. " << endl;
	}
	else
	{
		highest = W;
		cout << "West" << " Division. " << endl;
	}

	cout << "This quarter, the division earned " << "$" << highest << " in sales.\n " << endl; // displays the highest earning division's sales figure

}