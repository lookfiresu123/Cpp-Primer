#ifndef _H_TEST
#define _H_TEST

#include <iostream>

using namespace std;

class Test {
public:
    Test() { cout << this << " -> allocate memory " << endl; }
    Test(const Test &) { cout << this << " -> allocate memory " << endl; }
    ~Test() { cout << this << " -> free memory" << endl; }
};

#endif
