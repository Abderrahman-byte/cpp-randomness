#include <iostream>
#include <stack>
#include <mutex>
#include <fstream>

#ifndef _LOGGERS_V2_H_
#define _LOGGERS_V2_H_ 1

class FileLogger {
private :
	std::mutex mtx;
	std::fstream file;
	std::string _filename;
	std::once_flag _flag;

public :
	FileLogger(std::string filename) {
		_filename = filename;
	}

	void log(std::string str) {
		std::call_once(_flag, [&]{ file.open(_filename); }); // open file once 

		std::lock_guard<std::mutex> lck(mtx);
		file << str << std::endl;
	}
};

// Stout stream interface to be used in multithreads safely
class StdoutLogger {
private:
	std::mutex mtx;

public :
	void print(std::string str) {
		std::lock_guard<std::mutex> lck(mtx); // locale to lock mutex and unlock
		std::cout << str << std::endl;
	} 
};

// STACK interface designed to be thread safety
template <typename T> class Stack {
private :
	std::mutex mtx;
	std::stack<T> _data;

public :
	T pop() {
		std::lock_guard<std::mutex> lck(mtx); // locale to lock mutex and unlock

		T value = _data.top(); // get top value
		_data.pop(); // delete top value
		return value;	
	}

	void push(T value) {
		std::lock_guard<std::mutex> lck(mtx); // locale to lock mutex and unlock
		_data.push(value); // push to the stack
	}	

	bool empty() {
		std::lock_guard<std::mutex> lck(mtx); // locale to lock mutex and unlock
		return _data.empty();
	}

	int size() {
		std::lock_guard<std::mutex> lck(mtx); // locale to lock mutex and unlock
		return _data.size();
	}
};

#endif
