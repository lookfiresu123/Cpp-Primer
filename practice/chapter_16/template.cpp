#include <iostream>

using namespace std;

template <typename T>
bool compare(const T &v1, const T &v2) {
    if (v1 >= v2)
        return true;
    else
        return false;
}

template <typename T1, typename T2>
void print(const T1 &v1, const T2 &v2) {
    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;
}

int main() {
    print("chensu", 24);
    print("go", 15.0);
    print(1.1, 1.1);
    return 0;
}


