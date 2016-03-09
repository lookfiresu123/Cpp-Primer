#ifndef _H_QUOTE
#define _H_QUOTE 1

#include <string>
#include <iostream>

using namespace std;

class Quote {
public:
    Quote() = default;      // 默认构造函数
    // 直接构造函数
    Quote(const string &book, double sales_price) : bookNo(book), price(sales_price) {}
    string isbn() const { return bookNo; }  // 返回书籍的编号
    // 返回给定数量的书籍的销售总额
    // 派生类负责改写改写并使用不同的折扣计算算法
    virtual double net_price(size_t n) const { return n * price; }
    virtual ~Quote() = default; // 虚析构函数
private:
    string bookNo;
protected:
    double price = 0.0;
};

#endif
