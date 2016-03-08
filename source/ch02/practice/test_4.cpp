#include <iostream>

using namespace std;

int main (void) {
    int i = 0x10;
    int &r = i;
    int &x = i;
    x = 0x11;
    cout << "r = " << r << ", x = " << x << endl;
    return 0;
}
