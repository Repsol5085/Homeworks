#pragma once
#include<string>
#include"Meeting.h"
#include<vector>
using namespace std;
class Person
{
	string name;
	vector<Meeting*> allmeetings;
public:
	Person(const char* _name,vector<Meeting*>meetings);
	string getName();
	bool isFree(Date date, Time time);
	vector<Meeting*> getMeetings();
	void removeMeeting(Date date, Time time);
	void logIn();
	istream& operator >> (istream& in);
};