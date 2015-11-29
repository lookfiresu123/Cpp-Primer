#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <cstddef>

using namespace std;

#define DO_TEST_ARRAY_1 0
#define DO_TEST_ARRAY_2 0
#define DO_TEST_ARRAY_3 0
#define DO_TEST_ARRAY_4 1

int test_array_1 (void) {
    /*
    int array1[] = {0,1,2};
    int array2[3] = {0,1,2};
    int array3[] = {0,1};
    int array4[10] = {0,1};
    string array5[] = {"hello","world"};
    string array6[10] = {"hello","world"};
    char array7[] = "c++";      // sizeof(a) = 4，包括'\0'
    // 注： char array[len] = "..."; 此时，len至少为strlen()+1
    */
    return 0;
}

/* 练习3.28 */
string sa[10];
int ia[10];
int test_array_2 (void) {
    string sa2[10];
    int ia2[10];
    return 0;
}

int test_array_3 (void) {
    char score[10] = "hello";       // score = "hello\000\000\000\000"
    for (auto c : score)
        cout << c << " ";
    cout << endl;
    return 0;
}

int test_array_4 (void) {
    const size_t size = 10;
    int array[size] = {};   // 初始化为0
    for (auto index = 0 ; index < size ; ++index)
        array[index] = index;
    int array_another[size] = {};
    for (auto index = 0 ; index < size ; ++index)
        array_another[index] = array[index];
    vector<int> v;
    for (auto temp : array)
        v.push_back(temp);
    return 0;
}


int main (void) {
#if DO_TEST_ARRAY_1
    test_array_1();
#endif
#if DO_TEST_ARRAY_2
    test_array_2();
#endif
#if DO_TEST_ARRAY_3
    test_array_3();
#endif
#if DO_TEST_ARRAY_4
    test_array_4();
#endif

    return 0;
}
