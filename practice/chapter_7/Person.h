#ifndef _PERSON_H
#define _PERSON_H 1

#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;        // 姓名
    string address;     // 住址
public:
    Person () = default;
    Person (const string &init_name) : name(init_name) {  }
    Person (const std::string &init_name, const std::string &init_address) {
        name = init_name;
        address = init_address;
    }
    ~Person() {  }
    void Set_Name (const string &new_name);
    void Set_Address (const string &new_address);
    const string &Get_Name () const;  // 获得对象的姓名
    const string &Get_Address () const;   // 获得对象的住址
};

istream &read (istream &is, Person &person);
ostream &print (ostream &os, const Person &person);

#endif
