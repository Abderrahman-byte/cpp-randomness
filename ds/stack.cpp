#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define STACK_INIT_LEN 10

class Stack {
	private :
		int *data;
		int count = 0;
		
	public :
		Stack() {
			data = (int *)malloc(STACK_INIT_LEN * sizeof(int));
		}

		int push(int value) {
			if(count >= STACK_INIT_LEN) {
				data = (int *)realloc(data, (count + 1) * sizeof(int));

				if(data == NULL) {
					throw "Could not reallocate memory for new data";
				} 
			}

			data[count] = value;
			count++;
			return count;
		}

		int pop() {
			if(count > 0) { 
				int value = data[count - 1];
				data[count - 1] = 0;
				count--;
				return value;
			} else
				return 0;
		}

		int length() {
			return count;
		}

		bool empty() {
			return count > 0;
		}
};

int main() {
	Stack my_data;
	
	srand(time(NULL));
	
	for(int i = 1; i <= 10; i++) {
		my_data.push(i);
	}

	for(int i = 0; i < 5 ; i++) {
		cout << my_data.pop() << endl;
	}

	for(int i = 11; i <= 15; i++) {
		my_data.push(i);
	}

	cout << "*******************************" << endl;

	for(int i = 5; i <= 15 ; i++) {
		cout << my_data.pop() << endl;
	}

	return 0;
}
