#ifndef _H_NONMODIFY_ALGORITHM
#define _H_NONMODIFY_ALGORITHM

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <ctime>
#include <cstdlib>
#include <memory>
#include <set>
#include <map>
#include <list>
#include <utility>

using namespace std;

template <typename T, typename T1> void print(T &t) {
    for_each(t.begin(), t.end(), [](T1 &x){ cout << x << " "; });
    cout << endl;
}

template <typename T, typename T1, typename C> T make_container(C c, T1 init) {
    srand(time(0));
    T t(c, init);
    return t;
}

#endif
