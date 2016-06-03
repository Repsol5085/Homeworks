#include"ID.h"
#include"MovieStaff.h"
class Movie
{
	char* name;
	int yearOfRel;
	MovieStaff *leadActors;
	int sizeOfCast;
	double rating;
	char* genre;
	char* review;
	ID iD;
public:
	Movie();//
	Movie(const Movie& other);//
	Movie& operator=(const Movie& other);//
	~Movie();//
	void copy(const Movie& other);//
	void isOriginal(const Movie & other);//
	void addCast(int sizeOfCast);
	void createID();
	void registerMovie(char*_name, int year, int sizeofcast, double _rating, char*_genre,char*_review);
	char getName();
	ID getID();
	bool checkCast(const MovieStaff& other);
	bool operator==(const Movie& other);
	void addCastMember(const MovieStaff& other);
	char getReview();
	double getRating();
	void print();
	bool thisActor(const MovieStaff& thisactor);
	int getYear();
	void nananaBatfile(char* filename);
};
