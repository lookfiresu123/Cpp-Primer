#include <iostream>

using namespace std;

class A {
public:
    A(const string &_name_A) : name_A(_name_A) {
        cout << "create A" << endl;
    }
    ~A() {
        cout << "delete A" << endl;
    }
protected:
    string name_A;
};

class B : virtual public A {
public:
    B(const string &_name_A, const string &_name_B) : A(_name_A), name_B(_name_B) {
        cout << "create B" << endl;
    }
    ~B() {
        cout << "delete B" << endl;
    }
protected:
    string name_B;
};

class C : virtual public A {
public:
    C(const string &_name_A, const string &_name_C) : A(_name_A), name_C(_name_C) {
        cout << "create C" << endl;
    }
    ~C() {
        cout << "delete C" << endl;
    }
protected:
    string name_C;
};

class D : public B, public C {
public:
    D(const string &_name_A, const string &_name_B, const string &_name_C, const string &_name_D) : A(_name_A), B(_name_A, _name_B), C(_name_A, _name_C), name_D(_name_D) {
        cout << "create D" << endl;
    }
    ~D() {
        cout << "delete D" << endl;
    }
protected:
    string name_D;
};

int main() {
    D d("a","b","c","d");
    return 0;
}
