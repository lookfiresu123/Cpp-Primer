#include <iostream>
#include <string>
#include <cassert>

using namespace std;

inline bool Compare (void) {
    return true;
}

constexpr bool isShorter(const string &s1, const string &s2) {
    return &s1 == &s2;
    // return s1.size() < s2.size();
    // return Compare();
}

int main (void) {
    // string s1 = "hello", s2 = "world";
    // isShorter(s1, s2);
    cout << sizeof(int) << ", " << sizeof(float) << ", "<< sizeof(double) << endl;
    return 0;
}
