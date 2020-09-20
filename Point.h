#pragma once
#include<iostream>


using namespace std;

class Point
{
public:
	double x, y, z;
	Point();
	Point(double _x, double _y, double _z);
	Point(double _x, double _y);
	Point(const Point & p);

	Point & operator =(const Point& p);

	~Point();
	friend ostream& operator<< (ostream &out, const Point &point);
	friend istream& operator>> (istream &in, Point &point);
	double lengthTo(const Point & point)const;
private:
	void raw_copy(const Point & p);
};

