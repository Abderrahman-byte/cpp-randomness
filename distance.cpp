#include <iostream>
#include <cmath>
using namespace std;

class Point {
	public :
		float x;	
		float y;

	Point(float a, float b) {
		x = a;
		y = b;
	}	
};

float distance(Point, Point);

int main () {
	float ax, ay, bx, by;

	cout << "Enter point a :" << endl;
	cout << "\tX: ";
	cin >> ax;
	cout << "\tY: ";
	cin >> ay;
	cout << "Enter point b :" << endl;
	cout << "\tX: ";
	cin >> bx;
	cout << "\tY: ";
	cin >> by;

	Point point_a(ax, ay);
	Point point_b(bx, by);

	cout << "Distance between A and B : " << distance(point_a, point_b) << endl;
}

float distance(Point a, Point b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
