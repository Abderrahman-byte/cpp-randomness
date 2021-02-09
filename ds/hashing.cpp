#include <iostream>
<<<<<<< HEAD
#include <cstdlib>
using namespace std;

#define DATA_SIZE 255

template <typename T>
class HashTable {
	private :	
		T data[DATA_SIZE];
		string *keys;
		int size = 0;
		
		int get_hash(string key) {
			int some_data = 0;
			
			for(int i = 0; i < key.length(); i++) {
				int value = (i + 1) * (int)key[i];
				some_data += value;
			}

			some_data %= DATA_SIZE;
			return some_data;
		}
	
	public :
		HashTable() {
			keys = (string *)malloc(sizeof(string));
		}

		int get_size() {
			return size;
		}

		bool contains(string key) {
			bool answer = false;

			for(int i = 0; i < size; i++) {
				if(keys[i].compare(key) == 0) {
					answer = true;
					break;
				}
			}

			return answer;
		}

		void insert(string key, T value) {
			if(!contains(key)) {
				keys = (string *)realloc(keys, sizeof(string) * (size + 1));
				if(keys == NULL) {
					throw "Could not allocate more memory";
				}
				
				keys[size] = key;
				size++;	
			}


			int index = get_hash(key);
			data[index] = value;
		}

		T get(string key) {
			if(contains(key)) {
				int index = get_hash(key);
				return data[index];
			} else {
				 T tmp;
				 return tmp;
			}
		}
		
		void display() {
			cout << "{" << endl;
			for(int i = 0; i < size; i++) {
				cout << "\t" ;
				cout << "\"" << keys[i] << "\" : " << get(keys[i]) << endl; 
			}

			cout << "}" << endl;
		}

		void clear() {
			size = 0;
			keys = (string *)realloc(keys, sizeof(string));
			for(int i = 0; i < DATA_SIZE; i++) {
				T a;
				data[i] = a;
			}
		}
};

int main() {
	HashTable<string> obj;

	obj.insert("username", "abderrahmane00");
	obj.insert("username", "abderrahmane500");
	obj.insert("password", "qwertyuiop");
	obj.insert("first_name", "abderrahmane");
	obj.insert("last_name", "elasri");

		
	obj.display();
	obj.clear();
	obj.display();

	return 0;
}
