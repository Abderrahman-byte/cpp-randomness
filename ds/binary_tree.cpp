#include <iostream>
#include <ctime>
using namespace std;

class Node {
	public :
		int data;

	private :
		Node *left = NULL;
		Node *right = NULL;
	
	public :
		Node() : data(0) {}

		void insert(int value) {
			if(data == 0) {
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
		
		bool contains(int value) {
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
	srand(time(NULL));

	int max = (rand() % (100 - 50 + 1) ) + 1;
	int root_value = (rand() % max) + 1;

	Node root;
	root.insert(root_value);
	
	for(int i = 0; i < 100; i++) {
		int value = rand() % max;
		root.insert(value);
	}	

	root.printInOrder();	
	return 0;
}
