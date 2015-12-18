#ifndef _EXAMPLE_H
#define _EXAMPLE_H 1

#include <vector>

class Example {
public:
    static constexpr double rate = 6.5;
    static const int vecSize = 20;
    static std::vector<double> vec(4, 1);  // 错误，expected identifier before numeric constant
    static std::vector<double> vecother;    // 正确
};

static std::vector<double> v(4);        // 正确

#endif
