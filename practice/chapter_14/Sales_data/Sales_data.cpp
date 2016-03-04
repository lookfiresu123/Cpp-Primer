#include "Sales_data.h"

ostream &operator<<(ostream &os, const Sales_data &item) {
    os << item.bookNo << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}


istream &operator>>(istream &is, Sales_data &item) {
    is >> item.bookNo >> item.units_sold >> item.revenue;
    if (! is.good())
        item = Sales_data();
    Reset_Istream(is);
    return is;
}

void Reset_Istream (istream &is) {
    is.clear();
    is.sync();
}

Sales_data &Sales_data::operator+=(const Sales_data &lhs) {
    if (bookNo == lhs.bookNo) {
        units_sold += lhs.units_sold;
        revenue += lhs.revenue;
    }
    return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

bool operator==(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.bookNo == rhs.bookNo && lhs.units_sold == rhs.units_sold && lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs) {
    return !(lhs == rhs);
}

Sales_data &Sales_data::operator=(const Sales_data &rhs) {
    bookNo = rhs.bookNo;
    units_sold = rhs.units_sold;
    revenue = rhs.revenue;
    return *this;
}
