#ifndef _H_STRBLOB
#define _H_STRBLOB 1

#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class StrBlob {
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // 添加或删除元素
    void push_back(const string &t) { data->push_back(t); }
    void push_back(const string &t) const { data->push_back(t); }
    void pop_back();
    void pop_back() const;
    // 元素访问
    string &front();
    string &front() const;
    string &back();
    string &back() const;
private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const;
};

#endif
