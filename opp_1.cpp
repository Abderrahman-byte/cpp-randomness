#include <iostream>
#include <ctime>
using namespace std;

struct Date {
	short int day;
	short int month;
	short int year;
}; 

class User {
	public :
		string username;
		string password;
		Date day_of_birth;

		int getAge() {
			time_t now_time = time(NULL);
			unsigned long birth_sec = (((day_of_birth.year - 1970) * 365) + (day_of_birth.month * 30) + day_of_birth.day) * 24 * 3600;
			unsigned long age_sec = now_time - birth_sec;	

			return age_sec / (3600 * 24 * 365);
		}
};

int main() {
	User new_user;
	new_user.username = "abderrahmane";
	new_user.password = "1913@war";
	new_user.day_of_birth.day = 6;
	new_user.day_of_birth.month = 4;
	new_user.day_of_birth.year = 2001;

	cout << "User : " << new_user.username << endl;
	cout << "password: " << new_user.username << endl;
	cout << "Birthsday : " << new_user.day_of_birth.year << "/" << new_user.day_of_birth.month  << "/" << new_user.day_of_birth.day << endl ;
	cout << "User age : " << new_user.getAge() << endl;
	return 0;
}
