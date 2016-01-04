#include "container.h"

/**
 * 练习9.2 —— 定义一个list对象，其元素类型是int的deque
 * @method test_container_1
 * @return 0
 */
int test_container_1 (void) {
    std::list<std::deque<int>> l(10);   // 因为std::deque是标准库容器，因此它有默认构造函数，所以可以只传递一个元素数目的参数
    return 0;
}

bool search_for_value_return_bool (std::vector<int>::iterator _begin, std::vector<int>::iterator _end, int _value) {
    for (std::vector<int>::iterator index = _begin ; index != _end ; ++index) {
        if (*index == _value)
            return true;
    }
    return false;
}

/**
 * 练习9.4 —— 接受一对指向vector<int>的迭代器和一个int值，在两个迭代器指定的范围中查找给定的值，并返回一个布尔值指出是否找到，若找到则返回true，否则返回false
 * @method test_container_2
 * @return 0
 */
int test_container_2 (void) {
    std::vector<int> container;
    std::srand(std::time(nullptr));     // 将当前时间设为随机种子
    const size_t size = 10;   // container的大小
    int temp;
    for (size_t i = 0 ; i < size ; ++i) {
        temp = std::rand() % size;  // 在0到size之间取随机值
        container.push_back(temp);
    }
    int value = std::rand() % size;
    // 查找函数search_for_value_return_bool(...)
    bool result = search_for_value_return_bool(container.begin(), container.end(), value);
    std::cout << (result == true ? "true" : "false") << std::endl;
    return 0;
}

std::vector<int>::const_iterator search_for_value_return_iterator(std::vector<int>::iterator _begin, std::vector<int>::iterator _end, int value) {
    std::vector<int>::iterator result = _end;   // 若未找到给定值，则result = _end
    for (std::vector<int>::iterator index = _begin ; index != _end ; ++index) {
        if (*index == value) {
            result = index;
            break;
        }
    }
    return result;
}

/**
 * 练习9.5 —— 重写上一题，返回一个迭代器指向找到的元素，必须处理未找到给定值的情况
 * @method test_container_3
 * @return                  [description]
 */
int test_container_3 (void) {
    std::vector<int> container;
    std::srand(std::time(nullptr));     // 将当前时间设为随机种子
    const size_t size = 10;   // container的大小
    int temp;
    for (size_t i = 0 ; i < size ; ++i) {
        temp = std::rand() % size;  // 在0到size之间取随机值
        container.push_back(temp);
    }
    int value = std::rand() % size;
    // 查找函数search_for_value_return_iterator(...)
    std::vector<int>::const_iterator result = search_for_value_return_iterator( container.begin(), container.end(), value);
    if (result == container.cend())
        std::cout << "can't find it" << std::endl;
    else
        std::cout << "find it" << std::endl;
    return 0;
}

/**
 * 练习9.11 —— 对6种创建和初始化vector对象的方法，每一种给出一个实例
 * @method test_container_4
 * @return 0
 */
int test_container_4(void) {
    // std::array<int, 10> ia1;               // ia1中的10个元素为任意值
    // static std::array<int, 10> ia2;        // ia2中的10个元素都为0

    // 默认初始化
    std::vector<int> v1;
    // 直接初始化
    std::vector<int> v2{0,1,2,3,4,5,6,7,8,9};
    std::vector<int> v3 = {0,1,2,3,4,5,6,7,8,9};
    // 拷贝初始化
    std::vector<int> v4(v3);        // 对象拷贝
    std::vector<int> v5 = v3;       // 对象拷贝
    std::vector<int> v6(v3.begin(), v3.end());     // 迭代器拷贝
    return 0;
}

