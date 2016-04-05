#include "sort.h"

int test_sort_1() {
    srand(time(0));
    vector<int> vec(10, 0);
    for_each(vec.begin(), vec.end(), [](int &x){ x = rand() % 100; });
    print<vector<int>, int>(vec);
    sort(vec.begin(), vec.end());   // 从小到大排序
    print<vector<int>, int>(vec);
    sort(vec.begin(), vec.end(), greater<int>());   // 从大到小排序，其中greater<T>()的函数原型在functional头文件中
    print<vector<int>, int>(vec);
    return 0;
}

int test_partial_sort_1() {
    srand(time(0));
    vector<int> vec(10, 0);
    generate(vec.begin(), vec.end(), [](){ return rand()%100; });
    print<vector<int>, int>(vec);
    partial_sort(vec.begin(), vec.begin()+5, vec.end());
    print<vector<int>, int>(vec);
    partial_sort(vec.begin(), vec.begin()+5, vec.end(), greater<int>());
    print<vector<int>, int>(vec);
    return 0;
}

int test_nthelement_sort_1() {
    srand(time(0));
    vector<int> vec(10, 0);
    generate(vec.begin(), vec.end(), [](){ return rand()%100; });
    print<vector<int>, int>(vec);
    nth_element(vec.begin(), vec.begin()+3, vec.end());
    print<vector<int>, int>(vec);
    nth_element(vec.begin(), vec.begin()+3, vec.end(), greater<int>());
    print<vector<int>, int>(vec);
    return 0;
}

int test_make_heap() {
    vector<int> vec(10, 0);
    srand(time(0));
    generate(vec.begin(), vec.end(), [](){ return rand()%100; });
    print<vector<int>, int>(vec);
    make_heap(vec.begin(), vec.end());
    print<vector<int>, int>(vec);
    make_heap(vec.begin(), vec.end(), greater<int>());
    print<vector<int>, int>(vec);
    return 0;
}

int test_push_heap() {
    vector<int> vec(10, 0);
    srand(time(0));
    generate(vec.begin(), vec.end(), [](){ return rand()%100; });
    print<vector<int>, int>(vec);
    cout << "创建并插入最大堆" << endl;
    make_heap(vec.begin(), vec.end()-1);
    print<vector<int>, int>(vec);
    push_heap(vec.begin(), vec.end());
    print<vector<int>, int>(vec);
    cout << "创建并插入最小堆" << endl;
    make_heap(vec.begin(), vec.end()-1, greater<int>());
    print<vector<int>, int>(vec);
    push_heap(vec.begin(), vec.end(), greater<int>());
    print<vector<int>, int>(vec);
    return 0;
}

int test_pop_heap() {
    vector<int> vec(10, 0);
    srand(time(0));
    generate(vec.begin(), vec.end(), [](){ return rand()%100; });
    print<vector<int>, int>(vec);
    cout << "创建并删除最大堆" << endl;
    make_heap(vec.begin(), vec.end());
    print<vector<int>, int>(vec);
    pop_heap(vec.begin(), vec.end());
    print<vector<int>, int>(vec);
    cout << "创建并删除最小堆" << endl;
    make_heap(vec.begin(), vec.end(), greater<int>());
    print<vector<int>, int>(vec);
    pop_heap(vec.begin(), vec.end(), greater<int>());
    print<vector<int>, int>(vec);
    return 0;
}

int test_sort_heap() {
    vector<int> vec(10, 0);
    srand(time(0));
    generate(vec.begin(), vec.end(), [](){ return rand()%100; });
    print<vector<int>, int>(vec);
    cout << "创建最大堆并从小到大排序" << endl;
    make_heap(vec.begin(), vec.end());
    print<vector<int>, int>(vec);
    sort_heap(vec.begin(), vec.end());
    print<vector<int>, int>(vec);
    cout << "创建最小堆并从大到小排序" << endl;
    make_heap(vec.begin(), vec.end(), greater<int>());
    print<vector<int>, int>(vec);
    sort_heap(vec.begin(), vec.end(), greater<int>());
    print<vector<int>, int>(vec);
    return 0;
}



int main() {
#if TEST_SORT_1
    test_sort_1();
#endif
#if TEST_PARTIAL_SORT_1
    test_partial_sort_1();
#endif
#if TEST_NTHELEMENT_SORT_1
    test_nthelement_sort_1();
#endif
#if TEST_MAKE_HEAP
    test_make_heap();
#endif
#if TEST_PUSH_HEAP
    test_push_heap();
#endif
#if TEST_POP_HEAP
    test_pop_heap();
#endif
#if TEST_SORT_HEAP
    test_sort_heap();
#endif

    return 0;
}
