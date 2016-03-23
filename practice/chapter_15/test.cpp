#include <iostream>
#include <string>

using namespace std;

class A {
public:
    A(const string &_name, int _age) : name(_name), age(_age) {}
    void print() { cout << name << " " << age << endl; }
    virtual ~A() {}
protected:
    string name;
    int age;
};

class B : public virtual A {
public:
    B(const string &_name, int _age, int _height) : A(_name, _age), height(_height) {}
    virtual ~B() {}
protected:
    int height;
};

class C : public virtual A {
public:
    C(const string &_name, int _age, int _weight) : A(_name, _age), weight(_weight) {}
    virtual ~C() {}
protected:
    int weight;
};

class D : public B, public C {
public:
    D(const string &_name1, const string &_name2 ,int _age1, int _age2, int _height, int _weight, const string &_sex) :
        B(_name1, _age1, _height), C( _name2, _age2, _weight ), A(_name1, _age1), sex(_sex) {}
    ~D() {}
protected:
    string sex;
};

class E : public A {
public:
    E(const string &_name, int _age, int _height) : A(_name, _age), height(_height) {}
    virtual ~E() {}
protected:
    int height;
};

class F : public A {
public:
    F(const string &_name, int _age, int _weight) : A(_name, _age), weight(_weight) {}
    virtual ~F() {}
protected:
    int weight;
};

class G : public E, public F {
public:
    G(const string &_name1, const string &_name2 ,int _age1, int _age2, int _height, int _weight, const string &_sex) :
        E(_name1, _age1, _height), F( _name2, _age2, _weight ), sex(_sex) {}
    ~G() {}
protected:
    string sex;
};



int main() {
    // D d("chensu", "chenye", 24, 23, 172, 100, "male");
    // d.print();
    G g("chensu", "chenye", 24, 23, 172, 100, "male");
    return 0;
}
