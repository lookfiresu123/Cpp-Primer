#ifndef _H_CONTAINER
#define _H_CONTAINER

#include <iostream>
#include <vector>
#include <string>

// c->append :
    // (&c)-> ==> this_c-> ==> &(c.b)
    // (&(c.b))-> ==> this_b ==> &(c.b.a)
    // (&(c.b.a))->append ==> this_a->append ==> a function pointer

using namespace std;

int test_operator_pointer(void);

class A {
public:
    vector<string> vec;
    A &append(const string &s) { vec.push_back(s); return *this; }
    A &operator*() { return *this; }
};

class B {
public:
    A a;
    A *operator->() { return &a; }
    B &operator*() { return *this; }
};

class C {
public:
    B b;
    B &operator->() { return b; }
    C &operator*() { return *this; }
};

#endif