int test_container_5 (void) {
    std::array<int, 10> a1 = {0,1,2,3,4,5,6,7,8,9};     // 正确，array对象初始化时可以使用花括号{}
    // std::array<int, 11> a2 = a1;    // 错误，由于容器大小也是array类型的一部分，且容器大小无法转换,因此无法将std::array<int, 10ul>转换为std::array<int, 11ul>
    a1 = {0,0,0,0,0,0,0,0,0,0};
    std::vector<int> v1(10, 1);
    std::vector<int> v2;
    v2.assign(10, 2);
    v2.assign(v1.begin(), v1.end());
    v2.assign({1,2,3});
    v2.assign(v2.begin(), v2.end());
    return 0;
}

int test_container_6 (void) {
    std::vector<int> v1(10, 0);
    std::vector<int> v2(5, 1);
    v1.swap(v2);
    std::array<int, 10> a1{0,0,0,0,0,0,0,0,0,0};
    std::array<int, 10> a2{1,1,1,1,1,1,1,1,1,1};
    a1.swap(a2);
    std::string s1 = "abc";
    std::string s2 = "def";
    // s1.swap(s2);
    swap(s1, s2);
    return 0;
}

/**
 * 练习9.14 —— 将一个list中的char *指针元素赋值给一个vector中的string
 * @method test_container_7
 * @return 0
 */
int test_container_7 (void) {
    // 使用assign函数赋值不同类型的对象
    std::list<const char *> l{"hello", "world"};
    std::vector<std::string> v{"my", "name", "is", "chensu"};
    v.assign(l.begin(), l.end());
    return 0;
}

/**
 * 练习9.15 —— 判断两个vector<int>是否相等
 * @method test_container_8
 * @return 0
 */
int test_container_8 (void) {
    std::vector<int> v1(5, 1);
    std::vector<int> v2(5, 1);
    bool result = v1 == v2 ? true : false;
    return 0;
}

/**
 * 比较一个list<int>和一个vector<int>是否相等
 * @method test_container_9
 * @return 0
 */
int test_container_9 (void) {
    std::list<int> l{0,1,2,3,4,5,6,7,8,9};
    std::vector<int> v1{0,1,2,3,4,5,6,7,8,9};
    // 先将list<int>转换为vector<int>，在比较
    std::vector<int> v2;
    v2.assign(l.begin(), l.end());
    bool result = v1 == v2 ? true : false;
    return 0;
}

/**
 * 练习9.18， 从标准输入读取string序列，存入一个deque中，编写循环并用迭代器打印deque中的元素
 * @return 0
 */
int test_container_10 (void) {
    std::deque<std::string> dq;
    std::string word;
    while (std::cin >> word)
        dq.push_back(word);
    for (std::deque<std::string>::iterator index = dq.begin() ; index != dq.end(); ++index)
        std::cout << *index << " ";
    std::cout << std::endl;
    return 0;
}

/**
 * 练习9.19，用list替代deque重写上题程序
 * @return 0
 */
int test_container_11 (void) {
    std::list<std::string> lst;
    std::string word;
    while (std::cin >> word)
        lst.push_back(word);
    for (std::list<std::string>::iterator index = lst.begin() ; index != lst.end() ; ++index)
        std::cout << *index << " ";
    std::cout << std::endl;
    return 0;
}

/**
 * 练习9.20， 从一个list<int>拷贝元素到两个deque中，值为偶数的所有元素拷贝到一个deque中，值为奇数的拷贝到一个deque中
 * @return 0
 */
int test_container_12(void) {
    std::list<int> lst = {0,1,2,3,4,5,6,7,8,9};
    std::deque<int> dq1, dq2;
    for (int member : lst) {
        if (member % 2 == 0)
            dq1.push_back(member);
        else
            dq2.push_back(member);
    }
    for (int member : dq1)
        std::cout << member << " ";
    std::cout << std::endl;
    for (int member : dq2)
        std::cout << member << " ";
    std::cout << std::endl;
    return 0;
}

/**
 * 用insert代替push_front将数据插入vector中
 * @return 0
 */
int test_container_13(void) {
    std::vector<std::string> v;
    std::vector<std::string>::iterator iter = v.begin();
    std::string word;
    while (std::cin >> word)
        iter = v.insert(iter, word);
    return 0;
}

