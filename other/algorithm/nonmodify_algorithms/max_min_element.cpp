#include "nonmodify_algorithm.h"

#define TEST_MAX_1 0
#define TEST_MIN_1 0
#define TEST_MIN_MAX_1 1

int test_max_1() {
    auto vec = make_container<vector<int>, int, int>(10, 0);
    generate(vec.begin(), vec.end(), [](){ return rand()%100; });
    print<vector<int>, int>(vec);
    auto max_iter = max_element(vec.begin(), vec.end());
    cout << *max_iter << endl;
    return 0;
}

int test_min_1() {
    auto vec = make_container<vector<int>, int, int>(10, 0);
    generate(vec.begin(), vec.end(), [](){ return rand()%100; });
    print<vector<int>, int>(vec);
    auto min_iter = min_element(vec.begin(), vec.end());
    cout << *min_iter << endl;
    return 0;
}

int test_min_max_1() {
    auto vec = make_container<vector<int>, int, int>(10, 0);
    generate(vec.begin(), vec.end(), [](){ return rand()%100; });
    print<vector<int>, int>(vec);
    auto min_max = minmax_element(vec.begin(), vec.end());
    cout << "min = " << *min_max.first << ", max = " << *min_max.second << endl;
    return 0;
}



int main() {
#if TEST_MAX_1
    test_max_1();
#endif
#if TEST_MIN_1
    test_min_1();
#endif
#if TEST_MIN_MAX_1
    test_min_max_1();
#endif

    return 0;
}
