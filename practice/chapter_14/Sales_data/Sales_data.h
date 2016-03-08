#ifndef _SALES_DATA_H
#define _SALES_DATA_H 1

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

class Sales_data {
    friend ostream &operator<<(ostream &os, const Sales_data &item);
    friend istream &operator>>(istream &is, Sales_data &item);
    friend Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);     // 重载加法运算符
    friend bool operator==(const Sales_data &lhs, const Sales_data &rhs);
    friend bool operator!=(const Sales_data &lhs, const Sales_data &rhs);

private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    inline double avg_price () const { return static_cast<double> (units_sold != 0 ? revenue / units_sold : 0); }

public:
    Sales_data() = default;        // 默认合成的构造函数
    explicit Sales_data(const string &s) : bookNo(s) {}
    Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p*n) {}
    Sales_data(const Sales_data &item) : bookNo(item.bookNo), units_sold(item.units_sold), revenue(item.revenue) {}   // 自己版本的拷贝构造函数
    string isbn() const { return bookNo; }
    Sales_data &operator+=(const Sales_data &);
    Sales_data &operator=(const Sales_data &);
    operator string() const { return bookNo; }
    operator double() const { return units_sold; }

};
void Reset_Istream (istream &is);

ostream &operator<<(ostream &os, const Sales_data &item);   // 重载输出运算符
istream &operator>>(istream &is, Sales_data &item);     // 重载输入运算符
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs);     // 重载加法运算符
bool operator==(const Sales_data &lhs, const Sales_data &rhs);
bool operator!=(const Sales_data &lhs, const Sales_data &rhs);

#endif
