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
    return 0;
}
