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

	friend class LinkedList; // Donner à la classe LinkedList l'accès aux membres privés
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

	l1.insert(5); // ajouter 5 au debut 
	l1.insert(3);
	l1.insertQueue(98); // inserer 98 a la fin

	l2.insert(1);
	l2.insert(2);
	l2.insertQueue(3);
	
	// afficher la list et compter ses noeud
	std::cout << "L1 : "; l1.display(); std::cout << ", Count = " << l1.count() << std::endl;
	std::cout << "L2 : "; l2.display(); std::cout << ", Count = " << l2.count() << std::endl;
	
	// lier l1 et l2
	l1.link(l2);
	std::cout << "L1 : "; l1.display(); std::cout << ", Count = " << l1.count() << std::endl;
	
	
	l1.removeData(333);  // suprimer le noeud qui a comme donne 333
	l1.removeData(3);
	std::cout << "L1 : "; l1.display(); std::cout << ", Count = " << l1.count() << std::endl;

	return 0;
}

// Constructeur de la class LinkedList
LinkedList::LinkedList() {
	this->head = NULL;
};

// Insérer un élément à la fin de list
void LinkedList::insertQueue(int data) {
	// si la list est vide ajouter le noeud 'head'
	if(head == NULL) {
		head = new Node;
		head->setData(data);
	} else head->insert(data); // si la list n'est pas vide inserer apres 'head'
}

// Mutateur de 'data'
void Node::setData(int data) {
	this->data = data; 
}

// Insert un nouveau noeud
void Node::insert(int data) {
	if(this->next == NULL) {
		this->next = new Node;
		this->next->setData(data);
	} else {
		this->next->insert(data);
	}
}

// afficher la list
void LinkedList::display() {
	if(this->head != NULL) this->head->display();
}

// Afficher chaque noeud et son suivant
void Node::display() {
	std::cout << this->data;
	// si ce noeud a un suivant afficher le
	if(next != NULL) {
		std::cout << " -> "; 
		next->display();
	}
}

// Supprimer un noeud par indice
void Node::remove(int index) {
	if(index == 1 && this->next != NULL) {
		Node *tmp = this->next->next;
		delete this->next;
		this->next = tmp;
	} else if(index > 1 && this->next != NULL ) {
		this->next->remove(index-1);
	}
}

// Supprimer un noeud de la list par un indice
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

// Insérer un élément au début de la liste
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

// Compter les noeud suivant d'un noeud
int Node::countAfter() {
	if(this->next == NULL) return 0;
	else return this->next->countAfter() + 1;
}

// Compter les noeud de la list
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

// Avoir le dernier noeud dans la list
Node* Node::getTail() {
// Si le noeud n'est pas de suivant return le, sinon faire la meme chose sur son voisin
	if(this->next == NULL) return this;
	else return this->next->getTail();
}

// Lier deux list
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
