//Kyla Johnson
//COP2000.0M1
//This program calculates the number of points assigned to book purchases per month

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//Variables
	int sumBooks; //the number of books the user has purchased
	int sumAwards; //the number of points assigned to each book purchase
	 

	cout << "Monthly Book Club Awards \n\n" << endl;

	//Ask the user to input the number of books purchased
	cout << "Enter the number of books purchased this month: ";
	cin >> sumBooks;

	//Validate user input


	//Calculate the number of awards per month

	if (sumBooks < 1)
		sumAwards = 0;

	else if (sumBooks == 1)
		sumAwards = 5;

	else if (sumBooks == 2)
		sumAwards = 15;

	else if (sumBooks == 3)
		sumAwards = 30;

	else if (sumBooks >= 4)
		sumAwards = 50;

	//Display the number of awards per month

	cout << " \nCongrats! You have earned " << sumAwards << " points this month. " << endl;


	return 0;
}