int test_container_14(void) {
    int ia[] = {0,1,2,3,4,5,6,7,8,9};
    std::vector<int> v;
    std::list<int> lst;
    for (size_t i = 0 ; i < 10 ; i++) {
        v.push_back(ia[i]);
        lst.push_back(ia[i]);
    }
    // 不能使用for(index = v.begin() ; index != v.end() ; ++index)，因为删除元素会导致后面的元素前移，使迭代器失效
    for (std::vector<int>::iterator index = v.begin() ; index != v.end() ; ) {
        if (*index % 2 == 0)
            index = v.erase(index);
        else
            ++ index;
    }
    // 不能使用for(index = lst.begin() ; index != lst.end() ; ++index)，因为删除元素会导致被删除节点的前后节点的next指针和prev指针改变，从而导致迭代器失效
    for (std::list<int>::iterator index = lst.begin() ; index != lst.end() ; ){
        if (*index % 2 != 0)
            index = lst.erase(index);
        else
            ++ index;
    }
    return 0;
}

/**
 * 练习9.27：编写函数，查找并删除forward_list<int>中的奇数元素
 * @return 0
 */
int test_container_15(void) {
    std::forward_list<int> flst = {0,1,2,3,4,5,6,7,8,9};
    std::forward_list<int>::iterator prev = flst.before_begin();       // prev保存可能被删元素前驱的迭代器，被首前迭代器初始化
    std::forward_list<int>::iterator curr = flst.begin();       // curr保存可能被删元素的迭代器，被首元素迭代器初始化
    while (curr != flst.end()) {
        if (*curr % 2 != 0)
            curr = flst.erase_after(prev);
        else {
            prev = curr;
            ++ curr;
        }
    }
    return 0;
}

/**
 * 练习9.28：在forward_list<string>链表中查找第一个string的位置，并将第二个string插入到第一个string之后，若链表中没有第一个string，则将第二个string插入到表尾
 * @return 0
 */
int test_container_16(void) {
    std::forward_list<std::string> flst = {"hello", "world", "my", "name", "is", "chensu"};
    std::forward_list<std::string>::iterator prev = flst.before_begin();
    std::string word_1 = "my";
    std::string word_2 = "here";
    while (prev != flst.end()) {
        if (*prev == word_1)
            break;
        ++ prev;
    }
    flst.insert_after(prev, word_2);
    return 0;
}

/**
 * 分别在list和forward_list中删除偶数值并复制奇数值
 * @return 0
 */
int test_container_17(void) {
    std::list<int> lst = {0,1,2,3,4,5,6,7,8,9};
    std::forward_list<int> flst = {0,1,2,3,4,5,6,7,8,9};
    // 在list中操作
    for (std::list<int>::iterator index = lst.begin() ; index != lst.end() ; ) {
        if (*index % 2 == 0) {
            // 删除偶数
            index = lst.erase(index);
        } else {
            // 复制奇数
            index = lst.insert(index, *index);
            ++ index;
            ++ index;
        }
    }
    // 在forward_list中操作
    std::forward_list<int>::iterator prev = flst.before_begin();
    std::forward_list<int>::iterator curr = flst.begin();
    while (curr != flst.end()) {
        if (*curr % 2 == 0) {
            // 删除偶数
            curr = flst.erase_after(prev);
        } else {
            // 复制奇数
            curr = flst.insert_after(prev, *curr);
            ++ curr;
            prev = curr;
            ++ curr;
        }
    }
    return 0;
}

int test_container_18(void) {
    std::vector<std::string> v1, v2, v3, v4;
    std::vector<std::string>::size_type size1 = 256 + 256 / 2;
    std::vector<std::string>::size_type size2 = 512 + 512 / 2;
    std::vector<std::string>::size_type size3 = 1000 + 1000 / 2;
    std::vector<std::string>::size_type size4 = 1048 + 1048 / 2;
    v1.reserve(1024);
    v2.reserve(1024);
    v3.reserve(1024);
    v4.reserve(1024);
    v1.resize(size1);
    v2.resize(size2);
    v3.resize(size3);
    v4.resize(size4);
    std::cout << v1.capacity() << std::endl;        // 1024
    std::cout << v2.capacity() << std::endl;        // 1024
    std::cout << v3.capacity() << std::endl;        // 1500
    std::cout << v4.capacity() << std::endl;        // 1572
    return 0;
}

