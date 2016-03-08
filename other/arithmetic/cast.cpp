#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main (void) {
    int a = 10;
    bool b = true;
    int c = a + b;      // b cast to int instead of a cast to bool
    cout << c << endl;
    return 0;
}
