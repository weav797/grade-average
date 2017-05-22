/* Lab4_Weaver.cpp
Paul Orion Weaver
4/19/2017
This program prompts users to enter numeric grades, computes an average, 
and displays the letter grade based on the average grade.
It prompts users for the number of grades to enter. It processes the data using arrays.
See textbook pages 400-401, 409 */

#include <iostream>
#include <iomanip>
using namespace std;

double compute_average(double, int);
void high(double[], int);
void low(double[], int);
void letter_grade(double);

int main()
{

	int numberofgrades;
	double grades = 0.0;
	double total_grades = 0.0;
	double average_grades = 0.0;
	double amount = 0.0;
	const int SIZE = 25;
	double grades_array[SIZE];
	int count = 0;

	cout << "Average Grades using Arrays\n\n";
	cout << "This program can input 1 to " << SIZE << " grades\n\n";
	cout << "How many grades would you like to average for? ";
	cin >> numberofgrades;
	if (numberofgrades < 0) {
		cout << "The number of grades CANNOT be a negative number." << endl;
		system("pause");
		exit(1);
	}
	if (numberofgrades > 25) {
		cout << "You CANNOT enter more than 25 grades." << endl;
		system("pause");
		exit(1);
	}

	//save the contents to an array
	for (count = 0; count < numberofgrades; count++)
	{
		cout << "Enter the grade for grade " << count + 1 << ": ";
		cin >> grades_array[count];

		//Encourages user to only enter numbers between 0 and 100
		if (!(grades_array[count] <= 100 && grades_array[count] >= 0)) {
			cout << "You may only enter numbers between 0 and 100." << endl;
			system("pause");
			exit(1);
		}

		total_grades += grades_array[count];
	}

	//Call the compute_average function and update the average grades variable
	average_grades = compute_average(total_grades, numberofgrades);

	cout << endl;

	//Read the data from the array
	for (count = 0; count < numberofgrades; count++)
	{
		cout << "Grade " << count + 1 << ": " << grades_array[count] << endl;
	}

	cout << endl;
	high(grades_array, numberofgrades); //call the highest grade function
	low(grades_array, numberofgrades); //call the lowest grade function
	cout << endl;
	cout << "Average Grade: " << setprecision(1) << fixed << average_grades << endl;
	letter_grade(average_grades); //call the function that displays the letter grade
	cout << endl;


	cout << "Press Enter key to exit...";
	cin.ignore();
	cin.get();

	return 0;
}

double compute_average(double total, int number)
{
	//double avg;
	//avg = (total / number);
	//return avg;

	return (total / number);
}

void high(double grades[], int totalvalues)
{
	int count;
	double highest;

	highest = grades[0];

	for (count = 1; count < totalvalues; count++)
	{
		if (grades[count] > highest)
		{
			highest = grades[count];
		}

	}
	cout << "Highest grade: " << highest << endl;
}
void low(double grades[], int totalvalues)
{
	int count;
	double lowest;

	lowest = grades[0];

	for (count = 1; count < totalvalues; count++)
	{
		if (grades[count] < lowest)
		{
			lowest = grades[count];
		}

	}
	cout << "Lowest grade:  " << lowest << endl;
}

void letter_grade(double grades_avg)
{
	// Constants
	const int A_score = 90,
		B_score = 80,
		C_score = 70,
		D_score = 60;

	//Determines the letter grade and displays letter grade
	if (grades_avg >= A_score)
		cout << "\nYour final grade is A.\n";
	else if (grades_avg >= B_score)
		cout << "\nYour final grade is B.\n";
	else if (grades_avg >= C_score)
		cout << "\nYour final grade is C.\n";
	else if (grades_avg >= D_score)
		cout << "\nYour final grade is D.\n";
	else if (grades_avg >= 0)
		cout << "\nYour final grade is F.\n";


	return;
}