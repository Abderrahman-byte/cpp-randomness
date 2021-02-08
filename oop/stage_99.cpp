#include <iostream>
#include <ctime>
using namespace std;

#define SEC_PER_DAY 3600 * 24

typedef enum { female, male } gender_t ;

class Person ;
class User;
class Employee;

class Date {
	public :
		unsigned short day;
		unsigned short month;
		unsigned short year;
		
	public :
		Date() {
			day = 1;
			month = 1;
			year = 1970;
		}

		Date(Date &d) {
			day = d.day;
			month = d.month;
			year = d.year;
		}

		Date(int d, int m, int y) {
			if(d <= 0 || d > 31)
				throw "Day cannot be more than 31 or less than 1";
			if(m <= 0 || m > 12)
				throw "month cannot be more than 12 or less than 1";
			if(y < 1970)
				throw "Year value cannot be less than 1970";
			day = d;
			month = m;
			year = y;
		}
};

class Person {
	private :
		string first_name;
		string last_name;
		gender_t gender;
		Date day_of_birth;
		
		friend class User;
		friend class Employee;

	public :
		Person() {
			first_name = "Unkown";
			last_name = "Unkown";
			gender = male;
		}

		Person(Person &p) {
			first_name = "Unkown";
			last_name = "Unkown";
			gender = p.gender;
			day_of_birth = p.day_of_birth;
		}
	
		Person(string f, string l, gender_t g = male, int d = 1, int m = 1, int y = 1970) {
			first_name = f;
			last_name = l;
			gender = g;
			day_of_birth = Date(d, m, y);
		}

		virtual void present() {
			cout << "Hello my name is " << (first_name + last_name) << " ." << endl;
			cout << "I am a " << (gender == male ? "male" : "female") << endl;
		       	cout << "I am born in " << day_of_birth.day << "/" ; 	
		       	cout << day_of_birth.month << "/" << day_of_birth.year << endl ; 	
		}
};

class User : public Person {
	private :
		string username;
		string password;
	
	public :
		User(string f, string l, string u, string p, gender_t g = male, int d = 1, int m = 1, int y = 1970) : Person(f, l, g, d, m, y) {
			username = u;
			password = p;
		} 

		User() {
			username = "";
			password = "password";
		}

		void present() override {
			cout << "Hello my name is " << (first_name + last_name) << " ." << endl;
			cout << "I am a " << (gender == male ? "male" : "female") << endl;
		       	cout << "I am born in " << day_of_birth.day << "/" ; 	
		       	cout << day_of_birth.month << "/" << day_of_birth.year << endl ; 	
			cout << "My user name is " << username << endl;	
		}
};

int main() {
	User new_user("Abderrahmane", "Elasri", "abderrahmane00", "1913@war", male, 6, 4, 2001);
	new_user.present();
	return 0;
}
