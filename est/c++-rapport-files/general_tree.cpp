#include <iostream>
#include <vector>

class Node {
	private :
		char data;

	public :
		std::vector<Node *> children; // Tableau qui contient les noeuds enfants

		Node(char data) {
			this->data = data;
		}

		// Insert un nouveau enfant
		void addChild(char data) {
			this->children.push_back(new Node(data));
		}

		// Avoir le longueur de l'arbre
		int getDepth() {
			int children_max_depth = 0;
			
			// Avoir la longueur de chaque noeud
			// et prends le valeur maximale
			for(int i = 0; i < this->children.size(); i++) {
				int cd = this->children[i]->getDepth();
				if(cd > children_max_depth) children_max_depth = cd;
			}

			return children_max_depth + 1; // Ajouter 1 pour la racine
		}
		
		// Afficher l'arbre
		void printTree(int currLevel, int printLevel) {
			if(currLevel == printLevel) {
				std::cout << this->data << '\t';
			} else {
				for(int i = 0; i < this->children.size(); i++) {
					this->children[i]->printTree(currLevel, printLevel + 1);
				}
			}
		}
		
		// Afficher l'Arbre en fonction de sa longueur
		void display() {
			int depth = this->getDepth();

			for(int i = 0; i < depth; i++) {
				this->printTree(i, 0);
				std::cout << std::endl;
			}
		}

};

int main () {
	Node* root = new Node('A'); // creer la racine
	root->addChild('B'); // Ajouter un enfant 'B' a la racine 'A'
	root->addChild('C');
	root->addChild('D');

	root->children[0]->addChild('E'); // Ajouter un enfant 'E' a la racine 'B'
	root->children[0]->addChild('F');

	root->children[2]->addChild('G'); // Ajouter un enfant 'G' a la racine 'D'
	root->children[2]->addChild('H');
	
	root->display();
}
