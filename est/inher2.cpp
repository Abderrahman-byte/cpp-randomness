#include <iostream>

class Person {
	public :
		Person();
		void print();
};

class Student : public Person {
	public:
		Student();

		void print();
};

int main() {
	Student p;
	p.print();
}

Person::Person() {
	std::cout << "Person has been borned" << std::endl;
}

void Person::print() {
	std::cout << 2 << std::endl;
}

Student::Student() {
	std::cout << "Student Cons" << std::endl;
}


void Student::print() {
	std::cout << 365 << std::endl;
}
