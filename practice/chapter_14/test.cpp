#include <map>
#include <functional>
#include <string>
#include <iostream>

using namespace std;

class Person {
public:
    Person(const string &_name, int _age) : name(_name), age(_age) {}
    int operator()(int, int) { return 0; }
private:
    string name;
    int age;
};

int test_function_callable_1(int, int) { return 0; }
int test_function_callable_2(int, int) { return 0; }

int test_function() {
    map<string, function<int(int, int)>> binops;
    Person p("chensu", 24);
    function<int(int, int)> f1 = test_function_callable_1;
    function<int(int, int)> f2 = *test_function_callable_2;
    function<int(int, int)> f3 = [](int, int){ return 0; };
    function<int(int, int)> f4 = p;
    binops.insert(pair<string, function<int(int, int)>>("f1", f1));
    binops.insert(pair<string, function<int(int, int)>>("f2", f2));
    binops.insert(pair<string, function<int(int, int)>>("f3", f3));
    binops.insert(pair<string, function<int(int, int)>>("f4", f4));
    return 0;
}

int test_operator_type() {
    int i = 42;
    return 0;
}

int main() {
    // test_function();
    test_operator_type();
    return 0;
}
