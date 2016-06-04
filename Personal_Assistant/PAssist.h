#pragma once
#include<string>
#include"Date.h"
#include"Meeting.h"
#include"Person.h"
#include"Time.h"
#include<vector>
#include<string>
using namespace std;
class PersonalAssistant
{
	vector<Meeting*>everyMeeting;
	vector<Person*>everyPerson;
	Person* loggedPerson;
	
public:
	void createMeeting(Date date, Time start,Time duration, vector<Person*> people, string note,int regmeet);
	void removeMeeting(Date date, Time time);
	void createRegularMeeting(Date date, Time start, Time duration, vector<Person*> people, string note,int regmeet);
	void showMeetings(Date date);
	void suggestMeetingTime(Date date, Time duration, Person person);

};