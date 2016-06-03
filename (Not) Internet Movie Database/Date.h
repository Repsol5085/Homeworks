#ifndef DATE_H
#define DATE_H
class Date
{
	int day;
	int month;
	int year;
public:
	void setDay(int _day);//
	void setMonth(int _month);//
	void setYear(int _year);//
	int getDay()const;//
	int getMonth()const;//
	int getYear()const;//
	bool operator==(Date other);
};
#endif