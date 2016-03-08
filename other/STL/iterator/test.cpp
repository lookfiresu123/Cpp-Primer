#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

int main (void) {
    vector<int> v{0,1,2,3,4,5,6,7,8,9};
    auto b = v.begin();
    cout << *b << endl;
    while (b != v.end())
        ++b;
    auto c = v.end();
    return 0;
}
