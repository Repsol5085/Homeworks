#pragma once
#include<iostream>
using namespace std;
class Time
{
	int hour;
	int minute;
public:
	void setHour(int h);
	void setMinute(int min);
	int getHour();
	int getMinute();
	friend Time& operator+(const Time& start,const Time& other);
	friend ostream& operator << (ostream& out, const Time& time);
	friend bool operator==(const Time& time1, const Time& time2);
	friend istream& operator >> (istream& in,Time time);
	
};