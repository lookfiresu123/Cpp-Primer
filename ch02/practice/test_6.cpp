#include <iostream>

using namespace std;

int main (void) {
    int r = 0x11;
    const int *x = &r;
    r = 0x12;
    //*x = 0x13;
    return 0;
}
