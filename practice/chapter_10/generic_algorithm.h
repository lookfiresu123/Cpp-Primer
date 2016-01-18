#ifndef _H_GENERIC_ALGORITHM_H
#define _H_GENERIC_ALGORITHM_H 1

#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <numeric>
#include <typeinfo>
#include <functional>
#include <list>
#include <deque>
#include <fstream>
#include <sstream>
#include <iterator>

#define TEST_GENERIC_ALGORITHM_1 0
#define TEST_GENERIC_ALGORITHM_2 0
#define TEST_GENERIC_ALGORITHM_3 0
#define TEST_GENERIC_ALGORITHM_4 0
#define TEST_GENERIC_ALGORITHM_5 0
#define TEST_GENERIC_ALGORITHM_6 0
#define TEST_GENERIC_ALGORITHM_7 0
#define TEST_GENERIC_ALGORITHM_8 0
#define TEST_GENERIC_ALGORITHM_9 0
#define TEST_GENERIC_ALGORITHM_10 0
#define TEST_GENERIC_ALGORITHM_11 0
#define TEST_GENERIC_ALGORITHM_12 0
#define TEST_GENERIC_ALGORITHM_13 0
#define TEST_GENERIC_ALGORITHM_14 0
#define TEST_GENERIC_ALGORITHM_15 0
#define TEST_GENERIC_ALGORITHM_16 0
#define TEST_GENERIC_ALGORITHM_17 0
#define TEST_GENERIC_ALGORITHM_18 0
#define TEST_GENERIC_ALGORITHM_19 0
#define TEST_GENERIC_ALGORITHM_20 0
#define TEST_GENERIC_ALGORITHM_21 0
#define TEST_GENERIC_ALGORITHM_22 0
#define TEST_GENERIC_ALGORITHM_23 0
#define TEST_GENERIC_ALGORITHM_24 0
#define TEST_GENERIC_ALGORITHM_25 0
#define TEST_GENERIC_ALGORITHM_26 0
#define TEST_GENERIC_ALGORITHM_27 1
#define TEST_GENERIC_ALGORITHM_28 0
#define TEST_GENERIC_ALGORITHM_29 0

using namespace std::placeholders;
using namespace std;

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
