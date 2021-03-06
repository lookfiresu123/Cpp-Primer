#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

#define TEST_STREAM_1 0
#define TEST_STREAM_2 1

bool debug_istream (std::istream &is) {
    std::ios_base::iostate state = is.rdstate();
    // std::cout << state << std::endl;
    if (state == 0)
        std::cout << "well input" << std::endl;
    else if ((state & is.badbit) != 0)
        std::cout << "bad input" << std::endl;
    else if ((state & is.eofbit) != 0)
        std::cout << "eof input" << std::endl;
    else if ((state & is.failbit) != 0)
        std::cout << "fail input" << std::endl;
    return state == 0 ? true : false;
}

std::istream &function_stream_1 (std::istream &is) {
    char temp;
    while (is >> temp, !is.eof()) {     // 先输入，再判断
        std::cout << temp;
    }
    is.clear();
    // is.sync();
    return is;
}

int test_stream_1 (void) {
    function_stream_1(std::cin);
    return 0;
}

void split_string(std::vector<std::string> &vec, std::string &input) {
    std::stringstream ss(input);
    std::string word;
    while (std::getline(ss, word, ' '))
        vec.push_back(word);
}

int test_stream_2() {
    std::string s("Hello my name is chensu");
    std::vector<std::string> vec;
    split_string(vec, s);
    std::for_each(vec.begin(), vec.end(), [](std::string &i){std::cout << i << std::endl;});
    return 0;
}

int main (void) {
#if TEST_STREAM_1
    test_stream_1();    // 练习8.1和8.2
#endif
#if TEST_STREAM_2
    test_stream_2();
#endif
    return 0;
}
