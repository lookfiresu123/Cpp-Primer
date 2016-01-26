#ifndef _ASSOCIATIVE_CONTAINER_H
#define _ASSOCIATIVE_CONTAINER_H 1

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cctype>
#include <list>
#include <utility>

using std::vector;
using std::string;
using std::map;
using std::multimap;
using std::set;
using std::multiset;
using std::unordered_map;
using std::unordered_set;
using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::pair;

class Sales_data {
private:
    string bookname;
public:
    Sales_data(const string &str) : bookname(str) { }
    const string &isbn() const {
        return bookname;
    }
};

#define TEST_ASSOCIATIVE_CONTAINER_1 0
#define TEST_ASSOCIATIVE_CONTAINER_2 0
#define TEST_ASSOCIATIVE_CONTAINER_3 0
#define TEST_ASSOCIATIVE_CONTAINER_4 0
#define TEST_ASSOCIATIVE_CONTAINER_5 0
#define TEST_ASSOCIATIVE_CONTAINER_6 0
#define TEST_ASSOCIATIVE_CONTAINER_7 0
#define TEST_ASSOCIATIVE_CONTAINER_8 0
#define TEST_ASSOCIATIVE_CONTAINER_9 0
#define TEST_ASSOCIATIVE_CONTAINER_10 0
#define TEST_ASSOCIATIVE_CONTAINER_11 0
#define TEST_ASSOCIATIVE_CONTAINER_12 1
#define TEST_ASSOCIATIVE_CONTAINER_13 0
#define TEST_ASSOCIATIVE_CONTAINER_14 0

#endif

