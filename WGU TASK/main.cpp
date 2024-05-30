#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "Roster.h"
#include "Student.h"
#include "Degree.h"

using namespace std;


int main() {

	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Jeremy,Caston,jcasto5@wgu.edu,37,40,30,19,SOFTWARE"
	};

	const int numStudents = 5;

	Roster* classRoster = new Roster(numStudents);


	cout << "C867-Scrpiting & Programming: Applications" << endl;
	cout << "Language C++" << endl;
	cout << "Student ID: 000791434" << endl;
	cout << "Name: Jeremy Caston" << endl;

	cout << endl;

	for (int i = 0; i < numStudents; i++) {
		classRoster->parseAndAdd(studentData[i]);
	}

	// Display the students

	cout << "Displaying all students:" << endl;
	classRoster->printAll();


	cout << endl;

	// Display the invalid emails

	cout << "Displaying Invalid emails:" << endl << endl;
	classRoster->printInvalidEmails();

	cout << endl;

	for (int i = 0; i < numStudents; i++) {
		classRoster->printAverageDaysInCourse(classRoster->getStudentAt(i)->getStudentID());
	} 

	cout << endl;

	// Display the degree program

	cout << "Showing students in degree program: SOFTWARE" << endl << endl;
	classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);

	cout << endl;

	// Removing student A3

	classRoster->remove("A3");

	cout << endl;

	// Printing whole student list

	classRoster->printAll();

	cout << endl;

	// Removing again

	classRoster->removeAgain("A3");

	cout << "DONE.";

	return 0;
}

