#include <iostream>
#include <string>

using namespace std;

#define DO_TEST_BREAK_1 0
#define DO_TEST_CONTINUE_1 0
#define DO_TEST_CONTINUE_2 1

/* 练习5.20 */
int test_break_1 (void) {
    string current, previous;
    int flag = 0;   // flag为0表示没有连续重复的单词，flag为1表示有连续重复的单词
    while (cin >> current) {
        if (previous == current) {
            flag = 1;
            break;      // 跳出while循环
        }
        previous = current;
    }
    if (flag == 0)
        cout << "没有连续重复的单词" << endl;
    else
        cout << "连续重复的单词: " << current << endl;
    return 0;
}

int test_continue_1 (void) {
    string str = "hello world";
    int cnt = 0;
    for (auto c : str) {
        switch (c) {
            case ' ':
                continue;       // 跳回到第38行
            default:
                ++cnt;
        }
    }
    cout << cnt << endl;
    return 0;
}

/* 练习5.21 */
int test_continue_2 (void) {
    string current, previous;
    int flag = 0;   // flag为0表示没有连续重复且大写字母开头的单词，flag为1表示有连续重复且大写字母开头的单词
    while (cin >> current) {
        if (previous == current) {
            // 判断是否以大写开头
            if (isupper(*current.begin())) {
                flag = 1;
                break;
            } else
                continue;
        }
        previous = current;
    }
    if (flag == 0)
        cout << "没有连续重复且以大写字母开头的单词" << endl;
    else
        cout << "连续重复且以大写字母开头的单词: " << current << endl;
    return 0;
}



int main (void) {
#if DO_TEST_BREAK_1
    test_break_1();
#endif
#if DO_TEST_CONTINUE_1
    test_continue_1();
#endif
#if DO_TEST_CONTINUE_2
    test_continue_2();
#endif

    return 0;
}
