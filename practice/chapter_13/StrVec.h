#ifndef _H_STRVEC
#define _H_STRVEC

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <memory>
#include <utility>

using namespace std;


// 类vector类内存分配策略的简化实现
class StrVec {
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}   // 默认构造函数
    StrVec(const StrVec &);     // 拷贝构造函数
    StrVec &operator=(const StrVec &);      // 拷贝赋值运算
    ~StrVec();      // 析构函数
    void push_back(const string &);     // 插入元素
    size_t size() const { return first_free - elements; }    // 返回元素个数
    size_t capacity() const { return cap - elements; }   // 返回容量
    string *begin() const { return elements; }   // 返回首"迭代器"
    string *end() const { return first_free; }  // 返回尾后"迭代器"
    StrVec &reserve();      // 转置
    StrVec &resize(size_t count);   // 重新分配大小
    // ...
private:
    static allocator<string> alloc;     // 分配元素的分配器
    void chk_n_alloc() {        // 被添加元素的函数所使用
        if (size() == capacity())
            reallocate();
    }
    pair<string *, string *> alloc_n_copy(const string *, const string *);    // 工具函数
    void free();        // 销毁元素并释放内存
    void free(string *, string *);      // 释放两个指针间的对象
    void reallocate();  // 获得更多内存并拷贝已有元素
    void reallocate(size_t count);  // 获得更多内存并拷贝已有元素
    void swap(string *, string *);      // 交换两个string对象
    string *elements;    // 指向数组首元素的指针（对应vector的begin）
    string *first_free; // 指向数组第一个空闲元素的指针（对应vector的end）
    string *cap;        // 指向数组尾后位置的指针（对应vector的capability）
};

#endif
