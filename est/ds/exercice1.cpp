#include <iostream>
#include <stack>

void displayMenu();
void displayStack(std::stack<int>);
void pushToStack(std::stack<int> &);
void popFromStack(std::stack<int> &);

int main () {
	std::stack<int> s;

	while(true) {
		bool cont;
		std::string cmd;

		displayMenu();
		std::cout << "Entrez votre choix: " ;
		std::getline(std::cin, cmd);
		
		if(cmd.compare("exit") == 0 || cmd.compare("quit") == 0) exit(0);

		if(cmd.length() != 1) {
			std::cerr << "[!] invalid command" << std::endl;
			continue;
		}

		switch(cmd[0]) {
			case '1':
				pushToStack(s);
				break;

			case '2':
				popFromStack(s);
				break;

			case '3':
				displayStack(s);
				break;

			case '4':
				exit(0);

			default :
				std::cerr << "[!] invalid command" << std::endl;
		}

		std::cout << "\nVoulez-vous continuer (Taper 0(Non) 1(Oui)) ?: ";
		std::cin >> cont;
		getchar();
		if(!cont) break;
	}

	return 0;
}

void displayStack(std::stack<int> stk) {
	std::stack<int> tmp = stk;
	
	if(tmp.empty()) {
		std::cout << "La pile est vide\n";
		return;
	}

	while(!tmp.empty()) {
		std::cout << tmp.top();
		tmp.pop();	
		std::cout << (!tmp.empty() ? ", ": "");
	}

	std::cout << std::endl;
}

void displayMenu() {
	std::cout << "1. Empiler" << std::endl;
	std::cout << "2. Depiler" << std::endl;
	std::cout << "3. Afficher" << std::endl;
	std::cout << "4. exit" << std::endl << std::endl;
}

void pushToStack(std::stack<int> &s) {
	int value;
	std::string null;

	std::cout << "\nEntrer l'element a empiler : " ;
	std::cin >> value;
	
	s.push(value);
	std::getline(std::cin, null);
}

void popFromStack(std::stack<int> &s) {
	if(!s.empty()) {
		s.pop();
		std::cout << std::endl;
	}
}
