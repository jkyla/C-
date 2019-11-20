//Kyla Johnson
//COP2000.0M1
//This program reads input from a file, to determine 
//the average temperature in a given month - then
//displays the number of days in the month that are 
//above, below, and equal to the average.


#include<iostream>

#include<stdlib.h>

#include<fstream>

#include<string>

#include<iomanip>

using namespace std;

class Temperature {

	//private variables

private:

	int count[3]; //counter array for each temp instance

	float temp[30], averageTemp; //array to hold each of 30 days temp value & variable to hold average temp

public:

	//constructor to initialize array values

	Temperature()

	{

		averageTemp = 0; // initalizes average to 0 

		for (int i = 0;i < 3;i++)

			count[i] = 0; //initializes counter to 0

		for (int i = 0;i < 30;i++)

			temp[i] = 0; //initializes temp values to 0

	}

	//function to open the file and read the values in

	void Open()

	{

		ifstream File;

		File.open("NovTemps.txt");

		if (File.fail()) //checks for errors in reading the input file and returns error message

		{

			cerr << "File does not exist.\n";

			return;

		}

		int i = 0;

		while (!File.eof())

		{

			float n;

			File >> n;

			temp[i] = n;

			i++;

		}

		File.close();

	}

	//function to calculate how many days are above, below, and equal to average temperature

	void Calculate()

	{

		float totalTemp = 0; //initializes to 0

		for (int i = 0;i < 30;i++)

			totalTemp += temp[i]; //increments the total temp value

		averageTemp = totalTemp / 30; //sets the average temp variable 

		for (int i = 0;i < 30;i++)

		{

			if (temp[i] < averageTemp) //increments the counter for below average temps

				count[0]++;

			else if (temp[i] == averageTemp) //increments equal to

				count[1]++;

			else

				count[2]++; //else increments below

		}

	}

	//function to display the results

	void Display()

	{

		cout << "The average temperature for the month of November is: " << averageTemp;

		cout << "\nDays below average: " << count[0];

		cout << "\nDays above average: " << count[1];

		cout << "\nDays equal to the average: " << count[2];

	}

};

//main function

int main()

{

	Temperature day; //object of the class Temperature

	day.Open();

	day.Calculate();

	day.Display();

	return 0;

}
