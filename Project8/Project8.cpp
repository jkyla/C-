//Kyla Johnson
//COP2000.OM1
//This program reads input from a file to an array, sorts the array in alphabetical order, 
//and displays the ascending results

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<vector>

using namespace std;

class Names
{
private:
	const static int LIST = 30;
	string names[LIST]; 
	ifstream nameFile; 

	void readNames();
	void sortList(vector<string>& );
	void displayNames(vector<string>& );

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

void Names::sortList(vector<string>& names)
{
	//vector<string> names(LIST);



	vector<string> sort_strings(vector<string>& names); {
		int smallest = 0;

		for (int i = 0; i < names.size(); i++) {
			for (int j = i; j < names.size(); j++) {
				if (names[j].compare(names[smallest]) < 0) {
					smallest = j;
				}
			}
			if (smallest != i) {
				swap(names[i], names[smallest]);
			}
		}
		return names; 
	}
}

void Names::displayNames(vector<string>& names)
{
	vector<string> s = {names};

	vector<string> sorted_strings = names;

	cout << "\nList of names in alphabetical order:" << endl;
	for (int i = 0; i < s.size(); i++) {
		cout << sorted_strings[i] << endl;
	}
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