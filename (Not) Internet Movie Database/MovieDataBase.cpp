#include"stdafx.h"
#include"MovieDataBase.h"
#include"ID.h"
#include<iostream>
#include<cstring>
using namespace std;
MovieDataBase::MovieDataBase()
{
	allMovies = 0;
	allIDs = 0;
	staffDatabase = 0;
	sizeMDB = 0;
	sizeSDB = 0;
	capMDB = 0;
	capSDB = 0;
}
MovieDataBase::MovieDataBase(const MovieDataBase& other)
{
	copy(other);
}
MovieDataBase::MovieDataBase(int capM, int capS)
{
	capMDB = capM;
	capSDB = capS;
	sizeMDB = capMDB;
	sizeSDB = capSDB;
	allMovies = new Movie[capMDB];
	allIDs = new ID[capMDB];
	for (int i = 0; i < sizeMDB; i++)
	{
		char mN[250];
		cout << "Movie Name: ";
		cin.getline(mN, 250);
		int y;
		cout << "Year: ";
		cin >> y;
		cout << "Size of Cast: ";
		int c;
		cin >> c;
		double r;
		cout << "Rating: ";
		cin >> r;
		char g[25];
		cout << "Genre: ";
		cin >> g;
		char rev[700];
		cout << "Write review: ";
		cin.getline(rev, 700);
		allMovies[i].registerMovie(mN, y, c, r, g,rev);
		allIDs[i].setID(mN, y);
	}
	for (int i = 0; i < sizeSDB; i++)
	{
		char sN[250];
		cout << "Staff Name: ";
		cin.getline(sN, 250);
		int m, d, y;
		cout << "Day of birth: ";
		cin >> d;
		cout << "Month: ";
		cin >> m;
		cout << "Year: ";
		cin >> y;
		staffDatabase[i].addStaff(sN, d, m, y, 0, 0, 0);
	}
}
void MovieDataBase::copy(const MovieDataBase& other)
{
	capMDB = other.capMDB;
	capSDB = other.capSDB;
	sizeMDB = other.sizeMDB;
	allMovies = new Movie[capMDB];
	allIDs = new ID[capMDB];
	for (int i = 0; i < sizeMDB; i++)
	{
		allMovies[i] = other.allMovies[i];
		allIDs[i] = other.allIDs[i];
	}
	sizeSDB = other.sizeSDB;
	staffDatabase = new MovieStaff[capSDB];
	for (int i = 0; i < sizeSDB; i++)
	{
		staffDatabase[i] = other.staffDatabase[i];
	}
}
MovieDataBase& MovieDataBase::operator=(const MovieDataBase&other)
{
	if (this != &other)
	{
		delete[]allMovies;
		delete[]staffDatabase;
		delete[]allIDs;
		copy(other);
	}
	return *this;
}
MovieDataBase::~MovieDataBase()
{
	delete[]allMovies;
	delete[]staffDatabase;
	delete[]allIDs;
}
void MovieDataBase::resizeMDB()
{
	Movie* tempM = allMovies;
	allMovies = new Movie[capMDB+20];
	for (int i = 0; i < sizeMDB; i++)
	{
		allMovies[i] = tempM[i];
	}
	capMDB += 20;
	delete[]tempM;
}
void MovieDataBase::resizeSDB()
{
	MovieStaff* tempS = staffDatabase;
	staffDatabase = new MovieStaff[capSDB + 20];
	for (int i = 0; i < sizeSDB; i++)
	{
		staffDatabase[i] = tempS[i];
	}
	capSDB += 20;
	delete[]tempS;
}
void MovieDataBase::addStaff()
{
	if (sizeSDB == capSDB)
	{
		resizeSDB();
	}
	char sN[250];
	cout << "Staff Name: ";
	cin.getline(sN, 250);
	int m, d, y;
	cout << "Day of birth: ";
	cin >> d;
	cout << "Month: ";
	cin >> m;
	cout << "Year: ";
	cin >> y;
	MovieStaff a;
	a.addStaff(sN, d, m, y, 0, 0, 0);
	for (int i = 0; i < sizeSDB; i++)
	{
		if (a==staffDatabase[i])
		{
			cout << "Person Already Exists!";
			sN[0] = 0;

		}
	}
	if (sN[0] != 0)
		/////////////////////////
	{
		staffDatabase[sizeSDB].addStaff(sN, d, m, y, 0, 0, 0);
		checkPerson();
		checkMovie();
		sizeSDB++;
	}
}
void MovieDataBase::addMovie()
{
	if (sizeMDB == capMDB)
	{
		resizeMDB();
	}
	char mN[250];
	cout << "Movie Name: ";
	cin.getline(mN, 250);
	int y;
	cout << "Year: ";
	cin >> y;
	ID sumid;
	sumid.setID(mN,y);
	for (int i = 0; i < sizeMDB; i++)
	{
		if (sumid==allMovies[i].getID())
		{
			cout << "Movie Already Exists:";
			mN[0] = 0;
		}
	}
	/////////////////////////
	if (mN[0] != 0)
	{
		int soc;
		cout << "Size of cast: ";
		cin >> soc;
		double r;
		cout << "Rating: ";
		cin >> r;
		char g[25];
		cout << "Genre: ";
		cin >> g;
		char rev[700];
		cout << "Write review: ";
		cin.getline(rev, 700);
		allMovies[sizeMDB].registerMovie(mN, y, soc, r, g,rev);
		checkPerson();
		checkMovie();
		sizeMDB++;
	}
}
void MovieDataBase::checkPerson()
{
	for (int i = 0; i < sizeSDB; i++)
	{
		for (int k = 0; k < sizeMDB; k++)
		{
			if (!(staffDatabase[i].checkID(allIDs[k])) && allMovies[k].checkCast(staffDatabase[i]))
				staffDatabase[i].addMID(allIDs[k]);
		}
	}
}
void MovieDataBase::checkMovie()
{
	for (int i = 0; i < sizeMDB; i++)
	{
		for (int k = 0; k < sizeSDB; k++)
		{
			if (!(allMovies[i].checkCast(staffDatabase[k])) && staffDatabase[k].checkID(allIDs[i]))
				allMovies[i].addCastMember(staffDatabase[i]);
		}
	}
}
int MovieDataBase::getSMD()
{
	return sizeMDB;
}
int MovieDataBase::getSSD()
{
	return sizeSDB;
}
void MovieDataBase::getGERating(double gErating)
{
	for (int i = 0; i < sizeMDB; i++)
	{
		if (allMovies[i].getRating() == gErating)
		{
			allMovies[i].print();
		}
	}
}
void MovieDataBase::getMwithThisActor(const MovieStaff& thisactor)
{
	for (int i = 0; i < sizeMDB; i++)
	{
		if (allMovies[i].thisActor(thisactor))
			allMovies[i].print();
	}
}
void MovieDataBase::thisYear(int y)
{
	for (int i = 0; i < sizeMDB; i++)
	{
		if (y == allMovies[i].getYear())
			allMovies[i].print();
	}
}
void MovieDataBase::thisgenre(char* genre)
{
	//for (int i = 0; i < sizeMDB; i++)
	//{
	//	if (strcmp(genre, allMovies[i].getGenre()) == 0)
	//		allMovies[i].print();
	//}
}
void MovieDataBase::sortbyrating()
{
	Movie temp;
	for (int i = 0; i < sizeMDB; i++)
	{ 
		for (int j = 0; j < sizeMDB - 1; j++)
		{
			if (allMovies[i].getRating()<allMovies[i + 1].getRating())
			{
				temp = allMovies[i+1];
				allMovies[i + 1] = allMovies[i];
				allMovies[i] = temp;
			}
		}
	}
	for (int i = 0; i < sizeMDB; i++)
		allMovies[i].print();
}
void MovieDataBase::fIIILES(char*filename)
{
	for (int i = 0; i < sizeMDB; i++)
		allMovies[i].nananaBatfile(filename);
	for (int i = 0; i < sizeSDB; i++)
		staffDatabase[i].fileMobile(filename);
}


