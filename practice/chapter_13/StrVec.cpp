#include "StrVec.h"

allocator<string> StrVec::alloc;

pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e) {
    // 分配空间保存给定范围中的元素
    auto data = alloc.allocate(e - b);
    // 初始化并返回一个pair，该pair由data和uninitialized_copy的返回值构成
    return make_pair(data, uninitialized_copy(b, e, data));
}

void StrVec::free() {
    // 不能传递给deallocate一个空指针——即如果elements为nullptr，则函数什么也不做
    if (elements) {
        // 逆序销毁旧元素
        for (auto p = first_free ; p != elements ; --p)
            alloc.destroy(p);
        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::free(string *begin, string *end) {
    for (auto ptr = begin ; ptr <= end ; ++ptr)
        alloc.destroy(ptr);
    if (begin == elements && end == first_free)
        alloc.deallocate(elements, cap - elements);
}

void StrVec::push_back(const string &s) {
    chk_n_alloc();  // 确保有空间容纳新元素
    alloc.construct(++first_free, s);   // 在first_free指向的元素中构造的s的副本
}

StrVec::StrVec(const StrVec &s) {
    // 调用alloc_n_copy分配空间以容纳与s中一样多的元素
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec() {
    free();
}

StrVec &StrVec::operator=(const StrVec &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    // 分配新内存
    auto newdata = alloc.allocate(newcapacity);
    // 将数据从旧内存移入新内存
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0 ; i != size() ; ++i)
        alloc.construct(dest++, move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

void StrVec::reallocate(size_t count) {
    size_t newcapacity;
    for (newcapacity = 1 ; newcapacity <= count ; newcapacity *= 2)
        ;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0 ; i != size() ; ++i)
        alloc.construct(dest++, move(*elem++));
    free();
    elements = newdata;
    first_free = elements + count;
    for (auto ptr = dest ; ptr <= first_free ; ++ptr)
        push_back("");
    cap = elements + newcapacity;
}

void StrVec::swap(string *p, string *q) {
    string temp = *p;
    *p = *q;
    *q = temp;
}

StrVec &StrVec::reserve() {
     for (auto begin = elements, end = first_free ; begin <= end ; ++begin, --end)
         swap(begin, end);
     return *this;
}



StrVec &StrVec::resize(size_t count) {
    if (count >= capacity())
        reallocate(count);
    else if (count >= size()) {
        for (auto p = first_free ; p < elements + count ; ++p)
            push_back("");
    } else
        free(elements + count, first_free);
    return *this;
}


int main() {
    StrVec sv;
    return 0;
}
