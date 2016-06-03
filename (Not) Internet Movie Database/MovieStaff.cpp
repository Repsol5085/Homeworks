#include"stdafx.h"
#include"MovieStaff.h"
#include<cstring>
#include<iostream>
#include<fstream>
using namespace std;

MovieStaff::MovieStaff()
{
	name = 0;
	moviesWorkedOn = 0;
	role = 0;
	numberOfMovies = 0;
}
void MovieStaff::copy(const MovieStaff&other)
{
	numberOfMovies = other.numberOfMovies;
	moviesWorkedOn = new ID[numberOfMovies];
	for (int i = 0; i < numberOfMovies; i++)
	{
		moviesWorkedOn[i] = other.moviesWorkedOn[i];
	}
	name = new char[strlen(other.name) + 1];
	for (int i = 0; other.name[i] != '\0'; i++)
	{
		name[i] = other.name[i];
	}
	name[strlen(other.name)] = '\0';
}
MovieStaff& MovieStaff::operator=(const MovieStaff& other)
{
	if (this != &other)
	{
		delete[]name;
		delete[]moviesWorkedOn;
		delete[]role;
		copy(other);
	}
	return *this;
}
MovieStaff::MovieStaff(const MovieStaff&other)
{
	copy(other);
}
MovieStaff::~MovieStaff()
{
	delete[]name;
	delete[]moviesWorkedOn;
	delete[]role;
}
void MovieStaff::addStaff(char* _name, int d,int m,int y, ID *actsIn, char* _role, int nOM)
{
	numberOfMovies = nOM;
	moviesWorkedOn = new ID[numberOfMovies];
	for (int i = 0; i < numberOfMovies; i++)
	{
		moviesWorkedOn[i] = actsIn[i];
	}
	name = new char[strlen(_name) + 1];
	for (int i = 0; _name[i] != '\0'; i++)
	{
		name[i] = _name[i];
	}
	name[strlen(_name)] = '\0';
	birthdate.setDay(d);
	birthdate.setYear(y);
	birthdate.setMonth(m);
	role = new char[strlen(_role) + 1];
	for (int i = 0; _role[i] != '\0'; i++)
	{
		role[i] = _role[i];
	}
	role[strlen(_role)] = '\0';
	

}
char MovieStaff::getName()const
{
	return *name;
}
void MovieStaff::addMID(const ID& other)
{
	ID *tempID = moviesWorkedOn;
	moviesWorkedOn = new ID[numberOfMovies + 1];
	for (int i = 0; i < numberOfMovies; i++)
	{
		moviesWorkedOn[i] = tempID[i];
	}
	numberOfMovies++;
	moviesWorkedOn[numberOfMovies - 1] = other;
	delete[]tempID;
}
bool MovieStaff::checkID(const ID& other)
{
	for (int i = 0; i < numberOfMovies; i++)
	{
		if (moviesWorkedOn[i] == other)
			return true;
	}
	return false;
}
int MovieStaff::getNOM()
{
	return numberOfMovies;
}
bool MovieStaff::operator==(const MovieStaff& other)
{
	if (strcmp(name, other.name) == 0 && birthdate == other.birthdate)
		return true;
	return false;
}
void MovieStaff::print()
{
	cout << "Name of the person: " << name << endl
		<< "Date of birth: " << birthdate.getDay()
		<< "." << birthdate.getMonth() << "." << birthdate.getYear() << endl
		<< "Role in movies: " << role << endl;
}
void MovieStaff::fileMobile(char*filename)
{
		ofstream theFileCave;
		theFileCave.open(filename);
		theFileCave << "Name of the person: " << name << endl
			<< "Date of birth: " << birthdate.getDay()
			<< "." << birthdate.getMonth() << "." << birthdate.getYear() << endl
			<< "Role in movies: " << role << endl;
		theFileCave.close();
}