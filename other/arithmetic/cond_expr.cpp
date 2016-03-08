#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::iterator;

#define DO_TEST_CONDEXPR_1 0
#define DO_TEST_CONDEXPR_2 1
#define DO_TEST_CONDEXPR_3 0

/* 练习4.21 */
int test_condexpr_1 (void) {
    vector<int> v = {0,1,2,3,4,5,6,7,8,9};
    for (auto index = v.begin() ; index != v.end() ; ++index)
        *index = (*index % 2 == 0 ? *index : *index * 2);
    return 0;
}

/* 练习4.22 */
int test_condexpr_2 (void) {
    unsigned grade;
    cin >> grade;
    auto finalgrade = ( grade > 90 ? "high pass" :
                        grade > 75 ? "pass" :
                        grade >= 60 ? "low pass" : "fail");      // 右结合
    cout << finalgrade << endl;
    cin >> grade;
    if (grade > 90)
        finalgrade = "high pass";
    else if (grade > 75)
        finalgrade = "pass";
    else if (grade >= 60)
        finalgrade = "low pass";
    else
        finalgrade = "fail";
    cout << finalgrade << endl;
    return 0;
}

/* 练习4.23 */
int test_condexpr_3 (void) {
    string s = "word";
    string p1 = s + (s[s.size() - 1] == 's' ? "" : "s");
    return 0;
}

int main (void) {
#if DO_TEST_CONDEXPR_1
    test_condexpr_1();
#endif
#if DO_TEST_CONDEXPR_2
    test_condexpr_2();
#endif
#if DO_TEST_CONDEXPR_3
    test_condexpr_3();
#endif

    return 0;
}