/**
 * 练习9.41： 从一个vector<char>初始化一个string
 * @return 0
 */
int test_container_19(void) {
    std::vector<char> v = {'h','e','l','l','o'};
    std::string s;
    for (std::vector<char>::iterator index = v.begin(); index != v.end(); ++index) {
        s.push_back(*index);
    }
    return 0;
}

/**
 * 练习9.43：将s中所有oldVal替换为newVal
 * @return 0
 */
int test_container_20(void) {
    std::string s = "hello world";
    std::string oldVal = "or";
    std::string newVal = "pp";
    // 使用迭代器、insert、erase
    for (std::string::iterator index = s.begin() ; index != s.end()-oldVal.size(); ) {
        if (std::string(index, index + oldVal.size()) == oldVal) {
            index = s.erase(index, index + oldVal.size());      // 删去迭代器范围为index到index+oldVal.size()的元素，并返回下一个元素的迭代器
            for (std::string::iterator curr = newVal.begin() ; curr != newVal.end() ; ++curr)
                index = s.insert(index, *curr);
        } else {
            ++ index;
        }
    }
    return 0;
}

/**
 * 练习9.44： 使用下标和replace重写上一题
 * @return 0
 */
int test_container_21(void) {
    std::string s = "hello world";
    std::string oldVal = "or";
    std::string newVal = "pp";
    for (std::string::size_type index = 0 ; index < s.size() ; ) {
        if (s.substr(index, oldVal.size()) == oldVal) {
            s.replace(index, oldVal.size(), newVal);
            index += oldVal.size();
        } else {
            ++ index;
        }
    }
    return 0;
}

/**
 * 练习9.45： 使用迭代器、insert、append函数将前缀和后缀加到字符串中
 * @return 0
 */
int test_container_22(void) {
    std::string s = "Chen Su";
    std::string prev = "Mr. ";
    std::string post = " Jr.";
    s.insert(s.begin(), prev.begin(), prev.end());
    s.append(post);
    std::cout << s << std::endl;
    return 0;
}

/**
 * 练习9.46： 使用位置、长度、insert重写上一题
 * @return 0
 */
int test_container_23(void) {
    std::string s = "Chen Su";
    std::string prev = "Mr. ";
    std::string post = " Jr.";
    std::string::size_type curr = 0;
    s.insert(curr, prev);
    curr = s.size();
    s.insert(curr, post);
    std::cout << s << std::endl;
    return 0;
}

/**
 * 练习9.47： 查找string对象中的每个数字字符（使用find_first_of）和字母字符（使用find_first_not_of）
 * @return 0
 */
int test_container_24(void) {
    std::string s = "ab2c3d7R4E6";
    std::string digits = "0123456789";
    std::string s_digit, s_nodigit;
    std::string::size_type pos = 0;
    while ((pos = s.find_first_of(digits, pos)) != std::string::npos) {
        s_digit.append(1, s[pos]);
        ++ pos;
    }
    pos = 0;
    while ((pos = s.find_first_not_of(digits, pos)) != std::string::npos) {
        s_nodigit.append(1, s[pos]);
        ++ pos;
    }
    std::cout << s_digit << std::endl;
    std::cout << s_nodigit << std::endl;
    return 0;
}

/**
 * 读入一个单词文件，输出最长的既不包含上出头，也不包含下出头的单词
 * @return 0
 */
