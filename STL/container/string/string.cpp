#include <string>
#include <iostream>

using namespace std;

#define DO_TEST_STRING_1 0
#define DO_TEST_STRING_2 0
#define DO_TEST_STRING_3 0
#define DO_TEST_STRING_4 0
#define DO_TEST_STRING_5 0
#define DO_TEST_STRING_6 1
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

int test_string_4 (void) {
    string s;
    /*
    while (cin >> s)    // 自动跳过tab、'\n'、空格符，当类std::istream的对象cin中的有效位iostate = goodbit时，cin >> s == true，否则cin >> s == false（遇到EOF或非法输入）
        cout << s << " ";
    cout << endl;
    */
    /*
    while (getline(cin, s))     // 遇到终止符EOF，则getline函数返回false
        cout << s << endl;
    */
    // while (getline(cin, s) && !s.empty())   // 此时只输入'\n'也能退出循环
    //     cout << s << endl;
    while (getline(cin, s) && !s.empty())
        if (s.size() > 20)      // 只输出size大于20的字符串
            cout << s << endl;
    return 0;
}

int test_string_5 (void) {
    string str = "hello world";     // str实例在内存中实际上有个'\0'放在末尾，但没有实际意义，因为所有对类std::string的操作都会忽略'\0'
    string::size_type size_str = str.size();    // size_type隶属于string类，但string类不是namespace，换句话说string::size_type整体是一个类型
    cout << size_str << endl;
    size_str = distance(str.begin(), str.end());
    cout << size_str << endl;
    return 0;
}

int test_string_6 (void) {
    string s1 = "hello";
    string s2 = "world";
    string s = s1 + " " + s2 + "\n";
    cout << s << endl;
    //s = "," + "\n";         // 错误，两个字面值（const char [2]）之间不能用'+'（该操作符无效）
    s = s1 + ',' + "\n";    // 正确，s = ((s1 + ",") + "\n")，先讲string对象和第一个字面值相加得到一个新的临时string对象，再将该临时string对象和第二个字面值相加，得到新的临时string对象后赋值到s中。
    //s = "," + "\n" + s1;    // 错误，s = (("," + "\n") + s1)
    s1 += s2;
    cout << s1 << endl;
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
#if DO_TEST_STRING_4
    test_string_4();
#endif
#if DO_TEST_STRING_5
    test_string_5();
#endif
#if DO_TEST_STRING_6
    test_string_6();
#endif
    return 0;
}
