#include <vector>
#include <iostream>
#include <iterator>

using std::vector;
using std::cout;
using std::endl;

using F = int (int, int);   // 函数类型

inline int add (int x, int y) {
    return x + y;
}

inline int sub (int x, int y) {
    return x - y;
}

inline int mul (int x, int y) {
    return x * y;
}

inline int divide (int x, int y) {
    return x / y;
}

typedef decltype(add) *FP;

int main () {
    vector<FP> v = {add, sub, mul, divide};
    int x = 4, y = 2;
    for (auto index = v.begin() ; index != v.end() ; ++index)
        cout << (*index)(x, y) << endl;
    return 0;
}
