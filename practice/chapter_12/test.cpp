#include <memory>
#include <string>
#include <iostream>

using namespace std;

#define TEST_SHARED_PTR_AUTODELETE 0
#define TEST_SHARED_PTR_INITIALIZATION 0
#define TEST_SHARED_PTR_INITIALIZATION_NEW 1

class Person {
private:
    string name;
    int age;
public:
    Person(const string &_name, int _age) : name(_name), age(_age) {};
    void print() const { cout << "name = " << name << ", " << "age = " << age << endl; }
};

int test_shared_ptr_autodelete(void) {
    shared_ptr<Person> p(new Person("chensu", 24));
    shared_ptr<Person> q(new Person("chenye", 23));
    auto ptr_p = p.get(), ptr_q = q.get();
    p.swap(q);
    ptr_p = p.get(), ptr_q = q.get();
    return 0;
}

int test_shared_ptr_initialization(void) {
    shared_ptr<Person> p = make_shared<Person>(Person("chensu",24));
    shared_ptr<Person> q = make_shared<Person>(Person("chenye",23));
    cout << "the use count of p: " << p.use_count() << endl;
    cout << "the use count of q: " << q.use_count() << endl;
    p = q;
    cout << "the use count of p: " << p.use_count() << endl;
    cout << "the use count of q: " << q.use_count() << endl;
    return 0;
}

int test_shared_ptr_initialization_new(void) {
    // shared_ptr<Person> p = new Person("chensu", 24);
    shared_ptr<Person> p(new Person("chensu", 24));
    shared_ptr<Person> q = shared_ptr<Person>(new Person("chenye", 23));
    return 0;
}

int main() {
#if TEST_SHARED_PTR_AUTODELETE
    test_shared_ptr_autodelete();
#endif
#if TEST_SHARED_PTR_INITIALIZATION
    test_shared_ptr_initialization();
#endif
#if TEST_SHARED_PTR_INITIALIZATION_NEW
    test_shared_ptr_initialization_new();
#endif
    return 0;
}
