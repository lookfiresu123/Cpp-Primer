#include <iostream>
#include <iterator>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

#define DO_TEST_WHILE_1 0
#define DO_TEST_WHILE_2 1

/* for while */

// 练习5.4
int test_while_1 (void) {
    string s = "hello world";
    string::iterator iter = s.begin();
    while (iter != s.end())
        cout << *iter++ << endl;
    return 0;
}

// 练习5.14
int test_while_2 (void) {
    string temp, max_string;
    string prev;  // 保持前一个string对象
    int max_occur = 0, cur_occur = 0;
    while (cin >> temp) {
        if (temp == prev)
            ++cur_occur;
        else {
            if (cur_occur > max_occur) {
                max_occur = cur_occur;
                max_string = prev;
            }
            cur_occur = 1;
        }
        prev = temp;
    }
    return 0;
}

int main (void) {
#if DO_TEST_WHILE_1
    test_while_1();
#endif
#if DO_TEST_WHILE_2
    test_while_2();
#endif

    return 0;
}
