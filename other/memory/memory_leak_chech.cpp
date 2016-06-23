#include <iostream>
#include <map>
#include <string>

using namespace std;

// 动态分配的内存信息
struct Mem_Node {
    const string file_;
    int line_;
    size_t size_;
    Mem_Node(const char *file, int line, size_t size) : file_(file), line_(line), size_(size) {  }
};

static map<void *, Mem_Node> memory_pool;   // 内存池

static const char *file_name;
static int line_num;
static size_t global_size;

class Debug {
public:
    void *operator new(size_t size, const char *file, int line) {
        // cout << "newed " << size << " bytes at file " << file << ", at line " << line << endl;
        global_size = size;
        void *pointer = ::operator new(size);
        memory_pool.insert(pair<void *, Mem_Node>(pointer, Mem_Node(file, line, global_size)));
        return pointer;
    }

    void operator delete(void *p) {
        if (p) {
            // cout << "deleted " << global_size << " bytes at file " << file_name << ", at line " << line_num << endl;
            ::operator delete(p);
            memory_pool.erase(p);
        }
    }
};

void deletep(const char *file, int line) {
    file_name = file;
    line_num = line;
    return;
}

void do_memory_leak_check() {
    for (auto it = memory_pool.begin() ; it != memory_pool.end() ; ++it)
        cout << "memory leak at line " << it->second.line_ << " in file " << it->second.file_ << ", the leak memory address is " << it->first << ", and it's size = " << it->second.size_ << endl;
}

#define new new(__FILE__, __LINE__)
#define delete deletep(__FILE__, __LINE__), delete

int main() {
    Debug *debug = new Debug();
    // delete debug;
    do_memory_leak_check();
    return 0;
}
