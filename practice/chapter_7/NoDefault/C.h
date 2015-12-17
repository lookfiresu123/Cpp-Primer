#ifndef _C_H
#define _C_H 1

#include "NoDefault.h"
#include <vector>

class C {       // 使用了值初始化，因此是默认构造函数
public:
    C () : obj(0) { }       // 等价于调用构造函数 NoDefault::NoDefault(0);
private:
    NoDefault obj;
    //std::vector<C> vec;
};

#endif
