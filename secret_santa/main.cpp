#include <iostream>
#include <vector>
#include <map>

#include "utils.h"

void distribute(std::vector<std::string>, std::map<std::string, std::string>&);

int main () {
	std::vector<std::string> names;
	std::map<std::string, std::string> relations;
	
	std::cout << "Entrez les noms des person ou \"done\" pour finir." << std::endl;

	while(true) {
		std::string name;
		
		std::cout << "Person " << names.size() + 1 << " : ";
		std::cin >> name;

		if(name.compare("done") == 0 || name.compare("") == 0) break;

		names.push_back(name);
	}

	for(int i = 0; i < names.size(); i++) {
		std::cout << "[" << i << "] " << names[i] << " " << std::endl;
	}
	
	distribute(names, relations);

	for(int i = 0; i < names.size(); i++) {
		std::string name = names[i];
		std::cout << name << " => " << relations[name] << std::endl;
	}

	return 0;
}

bool exists(std::map<std::string, std::string> relations, std::string value) {
	bool exists = false;
	
	for(std::map<std::string, std::string>::iterator ii = relations.begin(); ii != relations.end(); ii++) {
		std::string c_value = (*ii).second;

		if(c_value.compare(value) == 0) {
			exists = true;
			break;
		}
	}

	return exists;
}

void distribute(std::vector<std::string> names, std::map<std::string, std::string> &relations) {
	int names_size = names.size();

	while(relations.size() < names_size) {
		for(int i = 0; i < names_size; i++) {
			int rndIndex;
			std::string name;

			do {
				rndIndex = randomRange(0, names.size() - 1);
				name = names[rndIndex];
				if(exists(relations, name)) rndIndex = i;
			} while (rndIndex == i);

			relations[names[i]] = name;
		}
	}
}
