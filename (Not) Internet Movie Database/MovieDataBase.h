#include"Movie.h"
#include"MovieStaff.h"
#include"User.h"
#include"ID.h"
class /*NOT INTERNET*/MovieDataBase
{
	Movie *allMovies;
	MovieStaff* staffDatabase;
	ID *allIDs;
	int sizeMDB;
	int sizeSDB;
	int capMDB;
	int capSDB;
public:
	MovieDataBase();//
	MovieDataBase(int capM, int capS);
	MovieDataBase(const MovieDataBase&other);//
	void copy(const MovieDataBase&other);//
	~MovieDataBase();//
	MovieDataBase& operator=(const MovieDataBase&other);//
	/*Used*/void resizeSDB();
	/*Used*/void resizeMDB();
	/*Used*/void addMovie();
	/*Used*/void addStaff();
	/*Used*/void checkPerson();
	/*Used*/void checkMovie();
	/*Used*/void getGERating(double gErating);
	void getMwithThisActor(const MovieStaff& thisactor);
	void thisYear(int y);
	int getSMD();
	int getSSD();
	void thisgenre(char* genre);
	void sortbyrating();
	void fIIILES(char*filename)
};