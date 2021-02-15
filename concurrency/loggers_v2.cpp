#include <thread>
#include <vector>
#include <unistd.h>

#include "loggers_v2.h"

void generate_data(int, Stack<int>&);
void get_data(int, Stack<int>&, StdoutLogger&, FileLogger&);

int main() {
	const unsigned int THREADS_NUM = std::thread::hardware_concurrency();
	std::vector<std::thread> threads;
	Stack<int> data;
	StdoutLogger output;
	FileLogger file_output("./data.log");
	
	for(int i = 0; i < THREADS_NUM; i++) {
		if(i <= 1) threads.push_back(std::thread(generate_data, i, std::ref(data)));
		else threads.push_back(std::thread(get_data, i, std::ref(data), std::ref(output), std::ref(file_output)));
	}	

	for(int i = 0; i < threads.size(); i++) {
		threads[i].join();
	}
	
	return 0;
}

void generate_data(int i, Stack<int> &s) {
	int a = i % 2 == 0 ? 0 : 1;

	while(true) {
		s.push(a);
		a += 2;	
		usleep(1000 * 1000 / 2);
	}
}

void get_data(int i, Stack<int> &s, StdoutLogger &output, FileLogger &file) {
	while(true) {
		if(!s.empty()) {
			int value = s.pop();
			int s_size = s.size();
			std::string str = "[Thread-" + std::to_string(i) + "] Value from Stack " + std::to_string(value);
			str += " , remains : " + std::to_string(s_size);
			output.print(str);
			file.log(str);
		}

		usleep(1000);
	}
}
