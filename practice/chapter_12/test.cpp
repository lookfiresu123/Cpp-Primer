#include <memory>
#include <string>
#include <iostream>

using namespace std;

#define TEST_SHARED_PTR_AUTODELETE 0
#define TEST_SHARED_PTR_INITIALIZATION 0
#define TEST_SHARED_PTR_INITIALIZATION_NEW 0
#define TEST_COMPARE_MAKESHARED_NEW 0
#define TEST_UNIQUE_PTR 0
#define TEST_UNIQUE_PTR_DELETE 0
#define TEST_DYNAMIC_ARRAY 0
#define TEST_ALLOCATOR 1

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

int test_compare_makeshared_new(void) {
    Person *p = new Person("chensu", 24);
    shared_ptr<Person> p1(p);
    shared_ptr<Person> p2(p);
    cout << "p1: " << p1.use_count() << endl;
    cout << "p2: " << p2.use_count() << endl;
    delete p;
    return 0;
}

int test_unique_ptr(void) {
    unique_ptr<int> u(new int(1));
    // u.release();    // 释放指针对象u对指针的控制权，返回指针，并将u置为空，但对象没有被释放且和指针之间的联系被断开
    // unique_ptr<int> p(u.release());     // 此时内存由p控制，离开作用域是，p会被销毁，同时内存也会被销毁
    unique_ptr<int> p(new int(2));
    // p.reset(nullptr);
    p.reset(u.release());
    return 0;
}

void my_deleter(int *ptr) {
    delete ptr;
}

int test_unique_ptr_delete(void) {
    int *q = new int(1);
    unique_ptr<int, decltype(my_deleter) *> p(q, my_deleter);
    return 0;
}

int test_dynamic_array(void) {
    int *p = new int[10]{0,1,2,3,4};
    delete [] p;
    return 0;
}

int test_allocator(void) {
    allocator<string> a;
    string *p = a.allocate(1);
    a.construct(p, "chensu");
    a.destroy(p);
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
#if TEST_COMPARE_MAKESHARED_NEW
    test_compare_makeshared_new();
#endif
#if TEST_UNIQUE_PTR
    test_unique_ptr();
#endif
#if TEST_UNIQUE_PTR_DELETE
    test_unique_ptr_delete();
#endif
#if TEST_DYNAMIC_ARRAY
    test_dynamic_array();
#endif
#if TEST_ALLOCATOR
    test_allocator();
#endif
    return 0;
}
