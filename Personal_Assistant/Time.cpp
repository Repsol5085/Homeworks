#include"stdafx.h"
#include"Time.h"
#include<iostream>
using namespace std;
void Time::setHour(int h) { hour = h; }
void Time::setMinute(int m) { minute = m; }
int Time::getHour() { return hour; }
int Time::getMinute() { return minute; }
Time& operator+(const Time& start, const Time& other)
{
	Time sum;
	sum.hour = start.hour + other.hour;
	if (start.minute + other.minute >= 60)
	{
		sum.minute = start.minute + other.minute - 60;
		sum.hour++;
	}
	else sum.minute = start.minute + other.minute;
	return sum;
}
ostream& operator<<(ostream& out, const Time& time)
{
	out << time.hour << " " << time.minute;
}
bool operator==(const Time& time1, const Time& time2)
{
	if (time1.hour == time2.hour&&time1.minute == time2.minute)
		return true;
	else return false;
}
istream& operator >> (istream& in, Time time)
{
	in >> time.hour >> time.minute;
}