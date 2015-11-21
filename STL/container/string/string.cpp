#include <string>
#include <iostream>

using namespace std;

#define DO_TEST_STRING_1 0
#define DO_TEST_STRING_2 0
#define DO_TEST_STRING_3 1
#define DO_TEST_STRING_4 0
#define DO_TEST_STRING_5 0
#define DO_TEST_STRING_6 0
#define DO_TEST_STRING_7 0
#define DO_TEST_STRING_8 0
#define DO_TEST_STRING_9 0

int test_string_1 (void) {
    string s1 = "hello world";
    //s1.erase();     // 清空s1，之后s1为空字符串，eraser为橡皮差
    s1 = "sina";
    //string s2(10, 'a');
    return 0;
}

int test_string_2 (void) {
    /* 空字符串string s = ""是否为占据内存空间？ */
    string s1 = "";     //在栈的某处存储一个字节的'\0'
    string s2 = "hello world";      //在堆中存储12字节的数据{h,e,l,l,o, ,w,o,r,l,d,\0}
    const char *s3 = "";            //在.rodata中存储1字节的'\0'
    const char *s4 = "hello world"; //在.rodata中存储12字节的数据{h,e,l,l,o, ,w,o,r,l,d,\0}
    /* s3、s4是指针，sizeof一个指针得到的值为64 or 32 / 8
     * s1、s2是类（class std::string）,sizeof该类得到的是该类的内存容量，正确方法是s1.size()
     */
    cout << s1.size() << endl;
    cout << s2.size() << endl;
    cout << sizeof(s3) << endl;
    cout << sizeof(s4) << endl;
    // cout << sizeof(s1.data()) << endl;
    // cout << sizeof(s2.data()) << endl;

    return 0;
}

int test_string_3 (void) {
    string s, t;
    //cin >> s;       // 若输入"hello world my name is chensu\n"，则cin遇到空格符停止并丢弃遇到的空格符，此时s="hello"，但流中还有"world my name is chensu\n"
    //getline(cin, s);    // 由于流中存在数据，因此扫描流，知道遇到最后的换行符'\n'停止并丢弃该'\n'，此时s="world my name is chensu"
    cin >> s >> t;
    return 0;
}

int main (void) {
#if DO_TEST_STRING_1
    test_string_1();
#endif
#if DO_TEST_STRING_2
    test_string_2();
#endif
#if DO_TEST_STRING_3
    test_string_3();
#endif
    return 0;
}
