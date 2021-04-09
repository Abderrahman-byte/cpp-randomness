#include <iostream>
#include <exception>

template <typename T> class Node {
	private :
		T data;
		Node<T> *next;

	public :
		void setData(T);
		void insert(T);
		void display();
		void remove(int);
		int countAfter();
		Node<T>* getTail();

	template <typename C> friend class LinkedList;
};

template <typename T> class LinkedList {
	private :
		Node<T> *head;
		
	public :
		LinkedList();
		void insert(T);
		void display();
		void remove(int);
		void insertQueue(T);
		int count();
		T min();
		void link(LinkedList<T>);
		void removeData(T);
};

int main () {
	LinkedList<int> l1, l2;

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

template <typename T> LinkedList<T>::LinkedList() {
	this->head = NULL;
};

template <typename T> void LinkedList<T>::insertQueue(T data) {
	if(head == NULL) {
		head = new Node<T>;
		head->setData(data);
	} else head->insert(data);
}

template <typename T> void Node<T>::setData(T data) {
	this->data = data; 
}

template <typename T> void Node<T>::insert(T data) {
	if(this->next == NULL) {
		this->next = new Node<T>;
		this->next->setData(data);
	} else {
		this->next->insert(data);
	}
}

template <typename T> void LinkedList<T>::display() {
	if(this->head != NULL) this->head->display();
}

template <typename T> void Node<T>::display() {
	std::cout << this->data;
	if(next != NULL) {
		std::cout << " -> "; 
		next->display();
	}
}

template <typename T> void Node<T>::remove(int index) {
	if(index == 1 && this->next != NULL) {
		Node<T> *tmp = this->next->next;
		delete this->next;
		this->next = tmp;
	} else if(index > 1 && this->next != NULL ) {
		this->next->remove(index-1);
	}
}

template <typename T> void LinkedList<T>::remove(int index) {
	if(index > 0 && this->head != NULL) {
		this->head->remove(index);
	} else if(index == 0 && this->head != NULL) {
		if(this->head->next != NULL) {
			Node<T> *tmp = this->head;
			this->head = this->head->next;
			delete tmp;
		} else {
			this->head = 0;
		}
	}
}

template <typename T> void LinkedList<T>::insert(T data) {
	if(this->head == NULL) {
		this->head = new Node<T>;
		this->head->setData(data);
	} else {
		Node<T> *tmp = this->head;
		this->head = new Node<T>;
		this->head->setData(data);
		this->head->next = tmp;
	}
}

template <typename T> int Node<T>::countAfter() {
	if(this->next == NULL) return 0;
	else return this->next->countAfter() + 1;
}

template <typename T> int LinkedList<T>::count() {
	if(this->head == NULL) return 0;
	else return this->head->countAfter() + 1;
}

template <typename T> T LinkedList<T>::min() {
	if(this->head == NULL) throw std::range_error("Linked list is empty");

	T min_value = this->head->data;
	Node<T> *current = this->head->next;

	while(current != NULL) {
		min_value = min_value > current->data ? current->data : min_value;
		current = current->next;
	}

	return min_value;
}

template <typename T> Node<T>* Node<T>::getTail() {
	if(this->next == NULL) return this;
	else return this->next->getTail();
}

template <typename T> void LinkedList<T>::link(LinkedList<T> l2) {
	if(this->head == NULL) this->head = l2.head;
	Node<T> *tmp = this->head->getTail();
	tmp->next = l2.head;
}

template <typename T> void LinkedList<T>::removeData(T data) {
	Node<T> *tmp = this->head;
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
