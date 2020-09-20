#include "Point.h"
#include <math.h>

Point::Point() :Point(0.0, 0.0, 0.0){}

Point::Point(double _x, double _y, double _z)
{
	x = _x;
	y = _y;
	z = _z;
}

Point::Point(double _x , double _y) : Point(_x,_y,0.0){}

Point::Point(const Point & p)
{
	raw_copy(p);
}

Point & Point::operator=(const Point & p)
{
	raw_copy(p);
	return *this;
}


Point::~Point()
{
}

double Point::lengthTo(const Point & point)
const
{
	return sqrt(pow(x - point.x, 2) + pow(y - point.y, 2) + pow(z - point.z, 2));
}

void Point::raw_copy(const Point & p)
{
	x = p.x;
	y = p.y;
	z = p.z;
}

ostream & operator<<(ostream & out, const Point & point)
{
	out << "( " << point.x << ", " << point.y << ", "<<point.z << ")"<<endl;
	return out;
}

istream& operator>> (istream &in, Point &point)
{
	cout << "Enter the coordinates of the point" << endl;
	in >> point.x >> point.y >> point.z;
	if (in.fail())
	{
		exception ex("Wrong input!");
		throw ex;
	}
	return in;
}