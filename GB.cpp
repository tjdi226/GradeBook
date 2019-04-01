/*
Grade Book Calculator
-------------------------------------------------------------
By:    Tyler Dishman
Class: CS 215 Section 004
Date:  Oct 13th, 2016

*/


#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


/*
PrintLogo()
-------------------------------------------------------------------------------------------------
Function Purpose:

Print the logo for the program.

*/


void PrintLogo()
{
	cout << "Grade Book Calculator App" << endl;
        cout << "CS 498 Final Project\n";
}

/*
AskNumber()
--------------------------------------------------------------------------------------------------
Function Purpose:

Given a question, lower and upper bound values, prints the prompt and allows the user to enter an
integer. You may assume the user will always enter an integer. But if a number is entered outside the given
bounds, the “Invalid answer” message is given and the question repeats until the user enters a valid
answer. The function returns the valid number entered.

*/

int AskNumber(string question, int lower_bound, int upper_bound)

{
	int response;

	cout << question;
	cin >> response;

	while (response < lower_bound || response > upper_bound)
	{

	cout << "Invalid input, enter a number between " << lower_bound << " and " << upper_bound << ": ";
	cin >> response;
        }

return response;
}

/*

AskClassNumbers()
--------------------------------------------------------------------------------------------------
Function Purpose:

Invokes AskNumber() to ask the user to enter the Number of Tests, Number of Projects and Number of
Attendance days. There must be at least one of each, but not more than 50. It returns these three integers
to the invoking function.

*/


void AskClassNumbers(int & Number_of_Tests, int & Number_of_Projects, int & Number_of_Attendance_Days)
{
	string TestNumber;
	TestNumber = "How many tests did you have:       ";
	string ProjectNumber;
	ProjectNumber = "How many projects did you have:       ";
	string AttendenceDays;
	AttendenceDays = "How many days of attendance:       ";
	Number_of_Tests = AskNumber(TestNumber, 0, 50);
	Number_of_Projects = AskNumber(ProjectNumber, 0, 50);
	Number_of_Attendance_Days = AskNumber(AttendenceDays, 0, 50);
	}

/*
GetTestAverage()                              
--------------------------------------------------------------------------------------------------
Function Purpose:

Given the number of tests, invokes AskNumber() the correct number of
times. It should calculate and return the average of the test scores entered.

*/

double GetTestAverage(int Number_of_Tests)
{
	string q1;
	string q2;
	int counter = 1;

	q1 = "Enter Test " + to_string(counter) + " score:            ";
	double t = 0;
	double ts;
	double cavg = 0;
	while (counter <= Number_of_Tests)
	{
		q2 = "Enter Test " + to_string(counter) + " score:                 ";
		ts = AskNumber(q2, 0, 100);
		counter++;
		t = t + ts;
	}
	cavg = (t / Number_of_Tests);
	return cavg;
}

/*
GetProjectAverage()                                     
------------------------------------------------------------------------------------------
 Function Purpose:
 
 Given the number of projects, invokes AskNumber() the correct number of times. 
 Note the project number is in the prompt. Project Scores are between 0 and 100. It
 should calculate and return the average of the project scores entered.

*/

double GetProjectAverage(int Number_of_Projects)
{
	string q1;
	string q2;
	int counter = 1;
	q1 = "Enter Project  " + to_string(counter) + ":         ";
	double t = 0;
	double ps;
	double cavg;
	while (counter <= Number_of_Projects)
	{
		q2 = "Enter Project  " + to_string(counter) + ":             ";
		ps = AskNumber(q2, 0, 100); 
		counter++;                                      
		t = t + ps;                 
	}
	cavg = (t / Number_of_Projects);
	return cavg;                               
}

/* 
GetAttendanceScore()
--------------------------------------------------------------------------------------------------
Function Purpose:

Given the number of attendance days, invokes AskNumber() to get the
number of days attended. This should be between 0 and the number of attendance days. It then
calculates and returns the attendance percentage (days attended / attendance days).

*/

double GetAttendanceScore(int Number_of_Attendance_Days)
{
	string question;
	question = "Enter Days Attended:          ";
	double average_days;
	double attended;
	attended = AskNumber(question, 0, Number_of_Attendance_Days);
	average_days = (attended / Number_of_Attendance_Days);
	average_days = (average_days * 100);              

	return average_days;                        
}


