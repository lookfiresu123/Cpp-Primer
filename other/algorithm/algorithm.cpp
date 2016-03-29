#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

#define TEST_ALGORITHM_1 0
#define TEST_ALGORITHM_2 0
#define TEST_ALGORITHM_3 1

class Person {
public:
    Person(const string &_name, int _age) : name(_name), age(_age) {}
    void print() { cout << name << " : " << age << endl; }
    const string &getname() const { return name; }
private:
    string name;
    int age;
};

int test_algorithm_1() {
    vector<shared_ptr<Person>> vec;
    int i = 1;
    const string names = "google sina apple baidu";
    string word;
    stringstream input(names);
    while (input >> word)
        vec.push_back(make_shared<Person>(Person(word, i++)));
    // for_each(vec.begin(), vec.end(), [](shared_ptr<Person> &ptr){ ptr->print(); });
    auto num = count_if(vec.begin(), vec.end(), [](shared_ptr<Person> &ptr){ return ptr->getname().size() > 5; });
    cout << num << endl;
    return 0;
}

int test_algorithm_2() {
    vector<int> vec(10, 0);
    srand(time(0));
    generate(vec.begin(), vec.end(), [](){ return rand()%10; });
    for_each(vec.begin(), vec.end(), [](int element){ cout << element << " "; });
    cout << endl;
    fill(vec.begin(), vec.end(), 0);
    for_each(vec.begin(), vec.end(), [](int element){ cout << element << " "; });
    cout << endl;
    return 0;
}


int test_algorithm_3() {
    vector<int> vec(10, 0);
    srand(time(0));
    generate(vec.begin(), vec.end(), [](){ return rand()%10; });
    for_each(vec.begin(), vec.end(), [](int element){ cout << element << " "; });
    cout << endl;
    cout << (binary_search(vec.begin(), vec.end(), 8) ? "true" : "false") << endl;
    return 0;
}

int main() {
#if TEST_ALGORITHM_1
    test_algorithm_1();
#endif
#if TEST_ALGORITHM_2
    test_algorithm_2();
#endif
#if TEST_ALGORITHM_3
    test_algorithm_3();
#endif

    return 0;
}
