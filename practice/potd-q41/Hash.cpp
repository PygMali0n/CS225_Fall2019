#include "Hash.h"
#include <string>

unsigned long bernstein(std::string str, int M)
{
	unsigned long b_hash = 5381;
	//Your code here
	for (const char& c : str) {
		b_hash *= 33;
		b_hash += (int) c;
	}
	return b_hash % M;
}

std::string reverse(std::string str)
{
    std::string output = "";
	//Your code here
	for (int i = str.size()-1; i>=0; i--) {
		output += str[i];
	}

	return output;
}
