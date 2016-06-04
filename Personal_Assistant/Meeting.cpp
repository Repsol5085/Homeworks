#include"stdafx.h"
#include"Meeting.h"
Meeting::Meeting(Time startOfMeeting, Time duration, string _note, vector<Person*>_person,int regmeet)
{
	startOM = startOfMeeting;
	this->duration = duration;
	note = _note;
	people=_person;
	regularMeeting = regmeet;

}
istream& operator >> (istream& in,Meeting meeting)
{
	Time end;
	in >> meeting.dOM >> meeting.startOM >> end;
	int nOP;
	in >> nOP;
	for (int i = 0; i < nOP; i++)
	{
		in>>meeting.people[i]->operator>>;
	}
	in >> meeting.note;
}
ostream& operator << (ostream& out, vector<Meeting*>meeting)
{
	for (int i = 0; i < meeting.size(); i++)
	{
		out << meeting[i]->dOM <<" "<< meeting[i]->startOM << " "
			<< meeting[i]->startOM + meeting[i]->duration << " ";
		for (int j = 0; i < meeting[j]->people.size(); j++)
			out << meeting[i]->people[j]->getName() << " ";
		out << meeting[i]->note<<" ";
	}
	return out;
}
Date Meeting::getDate()
{
	return dOM;
}
Time Meeting::getTime()
{
	return startOM;
}
void Meeting::printMeeting()
{
	cout << "Date: " << dOM.getDay()<<"."<<dOM.getMonth()<<"."<<dOM.getYear()
		<< " | Time: " << startOM.getHour()<<":"<<startOM.getMinute() << "-"
		<< (startOM + duration).getHour()<<":"<<(startOM+duration).getMinute()<< " | "
		<< "With: ";
	for (int i = 0; i < people.size()-1; i++)
	{
		cout << people[i]->getName()<<", ";
	}
	cout << people[people.size()]->getName()<<" | Notes: "<<note<<endl;

}