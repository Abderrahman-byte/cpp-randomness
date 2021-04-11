#include <iostream>

/* CLASS NODE START */
class Node  {
	public :
		int data;
		Node *left;
		Node *right;
		
		// Inserer une node 
		void insertNode(Node *node) {
			if(!node || node == this) return;

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

		int getData() {
			return this->data;
		}

		void newNode(int data) {
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

		Node* getNode(int data) {
			if(data == this->data) return this;
			else if(data > this->data && this->right != NULL) return this->right->getNode(data);
			else if(data < this->data && this->left != NULL) return this->left->getNode(data);

			return NULL;
		}

		int getHeight() {
			if(!this->left && !this->right) return 1;

			int left_height = 0, right_height = 0, mx;
			
			if(this->left) left_height = this->left->getHeight();
			if(this->right) right_height = this->right->getHeight();
			
			mx = left_height > right_height ? left_height : right_height;

			return mx + 1;	
		}
			
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
		
		// Repeter une chaine de caracteres n fois
		void padding(std::string ch, int n) {
			for(int i = 0; i < n; i++) std::cout << ch;
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

		void inorder() {
			if(this->left != NULL )this->left->inorder();
			std::cout << this->data << " ";
			if(this->right != NULL )this->right->inorder();
		}

};
/* CLASS NODE END */

int main() {
	Node* root = new Node(20);
	root->newNode(62);
	root->newNode(6);
	root->newNode(2);
	root->newNode(91);
	root->newNode(-3);
	root->newNode(72);
	root->newNode(17);
	root->newNode(-922);
	
	std::cout << "depth : " << root->getHeight() << std::endl;
	std::cout << "in-order : "; root->inorder(); std::cout << std::endl;	
	root->deleteNode(12);
	std::cout << "in-order : "; root->inorder(); std::cout << std::endl;	
	std::cout << "depth : " << root->getHeight() << std::endl;

	root->display();
	return 0;
}
