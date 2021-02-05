#include <iostream>
using namespace std;

class Complex {
	private :
		float real;
		float imag;
	
	public :		
		Complex() {
			real = 0;
			imag = 0;
		}

		Complex(float r, float i) {
			real = r;
			imag = i;
		}	
		
		Complex operator + (const Complex& obj) {
			Complex temp;
			temp.real = real + obj.real;
			temp.imag = imag + obj.imag;
			return temp;
		}

		void display() {
			cout << "c = " << imag << "i + " << real << endl; 
		}
};

int main() {
	Complex a(3.33, 8.3);
	Complex b(9, 8);
	Complex c = a + b;
		
	a.display();
	b.display();
	c.display();
	
	return 0;
}
