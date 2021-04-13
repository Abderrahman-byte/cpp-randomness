#include <iostream>

// Prototypes des functions
void padding(std::string, int);
void displayMenu();

/* CLASS NODE START */
class Node  {
	public :
		int data;
		Node *left;
		Node *right;
		
		// Inserer une node 
		void insertNode(Node *node) {
			// Ne faire si le noeud enfant est lui meme le noeud parent
			if(!node || node == this) return;

			// Inserer a gauche si la donnee d'enfant 
			// est inferieur de celle du parent
			// sinon inserer le a droit
			if(node->data < this->data && this->left) {
				this->left->insertNode(node);
			} else if(node->data < this->data) {
				this->left = node;
			} else if(this->right) {
				this->right->insertNode(node);
			} else {
				this->right = node;
			}
		}
		
	public :
		Node(int data) {
			this->data = data;
		}
		
		// Accesseur de donnee
		int getData() {
			return this->data;
		}

		// Creer un nouveau noeud enfant
		void newNode(int data) {
			// Creer le a gauche si la donnee
			// est inferieur de celle du parent
			// sinon creer le a droit
			if(data < this->data && this->left != NULL) {
				this->left->newNode(data);
			} else if(data < this->data) {
				this->left = new Node(data);
			} else if(this->right != NULL) {
				this->right->newNode(data);
			} else {
				this->right = new Node(data);	
			}
		}

		// Avoir un pointeur qui point a un noeud
		// qui a cette valeur de donnee
		Node* getNode(int data) {
			if(data == this->data) return this;
			else if(data > this->data && this->right != NULL) return this->right->getNode(data);
			else if(data < this->data && this->left != NULL) return this->left->getNode(data);

			return NULL;
		}

		// Avoir la longueur de l'arbre
		int getHeight() {
			// Retourner 1 si ce noeud est une Feuille
			if(!this->left && !this->right) return 1;

			int left_height = 0, right_height = 0, mx;
			
			// avoir longuer des sous-arbre 
			// gauche et droite si elles existent
			if(this->left) left_height = this->left->getHeight();
			if(this->right) right_height = this->right->getHeight();
			
			// longueur maximale des sous-arbres
			mx = left_height > right_height ? left_height : right_height;

			// Longueur de l'arbre = longueur max des sous-arbres + 1
			return mx + 1;	
		}
		
		// Supprimer un noeud
		void deleteNode(int data) {
			if(data < this->data && this->left != NULL) {
				if(this->left->data == data) {
					Node* tmp_root = this->left;
					Node* tmp_left = tmp_root->left;
					Node* tmp_right = tmp_root->right;
					this->left = 0;
					this->insertNode(tmp_left);
					this->insertNode(tmp_right);
					delete tmp_root;
				} else {
					this->left->deleteNode(data);
				}
			} else if(data > this->data && this->right != NULL) {
				if(this->right->data == data) {
					Node* tmp_root = this->right;
					Node* tmp_left = tmp_root->left;
					Node* tmp_right = tmp_root->right;
					this->right = 0;
					this->insertNode(tmp_left);
					this->insertNode(tmp_right);
					delete tmp_root;
				} else {
					this->right->deleteNode(data);
				}
			
			}
		}
			
		// Afficher l'arbre en 2D
		void display(int level = 0) {
			// aficher la partie droite
			if(this->right) this->right->display(level + 1);

			// aficher la donnee du noeud avec tabulation
			padding("\t", level);
			std::cout << data << std::endl;
			
			// aficher la partie gauche
			if(this->left) this->left->display(level + 1);
		}

		// avoir le nœud maximum 
		int getMax() {
			// la noeud maximum se trouve a droite
			if(this->right) return this->right->getMax();
			// si il n'y a pas de droite alors le noeud actuel est le max
			else return this->data;
		}

		// avoir le nœud minimum 
		int getMin() {
			// la noeud maximum se trouve a gauche
			if(this->left) return this->left->getMin();
			// si il n'y a pas de noeud a gauche alors le noeud actuel est le min
			else return this->data;
		}

		// Verifier si le exist
		bool exists(int data) {
			return this->getNode(data) != NULL;
		}

		// afficher l'arbre si inorder
		void inorder() {
			if(this->left != NULL )this->left->inorder();
			std::cout << this->data << " ";
			if(this->right != NULL )this->right->inorder();
		}

};
/* CLASS NODE END */

int main() {
	Node* root = NULL;

	while(true) {
		int data;
		std::string cmd; 

		displayMenu(); std::cout << ">>> " ;
		std::getline(std::cin, cmd);
		
		if(cmd.length() != 1) {
			std::cerr << "[!] commande non valide" << std::endl;
			continue;
		} 

		switch(cmd[0]) {
			case '1' :
				std::cout << "Entrez cle du noeud : ";
				std::cin >> data; getchar();

				if(!root) root = new Node(data);
				else root->newNode(data);

				break;

			case '2' :
				std::cout << "Entrez cle du noeud : ";
				std::cin >> data; getchar();
				root->deleteNode(data);

				break;

			case '3' :
				if(root != NULL) { 
					padding("*", 60);
					std::cout << std::endl;
					root->display();
				}

				break;

			case '4' :
				if (root) std::cout << "Max : " << root->getMax() << std::endl;
				else std::cout << "L'arbre est vide" << std::endl;

				break;

			case '5' :
				if (root) std::cout << "Min : " << root->getMin() << std::endl;
				else std::cout << "L'arbre est vide" << std::endl;

				break;

			case '6' :
				std::cout << "Entrez cle du noeud : ";
				std::cin >> data; getchar();
				if(root) {
				std::cout<<"Noeud "<<data<<" "<<(root->getNode(data)?"exist.":"n'exist pas.")<<std::endl;
				} else std::cout << "L'arbre est vide" << std::endl;

				break;
			case '7' :
				exit(0);
				break;
			default :
				std::cerr << "[!] commande non valide" << std::endl;
		}

		// getchar();
	}
	return 0;
}

// Aficher le menu
void displayMenu() {
	padding("=", 60); std::cout << std::endl;
	std::cout << "Menu des opérations de l'arborescence de recherche binaire:" << std::endl;
	padding("=", 60); std::cout << std::endl;
	std::cout << "1.Ajoutez un nouveau nœud" << std::endl;
	std::cout << "2.Supprimer un nœud" << std::endl;
	std::cout << "3.Imprimer tous les nœuds" << std::endl;
	std::cout << "4.Afficher le nœud maximum" << std::endl;
	std::cout << "5.Afficher le nœud minimum" << std::endl;
	std::cout << "6.Trouver un nœud" << std::endl;
	std::cout << "7.Quitter" << std::endl;
}

// Repeter une chaine de caracteres n fois
void padding(std::string ch, int n) {
	for(int i = 0; i < n; i++) std::cout << ch;
}
