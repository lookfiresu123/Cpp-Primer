#include <iostream>
#include <vector>
#include <string>

using namespace std;

int assignment_vector (void) {
    vector<int> src = {0,1,2,3,4,5,6,7,8,9};
    auto dst = src;     // dst会重新new一块内存出来，然后将src中的元素依次赋值到new出来的新内存中
                        // 也就是说&src和&dst中保存的值不同（指向的内存地址不同）
    return 0;
}

int assignment_string (void) {
    string src = "hello world";
    string dst = src;   // dst不会重新new一块内存出来，而是直接拷贝src本身的值到dst中
                        // 也就是说&src和&dst中保存的值相同（指向的内存地址相同）
    return 0;
}

int main (void) {
    //assignment_vector();
    assignment_string();
    return 0;
}
