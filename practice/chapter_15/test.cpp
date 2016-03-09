#include "Bulk_quote.h"

#define TEST_DESTRUCTOR_DYNAMIC_BIND 0
#define TEST_FUNCTION_DYNAMIC_BIND 0
#define TEST_ACCESS_CONTROL 1

int test_destructor_dynamic_bind() {
    Quote *ptr_quote = new Quote();     // 基类的构造函数
    Bulk_quote *ptr_bulk_quote = new Bulk_quote();  // 派生类的构造函数
    delete ptr_quote;
    delete ptr_bulk_quote;
    return 0;
}

int test_function_dynamic_bind() {
    // Quote quote1;     // 基类的构造函数
    Bulk_quote bulk_quote;  // 派生类的构造函数
    Quote &quote2 = bulk_quote;     // 引用
    // quote1.net_price(10);
    quote2.net_price(10);
    Quote *ptr_quote2 = new Bulk_quote();   // 指针
    ptr_quote2->net_price(10);
    delete ptr_quote2;
    return 0;
}

int test_access_control() {
    Quote q1;
    Bulk_quote q2;
    q2.isbn();
    q2.print_price();
    return 0;
}

int main() {
#if TEST_DESTRUCTOR_DYNAMIC_BIND
    test_destructor_dynamic_bind();
#endif
#if TEST_FUNCTION_DYNAMIC_BIND
    test_function_dynamic_bind();
#endif
#if TEST_ACCESS_CONTROL
    test_access_control();
#endif
    return 0;
}
