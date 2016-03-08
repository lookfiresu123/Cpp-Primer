#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define DO_TEST_IF_ELSE_1 0
#define DO_TEST_IF_ELSE_2 0
#define DO_TEST_IF_ELSE_3 0
#define DO_TEST_IF_ELSE_4 0
#define DO_TEST_IF_ELSE_5 0
#define DO_TEST_IF_ELSE_6 0
#define DO_TEST_IF_ELSE_7 0
#define DO_TEST_IF_ELSE_8 0
#define DO_TEST_IF_ELSE_9 1

int test_if_else_1 (void) {
    int grade = 10;
    if (grade < 10)
        cout << "grade is smaller than 10" << endl;
    // cout << "jump over if" << endl;
    else if (grade == 0)        // else if必须紧跟着if块（作用域）
        cout << "grade is equal to 10" << endl;
    // cout << "jump over else if" << endl;
    else                        // else必须紧跟着if块或else if块
        cout << "grade is larger than 10" << endl;
    return 0;
}

/* 练习5.5 */
int test_if_else_2 (void) {
    const vector<string> scores = {"F","D","C","B","A","A++"};
    unsigned grade;
    string grade_str;
    cin >> grade;
    if (grade < 60)
        grade_str = "F";
    else if (grade >= 60 && grade < 70)
        grade_str = "D";
    else if (grade >= 70 && grade < 80)
        grade_str = "C";
    else if (grade >= 80 && grade < 90)
        grade_str = "B";
    else if (grade >= 90 && grade < 100)
        grade_str = "A";
    else
        grade_str = "A++";
    cout << grade_str << endl;
    return 0;
}

/* 练习5.6 */
int test_if_else_3 (void) {
    const vector<string> scores = {"F","D","C","B","A","A++"};
    unsigned grade;
    string grade_str;
    cin >> grade;
    grade_str = (   grade < 60 ? "F" :
                    grade >= 60 && grade < 70 ? "D" :
                    grade >= 70 && grade < 80 ? "C" :
                    grade >= 80 && grade < 90 ? "B" :
                    grade >= 90 && grade < 100 ? "A" : "A++");
    cout << grade_str << endl;
    return 0;
}

int test_if_else_4 (void) {
    int ch = 'a';
    int cnt1 = 0, cnt2 = 0;
    switch (ch) {
        case 'a':
        case 'b':
        case 'c':
            ++cnt1;
            break;
        case 'd':
        case 'e':
        case 'f':
            ++cnt2;
            break;
    }
    return 0;
}

/* 练习5.9 */
int test_if_else_5 (void) {
    char ch;
    int vowelcnt = 0, othercnt = 0;
    while (cin >> ch) {
        switch (ch) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                ++vowelcnt;
                break;
            default:
                ++othercnt;
                break;
        }
    }
    cout << "there are "<< vowelcnt << " vowel letter" << endl;
    return 0;
}

/* 练习5.10 */
int test_if_else_6 (void) {
    char ch;
    int vowelcnt = 0, othercnt = 0;
    while (cin >> ch) {
        switch (ch) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                ++vowelcnt;
                break;
            default:
                ++othercnt;
                break;
        }
    }
    cout << "there are "<< vowelcnt << " vowel letter" << endl;
    return 0;
}

/* 练习5.11 */
int test_if_else_7 (void) {
    char ch;
    int vowelcnt = 0, spacecnt = 0, tabcnt = 0, newlinecnt = 0;
    int othercnt = 0;
    while (cin >> ch) {
        switch (ch) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                ++vowelcnt;
                break;
            case ' ':
                ++spacecnt;
                break;
            case '\t':
                ++tabcnt;
                break;
            case '\n':
                ++newlinecnt;
                break;
            default:
                ++othercnt;
                break;
        }
    }
    return 0;
}

/* 练习5.12 */
int test_if_else_8 (void) {
    char ch, prech = '\0';
    int ffcnt = 0, ficnt = 0, flcnt = 0;
    while (cin >> ch) {
        switch (ch) {
            case 'f':
                if (prech == 'f')
                    ++ffcnt;
                break;
            case 'i':
                if (prech == 'f')
                    ++ficnt;
                break;
            case 'l':
                if (prech == 'f')
                    ++flcnt;
                break;
        }
        prech = ch;
    }
    cout << "ff = " << ffcnt << endl;
    cout << "fi = " << ficnt << endl;
    cout << "fl = " << flcnt << endl;
    return 0;
}

/* wrong example */
/* 要确保后面的所有case标签都在变量（改变量已被初始化）的作用域之外 */
int test_if_else_9 (void) {
    bool result = true;
    switch (result) {
        case true:
            int jval = 0;
            break;
        case false:
            jval = 1;       // 不能只注释掉这一部分，因为之后的修改有可能又把它加回去，到时候会出现意想不到的bug，因此为了
                            // 帮助开发者治根，必须在初始化的case中加上{}块语句。
            break;
    }
    return 0;
}

int main (void) {
#if DO_TEST_IF_ELSE_1
    test_if_else_1();
#endif
#if DO_TEST_IF_ELSE_2
    test_if_else_2();
#endif
#if DO_TEST_IF_ELSE_3
    test_if_else_3();
#endif
#if DO_TEST_IF_ELSE_4
    test_if_else_4();
#endif
#if DO_TEST_IF_ELSE_5
    test_if_else_5();
#endif
#if DO_TEST_IF_ELSE_6
    test_if_else_6();
#endif
#if DO_TEST_IF_ELSE_7
    test_if_else_7();
#endif
#if DO_TEST_IF_ELSE_8
    test_if_else_8();
#endif
#if DO_TEST_IF_ELSE_9
    test_if_else_9();
#endif
#if DO_TEST_IF_ELSE_10
    test_if_else_10();
#endif



    return 0;
}
