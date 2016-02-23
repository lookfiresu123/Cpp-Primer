#include "StrBlob.h"

StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type i, const string &msg) const {
    if (i >= data->size())
        throw out_of_range(msg);
}

string &StrBlob::front() {
    // 如果vector为空，check会抛出一个异常
    check(0, "front on empty StrBlob");
    return data->front();
}

string &StrBlob::front() const {
    // 如果vector为空，check会抛出一个异常
    check(0, "front on empty StrBlob");
    return data->front();
}

string &StrBlob::back() {
     // 如果vector为空，check会抛出一个异常
    check(0, "back on empty StrBlob");
    return data->back();
}

string &StrBlob::back() const {
     // 如果vector为空，check会抛出一个异常
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back() {
     // 如果vector为空，check会抛出一个异常
    check(0, "back on empty StrBlob");
    return data->pop_back();
}

void StrBlob::pop_back() const {
     // 如果vector为空，check会抛出一个异常
    check(0, "back on empty StrBlob");
    return data->pop_back();
}
