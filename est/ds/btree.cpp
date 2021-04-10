#include <iostream>

template <typename T> class Node  {
	public :
		T data;
		Node<T> *left;
		Node<T> *right;
	
	public :
		Node(T data) {
			this->data = data;
		}

		T getData() {
			return this->data;
		}

		void newNode(T data, bool right = true) {
			if(right && this->right == NULL)  {
				this->right = new Node<T>(data);
			} else if(right) {
				this->right->newNode(data, right);
			} else if(this->left == NULL) { 
				this->left = new Node<T>(data);
			} else {
				this->left->newNode(data, right);
			}
		}

		Node* getNode(bool right = true) {
			return (right ? this->right : this->left);
		}

		int getDepth() {
			if(this->right == NULL && this->left == NULL) {
				return 1;
			}  else {
				int right_depth = this->right != NULL ? this->right->getDepth() : 0;
				int left_depth = this->left != NULL ? this->left->getDepth() : 0;

				return (left_depth > right_depth ? left_depth : right_depth ) + 1;
			}
		}

		void inorder() {
			if(this->left != NULL )this->left->inorder();
			std::cout << this->data << " ";
			if(this->right != NULL )this->right->inorder();
		}
		
		void preorder() {
			std::cout << this->data << " ";
			if(this->left != NULL )this->left->preorder();
			if(this->right != NULL )this->right->preorder();
		}

		void postorder() {
			if(this->left != NULL )this->left->postorder();
			if(this->right != NULL )this->right->postorder();
			std::cout << this->data << " ";
		}

};


int main() {
	Node<int> *n = new Node<int>(1);
	n->newNode(12, false);
	n->newNode(9, true);
	n->left->newNode(5, false);
	n->left->newNode(6, true);

	std::cout << "in-order : "; n->inorder() ; std::cout << std::endl;
	std::cout << "pre-order : " ; n->preorder() ; std::cout << std::endl;
	std::cout << "post-order : "; n->postorder() ; std::cout << std::endl;

	return 0;
}
