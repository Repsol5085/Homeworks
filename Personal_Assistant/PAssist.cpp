#include"stdafx.h"
#include "PAssist.h"
void PersonalAssistant::createMeeting(Date date, Time start, Time duration, vector<Person*> people, string note, int regmeet)
{
	vector<Person*> arefree;
	for (int i = 0; i < people.size(); i++)
	{
		bool free = true;
		int dur_h = duration.getHour();
		int dur_m = duration.getMinute();
		if (dur_m != 0)
			dur_h++;
		Time temptime = start;
		for (int i = 0; i < dur_h; i++)
		{
			temptime.setHour(dur_h);
			if (people[i]->isFree(date, temptime))
				free = false;
		}
		if (free)
		{
			arefree[arefree.size()] = people[i];
		}
	}
	loggedPerson->getMeetings().at(loggedPerson->getMeetings().size()) = new Meeting(start, duration, note, arefree, regmeet);
}

void PersonalAssistant::removeMeeting(Date date, Time time)
{

}

void PersonalAssistant::createRegularMeeting(Date date, Time start, Time duration, vector<Person*>people, string note, int regmeet)
{

}

void PersonalAssistant::showMeetings(Date date)
{
	for (int i = 0; i < loggedPerson->getMeetings.size(); i++)
	{
		loggedPerson->getMeetings()[i]->printMeeting;
	}
}
void PersonalAssistant::suggestMeetingTime(Date date, Time duration, Person person)
{

}
