#include <iostream>
#include <stack>

/* Prototype des fonctions */
void displayMenu();
void displayStack(std::stack<int>);
void pushToStack(std::stack<int> &);
void popFromStack(std::stack<int> &);
/**/

int main () {
	std::stack<int> s;
	
	// Demander a l'utilisateur d'entrer un choix jusqu'a qu'il choisie 4(exit)
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
				pushToStack(s); // Empiler
				break;

			case '2':
				popFromStack(s); // Supprimer element de la pile
				break;

			case '3':
				displayStack(s); // Afficher la pile
				break;

			case '4':
				exit(0); // Sortir du programme

			default :
				std::cerr << "[!] invalid command" << std::endl; // Afficher Erreur
		}

		// Demander a l'utilisateur s'il veut continue
		std::cout << "\nVoulez-vous continuer (Taper 0(Non) 1(Oui)) ?: ";
		std::cin >> cont;
		getchar();
		if(!cont) break; // Sortir de la boucle si l'utilisateur a choisie "0"
	}

	return 0;
}

// Afficher les element de la pile
void displayStack(std::stack<int> stk) {
	std::stack<int> tmp = stk; // Copier la pile
	
	// Afficher un message si la pile est vide
	if(tmp.empty()) {
		std::cout << "La pile est vide\n";
		return;
	}

	while(!tmp.empty()) {
		std::cout << tmp.top(); // afficher le premier element de la pile
		tmp.pop(); // depiler le premier element de la pile
		std::cout << (!tmp.empty() ? ", ": ""); // si la pile n'est pas vide afficher vergule
	}

	std::cout << std::endl;
}

// Afficher le menu
void displayMenu() {
	std::cout << "1. Empiler" << std::endl;
	std::cout << "2. Depiler" << std::endl;
	std::cout << "3. Afficher" << std::endl;
	std::cout << "4. exit" << std::endl << std::endl;
}

void pushToStack(std::stack<int> &s) {
	int value;
	std::string null;
	
	// Demander a l'utilisateur de saisir l'entier a empiler
	std::cout << "\nEntrer l'element a empiler : " ;
	std::cin >> value;
	
	s.push(value); // empiler
	std::getline(std::cin, null);
}

void popFromStack(std::stack<int> &s) {
	// Verifier si la pile n'est pas vide
	if(!s.empty()) {
		s.pop();
		std::cout << std::endl;
	}
}
