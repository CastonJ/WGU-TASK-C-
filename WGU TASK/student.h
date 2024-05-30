#pragma once
#include <string>
#include "Degree.h"
using namespace std;

class Student {



private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[3];
	DegreeProgram degreeProgram;

public:
	const static int daysArraySize = 3;

	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram);

	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysInCourse();
	DegreeProgram getDegree();

	void setSudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysInCourse(int daysInCourse[]);
	void setDegree(DegreeProgram degree);
	void print();

	~Student();

};

