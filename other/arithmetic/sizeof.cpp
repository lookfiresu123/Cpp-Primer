#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using std::cout;
using std::cin;
using std::endl;

int main (void) {
    int x[10];
    int *p = x;
    cout << sizeof(x) / sizeof(*x) << endl;
    cout << sizeof(p) / sizeof(*p) << endl;
    return 0;
}
