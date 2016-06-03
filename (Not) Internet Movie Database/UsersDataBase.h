

#include"User.h"
class UsersDataBase
{
	User *allUsers;
	int sizeUDB;
	int capUDB;
	int saveLogIn;
public:
	UsersDataBase();
	UsersDataBase(const UsersDataBase& other);
	UsersDataBase& operator=(const UsersDataBase& other);
	~UsersDataBase();
	void copy(const UsersDataBase& other);
	bool checkUser(char* _name);
	void addUser();
	void resize();
	bool checkOnLogIn(User other);
	int setAccess();
	void files(char*filename);
};
