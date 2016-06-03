#include"stdafx.h"
#include"Movie.h"
#include<iostream>
#include<fstream>
using namespace std;

Movie::Movie()
{
	name = 0;
	//director = 0;
	yearOfRel = 0;
	rating = 0;
	sizeOfCast = 0;
	genre = 0;
	review = 0;
}
Movie::Movie(const Movie& other)
{
	copy(other);
}
void Movie::copy(const Movie&other)
{
	name = new char[strlen(other.name) + 1];
	for (int i = 0; other.name[i] != '\0'; i++)
	{
		name[i] = other.name[i];
	}
	name[strlen(other.name)] = '\0';
	yearOfRel = other.yearOfRel;
	rating = other.rating;
	genre = new char[strlen(other.genre) + 1];
	for (int i = 0; other.genre[i] != '\0'; i++)
	{
		genre[i] = other.genre[i];
	}
	genre[strlen(other.genre)] = '\0';
	sizeOfCast = other.sizeOfCast;
	leadActors = new MovieStaff[sizeOfCast];
	for (int i = 0; i < sizeOfCast; i++)
	{
		leadActors[i] = other.leadActors[i];
	}
	review = new char[strlen(other.review) + 1];
	for (int i = 0; other.review[i] != '\0'; i++)
	{
		review[i] = other.review[i];
	}
	review[strlen(other.review)] = '\0';
}
Movie& Movie::operator=(const Movie&other)
{
	if (this != &other)
	{
		delete[]name;
		delete[]genre;
		delete[]leadActors;
		delete[]review;
		copy(other);
	}
	return *this;
}
Movie::~Movie()
{
	delete[]name;
	delete[]genre;
	delete[]leadActors;
	delete[]review;
}
void Movie::isOriginal(const Movie&other)
{
	if (this != &other)
	{
		if (strcmp(name, other.name)==0 && yearOfRel > other.yearOfRel)
		{
			iD = other.iD;
		}
	}
}
void Movie::registerMovie(char*_name, int year, int sizeofcast, double _rating, char*_genre,char*_review)
{
	name = new char[strlen(_name) + 1];
	for (int i = 0; _name[i] != '\0'; i++)
	{
		name[i] = _name[i];
	}
	name[strlen(_name)] = '\0';
	yearOfRel = year;
	rating = _rating;
	genre = new char[strlen(_genre) + 1];
	for (int i = 0; _genre[i] != '\0'; i++)
	{
		genre[i] = _genre[i];
	}
	genre[strlen(_genre)] = '\0';
	review = new char[strlen(_review) + 1];
	for (int i = 0; _review[i] != '\0'; i++)
	{
		review[i] = _review[i];
	}
	review[strlen(_review)] = '\0';
	addCast(sizeofcast);
}
void Movie::addCast(int sizeOfCast)
{
	leadActors = new MovieStaff[sizeOfCast];
	for (int i = 0; i < sizeOfCast; i++)
	{
		char nameOA[250];
		cout << "Enter name of the the actor: ";
		cin.getline(nameOA, 250);
		int m, d, y;
		cout << "Enter day of birth: ";
		cin >> d;
		cout << "Enter month of birth:";
		cin >> m;
		cout << "Enter year of birth: ";
		cin >> y;
		ID *actsIn; 
		char* _role; 
		int nOM;
		//NOT DONE
		leadActors[i].addStaff(nameOA,d,m,y,0,0,0);
	}
}
void Movie::createID()
{
	iD.setID(name, yearOfRel);
}
char Movie::getName()
{
	return *name;
}
ID Movie:: getID()
{
	return iD;
}
bool Movie::checkCast(const MovieStaff& other)
{
	for (int i = 0; i < sizeOfCast; i++)
	{
		if (leadActors[i] == other)
			return true;
	}
	return false;
}
bool Movie::operator==(const Movie& other)
{
	if (strcmp(name, other.name) == 0 && yearOfRel == other.yearOfRel)
		return true;
	return false;
}
void Movie::addCastMember(const MovieStaff& other)
{
	MovieStaff *tempMS = leadActors;
	leadActors = new MovieStaff[sizeOfCast + 1];
	for (int i; i < sizeOfCast; i++)
	{
		tempMS[i] = leadActors[i];
	}
	leadActors[sizeOfCast] = other;
	sizeOfCast++;
}
char Movie::getReview()
{
	return *review;
}
double Movie::getRating()
{
	return rating;
}
void Movie::print()
{
	cout << "Name of the Movie: " << name << endl
		<< "Year of Release: " << yearOfRel << endl
		<< "Rating: " << rating << endl
		<< "Review: " << review << endl
		<<"Cast: "<<endl ;
	for (int i = 0; i < sizeOfCast; i++)
	{
		leadActors[i].print();
	}
	
}
bool Movie::thisActor(const MovieStaff& thisactor)
{
	for (int i = 0; i < sizeOfCast; i++)
	{
		if (leadActors[i] == thisactor)
			return true;
	}
	return false;
}
int Movie::getYear()
{
	return yearOfRel;
}
void Movie::nananaBatfile(char* filename)
{
	ofstream toTheBatFile;
	toTheBatFile.open(filename);
	toTheBatFile << "Name of the Movie: " << name << endl
		<< "Year of Release: " << yearOfRel << endl
		<< "Rating: " << rating << endl
		<< "Review: " << review << endl;
	toTheBatFile.close();
}