/*
CalcPercentage()
---------------------------------------------------------------------------------------------------
Function Purpose:

Given the Test Average, Project Average and Attendance score, calculates and
returns the overall score based on the percentages listed

*/

double CalcPercentage(double test_average, double project_average, double attendance)
{
	double test_avg;
	double project_avg;
	double attendence_score;
	test_avg = (test_average * 0.40);
	project_avg = (project_average * 0.50);
	attendence_score = (attendance * 0.10);
	double finalp;

	finalp = (test_avg + project_avg + attendence_score); 
	return finalp;           
}

/*
GetLetterGrade() 
--------------------------------------------------------------------------------------------------
Fuction Purpose: 

Given the overall score, return the letter grade based on the standard 10-
point scale

*/


char GetLetterGrade(double Overall_score)
{
	char grade = ' ';
	if (Overall_score >= 90 && Overall_score <= 100)
	{
		grade = 'A';
	}
	if (Overall_score >= 80 && Overall_score <= 89)
	{
		grade = 'B';
	}
	if (Overall_score >= 70 && Overall_score <= 79)
	{
		grade = 'C';
	}
	if (Overall_score >= 60 && Overall_score <= 69)
	{
		grade = 'D';
	}
	if (Overall_score < 50)
	{
		grade = 'F';
	}

return grade;
}

/*
PrintStudent()                        
--------------------------------------------------------------------------------------------------
Function Purpose:

Given the Names, 3 Averages, Overall Score and Letter Grade, prints the report
as shown above.

*/



void PrintStudent(string name, double t_avg, double p_avg, double d_avg, double o_score, string l_grade)
{

	cout << "\n";
	cout << "   Name:                 " << name << "\n";
	cout << "   Test Average:         " << fixed << setprecision(1) << t_avg << "%" << endl;
	cout << "   Project Average:      " << fixed << setprecision(1) << p_avg << "%" << endl;
	cout << "   Attandance Average:   " << fixed << setprecision(1) << d_avg << "%" << endl;
	cout << "   Overall Average:      " << fixed << setprecision(1) << o_score << "%" << endl;
	cout << "   Letter Grade:         " << l_grade << endl;
	cout << "\n";
}

/*---------------------------------------------------------------------------------------------------------------------------*/

int main()
{
	string f_name;
	string l_name;
	string w_name;

	PrintLogo();
	cout << "To stop enter q for first and last name!" << endl;
	cout << "------------------------------------------------------------\n";
	cout << "Enter first name: ";
	cin >> f_name;
	cout << "Enter last name: ";
	cin >> l_name;
	w_name = f_name + " " + l_name;
	double tavg;
	double pavg;
	double davg;
	double fscore;
	string l_grade;
	double favg;
	double hi_score = 0.0;
	double lo_score = 100.0;
	int t;
	int p;
	int d;
	int counter = 0;

	while (f_name != "q")
	{
		AskClassNumbers(t, p, d); 
		tavg = GetTestAverage(t);
		pavg = GetProjectAverage(p);
		davg = GetAttendanceScore(d);
		fscore = CalcPercentage(tavg, pavg, davg);
		l_grade = GetLetterGrade(fscore);
		cout << "**********************************\n";
		PrintStudent(w_name, tavg, pavg, davg, fscore, l_grade);
		counter++;
		favg += fscore;
		cout << "Please enter first name: ";
		cin >> f_name;
		cout << "Please enter last name: ";
		cin >> l_name;
		w_name = f_name + " " + l_name;
		if (fscore > hi_score)
		{
			hi_score = fscore;
		}
		else
		{
			hi_score = hi_score;
		}
		if (fscore <= lo_score)
		{		
			lo_score = fscore;
		}
		else
		{
			lo_score = lo_score;
		}
	}
	cout << "---------------------------------------------------\n";
	cout << "|   The class average:    " << favg / counter << endl;
	cout << "|   The highest average:  " << hi_score << endl;
	cout << "|   The lowest average:   " << lo_score << endl;
	cout << "---------------------------------------------------\n";
	system("pause");
return 0;
}
