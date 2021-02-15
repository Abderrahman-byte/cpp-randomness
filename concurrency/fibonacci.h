#include <mutex>

#ifndef _FIBONACCI_H_
#define _FIBONACCI_H_
class FibonacciCache {
private :
	typedef unsigned int in_t;
	typedef unsigned long long int out_t;
	
	static const int _MAX = 93;
	out_t _data[_MAX];
	std::mutex mtx;

public :
	FibonacciCache() {
		for(int i = 0; i < _MAX; i++) _data[i] = 0;
	}

	out_t get(in_t n) {
		if(n <= 1) return n;
		else if(n >= _MAX) return 0;
		else if(_data[n] != 0) {
			std::lock_guard<std::mutex> lck(mtx);
			out_t fib_n = _data[n];
			return fib_n;
		} else {
			out_t fib_n = get(n - 1) + get(n - 2);
			std::lock_guard<std::mutex> lck(mtx);
			_data[n] = fib_n;
			return fib_n;
		}
	}
};

#endif
