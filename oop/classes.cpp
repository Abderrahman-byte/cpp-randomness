#include <iostream>

using namespace std;

typedef enum { female, male } gender_t;

typedef struct {
	unsigned short day;
	unsigned short month;
	unsigned short year;
} date_t ;

class Person {
	public :
		string first_name;
		string last_name;
		gender_t gender;
		date_t day_of_birth;

		Person() {
			first_name = "undefined";	
			last_name = "undefined";	
			gender = male;
			day_of_birth.day = 0;	
			day_of_birth.month = 0;	
			day_of_birth.year = 1970;	
		}
	
		Person(string fname, string lname, gender_t g, int dob, int mob, int yob) {
			first_name = fname;
			last_name = lname;
			gender = g;
			day_of_birth.day = dob;
			day_of_birth.month = mob;
			day_of_birth.year = yob;
		}

		static Person create() {
			Person a;
			int g;
			cout << "Enter first name : ";
			cin >> a.first_name;
			cout << "Enter last name : ";
			cin >> a.last_name;
			cout << "Enter gender (0 = female, 1 = male) : ";
			cin >> g;
			a.gender = (g == 1) ? male : female;

			cout << "Enter date of birth : " << endl;
			cout << "\tday : ";
			cin >> a.day_of_birth.day;
			cout << "\tmonth : ";
			cin >> a.day_of_birth.month;
			cout << "\tyear : ";
			cin >> a.day_of_birth.year;

			return a;
		}
};



int main () {
	Person user;
	user = Person::create();
	return 0;
}
