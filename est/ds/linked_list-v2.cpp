#include <iostream>
#include <exception>

class Node {
	private :
		int data;
		Node *next;

	public :
		void setData(int);
		void insert(int);
		void display();
		void remove(int);
		int countAfter();
		Node* getTail();

	friend class LinkedList;
};

class LinkedList {
	private :
		Node *head;
		
	public :
		LinkedList();
		void insert(int);
		void display();
		void remove(int);
		void insertQueue(int);
		int count();
		int min();
		void link(LinkedList);
		void removeData(int);
};

int main () {
	LinkedList l1, l2;

	l1.insert(5);
	l1.insert(3);
	l1.insertQueue(98);

	l2.insert(1);
	l2.insert(2);
	l2.insertQueue(3);
	
	std::cout << "L1 : "; l1.display(); std::cout << ", Count = " << l1.count() << std::endl;
	std::cout << "L2 : "; l2.display(); std::cout << ", Count = " << l2.count() << std::endl;

	l1.link(l2);
	std::cout << "L1 : "; l1.display(); std::cout << ", Count = " << l1.count() << std::endl;

	l1.removeData(333);
	l1.removeData(3);
	std::cout << "L1 : "; l1.display(); std::cout << ", Count = " << l1.count() << std::endl;

	return 0;
}

LinkedList::LinkedList() {
	this->head = NULL;
};

void LinkedList::insertQueue(int data) {
	if(head == NULL) {
		head = new Node;
		head->setData(data);
	} else head->insert(data);
}

void Node::setData(int data) {
	this->data = data; 
}

void Node::insert(int data) {
	if(this->next == NULL) {
		this->next = new Node;
		this->next->setData(data);
	} else {
		this->next->insert(data);
	}
}

void LinkedList::display() {
	if(this->head != NULL) this->head->display();
}

void Node::display() {
	std::cout << this->data;
	if(next != NULL) {
		std::cout << " -> "; 
		next->display();
	}
}

void Node::remove(int index) {
	if(index == 1 && this->next != NULL) {
		Node *tmp = this->next->next;
		delete this->next;
		this->next = tmp;
	} else if(index > 1 && this->next != NULL ) {
		this->next->remove(index-1);
	}
}

void LinkedList::remove(int index) {
	if(index > 0 && this->head != NULL) {
		this->head->remove(index);
	} else if(index == 0 && this->head != NULL) {
		if(this->head->next != NULL) {
			Node *tmp = this->head;
			this->head = this->head->next;
			delete tmp;
		} else {
			this->head = 0;
		}
	}
}

void LinkedList::insert(int data) {
	if(this->head == NULL) {
		this->head = new Node;
		this->head->setData(data);
	} else {
		Node *tmp = this->head;
		this->head = new Node;
		this->head->setData(data);
		this->head->next = tmp;
	}
}

int Node::countAfter() {
	if(this->next == NULL) return 0;
	else return this->next->countAfter() + 1;
}

int LinkedList::count() {
	if(this->head == NULL) return 0;
	else return this->head->countAfter() + 1;
}

int LinkedList::min() {
	if(this->head == NULL) throw std::range_error("Linked list is empty");

	int min_value = this->head->data;
	Node *current = this->head->next;

	while(current != NULL) {
		min_value = min_value > current->data ? current->data : min_value;
		current = current->next;
	}

	return min_value;
}

Node* Node::getTail() {
	if(this->next == NULL) return this;
	else return this->next->getTail();
}

void LinkedList::link(LinkedList l2) {
	if(this->head == NULL) this->head = l2.head;
	Node *tmp = this->head->getTail();
	tmp->next = l2.head;
}

void LinkedList::removeData(int data) {
	Node *tmp = this->head;
	int index = 0;

	while(tmp != NULL) {
		if(tmp->data == data) {
			this->remove(index);
			break;
		}

		index++;
		tmp = tmp->next;
	}
}
