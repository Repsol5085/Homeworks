#ifndef MOVIESTAFF_H
#define MOVIESTAFF_H
#include "Date.h"
#include "ID.h"
class MovieStaff
{
	char* name;
	Date birthdate;
	char* role;
	int numberOfMovies;
	ID * moviesWorkedOn;

public:
	MovieStaff();//
	MovieStaff(const MovieStaff& other);//
	MovieStaff& operator=(const MovieStaff& other);//
	~MovieStaff();//
	void copy(const MovieStaff& other);//
	void addStaff(char* _name,int d,int m,int y,ID *actsIn, char* _role,int nOM);
	char getName()const;
	void addMID(const ID& other);
	bool checkID(const ID& other);
	int getNOM();
	bool operator==(const MovieStaff& other);
	void print();
	void MovieStaff::fileMobile(char*filename);
};
#endif