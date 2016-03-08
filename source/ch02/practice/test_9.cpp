/* test for const reference */

#include <iostream>

using namespace std;

int main (void) {
    const int &r = 0x11;
    const int *p = &r;
    //*(p - 1) = 0x12;
    int *q = (int *)p;
    *q = 0x12;
    cout << "r = " << r << endl;
    return 0;
}
