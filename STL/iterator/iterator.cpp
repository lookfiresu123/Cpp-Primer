#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cassert>

using namespace std;

#define DO_TEST_ITERATOR_1 0
#define DO_TEST_ITERATOR_2 0
#define DO_TEST_ITERATOR_3 1
#define DO_TEST_ITERATOR_4 0
#define DO_TEST_ITERATOR_5 0
#define DO_TEST_ITERATOR_6 0

void output (auto value) {
    cout << "size is : " << value.end() - value.begin() << endl;
    cout << "data is : ";
    for (auto index = value.begin() ; index != value.end() ; ++index)
        cout << *index << " ";
    cout << endl;
}

/* 练习3.21 */
int test_iterator_1 (void) {
    vector<int> v1;                 // 空
    vector<int> v2(10);             // 10个0
    vector<int> v3(10, 42);         // 10个42
    vector<int> v4{10};             // 1个10
    vector<int> v5{10, 42};         // 10， 42
    vector<string> v6{10};          // 10个空字符串
    vector<string> v7{10, "hi"};    // 10个"hi"

    output(v1);
    cout << " ------------ " << endl;
    output(v2);
    cout << " ------------ " << endl;
    output(v3);
    cout << " ------------ " << endl;
    output(v4);
    cout << " ------------ " << endl;
    output(v5);
    cout << " ------------ " << endl;
    output(v6);
    cout << " ------------ " << endl;
    output(v7);

    return 0;
}

/* 练习3.22 */
int test_iterator_2 (void) {
    vector<string> v;
    string str;
    for (auto i = 0 ; i < 3 ; ++i) {      // 共3段text
        getline(cin, str);
        v.push_back(str);
    }
    for (auto index = v.cbegin() ; index != v.cend() && ! index->empty() ; ++index) {
        if (index == v.cbegin()) {
            for (auto index_char = index->cbegin() ; index_char != index->cend() ; ++index_char)
                cout << static_cast<char>(toupper(*index_char));
            cout << " ";
        } else {
            for (auto index_char = index->cbegin() ; index_char != index->cend() ; ++index_char)
                cout << *index_char;
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}

/* 练习3.23 */
int test_iterator_3 (void) {
    vector<int> v;
    int temp;
    for (auto i = 0 ; i < 10 ; ++i) {
        assert(cin >> temp);
        v.push_back(temp);
    }
    for (auto index = v.begin() ; index != v.end() ; ++index) {
        *index *= 2;
        cout << *index << " ";
    }
    cout << endl;
    return 0;
}

int test_iterator_4 (void) {
    return 0;
}

int test_iterator_5 (void) {
    return 0;
}

int test_iterator_6 (void) {
    return 0;
}


int main (void) {
#if DO_TEST_ITERATOR_1
    test_iterator_1();
#endif
#if DO_TEST_ITERATOR_2
    test_iterator_2();
#endif
#if DO_TEST_ITERATOR_3
    test_iterator_3();
#endif
#if DO_TEST_ITERATOR_4
    test_iterator_4();
#endif
#if DO_TEST_ITERATOR_5
    test_iterator_5();
#endif
#if DO_TEST_ITERATOR_6
    test_iterator_6();
#endif

    return 0;
}
