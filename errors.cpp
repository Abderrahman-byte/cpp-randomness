#include <iostream>
using namespace std;
	
class ArithmeticError : public exception {
	private :
		string phrase;

	public :
		ArithmeticError(string const& phrase="") throw() {
			this->phrase = phrase;
		}

		virtual const char* what() const throw() {
			return phrase.c_str();
		}

		virtual ~ArithmeticError() throw() {}
};

int division(int a, int b) {
	if(b != 0) {
		return a / b;
	} else {
		throw ArithmeticError("Cannot divide by zero");
	}
}
int main() {
	int d;

	try {
		d = division(6, 0);
		cout << "6/0 = " << d << endl ;
	} catch(ArithmeticError const& e) {
		cout << "[ERROR] in 6/0 " << e.what() << endl;
	}

	return 0;
}
