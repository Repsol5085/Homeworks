#ifndef ID_H
#define ID_H
class ID
{
	char* idOfMovie;
public:
	ID();
	ID(const ID& other);
	ID& operator=(const ID& other);
	~ID();
	void copy(const ID& other);
	void setID(char* _name, int _year);
	char getID()const;
	bool operator==(const ID& other);
};
#endif