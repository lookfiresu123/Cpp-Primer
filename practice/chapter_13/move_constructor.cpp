#include <vector>
#include <iostream>

using namespace std;

class Person {
public:
    Person() : vec(new vector<int>()) {}
    Person(Person &&p) noexcept : vec(p.vec) { p.vec = nullptr; }
    void print();
    void push_back(int x) { vec->push_back(x); }
    ~Person() {
        if (vec)
            delete vec;
    }
private:
    vector<int> *vec;
};

void Person::print() {
    if (vec) {
        for (vector<int>::size_type i = 0 ; i < vec->size() ; ++i)
             cout << (*vec)[i] << " ";
        cout << endl;
    }
}

int main() {
    Person p1;
    p1.push_back(1);
    p1.push_back(2);
    p1.push_back(3);
    p1.print();
    Person p2 = std::move(p1);
    p1.print();
    p2.print();
    return 0;
}
