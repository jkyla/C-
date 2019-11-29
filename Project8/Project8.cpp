//Kyla Johnson
//COP2000.OM1
//This program reads input from a file to an array, sorts the array in alphabetical order, 
//and displays the ascending results

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

class Names
{
private:
	const static int LIST = 30;
	string names[LIST]; 
	ifstream nameFile; 

	void readNames();
	void sortList(string []);
	void displayNames();

public:
	void driver(); 
};

/*******************************Method Definitions****************************************/

void Names::readNames()
{
	int nameVar; // variable to loop through array of names

	nameFile.open("Names.txt");
	if (!nameFile)
		cout << "Error opening file.\n";
	else
	{
		for (nameVar = 0; nameVar < LIST; nameVar++)
			nameFile >> names[nameVar]; //inputs file into array
		nameFile.close(); //close the input file
	}
}

void Names::sortList(string array[], int list)
{
	int startScan, minIndex, minValue;
	for (startScan = 0; startScan < (list - 1); startScan++)
	{
		minIndex = startScan;
		minValue = array[startScan];
		for (int index = startScan + 1; index < list; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;
			}
		}
		array[minIndex] = array[startScan];
		array[startScan] = minValue;
	}

}

void Names::displayNames(string array[], int list)
{
	for (int count = 0; count < list; count++)
		cout << array[count] << " ";
	cout << endl;
}

void Names::driver()
{
	readNames();

	sortList();

	displayNames();
}

int main()
{
	//instantiate object of class Names
	Names reader;

	reader.driver();

	return 0;
}