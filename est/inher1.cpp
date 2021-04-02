#include <iostream>

class ObjectVolant {
	protected :
		int nbreAiles;

	public :
		ObjectVolant();
		ObjectVolant(int);
		virtual ~ObjectVolant();

		virtual void vole();

};

class ObjectMotorise {
	protected :
		int nbreRoues;

	public :
		ObjectMotorise();
		ObjectMotorise(int);
		virtual ~ObjectMotorise();

		void roule();
		void vole();

};

class Avion : public ObjectVolant, public ObjectMotorise {
	public :
		virtual ObjectMotorise() = 0;
		// virtual ObjectMotorise(int) = 0;
		Avion();
		Avion(int, int);
		~Avion();
};

int main () {
	Avion v;
	// v.vole();

	return 0;
}

/* Object Volant*/
ObjectVolant::ObjectVolant() {
	this->nbreAiles = 2;
	std::cout << "Demarrage d'un object volant a 2 ailes" << std::endl;
}

ObjectVolant::ObjectVolant(int a) {
	this->nbreAiles = a;
	std::cout << "Demarrage d'un object volant a " << a << " ailes" << std::endl;
}

ObjectVolant::~ObjectVolant() {
	std::cout << "Arret de l'object volant a "<< this->nbreAiles << " ailes" << std::endl;
}

void ObjectVolant::vole() {
	std::cout << "Ca vole" << std::endl;
}

/* Object Roulant */
ObjectMotorise::ObjectMotorise() {
	this->nbreRoues = 2;
	std::cout << "Demarrage d'un object motorise a 2 roues" << std::endl;
}

ObjectMotorise::ObjectMotorise(int a) {
	this->nbreRoues = a;
	std::cout << "Demarrage d'un object motorise a " << a << " roues" << std::endl;
}

ObjectMotorise::~ObjectMotorise() {
	std::cout << "Arret de l'object motorise a " << this->nbreRoues << " roues" << std::endl;
}

void ObjectMotorise::roule() {
	std::cout << "Ca roule" << std::endl;
}

void ObjectMotorise::vole() {
	std::cout << "Ca roule from ObjectMotorise" << std::endl;
}

// Avion Class
Avion::Avion() : ObjectVolant(5), ObjectMotorise(3){
	std::cout << "Demarrage d'avion" << std::endl;
}
	
	
Avion::Avion(int a, int b) : ObjectVolant(a), ObjectMotorise(b) {
	std::cout << "Demarrage d'avion" << std::endl;
}
		 
Avion::~Avion() {
	std::cout << "Demarrage d'avion" << std::endl;
}
