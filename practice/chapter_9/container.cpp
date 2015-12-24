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
    return 0;
}
