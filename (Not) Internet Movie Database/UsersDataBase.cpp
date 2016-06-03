#include"stdafx.h"
#include"UsersDataBase.h"
#include<cstring>
#include<iostream>
#include<fstream>
using namespace std;
UsersDataBase::UsersDataBase()
{
	allUsers = 0;
	sizeUDB = 0;
	capUDB = 0;
	saveLogIn = 0;
}
UsersDataBase::UsersDataBase(const UsersDataBase& other)
{
	copy(other);
}
UsersDataBase& UsersDataBase::operator=(const UsersDataBase& other)
{
	if (this != &other)
	{
		delete[]allUsers;
		copy(other);
	}
	return *this;
}
void UsersDataBase::copy(const UsersDataBase& other)
{
	capUDB = other.capUDB;
	sizeUDB = other.sizeUDB;
	saveLogIn = 0;
	allUsers = new User[capUDB];
	for (int i = 0; i < sizeUDB; i++)
	{
		allUsers[i] = other.allUsers[i];
	}
}
UsersDataBase::~UsersDataBase()
{
	delete[]allUsers;
}
/*Used*/bool UsersDataBase::checkUser(char*_name)
{
	User a;
	a.registerNewUser(_name, 0);
	for (int i = 0; i < sizeUDB; i++)
	{
		if (allUsers[i]==a)
			return true;
	}
	return false;
}
/*Used*/void UsersDataBase::addUser()
{
	if (sizeUDB == capUDB)
	{
		resize();
	}
	int s = 1;
	char n[51],pass[31];
	cout << "Enter new Username (max 50 symbols): ";
	cin >> n;
	for (int i = 0; i < s; i++)
	{
		if (checkUser(n) == true)
		{
			cout << "Username is taken , please select a different one ." << endl;
			cout << "Enter new Username (max 50 symbols): ";
			cin >> n;
			s++;
		}
	}
	cout << "Enter new Password (max 30 characters): ";
	cin >> pass;
	allUsers[sizeUDB].registerNewUser(n, pass);

}
/*Used*/void UsersDataBase::resize()
{
	User* tempU = allUsers;
	allUsers = new User[capUDB + 20];
	for (int i = 0; i < sizeUDB; i++)
	{
		allUsers[i] = tempU[i];
	}
	capUDB += 20;
	delete[]tempU;
}
/*Used*/bool UsersDataBase::checkOnLogIn(User other)
{
	other.logIn();
	for (int i = 0; i < sizeUDB; i++)
	{
		if (allUsers[i] == other)
			saveLogIn = i;
			return true;
	}
	return false;
}
/*Used*/int UsersDataBase::setAccess()
{
	User other;
	if (checkOnLogIn(other))
	{
		User a;
		a.registerNewUser("Admin", 0);
		if (allUsers[saveLogIn] == a)
			allUsers[saveLogIn].setAccess(3);
		else
			allUsers[saveLogIn].setAccess(1);
	}

}
void UsersDataBase::files(char*filename)
{
	for (int i; i < sizeUDB; i++)
	{
		allUsers[i].tofile(filename);
	}
}