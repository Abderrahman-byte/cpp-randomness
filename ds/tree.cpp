#include <iostream>
#include <vector>

class TreeNode {
	private :
		char data;
		std::vector<TreeNode> children;

	public :
		TreeNode(char data = '.') {
			this->data = data;
		}

		char getData() {
			return this->data;
		}

		int getChildIndex(char data) {
			int index = -1;

			for(int i = 0; i < children.length(); i++) {
				if(children[i].getData() === data) {
					index = i;
					break;	
				}
			}

			return index;
		}

		void insert(std::string str) {
			int childIndex = getChildIndex(str[0]);

			if(childIndex >= 0) {
				
			}
		} 
};
