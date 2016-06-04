#include"Date.h"
#include<iostream>
using namespace std;
void Date::setDay(int d) { day = d; }
void Date::setMonth(int m) { month = m; }
void Date::setYear(int y) { year = y; }
int Date::getDay() { return day; }
int Date::getMonth() { return month; }
int Date::getYear() { return year; }
ostream& operator <<(ostream& out, const Date date)
{
	out << date.day << " " << date.month << " " << date.year;
	return out;
}
bool operator==(const Date& date1, const Date& date2)
{
	if (date1.day == date2.day&&date2.month == date1.month&&date1.year == date2.year)
		return true;
	return false;
}
istream& operator >> (istream& in,Date date)
{
	in >> date.day >> date.month >> date.year;
		return in;

}