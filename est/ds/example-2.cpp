#include <iostream>
#include <stack>

void displayStack(std::stack<int>);
void stackStat(std::stack<int>);

int main () {
	std::stack<int> s;

	std::cout << "Apres declaration ";
	stackStat(s);

	s.push(20);
	s.push(30);
	s.push(40);

	std::cout << "\nApres empilement de 20, 30 et 40 ";
	stackStat(s);
	
	std::cout << "\nApres empilement de 20, 30 et 40 ";
	stackStat(s);
	
	s.pop();
	std::cout << "\nApres p.pop(), ";
	stackStat(s);

	s.pop();
	std::cout << "\nApres p.pop(), ";
	stackStat(s);

	s.pop();
	std::cout << "\nApres p.pop(), ";
	stackStat(s);
}

void displayStack(std::stack<int> stk) {
	std::stack<int> tmp = stk;

	while(!tmp.empty()) {
		std::cout << tmp.top();
		tmp.pop();	
		std::cout << (!tmp.empty() ? " ,": "");
	}
}

void stackStat(std::stack<int> stk) {
	std::cout << "p = " ;
	displayStack(stk);
	std::cout << " => p.size() = " << stk.size() << std::endl;
	std::cout << "p.empty() = " << (stk.empty() ? "true" : "false") << std::endl;
	if(!stk.empty()) std::cout << "p.top() = " << stk.top() << std::endl;
}
