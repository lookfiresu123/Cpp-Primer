#include <iostream>

using namespace std;

int main (void) {
    int r = 0x11;
    const int *const p = &r;
    constexpr int *q = p;
    return 0;
}
