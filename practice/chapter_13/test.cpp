#include "test.h"

void fcn(const Test *p1, Test p2) {
    Test t1(*p1), t2(p2);
}

int main() {
    Test p1, p2;
    fcn(&p1, p2);
    return 0;
}
