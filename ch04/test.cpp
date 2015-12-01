#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main (void) {
    vector<string> v = {""};
    auto iter = v.begin();
    auto i = iter++->empty();
    cout << i << endl;
    return 0;
}
