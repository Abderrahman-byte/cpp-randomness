#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define MAXLINES 100
#define LINESIZE 100

int main () {
	char* text[MAXLINES];
	int n = 0;

	while(n < MAXLINES) {
		char line_tmp[LINESIZE];
		cin.get(line_tmp, LINESIZE);
		if((int)getchar() == -1 || (int)line_tmp[0] == 0) break;
		
		char *line;
		line = (char *)malloc(strlen(line_tmp) * sizeof(char));
		text[n] = line;

		n++;
	}

	cout << "lines " << n << endl;

	for(int i = 0; i < n ; i++) {
		cout << *(text[i]) << endl;
	}

	return 0;
}
