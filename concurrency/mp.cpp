#include <iostream>

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>

static int *globaleVar;

int main() {
	int pid = 1;
	std::cout << "[START]" << std::endl ;
	
	globaleVar = (int *)mmap(NULL, sizeof *globaleVar, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);

	*globaleVar = 1;

	for(int i = 0; i < 3; i++) {
		if(pid > 0) pid = fork();
	}

	std::cout << "[" << getpid() << "] &pid => " << &pid  << std::endl ;
	
	while(true) {
		if(pid > 0) {
			std::cout << "[MASTER " << getpid() << "] " << *globaleVar << std::endl;
		} else {
			*globaleVar += 1;
		}

		sleep(1);
	}

	return 0;
}
