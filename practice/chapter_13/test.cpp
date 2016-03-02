#include "test.h"

void fcn(const Test *q1, Test q2) {
    Test t1(*q1), t2(q2);
}

void f(numbered s) {
    s.print();
}

int Employee::id = 0;

HasPtr &HasPtr::operator=(const HasPtr &that) {
    if (!(*ps).empty())
        delete ps;
    ps = new string(*that.ps);
    i = that.i;
    cout << "HasPtr &operator=(const HasPtr &)" << endl;
    return *this;
}

HasPtrShare &HasPtrShare::operator=(const HasPtrShare &that) {
    ++*that.use;
    if (--*use == 0) {
        delete use;
        delete ps;
    }
    ps = that.ps;
    i = that.i;
    use = that.use;
    return *this;
}

HasPtrShare::~HasPtrShare() {
    if (--*use == 0) {
        delete use;
        delete ps;
    }
}

int main() {
#if TEST_CONSTRUCTOR_ORDER
    Test p1, p2;
    fcn(&p1, p2);
#endif
#if TEST_NUMBERED
    numbered a, b = a, c = b;
    f(a); f(b); f(c);
#endif
#if TEST_PRACTICE_1
    Employee p1;
    p1.print();
    Employee p2("chensu");
    p2.print();
#endif
#if TEST_CLASS_VALUE_USAGE
    HasPtr p1("chensu");    // 直接构造函数
    HasPtr p2(p1);      // 拷贝构造函数
    HasPtr p3 = p2;     // 拷贝构造函数
    p1 = p2;        // 赋值
#endif
#if TEST_CLASS_POINTER_USAGE
    HasPtrShare p1("chensu");    // 直接构造函数
    p1.addi(); p1.print();
    HasPtrShare p2(p1);      // 拷贝构造函数
    p2.addi(); p2.print();
    HasPtrShare p3 = p2;     // 拷贝构造函数
    p3.addi(); p3.print();
    p1 = p2;        // 赋值
    p1.addi(); p1.print();
#endif
    return 0;
}
