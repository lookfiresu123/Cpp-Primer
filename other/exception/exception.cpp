#include <iostream>
#include <string>
#include <stdexcept>        // 处理异常的头文件
#include <ctime>
#include <cstdlib>

using namespace std;

#define DO_TEST_THROW_1 0
#define DO_TEST_TRY_CATCH_1 0
#define DO_TEST_EXCEPTION_1 0
#define DO_TEST_EXCEPTION_2 0
#define DO_TEST_EXCEPTION_3 1
#define DO_TEST_EXCEPTION_4 0

int test_throw_1 (void) {
    string s1 = "hello world";
    string s2 = "my name is chensu";
    if (s1 != s2)
        throw runtime_error("string is different");     //抛出异常，并把程序的控制权交给能处理该异常的代码（在这里时terminate库函数）
    // 没有设置try-catch语句，故程序将控制权交给terminate库函数以终止程序。
    cout << "string is the same" << endl;
    return 0;
}

int test_try_catch_1 (void) {
    string s1, s2;
    try {
        cin >> s1 >> s2;
        if (s1.size() > 15 || s2.size() >15)
            throw length_error("every string must not larger than 15");     // 抛出异常，并把程序的控制权交给第28行
        else if (s1.size() != s2.size())
            throw runtime_error("string si different");                     // 抛出异常，并把程序的控制权交给第30行
    } catch (length_error err) {
        cout << err.what() << "\nTry argin ? Enter y or n" << endl;
    } catch (runtime_error err) {
        cout << err.what() << "\nTry argin ? Enter y or n" << endl;
    }
    return 0;
}

int test_exception_1 (void) {
    int numerator, denominator, quotient;
    try {
        cin >> numerator >> denominator;
        if (denominator == 0)
            throw invalid_argument("the denominator can not be 0");
        else
            quotient = numerator / denominator;
    } catch (invalid_argument err) {
        cout << err.what() << endl;
    }
    return 0;
}

int test_exception_2 (void) {
    int numerator, denominator, quotient;
    try {
        cin >> numerator >> denominator;
        if (denominator == 0)
            throw invalid_argument("the denominator can not be 0");
        else
            quotient = numerator / denominator;
    } catch (runtime_error err) {       // 没有匹配的catch，程序将调用terminate库函数，终止程序
        cout << err.what() << endl;
    }
    return 0;
}

class Exception_1 {};       // 自定义异常类
class Exception_2 {};       // 自定义异常类
class Exception_3 {};       // 自定义异常类

int test_exception_3() {
    srand(time(0));
    int temp = rand() % 3;
    try {
        if (temp == 1)
            throw Exception_1();
        else if (temp == 2)
            throw Exception_2();
        else
            throw Exception_3();
    }
    catch(Exception_1) {
        cout << "exception 1" << endl;
    }
    catch(Exception_2) {
        cout << "exception 2" << endl;
    }
    catch(Exception_3) {
        cout << "exception 3" << endl;
    }
    return 0;
}

int main (void) {
#if DO_TEST_THROW_1
    test_throw_1();
#endif
#if DO_TEST_TRY_CATCH_1
    test_try_catch_1();
#endif
#if DO_TEST_EXCEPTION_1
    test_exception_1();
#endif
#if DO_TEST_EXCEPTION_2
    test_exception_2();
#endif
#if DO_TEST_EXCEPTION_3
    test_exception_3();
#endif

    return 0;
}
