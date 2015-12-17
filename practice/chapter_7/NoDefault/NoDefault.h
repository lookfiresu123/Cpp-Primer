#ifndef _NODEFAULT_H
#define _NODEFAULT_H 1

#include <iostream>

class NoDefault {
public:
    NoDefault(int _value) {     // 非值初始化或默认初始化，因此不是默认构造函数
        value = _value;
        std::cout << value << std::endl;
    }
private:
    int value;
};

#endif
