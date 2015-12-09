#ifndef _SALES_DATA_H
#define _SALES_DATA_H 1

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    std::string isbn() const {
        return bookNo;
    }
    Sales_data &combine(const Sales_data &rhs) {
        units_sold += rhs.units_sold;
        revenue += rhs.revenue;
        return *this;
    }
};

istream &read (istream &is, Sales_data &item);      // IO类不能拷贝，必须用引用
ostream &print (ostream &os, const Sales_data &item);
Sales_data add (const Sales_data &lhs, const Sales_data &rhs);
void Reset_Istream (istream &is);

#endif
