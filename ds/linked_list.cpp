#include <iostream>
using namespace std;

class Node {
	private :
		Node *next;
		unsigned char data;
	
	public :
		// Constructor with args
		Node(unsigned char c) {
			data = c;
		}
		
		// Contructor without args
		Node() {
			data = 0x0;
		}

		// Copy constructor
		Node(Node &n) {
			data = n.data;
		} 

		// get data of node
		unsigned get_data() {
			return data;
		}
		
		// set data of node
		void set_data(unsigned char value) {
			data = value;
		} 

		// create node
		Node* add_next(unsigned char c=0x0) {
			next = new Node(c);
			return next;
		}

		// get count of next elements
		int get_next_count() {
			int n = 0;

			if(next != NULL) {
				n++;
				n += next->get_next_count();
			}

			return n;
		}

		void display_data() {
			cout << data << "\t";
			if(next != NULL) {
				next->display_data();
			}
		}
};

int main() {
	char choice;
	
	Node* head = new Node();
	Node* last = head;

	do {
		char c;
		Node* new_node;

		cout << "[*] DATA : " ;
		cin >> c;
		
		last->set_data((unsigned char)c);
		new_node = last->add_next();
		last = new_node;
		
		cout << "Do you wanna continue that shit ? ";
		cin >> choice;

	} while(choice == 'y' or choice == 'Y');
	
	cout << "data len : " << head->get_next_count() << endl;
	cout << "data :" << endl ;
	head->display_data();
	cout << endl;

	return 0;
}
