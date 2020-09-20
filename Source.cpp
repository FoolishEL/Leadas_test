#include "Triangle.h"

using namespace std;

const double eps = 1e-10;

static class function
{
public:
	static bool Check(const Triangle & triangle, const Point &point);
};

int main()
{
	try {
		Triangle t;
		Point p;
		cout << "Enter 3 points of the triangle" << endl;
		cin >> t;
		system("cls");
		cout << "Enter Point to check" << endl;
		cin >> p;
		system("cls");
		function::Check(t, p) ? cout << "Point is internal" << endl : cout << "Point is not internal" << endl;
		system("pause");
	}
	catch(exception ex)
	{
		cout << ex.what()<<endl;
		system("pause");
	}
}

bool function::Check(const Triangle & triangle, const Point &point)
{
	double S, S1, S2, S3;
	Triangle T1, T2, T3;
	T1 = T2 = T3 = triangle;
	T1.exchange(point, 0);
	T2.exchange(point, 1);
	T3.exchange(point, 2);
	S = triangle.calculateS();
	S1 = T1.calculateS();
	S2 = T2.calculateS();
	S3 = T3.calculateS();
	return abs(S - (S1 + S2 + S3)) <= eps;
}