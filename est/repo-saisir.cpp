#include <iostream>
#include <fstream>

#ifndef TAILLE
#define TAILLE 10
#endif

#define SEP "$"
#define FILENAME "./repertoire"

class Contact {
	public :
		std::string nom;
		std::string num;
		std::string address;

		std::string get_data();
};

void save(Contact [], int, std::string);

int main () {
	Contact list_contacts[TAILLE];

	for(int i = 0; i < TAILLE; i++) {
		std::cout << "[*] Contact numero " << i + 1 << " : " << std::endl;

		std::cout << "\tNom : ";
		std::getline(std::cin, list_contacts[i].nom);

		std::cout << "\tNumero de telephone : ";
		std::getline(std::cin, list_contacts[i].num);

		std::cout << "\tAddress : ";
		std::getline(std::cin, list_contacts[i].address);
	}
	
	save(list_contacts, TAILLE, FILENAME);

	std::cout << "Vos donnees sont enregistees." << std::endl;
	return 0;
}

std::string Contact::get_data() {
	return nom  + SEP + num + SEP + address;
}

void save(Contact list[], int size, std::string filename) {
	static std::ofstream f;

	if(!f.is_open()) f.open(filename);

	for(int i = 0; i < size; i++) {
	 	f << list[i].get_data() << std::endl;
	}
}
