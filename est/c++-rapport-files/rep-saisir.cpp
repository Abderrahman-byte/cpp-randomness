#include <iostream>
#include <fstream>

#ifndef TAILLE
#define TAILLE 10 // taille du repertoire
#endif

#define SEP "$" // séparater les donnees d'un personne EXP: Abderrahmane$0697827872$C7, imm omari, casablanca , Maroc
#define FILENAME "./repertoire" // Nom de Fichier dans le quel les donnees sont enregistrer

// Stocker les donnees d'un personne
class Contact {
	public :
		std::string nom;
		std::string num;
		std::string address;

		std::string get_data();
};

// Enregister un tableau des contact dans fichier
void save(Contact [], int, std::string);

int main () {
	Contact list_contacts[TAILLE];

	// Demander a l'utilisateur a entrer les donnees des personnes
	for(int i = 0; i < TAILLE; i++) {
		std::cout << "[*] Contact numero " << i + 1 << " : " << std::endl;

		std::cout << "\tNom : ";
		std::getline(std::cin, list_contacts[i].nom);

		std::cout << "\tNumero de telephone : ";
		std::getline(std::cin, list_contacts[i].num);

		std::cout << "\tAddress : ";
		std::getline(std::cin, list_contacts[i].address);
	}
	
	// Enregistrer les donnees saisies par l'utilisateur
	save(list_contacts, TAILLE, FILENAME); 
	
	std::cout << "Vos donnees sont enregistees." << std::endl;
	return 0;
}

// Formater les donnees d'un personne sous forme d'un ligne
std::string Contact::get_data() {
	// Format : nom$numero$address
	return nom  + SEP + num + SEP + address;
}

void save(Contact list[], int size, std::string filename) {
	static std::ofstream f; // Creer stream une seule fois

	// Ouvrir le fichier si n'est pas ouvert 
	if(!f.is_open()) f.open(filename);

	for(int i = 0; i < size; i++) {
	 	f << list[i].get_data() << std::endl; // Ecrire au fichier
	}
}
