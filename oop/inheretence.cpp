#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

extern "C" {
#include <unistd.h>
}

typedef enum { female, male } gender_t;
typedef enum { ceo, cto, admin, manager, sysadmin, developer } job_t;

class Person {
	public :
		string name ;
		gender_t gender;
		int age;
	
	Person() {}

	Person (string n, gender_t g, int a)  {
		name = n;
		gender = g;
		age = a;
	}

	static string get_id() {
		string id;
		char allowed_chars[10 + 26 + 26];
		int n = 0;
		
		for(int i = 48; i < 58; i++) {
			allowed_chars[n] = (char)i;	
			n++;
		}

		for(int i = 65; i < 91; i++) {
			allowed_chars[n] = (char)i;	
			n++;
		}

		for(int i = 97; i < 123; i++) {
			allowed_chars[n] = (char)i;	
			n++;
		}

		for(int i = 0; i < 10; i++) {
			id += allowed_chars[rand() % n];
		}

		return id;
	}
} ;

class Employee : public Person {
	public :
		job_t job;
		double salary;

	Employee(string n, gender_t g, int a, job_t j, double s) {
		name = n;
		gender = g;
		age = a;
		job = j;
		salary = s;
	}
} ;

int main() {
	srand(time(NULL));
	Employee emp("Abderrahmane Elasri", male, 19, sysadmin, 5000);
	
	cout << Person::get_id() << endl;
	return 0;
}
