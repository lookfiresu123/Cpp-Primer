#include <iostream>
#include <string>
#include "Sales_data.h"

#define DO_TEST_SALES_DATA_1 0
#define DO_TEST_SALES_DATA_2 0
#define DO_TEST_SALES_DATA_3 0
#define DO_TEST_SALES_DATA_4 1

void Reset_Istream (istream &is) {
    is.clear();
    is.sync();
}

/* 练习7.1 */
int test_sales_data_1 (void) {
    Sales_data total;       // 某种书的总销售记录
    if (std::cin >> total.bookNo >> total.units_sold >> total.revenue) {
        Sales_data trans;   // 下一本书的信息
        while (std::cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
            if (total.bookNo == trans.bookNo) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            } else {
                // 打印前种本书的信息
                std::cout << total.bookNo << total.units_sold << total.revenue << std::endl;
                total = trans;
            }
        }
        std::cout << total.bookNo << total.units_sold << total.revenue << std::endl;
    } else {
        // 没有输入，警告读者
        std::cerr << "No data?!"<< std::endl;
        return -1;      // 表示失败
    }
    return 0;
}

/* 练习7.3 */
int test_sales_data_2 (void) {
    Sales_data total;
    if (std::cin >> total.bookNo >> total.units_sold >> total.revenue) {
        Sales_data trans;
        while (std::cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                std::cout << total.bookNo << total.units_sold << total.revenue << std::endl;
                total = trans;
            }
        }
        std::cout << total.bookNo << total.units_sold << total.revenue << std::endl;
    } else {
        std::cerr << "No data?!" << std::endl;
    }
    return 0;
}

istream &read (istream &is, Sales_data &item) {
    double price = 0;   // 某种书的单价
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}

ostream &print (ostream &os, const Sales_data &item) {
    os << item.bookNo << " " << item.units_sold << " " << item.revenue;
    return os;
}

Sales_data add (const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

/* 练习7.6 */
int test_sales_data_3 (void) {
    Sales_data item1, item2;
    read(cin, item1);
    read(cin, item2);
    Sales_data sum = add(item1, item2);
    print(cout, sum);
    cout << endl;
    return 0;
}

/* 练习7.7 */
int test_sales_data_4 (void) {
    Sales_data total;
    if (read(cin, total)) {
        Sales_data trans;
        while (read(cin, trans)) {      // 知道读到某个数，使得istream中的iostate不为goodbit
            if (total.isbn() == trans.isbn())
                total = add(total, trans);
            else {
                print(cout, total);
                cout << endl;
                total = trans;
            }
            Reset_Istream(cin);
        }
        print(cout, total);
        cout << endl;
    } else
        cerr << "No data?!" << endl;
    return 0;
}

int main (void) {
#if DO_TEST_SALES_DATA_1
    test_sales_data_1();
#endif
#if DO_TEST_SALES_DATA_2
    test_sales_data_2();
#endif
#if DO_TEST_SALES_DATA_3
    test_sales_data_3();
#endif
#if DO_TEST_SALES_DATA_4
    test_sales_data_4();
#endif

    return 0;
}
