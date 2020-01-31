#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int COUNT = 10;
int CHOICE1;
string ARRANGEMENT;
int RANDOM;

class User {
private:
	string UserName;
	int UserAge;
	string UserJob;

public:
	User(string name, int userAge, string userJob);
};

class File {
private:
	string FileName;
	int LineCount;

public:
	File(string fileName);
};


User::User(string name, int userAge, string userJob) {
	UserName = name;
	UserAge = userAge;
	UserJob = userJob;
}

File::File(string fileName) {
	FileName = fileName;
	LineCount = COUNT;
}

int Choice1(string name);
int RandLine();
string Living(int userAge);

int main() {
	string name;
	int userAge;
	string sex = "void";
	string line;
	string userJob;
	string company;
	string inst;
	string course;
	int randTen = 0;

	srand((unsigned int)time(0));

	cout << "Welcome to your story!" << endl;

	cout << "Please enter name: ";
	cin >> name;

	cout << endl << "Please enter age: ";
	cin >> userAge;

	while (sex == "void") {
		cout << "Are you male or female? (M/F): ";
		cin >> sex;

		if ((sex == "M") || (sex == "m")) {
			sex = "male";
		}
		else if ((sex == "F") || (sex == "f")) {
			sex = "female";
		}
		else {
			cout << "invalid Input! Please try again." << endl;
			cin >> sex;
		}
	}

	ifstream jobFile("Jobs.txt");

	while (getline(jobFile, line)) {
		COUNT++;
	}

	RandLine();

	for (int lineno = 0; lineno < RANDOM + 1; lineno++)
		if (lineno == RANDOM)
			userJob = line;
	jobFile.close();

	ifstream compFile("Companies.txt");
	COUNT = 0;

	while (getline(compFile, line)) {
		COUNT++;
	}

	RandLine();

	for (int lineno = 0; lineno < RANDOM + 1; lineno++)
		if (lineno == RANDOM)
			company = line;
	compFile.close();

	ifstream instFile("Institutions.txt");
	COUNT = 0;

	while (getline(instFile, line)) {
		COUNT++;
	}

	RandLine();

	for (int lineno = 0; lineno < RANDOM + 1; lineno++)
		if (lineno == RANDOM)
			inst = line;
	instFile.close();

	ifstream coursesFile("Courses.txt");
	COUNT = 0;

	while (getline(coursesFile, line)) {
		COUNT++;
	}

	RandLine();

	for (int lineno = 0; lineno < RANDOM + 1; lineno++)
		if (lineno == RANDOM)
			course = line;
	coursesFile.close();

	Living(userAge);
	Choice1(name);

	if (CHOICE1 == 1) {
		cout << name << " is a " << userJob << " who lives " << ARRANGEMENT << ". ";
		if (sex == "male") {
			cout << "Your daughter has got into " << inst << " to study " << course << "." << endl;
		}
		else {
			cout << "Your son is studying at " << inst << " but is lazy so he will probably fail the year." << endl;
		}
	}
	else {
		cout << "You run a " << company << " company ";
		if (sex == "male") {
			cout << "with predominantly male employees";
		}
		else {
			cout << "with predominantly female clients";
		}

		cout << " and have therefore been accused of sexual discrimination in the workplace." << endl;
	}

	return 0;
}

string Living(int userAge) {
	string living[10] = { "alone", "with friends", "with their wife", "in a student dorm", "in an apartment", "with their parents", "with a roomate", "with their husband", "with their girlfriend", "with their boyfriend" };
	string age = to_string(userAge);

	switch (age.at(1)) {
	case '0':
		ARRANGEMENT = living[0];
		break;
	case '1':
		ARRANGEMENT = living[1];
		break;
	case '2':
		ARRANGEMENT = living[2];
		break;
	case '3':
		ARRANGEMENT = living[3];
		break;
	case '4':
		ARRANGEMENT = living[4];
		break;
	case '5':
		ARRANGEMENT = living[5];
		break;
	case '6':
		ARRANGEMENT = living[6];
		break;
	case '7':
		ARRANGEMENT = living[7];
		break;
	case '8':
		ARRANGEMENT = living[8];
		break;
	case '9':
		ARRANGEMENT = living[9];
		break;
	default:
		ARRANGEMENT = "all by yourself";
		break;
	}

	//cout << ARRANGEMENT << endl;

	return ARRANGEMENT;
}

int Choice1(string name) {
	if (((name.at(0) >= 'a') && (name.at(0) <= 'm')) || ((name.at(0) >= 'A') && (name.at(0) <= 'M'))) {
		CHOICE1 = 1;
	}
	else {
		CHOICE1 = 2;
	}

	return CHOICE1;
}

int RandLine() {
	RANDOM = (1 + (rand() % COUNT));

	//cout << RANDOM << endl;

	return RANDOM;
}