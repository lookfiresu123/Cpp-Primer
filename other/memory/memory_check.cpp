#include <iostream>

using namespace std;

class Memory {
public:
    Memory(const string &_name) : name(_name) {
        cout << "construct : " << "Class = Memory" << ", Object = " << name << ";" << endl;
    }
    ~Memory() noexcept {
        cout << "destroy : " << "Class = Memory" << ", Object = " << name << "; " << endl;
    }
    void *operator new(size_t size, const string &file = __FILE__, const size_t line = __LINE__) {
        cout << "allocate " << size << " bytes, " << "file = " << file << ", line = " << line << "; ";
        if (size == 0) {
            cout << "size for malloc can not be zero" << "; ";
        }
        return malloc(size);
    }
    static void myDelete(void *p) {
        free(p);
    }

    void operator delete(void *p) {
        if (!p)
            cout << "p can not be nullptr" << endl;
        else {
            myDelete(p);
        }
    }

private:
    string name;
};

#define new new(__FILE__, __LINE__)

int main() {
    Memory *object1_ptr = new Memory("object1");
    delete object1_ptr;
    return 0;
}
