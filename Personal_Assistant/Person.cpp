#include"stdafx.h"
#include"Person.h"
Person::Person(const char* _name,vector<Meeting*>meetings)
{
	name = _name;
	allmeetings = meetings;
}
string Person::getName()
{
	return name;
}
bool Person::isFree(Date date, Time time)
{
	for (int i = 0; i < allmeetings.size(); i++)
	{
		if (allmeetings[i]->getDate() == date&&allmeetings[i]->getTime() == time)
			return false;
		return true;

	}
}
vector<Meeting*> Person::getMeetings()
{
	return allmeetings;
}
void Person::removeMeeting(Date date, Time time)
{
	for (int i = 0; i < allmeetings.size(); i++)
	{
		if (allmeetings[i]->getDate() == date&&allmeetings[i]->getTime() == time)
		{
			Meeting* temp = allmeetings[i];
			for (int j = i; j < allmeetings.size() - 1; j++)
			{
				allmeetings[j] = allmeetings[j + 1];
			}
			allmeetings.pop_back();
			delete temp;
		}
	}
}
istream& Person::operator >> (istream& in)
{
	in >> name;
	return in;
}