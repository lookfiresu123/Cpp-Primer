#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define DO_TEST_IF_ELSE_1 0
#define DO_TEST_IF_ELSE_2 0
#define DO_TEST_IF_ELSE_3 1
#define DO_TEST_IF_ELSE_4 0
#define DO_TEST_IF_ELSE_5 0

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



    return 0;
}
