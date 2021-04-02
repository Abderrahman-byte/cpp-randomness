#include <iostream>
#include <cmath>

class Point {
	private:
		float x, y;
	public :
		Point();
		Point(float, float);
		
		// Getter X
		float getAbscisse();
		
		// Getter Y
		float getOrdonne();

		// Setter X
		void setAbscisse(float);
		
		// Setter Y
		void setOrdonne(float);

		// 
		float Norme();
};	

int main () {
	Point p(1, 2);
	
	std::cout << "x: " << p.getAbscisse() << ", y = " << p.getOrdonne() << ", Norme : "<< p.Norme() << std::endl; 
	return 0;
}

Point::Point() {
	this->x = 0;
	this->y = 0;
}

Point::Point(float a, float b) {
	this->x = a;
	this->y = b;
}


float Point::getAbscisse() {
	return this->x;
}

float Point::getOrdonne() {
	return this->y;
}

void Point::setAbscisse(float a) {
	this->x = a;
}
		
void Point::setOrdonne(float b) {
	this->y = b;
}


float Point::Norme() {
	return sqrt(pow(this->x, 2) + pow(this->y, 2));
}
