#pragma once
#include"Time.h"
#include"Date.h"
#include"Person.h"
#include<string>
#include<vector>
#include<fstream>
#include"Meeting.h"
using namespace std;
class Meeting
{
	Time startOM;
	Time duration;
	Date dOM;
	string note;
	vector<Person*> people;
	int regularMeeting;

public:
	Meeting(Time startOfMeeting, Time duration, string _note, vector<Person*>_person,int regmeet);
	friend istream& operator >> (istream& in,Meeting meeting);
	friend ostream& operator<< (ostream& out, vector<Meeting*>meetings);
	Date getDate();
	Time getTime();
	void printMeeting();
};