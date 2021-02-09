#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
class Node {
	public :
		T data;

	private :
		Node *left = NULL;
		Node *right = NULL;
	
	public :
		Node() : data((T)0) {}

		void insert(T value) {
			if((int)data == 0) {
				data = value;
			} else if(value > data) {
				if(right == NULL)
					right = new Node();

				right->insert(value);
			} else if(value < data) {
				if(left == NULL)
					left = new Node();	

				left->insert(value);
			}
		}
		
		bool contains(T value) {
			if(data == value) {
				return true;
			} else if(value > data) {
				if(right == NULL) return false;
				return right->contains(value);
			} else {
				if(left == NULL) return false;
				return left->contains(value);	
			}
		}

		void printInOrder(int dept=0) {
			if(left != NULL)
				left->printInOrder(dept + 1);

			for(int i = 0; i < dept; i++) cout << '\t';
			cout << data << endl;

			if(right != NULL)
				right->printInOrder(dept + 1);
		}
};

int main() {
	Node<char> root;
	char input[19];

	cout << "Enter a string : ";
	cin >> input ;

	for(int i = 0; i < strlen(input); i++) {
		root.insert(input[i]);
	}
		

	root.printInOrder();	
	return 0;
}
