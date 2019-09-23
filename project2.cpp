//Kyla Johnson
//COP2000.0M1
//This project calculates the percentage of students according to gender

#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	//variables
	int female;
	int male;
	int total;
	float percentfemale;
	float percentmale;




	//ask the user to enter number of students by gender
	cout << "Enter the number of females in the class" << "\n\n";
	cin >> female;

	cout << endl;
	cout << "Enter the number of males in the class" << "\n\n";
	cin >> male;

	cout << "\n\n\n\n\n";
	//compute total number of students
	total = female + male;

	//compute percentages
	percentfemale = 100.0 * female / total;
	percentmale = 100.0 * male / total;

	//display percentage of students to user

	cout << fixed << showpoint << setprecision(2);
	cout << "The percentage of females is" << "\n\n" << percentfemale << endl;
	cout << "\n\n" << "The percentage of males is" << "\n\n" << percentmale << endl;




	return 0;
}