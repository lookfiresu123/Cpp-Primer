#ifndef _H_GENERIC_ALGORITHM_H
#define _H_GENERIC_ALGORITHM_H 1

#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <numeric>

#define TEST_GENERIC_ALGORITHM_1 0
#define TEST_GENERIC_ALGORITHM_2 0
#define TEST_GENERIC_ALGORITHM_3 0
#define TEST_GENERIC_ALGORITHM_4 0
#define TEST_GENERIC_ALGORITHM_5 0
#define TEST_GENERIC_ALGORITHM_6 0
#define TEST_GENERIC_ALGORITHM_7 0
#define TEST_GENERIC_ALGORITHM_8 1
#define TEST_GENERIC_ALGORITHM_9 0

class Sales_data {
private:
	std::string bookname;
public:
	Sales_data(const std::string &s) : bookname(s) { }
	const std::string &isbn() const {
		return bookname;
	}
};

#endif
