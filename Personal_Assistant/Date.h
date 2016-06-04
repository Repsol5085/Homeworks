#pragma once
#include"Time.h"
#include<vector>
using namespace std;
class Date //:public Time
{
	int day;
	int month;
	int year;
public:
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);
	int getDay();
	int getMonth();
	int getYear();
	friend ostream& operator <<(ostream& out, const Date date);
	friend istream& operator >> (istream& in,Date date);
	friend bool operator==(const Date& date1, const Date& date2);
};