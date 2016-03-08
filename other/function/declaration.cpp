#include <iostream>

using namespace std;

typedef string::size_type sz;

string screen (sz ht, sz wid = 80, char backgrnd = ' ');

string screen (sz ht = 20, sz wid, char backgrnd) { return ""; }

int main (void) {
    screen(10, 1);
    return 0;
}
