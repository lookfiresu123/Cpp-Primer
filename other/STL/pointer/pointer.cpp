#include <iostream>
#include <iterator>     // 标准库函数begin()和end()函数所在的头文件
#include <cstddef>
#include <vector>
#include <string>

using namespace std;

#define DO_TEST_POINTER_1 0
#define DO_TEST_POINTER_2 0
#define DO_TEST_POINTER_3 1

// usage of begin() and end()
int test_pointer_1 (void) {
    int array[10] = {0,1,2,3,-1,4,5,6,7,8};     // 初始化为0
    auto first = begin(array);      // auto为指针类型，first表示array的第一个元素所在地址，即&array[0]
    auto last = end(array);         // auto为指针类型，last表示array的尾元素的下一个元素所在地址，即&array[10]
    while (first != last && *first >= 0)
        ++first;
    if (first == last)
        cout << "没有负数" << endl;
    else
        cout << "第一个负数为：" << *first << endl;
    return 0;
}

int test_pointer_2 (void) {
    const size_t size = 10;
    int array[size];
    for (auto pointer = begin(array) ; pointer != end(array) ; ++pointer)
        *pointer = 0;
    return 0;
}

int test_pointer_3 (void) {
    const size_t size1 = 10;
    const size_t size2 = 10;
    int array1[size1] = {0,1,2,3,4,5,6,0,0,0};
    int array2[size2] = {0,1,2,3,4,5,6};
    vector<string> v1(size1, "hello");
    vector<string> v2 = {size1, "hello"};

    // compare betwwen array1 and array2
    if (end(array1) - begin(array1) == end(array2) - begin(array2)) {
        for (auto pointer1 = begin(array1), pointer2 = begin(array2) ; pointer1 != end(array1) ; ++pointer1, ++pointer2) {
            if (*pointer1 != *pointer2) {
                cout << "array1 is different from array2" << endl;
                return 0;
            }
        }
        cout << "array1 is same with array2" << endl;
    } else
        cout << "array1 is different from array2" << endl;

    // compare between v1 and v2
    if (v1.size() == v2.size()) {
        for (auto pointer1 = v1.begin(), pointer2 = v2.begin() ; pointer1 != v1.end() ; ++pointer1, ++pointer2) {
            if (*pointer1 != *pointer2) {
                cout << "v1 is different from v2" << endl;
                return 0;
            }
        }
        cout << "v1 is same with v2" << endl;
    } else
        cout << "v1 is different from v2" << endl;

    return 0;
}

int main (void) {
#if DO_TEST_POINTER_1
    test_pointer_1();
#endif
#if DO_TEST_POINTER_2
    test_pointer_2();
#endif
#if DO_TEST_POINTER_3
    test_pointer_3();
#endif

    return 0;
}
