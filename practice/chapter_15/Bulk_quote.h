#ifndef _H_BULK_QUOTE
#define _H_BULK_QUOTE

#include "Quote.h"

class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const string &, double, size_t, double);
    double net_price(size_t) const override { return 0; }
    void print_price() { cout << price << endl; };
private:
    size_t min_qty = 0;
    double discount = 0.0;
};

#endif
