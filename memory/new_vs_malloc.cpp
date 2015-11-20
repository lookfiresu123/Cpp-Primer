#include <iostream>
#include <cstdlib>

using namespace std;

class Student {
public:
    int stdnum;
    Student () {
        cout << "call constructor" << endl;
        stdnum = 111;
    }
    ~Student () {
        cout << "call destructor" << endl;
    }
};

int main () {
    //Student *student1 = new Student;      // allocate size bytes of initialized storage by call constructor
    Student *student1 = static_cast<Student *>(malloc(sizeof(Student)));        // allocate size bytes of uninitialized storage
    return 0;
}
