#include "Sales_data.h"
#include "container.h"

#define TEST_OPERATOR_ADD 0
#define TEST_OPERATOR_POINTER 0
#define TEST_OPERATOR_DEREFERENCE 1

int test_operator_add(void) {
    Sales_data lhs, rhs;
    cin >> lhs >> rhs;
    cout << lhs + rhs << endl;
    return 0;
}

int test_operator_pointer(void) {
    C c;
    c->append("google");
    return 0;
}

int test_operator_dereference(void) {
    C c;
    C *cptr = &c;
    (*&(*&(*cptr).b).a).append("google");
    return 0;
}

int main() {
#if TEST_OPERATOR_ADD
    test_operator_add();
#endif
#if TEST_OPERATOR_POINTER
    test_operator_pointer();
#endif
#if TEST_OPERATOR_DEREFERENCE
    test_operator_dereference();
#endif
    return 0;
}
