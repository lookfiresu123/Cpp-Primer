#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cstdio>

class String {
public:
    typedef unsigned int size_type;
    String();
    String(const char *data);
    String(const String &t);
    String(String &&t);
    ~String();
    String &operator=(const String &t);
    size_type size();
    size_type length();
    String &push_back(const char &c);
    String &append(const String &t);
    void print() {
        printf("%s\n", data_);
    }
private:
    size_type capacity;
    size_type len;
    char *data_;
};

String::String() : capacity(1), len(0), data_(new char[capacity]) {
    data_[0] = '\0';
}

String::String(const char *data) : capacity(1) {
    if (data) {
        len = strlen(data);
        while (capacity <= len)
            capacity *= 2;
        data_ = new char[capacity];
        strcpy(data_, data);
    }
}

String::String(const String &t) : capacity(1), len(strlen(t.data_)) {
    while (capacity <= len)
        capacity *= 2;
    data_ = new char[capacity];
    strcpy(data_, t.data_);
}

String::String(String &&t) : capacity(1), len(strlen(t.data_)) {
    while (capacity <= len)
        capacity *= 2;
    data_ = new char[capacity];
    strcpy(data_, t.data_);
    t.~String();
}

String::~String() {
    delete[] data_;
    data_ = nullptr;
}

String &String::operator=(const String &t) {
    capacity = t.capacity;
    len = t.len;
    delete[] data_;
    data_ = new char[capacity];
    strcpy(data_, t.data_);
    return *this;
}

String::size_type String::size() {
    return len;
}

String::size_type String::length() {
    return len;
}

String &String::push_back(const char &c) {
    if (capacity == len + 1) {
        capacity *= 2;
        char *p = data_;
        // reallocate new array
        data_ = new char[capacity];
        strcpy(data_, p);
        // deallocate old array
        delete p;
    }
    ++len;
    // push back c
    data_[len-1] = c;
    data_[len] = '\0';
    return *this;
}

String &String::append(const String &t) {
    len += strlen(t.data_);
    while (capacity <= len)
         capacity *= 2;
    char *p = data_;
    // reallocate new array
    data_ = new char[capacity];
    strcpy(data_, p);
    // deallocate old array
    delete p;
    strcat(data_, t.data_);
    return *this;
}

int main() {
    String s("hello world!");
    s.append(" my name is chensu.");
    s.push_back('a');
    s.print();
    return 0;
}