int test_container_25(void) {
    std::string ascender = "bdfhijklt";
    std::string descender = "gjpqy";
    std::vector<std::string> letters;
    std::string word, line;
    std::ifstream input("letter.txt");
    while (std::getline(input, line)) {
        std::istringstream sinput(line);
        while (sinput >> word)
            letters.push_back(word);
    }
    input.close();
    std::string longest_letter = "";
    for (std::vector<std::string>::iterator index = letters.begin() ; index != letters.end() ; ++index) {
        if ((*index).find_first_of(ascender) == std::string::npos && (*index).find_first_of(descender) == std::string::npos) {
            if (longest_letter.size() < (*index).size())
                longest_letter = *index;
        }
    }
    std::cout << longest_letter << std::endl;
    return 0;
}

/**
 * 练习9.50： 将vector<string>转为int或double，并计算和
 * @return 0
 */
int test_container_26(void) {
    std::vector<std::string> v = {"0","1","2","3","4","5","6","7","8","9"};
    int sum_int = 0;
    double sum_double = 0.0;
    for (std::string s : v) {
        sum_int += stoi(s);
    }
    for (std::string s : v) {
        sum_double += stod(s);
    }
    std::cout << sum_int << std::endl;
    std::cout << sum_double << std::endl;
    return 0;
}

/**
 * 练习9.51： 设计一个类，它由year、day、month组成，编写一个构造函数，接受日期string（格式不同）
 * @return 0
 */
int test_container_27(void) {
    Date date1("1/1/1990");
    Date date2("January 1,1990");
    Date date3("Jan 1 1990");
    return 0;
}

/**
 * 练习9.52：使用stack处理括号表达式
 * @return 0
 */
int test_container_28(void) {
    std::string expression = {"This is (pezy)"};
    std::stack<char> stk;
    bool bseen = false;
    for (char c : expression) {
        if (c == '(') {
            bseen = true;
            continue;
        } else if (c == ')')
            bseen = false;
        if (bseen)
            stk.push(c);
    }
    // 处理stk中的元素
    std::string temp;
    while (!stk.empty()) {
        temp += stk.top();
        stk.pop();
    }
    expression.replace(expression.find("(")+1, temp.size(), temp);
    std::cout << expression << std::endl;
    return 0;
}

int main (void) {
#if TEST_CONTAINER_1
    test_container_1();
#endif
#if TEST_CONTAINER_2
    test_container_2();
#endif
#if TEST_CONTAINER_3
    test_container_3();
#endif
#if TEST_CONTAINER_4
    test_container_4();
#endif
#if TEST_CONTAINER_5
    test_container_5();
#endif
#if TEST_CONTAINER_6
    test_container_6();
#endif
#if TEST_CONTAINER_7
    test_container_7();
#endif
#if TEST_CONTAINER_8
    test_container_8();
#endif
#if TEST_CONTAINER_9
    test_container_9();
#endif
#if TEST_CONTAINER_10
    test_container_10();
#endif
#if TEST_CONTAINER_11
    test_container_11();
#endif
#if TEST_CONTAINER_12
    test_container_12();
#endif
#if TEST_CONTAINER_13
    test_container_13();
#endif
#if TEST_CONTAINER_14
    test_container_14();
#endif
#if TEST_CONTAINER_15
    test_container_15();
#endif
#if TEST_CONTAINER_16
    test_container_16();
#endif
#if TEST_CONTAINER_17
    test_container_17();
#endif
#if TEST_CONTAINER_18
    test_container_18();
#endif
#if TEST_CONTAINER_19
    test_container_19();
#endif
#if TEST_CONTAINER_20
    test_container_20();
#endif
#if TEST_CONTAINER_21
    test_container_21();
#endif
#if TEST_CONTAINER_22
    test_container_22();
#endif
#if TEST_CONTAINER_23
    test_container_23();
#endif
#if TEST_CONTAINER_24
    test_container_24();
#endif
#if TEST_CONTAINER_25
    test_container_25();
#endif
#if TEST_CONTAINER_26
    test_container_26();
#endif
#if TEST_CONTAINER_27
    test_container_27();
#endif
#if TEST_CONTAINER_28
    test_container_28();
#endif
    return 0;
}
