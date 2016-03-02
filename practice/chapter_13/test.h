#ifndef _H_TEST
#define _H_TEST

#include <iostream>
#include <cstdlib>
#include <ctime>

#define TEST_CONSTRUCTOR_ORDER 0
#define TEST_NUMBERED 0
#define TEST_PRACTICE_1 0
#define TEST_CLASS_VALUE_USAGE 0
#define TEST_CLASS_POINTER_USAGE 0
#define TEST_PRACTICE_2 1
#define TEST_PRACTICE_3 0
#define TEST_PRACTICE_4 0
#define TEST_PRACTICE_5 0
#define TEST_PRACTICE_6 0

using namespace std;

class Test {
public:
    Test() { cout << this << " : Test()" << endl; }
    Test(const Test &) { cout << this << " : Test(const Test &)" << endl; }
    ~Test() { cout << this << " : ~Test()" << endl; }
};

class numbered {
public:
    numbered() { srand(time(0)); mysn = rand() % 1000; }
    numbered(const numbered &p) { mysn = p.mysn; srand(time(0)); mysn = rand() % 1000; }
    void print() { cout << "mysn = " << mysn << endl; }
private:
    int mysn;
};

class Employee {
public:
    Employee() { ++id; }
    Employee(const string &_name) : name(_name) { ++id; }
    ~Employee() {}
    void print() { cout << "name = " << name << ", " << "id = " << id << endl; }
private:
    string name;
    static int id;
};

class HasPtr {
public:
    HasPtr(const string &s) : ps(new string(s)), i(0) { cout << "HasPtr(const string &s)" << endl; }
    HasPtr(const HasPtr &p) : ps(new string(*p.ps)), i(p.i) { cout << "HasPtr(const HasPtr &p)" << endl; }
    HasPtr &operator=(const HasPtr &);
    ~HasPtr() { delete ps; }
private:
    string *ps;
    int i;
};

class HasPtrShare {
public:
    // direct constructor allocate new string and new calculator which set to 1
    HasPtrShare(const string &s) : ps(new string(s)), i(0), use(new size_t(1)) {}
    // copy constructor set string and set calculator pointer to the same one, and then add 1 to it
    HasPtrShare(const HasPtrShare &p) : ps(p.ps), i(p.i), use(p.use) { ++*use; }
    HasPtrShare &operator=(const HasPtrShare &);
    ~HasPtrShare();
    void print() { cout << *ps << ", " << i << ", " << *use << endl;}
    void addi() { ++i; }
private:
    string *ps;
    int i;
    size_t *use;   // use count
};

#endif
