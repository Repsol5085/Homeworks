#ifndef REVIEW_H
#define REVIEW_H
class Review
{
	char* review;
	int sizeOfReviews;
	//class sadurjasht vs. reviewta na edin film 
	//prekaleno kusno da go po4vam => 20:55 | 19.04.16
	//zamestvam char* review s Review* review v Movie...
public:
	Review();
	Review(const Review& other);
	Review& operator=(const Review& other);
	void copy(const Review& other);
	void addReview();
	void resizeR();

};
#endif