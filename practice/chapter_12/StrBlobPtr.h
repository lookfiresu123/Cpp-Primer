#ifndef _H_STRBLOBPTR
#define _H_STRBLOBPTR 1

#include <vector>
#include <memory>
#include <string>
#include "StrBlob.h"

using namespace std;

class StrBlobPtr {
public:
    friend class StrBlob;
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    string &deref() const;
    StrBlobPtr &incr(); // 前缀递增

private:
    // 若检查成功，check返回一个指向vector的shared_ptr
    shared_ptr<vector<string>> check(size_t, const string &) const;
    // 保存一个weak_ptr，意味着底层vector可能被销毁
    weak_ptr<vector<string>> wptr;
    size_t curr;    // 在数组中的当前位置
};

#endif
