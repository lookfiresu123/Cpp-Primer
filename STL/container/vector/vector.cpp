#include <vector>
#include <iostream>

using namespace std;

#define DO_TEST_VECTOR_1 0
#define DO_TEST_VECTOR_2 1
#define DO_TEST_VECTOR_3 0
#define DO_TEST_VECTOR_4 0
#define DO_TEST_VECTOR_5 0
#define DO_TEST_VECTOR_6 0
#define DO_TEST_VECTOR_7 0
#define DO_TEST_VECTOR_8 0
#define DO_TEST_VECTOR_9 0
#define DO_TEST_VECTOR_10 0
#define DO_TEST_VECTOR_11 0
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

int main (void) {
#if DO_TEST_VECTOR_1
    test_vector_1();
#endif
#if DO_TEST_VECTOR_2
    test_vector_2();
#endif
#if DO_TEST_VECTOR_3
#endif
#if DO_TEST_VECTOR_4
#endif
#if DO_TEST_VECTOR_5
#endif
#if DO_TEST_VECTOR_6
#endif
#if DO_TEST_VECTOR_7
#endif
#if DO_TEST_VECTOR_8
#endif
#if DO_TEST_VECTOR_9
#endif
#if DO_TEST_VECTOR_10
#endif
#if DO_TEST_VECTOR_11
#endif
#if DO_TEST_VECTOR_12
#endif
#if DO_TEST_VECTOR_13
#endif

    return 0;
}
