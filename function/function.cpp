#include <iostream>
#include <cmath>
#include <string>
#include <cctype>

#define DO_TEST_BASIC 0
#define DO_TEST_REFERENCE_PARAMETER 0
#define DO_TEST_REFERENCE_DECLARATION 0
#define DO_TEST_PRACTICE_1 0
#define DO_TEST_SELF_CHANGE 0
#define DO_TEST_ARRAY_AUTOCHANGE 0
#define DO_TEST_PRACTICE_2 0
#define DO_TEST_PRACTICE_3 1
#define DO_TEST_PRACTICE_4 0
#define DO_TEST_PRACTICE_5 0
#define DO_TEST_PRACTICE_6 0


using namespace std;

int fact (int n) {
    int result = 1;
    while (n > 0)
        result *= n--;
    return result;
}

int test_basic (void) {
    int n;
    cin >> n;
    int result = fact(n);
    cout << result << endl;
    cin.clear();
    cin.sync();
    cin >> n;
    result = abs(n);
    cout << result << endl;
    return result;
}

void reset (auto &r, auto default_value) {
    r = default_value;
}

/* 练习6.11 */
int test_reference_parameter (void) {
    string s = "hello world";
    decltype(s) x = "";
    reset(s, x);
    return 0;
}

/* 练习6.13 */
void FR (int &) {}

int test_reference_declaration (void) {
    int a = 1;
    // int const &r = a;       // &是r的修饰符，不属于类型，表示引用
    FR(a);
    return 0;
}

void fcn (const int i) {}       // 符号表中为"_Z3fcni"，被调用或传实参时会忽略掉顶层const，但在函数内部依然有效。

// void fcn (int i) {}     // error，redefination of 'void fcn (int)'

bool iscontain_upper (const string &s) {
    for (auto c : s)
        if (! isupper(c))
            return true;
    return false;
}

void tolower_string (string &s) {
    for (auto &c : s)
        c = tolower(c);
}

/* 练习6.17 */
int test_practice_1 (void) {
    string s;
    cin >> s;
    cin.clear();
    cin.sync();
    cout << (iscontain_upper(s) ? "true" : "false") << endl;
    cin >> s;
    tolower_string(s);
    cout << s << endl;
    return 0;
}

void change_const (const int &) {}      // 可以绑定临时对象（i++）
void change_variable (int &) {}         // 不可以绑定临时对象（i++）

int test_self_change (void) {
    int i = 0;
    change_const(i++);      // i++是临时对象
    change_variable(++i);   // ++i不是临时对象，在内存中就是i
    return 0;
}

void auto_change_pointer (int a[10]) {      // 形参数组a自动转换为&a[0]
    cout << sizeof(a) << endl;
}

void auto_change_reference (int (&a)[10]) {
    cout << sizeof(a) << endl;
}

int test_array_autochange (void) {
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    auto_change_pointer(a);
    auto_change_reference(a);
    return 0;
}

/* 练习6.21 */
int test_practice_2 (int a, int *b) {
    return (a >= *b ? a : *b);
}

/* 练习6.22 */
int test_practice_3 (int *&p, int *&q) {
    auto temp = p;
    p = q;
    q = temp;
    return 0;
}

int main (void) {
#if DO_TEST_BASIC
    test_basic();
#endif
#if DO_TEST_REFERENCE_PARAMETER
    test_reference_parameter();
#endif
#if DO_TEST_REFERENCE_DECLARATION
    test_reference_declaration();
#endif
#if DO_TEST_PRACTICE_1
    test_practice_1();
#endif
#if DO_TEST_SELF_CHANGE
    test_self_change();
#endif
#if DO_TEST_ARRAY_AUTOCHANGE
    test_array_autochange();
#endif
#if DO_TEST_PRACTICE_2
    int _b = 1;
    int *b = &_b;
    cout << test_practice_2(0, b) << endl;
#endif
#if DO_TEST_PRACTICE_3
    int a = 0, b = 1;
    int *p = &a, *q = &b;
    test_practice_3(p, q);
    cout << "*p = " << *p << " , *q = " << *q << endl;
#endif
#if DO_TEST_PRACTICE_4
    test_practice_4();
#endif
#if DO_TEST_PRACTICE_5
    test_practice_5();
#endif
#if DO_TEST_PRACTICE_6
    test_practice_6();
#endif

    return 0;
}
