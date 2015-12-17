#include "C.h"

int main (void) {
    //std::vector<NoDefault> vec(10);       // NoDefault没有默认构造函数
    std::vector<C> vec(10);                 // C有默认构造函数
    return 0;
}
