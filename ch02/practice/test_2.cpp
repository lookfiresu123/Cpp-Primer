/* some test of reference */
#include <iostream>

using namespace std;

int main (void) {
    int a = 10;
    int b = 9;
    int &r = a;
    cout << " r = " << r << ", a = " << a << endl;
    r = b;
    //&r = b;
    cout << " r = " << r << ", b = " << a << endl;
    //int &s = 10;      // invalid
    const int &s = 10;      //valid
    return 0;
}
