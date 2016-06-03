//Save it all to files
#include"MovieDataBase.h"
#include"UsersDataBase.h"
class Dispatcher
{
	UsersDataBase UDB;
	MovieDataBase MDB;
	int generalAccess;
public:
	void setGA();
	void addToUDB();
	void addMToMDB();
	void addSToMDB();
	MovieDataBase searchByRating();
	MovieDataBase searchByActor();
	MovieDataBase searchByYear();
	//otpada MovieDataBase searchByDirector();
	MovieDataBase searchByGanre();
	void sortByRating();
	void sortByYear();
	void sblActorsandDirector();
	void serialiseInTextFile(char* fileName);
	void getDataFile(char*fileName);
	

};
/*

*/