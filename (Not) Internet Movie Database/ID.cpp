#include"stdafx.h"
#include"ID.h"
#include<iostream>
#include<cstring>
using namespace std;

ID:: ID()
{
	idOfMovie = 0;
}
ID::ID(const ID& other)
{
	copy(other);
}
ID::~ID()
{
	delete[] idOfMovie;
}
ID& ID::operator=(const ID& other)
{
	if (this != &other)
	{
		delete[]idOfMovie;
		copy(other);
	}
	return *this;
}
void ID::copy(const ID& other)
{
	idOfMovie = new char[strlen(other.idOfMovie) + 1];
	for (int i = 0; other.idOfMovie[i] != '\0'; i++)
		idOfMovie[i] = other.idOfMovie[i];
	idOfMovie[strlen(other.idOfMovie)] = '\0';
}
void ID::setID(char* _name, int _year)
{
	idOfMovie = new char[strlen(_name) + 2];
	for (int i = 0; _name[i] != '\0'; i++)
	{
		idOfMovie[i] = _name[i];
	}
	idOfMovie[strlen(_name)] = _year;
	idOfMovie[strlen(_name) + 1] = '\0';
}
char ID:: getID()const
{
	return *idOfMovie;
}
bool ID::operator==(const ID& other)
{
	if (idOfMovie==other.idOfMovie)
		return true;
	return false;
}
