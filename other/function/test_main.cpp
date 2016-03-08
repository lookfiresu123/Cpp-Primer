#include <iostream>
#include <string>

using namespace std;

/* 练习6.25 */
int main (int argc, char *argv[]) {
    int i = 1;      // argv[0]为程序名
    string str, result;
    while (argv[i]) {
        str = argv[i];      // 将char *转为string类型
        result += str;
        i++;
    }
    cout << result << endl;
    return 0;
}
