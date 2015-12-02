#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

#define DO_TEST_WHILE_1 0
#define DO_TEST_WHILE_2 0
#define DO_TEST_WHILE_3 0
#define DO_TEST_WHILE_4 1

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

/* 练习5.17 */
bool test_while_3 (void) {
    vector<int> v1, v2;
    int temp;
    while (cin >> temp)     // 输入EOF后，只是将iostate置为failbit，而EOF还在cin流中
        v1.push_back(temp);
    // 清空cin缓冲区
    cin.clear();
    cin.sync();
    while (cin >> temp)     // 由于EOF还在cin流中，若不清空cin缓冲器，则直接退出循环（第一个读入的字符就是EOF）
        v2.push_back(temp);
    if (v1.size() < v2.size()) {
        for (auto index_v1 = v1.begin(), index_v2 = v2.begin() ; index_v1 != v1.end() ; ++index_v1, ++index_v2)
            if (*index_v1 != *index_v2)
                return false;
        return true;
    } else {
        for (auto index_v1 = v1.begin(), index_v2 = v2.begin() ; index_v2 != v2.end() ; ++index_v1, ++index_v2)
            if (*index_v1 != *index_v2)
                return false;
        return true;
    }
}

/* 练习5.19 */
int test_while_4 (void) {
    string s1, s2;
    do {
        cout << "enter two strings" << endl;
        cin >> s1 >> s2;
        cin.clear();
        cin.sync();
        cout << (s1.size() <= s2.size() ? s1 : s2) << endl;
    } while (1);
    return 0;
}

int main (void) {
#if DO_TEST_WHILE_1
    test_while_1();
#endif
#if DO_TEST_WHILE_2
    test_while_2();
#endif
#if DO_TEST_WHILE_3
    bool result = test_while_3();
#endif
#if DO_TEST_WHILE_4
    test_while_4();
#endif

    return 0;
}
