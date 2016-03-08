#include <string>
#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

/* 函数内部的string对象的值保存在栈中，但其字符串成员保存在堆中（c语言中字符串字面值保存在.rodata中） */

#define DO_TEST_STRING_1 0
#define DO_TEST_STRING_2 0
#define DO_TEST_STRING_3 0
#define DO_TEST_STRING_4 0
#define DO_TEST_STRING_5 0
#define DO_TEST_STRING_6 0
#define DO_TEST_STRING_7 0
#define DO_TEST_STRING_8 0
#define DO_TEST_STRING_9 0
#define DO_TEST_STRING_10 0
#define DO_TEST_STRING_11 0
#define DO_TEST_STRING_12 0
#define DO_TEST_STRING_13 1
#define DO_TEST_STRING_14 0
#define DO_TEST_STRING_15 0

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
/* 第3.2.2节练习 */
int test_string_7 (void) {
    // 练习3.2
#if 0
    string str2;
    getline(cin, str2);     // 遇到'\n'丢弃该字符并结束读入
    while (cin >> str2)     // 遇到EOF(或cin.iostate != goodbit)跳出循环
        cout << str2 << endl;
#endif
    // 练习3.3
    // 练习3.4
#if 0
    string s1, s2, result;
    cin >> s1 >> s2;
    if (s1 != s2)
        result = s1 > s2 ? s1 : s2;
    cout << result << endl;
#endif
#if 0
    string s1, s2, result;
    cin >> s1 >> s2;
    decltype(s1.size()) len1 = s1.size();
    decltype(s2.size()) len2 = s2.size();
    if (len1 != len2)
        result = len1 > len2 ? s1 : s2;
    cout << result << endl;
#endif
    // 练习3.5
#if 0
    string str, result;
    while (cin >> str)
        result += str;
    cout << result << endl;
#endif
#if 1
    string str, result;
    while (cin >> str)
        result += (str + " ");
    result.pop_back();      // 移除最后一个字符
    cout << result << endl;
#endif
    return 0;
}

typedef struct COUNT_CHAR Count_char;
struct COUNT_CHAR {
    string::size_type alnum_cnt = 0;
    string::size_type alpha_cnt = 0;
    string::size_type cntrl_cnt = 0;
    string::size_type digit_cnt = 0;
    string::size_type graph_cnt = 0;
    string::size_type lower_cnt = 0;
    string::size_type print_cnt = 0;
    string::size_type punct_cnt = 0;
    string::size_type space_cnt = 0;
    string::size_type upper_cnt = 0;
    string::size_type xdigit_cnt = 0;
};

/* 遍历整个string变量 */
int test_string_8 (void) {
    string str;
    getline(cin, str);
    Count_char cnt;
    for (auto c : str) {
        if (isalnum(c))
            cnt.alnum_cnt ++;
        if (isalpha(c))
            cnt.alpha_cnt ++;
        if (iscntrl(c))
            cnt.cntrl_cnt ++;
        if (isdigit(c))
            cnt.digit_cnt ++;
        if (isgraph(c))
            cnt.graph_cnt ++;
        if (islower(c))
            cnt.lower_cnt ++;
        if (isprint(c))
            cnt.print_cnt ++;
        if (ispunct(c))
            cnt.punct_cnt ++;
        if (isupper(c))
            cnt.upper_cnt ++;
        if (isxdigit(c))
            cnt.xdigit_cnt ++;
    }
    cout << "the str is : " << str << endl;
    for (auto &c : str) {       // 要改变str的值，必须使用引用，因为引用符号&属于标识符，所以auto不变
        if (islower(c)) {
            c = toupper(c);
            cnt.lower_cnt --;
            cnt.upper_cnt ++;
        }
    }
    cout << "the str is : " << str << endl;
    return 0;
}

