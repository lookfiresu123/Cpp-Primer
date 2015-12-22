#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define TEST_FSTREAM_1 0
#define TEST_FSTREAM_2 0
#define TEST_FSTREAM_3 1


/**
 * 编写函数，以读模式打开一个文件，并将其内容读到一个string的vector中，将每一行作为一个独立的元素存于vector中
 * @method test_fstream_1
 * @return 0
 */
int test_fstream_1 (void) {
    std::vector<std::string> v;
    std::ifstream input("data.txt");    // open file stream input and bind it to data.txt
    std::string temp;
    while (std::getline(input, temp))
        v.push_back(temp);
    for (std::vector<std::string>::iterator index = v.begin(); index != v.end(); ++index)
        std::cout << *index << std::endl;
    input.close();
    return 0;
}

/**
 * 编写函数，以读模式打开一个文件，并将其内容读到一个string的vector中，将每个单词作为一个独立的元素存于vector中
 * @method test_fstream_2
 * @return 0
 */
int test_fstream_2 (void) {
    std::vector<std::string> v;
    std::ifstream input("data.txt");    // open file stream input and bind it to data.txt
    std::string temp;
    while (input >> temp)
        v.push_back(temp);
    for (std::vector<std::string>::iterator index = v.begin(); index != v.end(); ++index)
        std::cout << *index << std::endl;
    input.close();
    return 0;
}

/**
 * 写入文件，但不丢弃已有数据 —— 通过添加std::ofstream::app模式
 * @method test_fstream_3
 * @return 0
 */
int test_fstream_3 (void) {
    std::vector<std::string> v;
    std::ifstream input("data.txt");    // open file stream input and bind it to data.txt
    std::string temp;
    while (input >> temp)
        v.push_back(temp);
    input.close();
    std::ofstream output;
    output.open("output.txt", std::ofstream::app);
    for (std::vector<std::string>::iterator index = v.begin(); index != v.end(); ++index)
        output << *index << " ";
    output.close();
    return 0;
}

int main (void) {
#if TEST_FSTREAM_1
    test_fstream_1();
#endif
#if TEST_FSTREAM_2
    test_fstream_2();
#endif
#if TEST_FSTREAM_3
    test_fstream_3();
#endif
    return 0;
}
