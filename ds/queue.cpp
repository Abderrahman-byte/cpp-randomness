#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
class Queue {
	private :
		T *data;
		int size;

	public :
		Queue() {
			size = 0;
			data = (T *)malloc(1 * sizeof(T));
		}

		void enqueue(T value) {
			data = (T *)realloc(data, sizeof(T) * (size + 1));
			if(data != NULL) {
				data[size] = value;
				size++;
			} else
				throw "Could not reallocate queue in memory";
		}

		T dequeue() {
			if(size > 0) {
				T value = data[0];
				for(int i = 0; i < (size - 1); i++) {
					data[i] = data[i + 1];
				}

				data[size] = (T)0;
				size--;
				return value;
			} else 
				return (T)0;
		}

		bool empty() {
			return size <= 0;
		}
};

int main () {
	Queue<int> queue;
	
	for(int i = 0; i <= 10; i++) {
		queue.enqueue(i);
	}


	for(int i = 0; i < 5; i++) {
		cout << queue.dequeue() << endl;
	}

	for(int i = 11; i <= 15; i++) {
		queue.enqueue(i);
	}

	cout << "******************" << endl;
	while(!queue.empty()) {
		cout << queue.dequeue() << endl;	
	}

	return 0;
}
