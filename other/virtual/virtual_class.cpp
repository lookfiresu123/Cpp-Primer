#include <iostream>

using namespace std;

class A {
public:
    friend class B;
    void runA() { cout << "this is A::runA" << endl; }
    class AA {
    public:
        virtual void runAA() = 0;
    };
};

class B : public A {
public:
    class AB : public A::AA {
    public:
        void runAA() { cout << "this is B::runAA();" << endl; }
    };
};

int main() {
    B::AB ab;
    ab.runAA();
    return 0;
}
