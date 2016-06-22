#include <iostream>

using namespace std;

static const char *file_name;
static int line_num;
static size_t global_size;

class Debug {
public:
    void *operator new(size_t size, const char *file, int line) {
        cout << "newed " << size << " bytes at file " << file << ", at line " << line << endl;
        global_size = size;
        return ::operator new(size);
    }
    void operator delete(void *p) {
        if (p) {
            cout << "deleted " << global_size << " bytes at file " << file_name << ", at line " << line_num << endl;
            ::operator delete(p);
        }
    }
};

void deletep(const char *file, int line) {
    file_name = file;
    line_num = line;
    return;
}

#define new new(__FILE__, __LINE__)
#define delete deletep(__FILE__, __LINE__), delete

int main() {
    Debug *debug = new Debug();
    delete debug;
    return 0;
}
