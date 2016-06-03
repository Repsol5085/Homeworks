#include"stdafx.h"
#include"User.h"
#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
User::User()
{
	username = 0;
	password = 0;
	access = 0;
	
}
void User::copy(const User& other)
{
	username = new char[strlen(other.username) + 1];
	password = new char[strlen(other.password) + 1];
	access = other.access;
	for (int i = 0; other.username[i] != '\0'; i++)
	{
		username[i] = other.username[i];
	}
	username[strlen(other.username)] = '\0';
	password = new char[strlen(other.password) + 1];
	//strcpy(password, other.password);
	for (int i = 0; other.password[i] != '\0'; i++)
	{
		password[i] = other.password[i];
	}
	password[strlen(other.password)] = '\0';
}
User::User(const User& other)
{
	copy(other);
}
User& User::operator=(const User& other)
{
	if (this != &other)
	{
		delete[]username;
		delete[]password;
		copy(other);
	}
	return *this;
}
User::~User()
{
	delete[]username;
	delete[]password;
}
void User::registerNewUser(char* name, char*pass)
{
	username = new char[strlen(name) + 1];
	password = new char[strlen(pass) + 1];
	if (strcmp("Admin", name)==0)
	{
		access = 3;
	}
	for (int i = 0; name[i] != '\0'; i++)
	{
		username[i] = name[i];
	}
	username[strlen(name)] = '\0';
	password = new char[strlen(pass) + 1];
	//strcpy(password, other.password);
	for (int i = 0; pass[i] != '\0'; i++)
	{
		password[i] = pass[i];
	}
	password[strlen(pass)] = '\0';
}
int User::getAccess()
{
	return access;
}
char User::getUN()
{
	return *username;
}
char User::getPass()
{
	return *password;
}
void User::logIn()
{
	char n[51], pass[31];
	cout << "Enter Username: ";
	cin >> n;
	cout << "Enter Password : ";
	cin >> pass;
	username = new char[strlen(n) + 1];
	password = new char[strlen(pass) + 1];
	for (int i = 0; n[i] != '\0'; i++)
	{
		username[i] = n[i];
	}
	username[strlen(n)] = '\0';
	password = new char[strlen(pass) + 1];
	//strcpy(password, other.password);
	for (int i = 0; pass[i] != '\0'; i++)
	{
		password[i] = pass[i];
	}
	password[strlen(pass)] = '\0';
}
bool User::operator==(const User& other)
{
	if (strcmp(username, other.username) == 0)
		return true;
	return false;
}
void User::setAccess(int _access)
{
	access = _access;
}
void User::tofile(char*filename)
{
	ofstream toTheBatFile;
	toTheBatFile.open(filename);
	toTheBatFile << "Username: " << username << endl
		<< "Password: " << password << endl << "Access: " << access << endl;
	toTheBatFile.close();
}