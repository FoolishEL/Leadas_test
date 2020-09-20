#pragma once
#include "Point.h"


using namespace std;

class Triangle
{
public:
	Point points[3];

	Triangle();
	Triangle(const Triangle & t);
	Triangle(const Point * _points);
	~Triangle();
	double calculateS() const;
	Triangle & operator =(const Triangle& t);
	bool exchange(const Point & point, int pos);
	friend ostream& operator<< (ostream &out, const Triangle &triangle);
	friend istream& operator>> (istream &in, Triangle &triangle);
private:
	void raw_copy(const Triangle & t);
};

