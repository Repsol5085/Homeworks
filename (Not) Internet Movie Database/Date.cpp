#include"stdafx.h"
#include"Date.h"
#include<iostream>
using namespace std;

void Date::setDay(int _day)
{
	day = _day;
}
void Date::setMonth(int _month)
{
	month = _month;
}
void Date::setYear(int _year)
{
	year = _year;
}
int Date::getDay()const
{
	return day;
}
int Date::getMonth()const
{
	return month;
}
int Date::getYear()const
{
	return year;
}
bool Date::operator==(Date other)
{
	if (day == other.day&&month == other.month&&year == other.year)
		return true;
	return false;
}