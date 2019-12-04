//Kyla Johnson
//COP2000.OM1
//This program reads input from a file to an array, sorts the array in alphabetical order, 
//and displays the ascending results

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<algorithm>

using namespace std;

class Names
{
private:
	const static int LIST = 30; //number of names in the file
	string names[LIST]; //array with 30 elements
	ifstream nameFile; //input file


	void readNames(); //function to read the file and input names into array
	void sortList(string[], int); //function to sort names 
	void displayNames(string [], int); //function to display names in order

public:
	void driver(); //calls the methods in specific order
};

/*******************************Method Definitions****************************************/

void Names::readNames()
{
	int i; // variable to loop through array of names

	nameFile.open("Names.txt");
	if (!nameFile)
		cout << "Error opening file.\n";
	else
	{
		for (i = 0; i < LIST; i++)
			nameFile >> names[i]; //inputs file into array
		nameFile.close(); //close the input file
	}
}

void Names::sortList(string names[], int size)
{ 
	int i, j; //int variables to compare
	string filename; //variable to hold string data

	for (i = 0; i < size-1; i++)
		for (j = 0; j < size - 1; j++)
		{
			if (names[j] > names[j + 1]) //compare sizes
			{
				filename = names[j]; //sets array to filename
				names[j] = names[j + 1];
				names[j + 1] = filename;
			}
		}
}

void Names::displayNames(string names[], int size)
{
	for (int i = 0; i < size; i++) //loops through array and displays names
		cout << names[i] << " , ";
	cout << endl;
}

void Names::driver()
{
	readNames();

	sortList(names, LIST);

	displayNames(names, LIST);
}

int main()
{
	//instantiate object of class Names
	Names reader;

	reader.driver();

	return 0;
}