#include <vector>
#include <iostream>

using namespace std;

#define DO_TEST_VECTOR_1 0
#define DO_TEST_VECTOR_2 0
#define DO_TEST_VECTOR_3 0
#define DO_TEST_VECTOR_4 0
#define DO_TEST_VECTOR_5 0
#define DO_TEST_VECTOR_6 0
#define DO_TEST_VECTOR_7 0
#define DO_TEST_VECTOR_8 0
#define DO_TEST_VECTOR_9 0
#define DO_TEST_VECTOR_10 0
#define DO_TEST_VECTOR_11 1
#define DO_TEST_VECTOR_12 0
#define DO_TEST_VECTOR_13 0

int test_vector_1 (void) {
    vector<int> v;
    //cout << "the max_size is : " << v.max_size() << endl;
    unsigned long int max_element = v.max_size();
    for (int i = 0 ; i < 10 ; i++)
        v.push_back(i);
    int elements_count = v.size();
    v.resize(11);
    elements_count = v.size();
    int *data = v.data();
    return 0;
}

int test_vector_2 (void) {
    vector<int> v;
    for (int i = 0 ; i < 10 ; i++)
        v.push_back(i);
    for (auto &c : v)
        c = 0;
    return 0;
}

/* 3.3.2节练习 */
int test_vector_3 (void) {
    //vector<string> s = {"a","b","c"};
    // 练习3.14
#if 0
    vector<int> v;
    int temp;
    while (cin >> temp)
        v.push_back(temp);
#endif
    // 练习3.15
#if 1
    vector<string> s;
    string str;
    while (cin >> str)
        s.push_back(str);
#endif
    return 0;
}

int test_vector_4 (void) {
    vector<int> v{0,1,2,3,4,5,6,7,8,9};
    for (auto &temp : v)     // auto类型为vector<int>::size_type
        temp *= temp;
    for (auto temp : v)
        cout << temp << endl;
    return 0;
}

int test_vector_5 (void) {
    vector<unsigned> scores(11, 0);     // 初始化vector
    unsigned grade;
    while (cin >> grade)
        ++scores[grade/10];
    return 0;
}

void output (auto temp) {
    cout << "size is: " << temp.size() << endl;
    cout << "data is: ";
    for (auto interator = temp.begin() ; interator != temp.end() ; ++interator)
        cout << *interator << " ";
    cout << endl;
}

/* 练习3.16 */
int test_vector_6 (void) {
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 2);
    vector<int> v4{10};
    vector<int> v5{10,42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};
    output(v1);
    cout << "--------" << endl;
    output(v2);
    cout << "--------" << endl;
    output(v3);
    cout << "--------" << endl;
    output(v4);
    cout << "--------" << endl;
    output(v5);
    cout << "--------" << endl;
    output(v6);
    cout << "--------" << endl;
    output(v7);
    return 0;
}

/* 练习3.17 */
int test_vector_7 (void) {
    string str;
    vector<string> container;
    while (cin >> str)
        container.push_back(str);
    for (auto str_one : container) {
        for (auto char_one : str_one)
            cout << static_cast<char>(toupper(char_one));
        cout << endl;
    }
    return 0;
}

/* 练习3.19 */
int test_vector_8 (void) {
    // 定义含10个元素的vector对象，所有元素的值都是42
    vector<int> v1(10, 42);
    vector<int> v2 = {42,42,42,42,42,42,42,42,42,42};
    vector<int> v3;
    for (int i = 0 ; i < 10 ; ++i)
        v3.push_back(42);
    return 0;
}

/* 练习3.20 */
int test_vector_9 (void) {
    vector<int> v;
    int temp;
    while (cin >> temp)
        v.push_back(temp);
    for (auto first = v.begin(), last = v.end() ; first <= last ; ++first, --last)
        cout << *first << " + " << *last << " = " << *first + *last << endl;
    return 0;
}

/* 练习3.41 */
int test_vector_10 (void) {
    int array[] = {0,1,2,3,4,5,6,7,8,9};
    vector<int> v(begin(array), end(array));        // end(array) = &array[10]，表示数组尾后一位的地址
    return 0;
}

/* 练习3.42 */
int test_vector_11 (void) {
    vector<int> v = {0,1,2,3,4,5,6,7,8,9};
    const size_t size = v.end() - v.begin();
    int array[size];
    auto beg = v.begin();
    for (auto index = v.begin() ; index != v.end() ; ++index)
        *(array + (index - beg)) = *index;
    return 0;
}

int main (void) {
#if DO_TEST_VECTOR_1
    test_vector_1();
#endif
#if DO_TEST_VECTOR_2
    test_vector_2();
#endif
#if DO_TEST_VECTOR_3
    test_vector_3();
#endif
#if DO_TEST_VECTOR_4
    test_vector_4();
#endif
#if DO_TEST_VECTOR_5
    test_vector_5();
#endif
#if DO_TEST_VECTOR_6
    test_vector_6();
#endif
#if DO_TEST_VECTOR_7
    test_vector_7();
#endif
#if DO_TEST_VECTOR_8
    test_vector_8();
#endif
#if DO_TEST_VECTOR_9
    test_vector_9();
#endif
#if DO_TEST_VECTOR_10
    test_vector_10();
#endif
#if DO_TEST_VECTOR_11
    test_vector_11();
#endif
#if DO_TEST_VECTOR_12
#endif
#if DO_TEST_VECTOR_13
#endif

    return 0;
}
