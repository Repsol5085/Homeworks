#include"stdafx.h"
#include"Dispatcher.h"
#include<iostream>
using namespace std;

void Dispatcher::setGA()
{
	generalAccess = UDB.setAccess();
}
void Dispatcher::addToUDB()
{
	UDB.addUser();
}
void Dispatcher::addMToMDB()
{
	if (generalAccess == 3)
	{
		MDB.addMovie();
	}
}
void Dispatcher::addSToMDB()
{
	if (generalAccess == 3)
		MDB.addStaff();
}
MovieDataBase Dispatcher::searchByRating()
{
	if (generalAccess >= 1)
	{
		cout << "Seach by rating => Enter Rating: ";
		int r;
		cin >> r;
		MDB.getGERating(r);
	}
}
MovieDataBase Dispatcher::searchByActor()
{
	MovieStaff THISACTOR;
	char sN[250];
	cout << "Actor Name: ";
	cin.getline(sN, 250);
	int m, d, y;
	cout << "Day of birth: ";
	cin >> d;
	cout << "Month: ";
	cin >> m;
	cout << "Year: ";
	cin >> y;
	THISACTOR.addStaff(sN, d, m, y, 0, "Actor", 0);
	MDB.getMwithThisActor(THISACTOR);	
}
MovieDataBase Dispatcher::searchByYear()
{
	int y;
	cout << "Year: ";
	cin >> y;
	MDB.thisYear(y);
}
MovieDataBase Dispatcher::searchByGanre()
{
	char genre[20];
	cout << "Genre: ";
	cin >> genre;
	MDB.thisgenre(genre);
}
void Dispatcher::sortByRating()
{
	MDB.sortbyrating();
}
void Dispatcher::sortByYear()
{
	//same as by rating
}
void Dispatcher::sblActorsandDirector()
{

}
void Dispatcher::serialiseInTextFile(char* fileName)
{
	MDB.fIIILES(fileName);
	UDB.files(fileName);
}
void Dispatcher::getDataFile(char*fileName)
{
	//no time
}
