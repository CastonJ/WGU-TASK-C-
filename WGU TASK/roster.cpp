#include <string>
#include "Degree.h"
#include "Student.h"
#include "Roster.h"
#include <iostream>
using namespace std;

Roster::Roster() {
	this->index = -1;
	this->rosterSize = 0;
	this->classRosterArray = nullptr;
}

Roster::Roster(int rosterSize) {
	this->rosterSize = rosterSize;
	this->index = -1;
	this->classRosterArray = new Student * [rosterSize];
}

void Roster::parseAndAdd(string row) {

	if (index < rosterSize) {
		index++;
	}

	int rLimit = row.find(",");
	string studentID = row.substr(0, rLimit);

	int lLimit = rLimit + 1;
	rLimit = row.find(",", lLimit);
	string firstName = row.substr(lLimit, rLimit - lLimit);

	lLimit = rLimit + 1;
	rLimit = row.find(",", lLimit);
	string lastName = row.substr(lLimit, rLimit - lLimit);

	lLimit = rLimit + 1;
	rLimit = row.find(",", lLimit);
	string emailAddress = row.substr(lLimit, rLimit - lLimit);

	lLimit = rLimit + 1;
	rLimit = row.find(",", lLimit);
	string tempAge = row.substr(lLimit, rLimit - lLimit);
	int age = stoi(tempAge);

	lLimit = rLimit + 1;
	rLimit = row.find(",", lLimit);
	int daysInCourse1 = stoi(row.substr(lLimit, rLimit - lLimit));

	lLimit = rLimit + 1;
	rLimit = row.find(",", lLimit);
	int daysInCourse2 = stoi(row.substr(lLimit, rLimit - lLimit));

	lLimit = rLimit + 1;
	rLimit = row.find(",", lLimit);
	int daysInCourse3 = stoi(row.substr(lLimit, rLimit - lLimit));

	lLimit = rLimit + 1;
	rLimit = row.find(",", lLimit);
	DegreeProgram degreeProgram;
	string degreeStr = row.substr(lLimit, rLimit - lLimit);
	if (degreeStr == "NETWORK") {
		degreeProgram = DegreeProgram::NETWORK;
	}
	else if (degreeStr == "SECURITY") {
		degreeProgram = DegreeProgram::SECURITY;
	}
	else if (degreeStr == "SOFTWARE") {
		degreeProgram = DegreeProgram::SOFTWARE;
	}

	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);

}

bool Roster::remove(string studentID) {

	bool found = false;
	for (int i = 0; i < index; ++i) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			found = true;
			delete this->classRosterArray[i];
			cout << "Removing " << studentID << ":" << endl;
			classRosterArray[i] = classRosterArray[index];
			index--;
		}
	}

	return found;
}

	bool Roster::removeAgain(string studentID) {


		bool found = false;
		for (int i = 0; i < index; ++i) {
			if (classRosterArray[i]->getStudentID() == studentID) {
				found = true;
				delete this->classRosterArray[i];
				cout << "Removing " << studentID << ":" << endl;
				classRosterArray[i] = classRosterArray[index];
				index--;
			}

		}
		cout << "Removing " << studentID << " again" << endl << endl;

		if (!found) {
			cout << "The student with the ID: " << studentID << " was not found." << endl;
		}

		return found;
	}


void Roster::printAll() {
	for (int i = 0; i <= index; ++i) {
		classRosterArray[i]->print();
	}
}

void Roster::printAverageDaysInCourse(string studentID) {

	int average = 0;

	for (int i = 0; i < 5; ++i) {
		string tempID = classRosterArray[i]->getStudentID();
		if (tempID == studentID) {
			average = ((classRosterArray[i]->getDaysInCourse()[0] + classRosterArray[i]->getDaysInCourse()[1] + classRosterArray[i]->getDaysInCourse()[2]) / 3);
			cout << "Student ID: " <<  studentID << "," << " average days in course: " << average << endl;
		}
	}
}

void Roster::printInvalidEmails() {
	for (int i = 0; i < 5; ++i) {
		string tempEmail = classRosterArray[i]->getEmailAddress();
		
		if ((tempEmail.find("@") == string::npos || tempEmail.find(".") == string::npos) || (tempEmail.find(" ") != string::npos)) {
			cout << tempEmail << " - is invalid." << endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degree) {
	for (int i = 0; i < 5; ++i) {
		DegreeProgram tempDegree = classRosterArray[i]->getDegree();
		if (tempDegree == degree) {
			classRosterArray[i]->print();
		}
	}
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int daysInCourse[Student::daysArraySize];

	daysInCourse[0] = daysInCourse1;
	daysInCourse[1] = daysInCourse2;
	daysInCourse[2] = daysInCourse3;

	classRosterArray[index] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
}

Student* Roster::getStudentAt(int index) {
	return classRosterArray[index];
}

Roster::~Roster() {
	for (int i = 0; i < 5; ++i) {
		delete classRosterArray[i];
	}
	delete classRosterArray;
}
