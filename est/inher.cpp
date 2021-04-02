#include <iostream>

class Class1 {
	public : Class1() {
		std::cout << "Constructeur Class1" << std::endl;	 
	}

};

class Class2 : public Class1 {
	public : Class2() {
		std::cout << "Constructeur Class2" << std::endl;	 
	}
};

int main () {
	Class2 c;
	return 0;
}
