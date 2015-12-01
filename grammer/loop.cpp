#include <iostream>
#include <iterator>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

#define DO_TEST_WHILE_1 1
#define DO_TEST_WHILE_2 0

/* for while */

// 练习5.4
int test_while_1 (void) {
    string s = "hello world";
    string::iterator iter = s.begin();
    while (iter != s.end())
        cout << *iter++ << endl;
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
