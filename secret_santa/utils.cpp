#include <fstream>

#define RNDSOURCEFILE "/dev/urandom"
#define BUFFER_SIZE 50

int randomNumber() {
	static std::ifstream rnd_source;
	unsigned char buffer[BUFFER_SIZE];
	int rndSome = 0;

	if(!rnd_source.is_open()) {
		rnd_source.open(RNDSOURCEFILE);
	}

	rnd_source.read((char *)buffer, BUFFER_SIZE);

	for(int i = 0; i < BUFFER_SIZE; i++) rndSome += (int)buffer[i];

	return rndSome;
}

int randomRange (int min, int max) {
	return (randomNumber() % (max - min + 1)) + min;
}
