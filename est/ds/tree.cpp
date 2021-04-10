#include <iostream>
#include <vector>

template <typename T> class Node {
	public :
		T data;
		std::vector<Node *> children;

		Node(T data) {
			this->data = data;
		}

		void addChild(T data) {
			this->children.push_back(new Node(data));
		}

		int getDepth() {
			int children_max_depth = 0;
			for(int i = 0; i < this->children.size(); i++) {
				int cd = this->children[i]->getDepth();
				if(cd > children_max_depth) children_max_depth = cd;
			}

			return children_max_depth + 1;
		}

		int getMaxGen() {
			int gen_count = 0;
			for(int i = 0; i < this->children.size(); i++ ) {
				gen_count += this->children[i]->getMaxGen();
			}

			return gen_count > this->children.size() ? gen_count : this->children.size();
		}

		void display(bool root = true, bool newLine = true) {
			if(root) std::cout << this->data << std::endl;
			
			for(int i = 0; i < this->children.size(); i++) std::cout << this->children[i]->data << " " ;
			
			if(newLine) std::cout << "\n";

			
			for(int i = 0; i < this->children.size(); i++) {
				this->children[i]->display(false, i == this->children.size() - 1 && newLine);
			}
		}
};

int main () {
	Node<char>* root = new Node<char>('A');
	root->addChild('B');
	root->addChild('C');
	root->addChild('D');

	root->children[0]->addChild('E');
	root->children[0]->addChild('F');

	root->children[2]->addChild('G');
	root->children[2]->addChild('H');
	
	std::cout << "Depth : " << root->getDepth() <<std::endl;
	std::cout << "Max Gen : " << root->getMaxGen() <<std::endl;
	root->display();
}
