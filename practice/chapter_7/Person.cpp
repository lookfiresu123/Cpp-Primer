#include "Person.h"

#define DO_TEST_PERSON_1 0
#define DO_TEST_PERSON_2 1

const string &Person::Get_Name () const {
    return name;
}

const string &Person::Get_Address () const {
    return address;
}

void Person::Set_Name (const string &new_name) {
    name = new_name;
}

void Person::Set_Address (const string &new_address) {
    address = new_address;
}

istream &read (istream &is, Person &person) {
    string new_name, new_address;
    cout << "input for new name" << endl;
    getline(is, new_name);
    cout << "input for new address" << endl;
    getline(is, new_address);
    person.Set_Name(new_name);
    person.Set_Address(new_address);
    return is;
}

ostream &print (ostream &os, const Person &person) {
    string person_name, person_address;
    person_name = person.Get_Name();
    person_address = person.Get_Address();
    os << person_name << endl;
    os << person_address << endl;
    return os;
}

int test_person_1 (void) {
    Person person1, person2;
    string person1_name = person1.Get_Name();
    string person2_name = person2.Get_Name();
    string person1_address = person1.Get_Address();
    string person2_address = person2.Get_Address();
    cout << person1_name << endl;
    cout << person1_address << endl;
    cout << person2_name << endl;
    cout << person2_address << endl;
    return 0;
}

/* 练习7.9 */
int test_person_2 (void) {
    Person person1;
    read(cin, person1);
    print(cout, person1);
    return 0;
}

int main (void) {
#if DO_TEST_PERSON_1
    test_person_1();
#endif
#if DO_TEST_PERSON_2
    test_person_2();
#endif

    return 0;
}
