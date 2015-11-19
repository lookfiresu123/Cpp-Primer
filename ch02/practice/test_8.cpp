/* test for auto type */
#include <iostream>

using namespace std;

auto divide (auto x, auto y) {
    auto z = x / y;
    return z;
}

int main (void) {
    auto x = 3.0;
    auto y = 2;
    auto result = divide(x, y);     // result的类型和x一样
    return 0;
}
