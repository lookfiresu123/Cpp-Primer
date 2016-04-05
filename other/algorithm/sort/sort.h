#ifndef _H_SORT
#define _H_SORT

#include <vector>
#include <algorithm>
#include <deque>
#include <list>
#include <iostream>
#include <map>
#include <set>
#include <memory>
#include <iterator>
#include <ctime>
#include <cstdlib>
#include <functional>

using namespace std;

#define TEST_SORT_1 0
#define TEST_PARTIAL_SORT_1 0
#define TEST_NTHELEMENT_SORT_1 0
#define TEST_MAKE_HEAP 0
#define TEST_PUSH_HEAP 0
#define TEST_POP_HEAP 0
#define TEST_SORT_HEAP 1

template <typename T, typename S> void print(T &t) {
    for_each(t.begin(), t.end(), [](S &x){ cout << x << " "; });
    cout << endl;
}

#endif
