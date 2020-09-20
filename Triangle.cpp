#include "Triangle.h"
#include <math.h>
#define p points

Triangle::Triangle()
{
	for (size_t i = 0; i < 3; i++)
	{
		points[i] = Point(0.0, 0.0);
	}
}

Triangle::Triangle(const Triangle & t)
{
	raw_copy(t);
}

Triangle::Triangle(const Point * _points)
{
	for (size_t i =0;i<3;i++)
	{
		points[i] = _points[i];
	}
}


Triangle::~Triangle()
{
}

double Triangle::calculateS() const
{
	double l1, l2, l3, P, answer;
	l1 = p[0].lengthTo(p[1]);
	l2 = p[1].lengthTo(p[2]);
	l3 = p[2].lengthTo(p[0]);
	P = l1 + l2 + l3;
	P /= 2;
	return sqrt(P*(P - l1)*(P - l2)*(P - l3));
}

Triangle & Triangle::operator=(const Triangle & t)
{
	raw_copy(t);
	return *this;
}

bool Triangle::exchange(const Point & point, int pos)
{
	bool answer = false;
	if(pos>=0||pos<=2)
	{
		p[pos] = point;
		answer = true;
	}
	return answer;
}

void Triangle::raw_copy(const Triangle & t)
{
	p[0] = t.points[0];
	p[1] = t.points[1];
	p[2] = t.points[2];
}

ostream & operator<<(ostream & out, const Triangle & triangle)
{
	out << "Point 1: " << triangle.points[0] << endl << "Point 2: " << triangle.points[1] << endl << "Point 3: " << triangle.points[2] << endl;
	return out;
}

istream & operator>>(istream & in, Triangle & triangle)
{
	in >> triangle.points[0] >> triangle.points[1] >> triangle.points[2];
	return in;
}
