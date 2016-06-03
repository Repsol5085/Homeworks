#ifndef USER_H
#define USER_H
#include"MovieStaff.h"
class User
{
	char* username;
	char* password;
	int access;
	
public:
	User();//
	User(const User& other);//
	User& operator=(const User& other);//
	~User();//
	void copy(const User& other);//
	void registerNewUser(char* name, char* pass);//
	int getAccess();//
	char getUN();//
	void logIn();
	char getPass();
	bool operator==(const User& other);
	void setAccess(int _access);
	//char getPass();
	void tofile(char*filename);
};
#endif