/* 只访问string类型中的某一个字符 */
int test_string_9 (void) {
    string s;
    //下标运算符接受的参数和s.size()相同，都是string::size_type类型，由于下标必须大于等于0且小于s.size()，超出范围的下标会发生不可预知的效果.
    //任何表达式的值只要是整数值都能作为下标（因为编译器会隐式的转换为string::size_type，由于该类型是无符号类型，因此s[-1] = s[11...11]，这就是不可预知的效果）
#if 0
    cin >> s;
    if (! s.empty())    // 确保该字符不为空
        cout << s[0] << endl;
    if (! s.empty())    // 不管何时只要对string对象使用下标，都要确认那个位置上确实有值
        s[0] = 'c';
    cout << s << endl;
#endif
#if 1
    getline(cin, s);
    // 依次处理s，知道处理完或遇到一个空白字符为止
    for (decltype(s.size()) index = 0 ; index < s.size() && !isspace(s[index]) ; index++)
        s[index] = toupper(s[index]);
    cout << s << endl;
#endif
    return 0;
}

/* 3.2.3练习 */
int test_string_10 (void) {
    // 练习3.6
#if 0
    string s;
    getline(cin, s);
    for (auto &c : s)
        c = 'x';
    cout << s << endl;
    for (decltype(s.size()) index = 0 ; index < s.size() ; index++)
        s[index] = toupper(s[index]);
    cout << s << endl;
#endif
    // 练习3.7
#if 0
    string s;
    getline(cin, s);
    for (char c : s)
        c = 'X';
    // s不变，因为c只是一个副本
    cout << s << endl;
    for (char &c : s)
        c = 'X';
    // s都变为X，因为c和s中的字符绑定
    cout << s << endl;
#endif
    // 练习3.8
#if 0
    string s;
    getline(cin, s);
    string::size_type i = 0;
    while (i < s.size())
        s[i++] = 'X';
    cout << s << endl;
#endif
    // 练习3.9
    // 练习3.10
#if 1
    string s = "hello world! My name is Chensu. I'm 24 years old, my birthday is 1992.10.7.";
    //string::iterator c = s.end();       // c为字符'\0'，这表明'\0'也是string对象的一部分，只是size()函数不考虑它（size()类似于strlen()，而不是sizeof）
    for (auto c : s)
        if (! ispunct(c))
            cout << c;
    cout << endl;
#endif
    // 练习3.11
    return 0;
}

/* 用数组初始化string */
int test_string_11 (void) {
    string s1("hello world");       // for initial of string: () <--> {}
    char array[] = "hello world";
    string s2 = array;              // use array to initialize string object
    const char *p = s2.c_str();     // use string object to initialize constant pointer or array
    s2 = "my name is chensu";       // 编译器重新在堆中分配内存用于存放"my name is chensu"字符串，而将在栈中的string对象s2本身的值改为"my name is chensu"的首地址
                                    // 且p的值依然是"hello world"的首地址
    return 0;
}

/* 练习3.39 */
int test_string_12 (void) {
    string s1("hello world1");
    string s2("hello world2");
    if (s1 == s2)
        cout << "s1 is same with s2" << endl;
    else if (s1 > s2)
        cout << "s1 is larger than s2" << endl;
    else
        cout << "s1 is smaller than s2" << endl;

    char str1[] = "hello world";
    char str2[] = "hello world";
    auto ret = strcmp(str1, str2);
    if (ret == 0)
        cout << "str1 is same with str2" << endl;
    else if (ret > 0)
        cout << "str1 is larger than str2" << endl;
    else
        cout << "str1 is smaller than str2" << endl;
    return 0;
}

/* 练习3.40 */
int test_string_13 (void) {
    char array1[] = "hello world, ";
    char array2[] = "my name is chensu";
    const size_t size = strlen(array1) + strlen(array2) + 1;
    char array[size];
    strcpy(array, array1);
    strcat(array, array2);
    cout << array << endl;
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
#if DO_TEST_STRING_7
    test_string_7();
#endif
#if DO_TEST_STRING_8
    test_string_8();
#endif
#if DO_TEST_STRING_9
    test_string_9();
#endif
#if DO_TEST_STRING_10
    test_string_10();
#endif
#if DO_TEST_STRING_11
    test_string_11();
#endif
#if DO_TEST_STRING_12
    test_string_12();
#endif
#if DO_TEST_STRING_13
    test_string_13();
#endif

    return 0;
}
