#include <vector>
#include <memory>
#include <string>
#include <iostream>

using namespace std;

#define TEST_DYNAMIC_MEMORY_1 0
#define TEST_DYNAMIC_MEMORY_2 0
#define TEST_DYNAMIC_MEMORY_3 1
#define TEST_DYNAMIC_MEMORY_4 0
#define TEST_DYNAMIC_MEMORY_5 0

void read(vector<int> *ptr) {
    int temp;
    while (cin >> temp)
        ptr->push_back(temp);
}

void print(vector<int> *ptr) {
    vector<int>::size_type length = ptr->size();
    for (vector<int>::size_type i = 0 ; i < length ; ++i)
        cout << (*ptr)[i] << " ";
    cout << endl;
}

int test_dynamic_memory_1(void) {
    vector<int> *ptr = new vector<int>;     // 默认初始化为空
    read(ptr);
    print(ptr);
    delete ptr;
    return 0;
}

void read(shared_ptr<vector<int>> ptr) {
    int temp;
    while (cin >> temp)
        ptr->push_back(temp);
}

void print(shared_ptr<vector<int>> ptr) {
    vector<int>::size_type length = ptr->size();
    for (vector<int>::size_type i = 0 ; i < length ; ++i)
        cout << (*ptr)[i] << " ";
    cout << endl;
}

int test_dynamic_memory_2(void) {
    shared_ptr<vector<int>> ptr(new vector<int>);
    read(ptr);
    print(ptr);
    return 0;
}

int test_dynamic_memory_3(void) {
    const size_t n = 10;
    allocator<string> a;
    string *const p = a.allocate(n);
    for (size_t i = 0 ; i < n ; ++i)
        a.construct(p+i);
    string s;
    string *q = p;
    while (cin >> s && q != p + n)
        *q++ = s;
    const size_t size = q - p;
    for (size_t i = 0 ; i < n ; ++i)
        a.destroy(p+i);
    a.deallocate(p, n);
    cout << size << endl;
    return 0;
}

int main() {
#if TEST_DYNAMIC_MEMORY_1
    test_dynamic_memory_1();    // 练习1.26
#endif
#if TEST_DYNAMIC_MEMORY_2
    test_dynamic_memory_2();    // 练习1.27
#endif
#if TEST_DYNAMIC_MEMORY_3
    test_dynamic_memory_3();
#endif
#if TEST_DYNAMIC_MEMORY_4
#endif
#if TEST_DYNAMIC_MEMORY_5
#endif

    return 0;
}
