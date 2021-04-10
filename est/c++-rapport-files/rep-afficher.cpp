#include <iostream>
#include <fstream>

#define TAILLE 10
#define SEP "$"
#define FILENAME "./repertoire"

std::string split(std::string, std::string, int &, int &);

int main () {
	int i = 0;
	std::ifstream f(FILENAME); // Ouvrir le fichier qui contient les donnees des personnes
	std::string line;

	while(getline(f, line)) {
		int start = 0, end = line.find(SEP, start); // Trouver la premier partie avant $

		std::cout << "[*] Contact " << ++i << " : " << std::endl;
		std::cout << "\tNom : " << split(line, SEP, start, end) << std::endl;  // Afficher partie le nom
		std::cout << "\tNumero de telephone : " << split(line, SEP, start, end) << std::endl; // Afficher partie le numero
		std::cout << "\tAddress : " << split(line, SEP, start, end) << std::endl; // Afficher partie l'address
	}

	f.close(); // Fermer le fichier

	return 0;
}

// Separer les donnees de chaque ligne 
std::string split(std::string str, std::string del, int &start, int &end) {
	if(end != -1) {
		int s = start, e = end;
		start = end + del.size();
		end = str.find(del, start);
		return str.substr(s, e - s) ;
	} else {
		return str.substr(start);
	}
}
