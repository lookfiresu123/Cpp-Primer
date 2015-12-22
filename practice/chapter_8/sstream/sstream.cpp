#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>

/**
 * 单个人的信息
 */
class PersonInfo {
public:
    std::string name;
    std::vector<std::string> phones;    // 一个人有多个电话号码
};

#define TEST_SSTREAM_1 0
#define TEST_SSTREAM_2 0
#define TEST_SSTREAM_3 1

/**
 * 利用文件流从data.txt文件中读入数据，并利用string流分割getline得到的行数据，并读入PersonInfo类的成员中
 * @method test_sstream_1
 * @return 0
 */
int test_sstream_1 (void) {
    std::vector<PersonInfo> persons;
    std::string line, word;
    std::fstream finput;
    finput.open("data.txt");
    while (getline(finput, line)) {
        PersonInfo per;
        // 用std::istringstream流分割line行stirng对象
        std::istringstream sinput(line);
        sinput >> per.name;
        while (sinput >> word)
            per.phones.push_back(word);
        persons.push_back(per);
    }
    finput.close();
    for (std::vector<PersonInfo>::iterator i = persons.begin() ; i != persons.end() ; ++i) {
        std::cout << (*i).name << " ";
        for (std::vector<std::string>::iterator j = (*i).phones.begin() ; j != (*i).phones.end() ; ++j)
            std::cout << *j << " ";
        std::cout << std::endl;
    }
    return 0;
}

/**
 * 通过调用std::istringstream.str()和std::istringstream.clear()实现在while循环外部的定义流
 * @method test_sstream_2
 * @return 0
 */
int test_sstream_2 (void) {
    std::vector<PersonInfo> persons;
    std::string line, word;
    std::fstream finput;
    finput.open("data.txt");
    std::istringstream sinput;
    while (getline(finput, line)) {
        PersonInfo per;
        sinput.clear();     // 使sinput有效，从iostream类中继承过来
        sinput.str(line);
        sinput >> per.name;
        while (sinput >> word)     // 当跳出循环时，sinput的eofbit位置为1，因此需要在下次开头重置改为，通过调用clear函数实现
            per.phones.push_back(word);
        // sinput.close();
        persons.push_back(per);
    }
    finput.close();
    for (std::vector<PersonInfo>::iterator i = persons.begin() ; i != persons.end() ; ++i) {
        std::cout << (*i).name << " ";
        for (std::vector<std::string>::iterator j = (*i).phones.begin() ; j != (*i).phones.end() ; ++j)
            std::cout << *j << " ";
        std::cout << std::endl;
    }
    return 0;
}

inline bool valid (const std::string &value) {
    return value.size() == 10 ? true : false;
}

std::string format (std::string value) {
    std::string format_value;
    const size_t size = value.size();
    char temp[size+3];
    size_t j = 0, i = 0;
    for (std::string::iterator index = value.begin(); index != value.end() ; ++index) {
        if (i != 3 && i != 6)
            temp[j] = *index;
        else {
            temp[j] = '-';
            j++;
            temp[j] = *index;
        }
        j++;
        i++;
    }
    temp[j] = '\0';
    format_value = temp;
    return format_value;
}

int test_sstream_3 (void) {
    std::ifstream finput;
    std::string line, word;
    std::vector<PersonInfo> persons;
    finput.open("data.txt");
    std::istringstream sinput;
    while (std::getline(finput, line)) {
        PersonInfo per;
        sinput.clear();
        sinput.str(line);
        sinput >> per.name;
        while (sinput >> word)
            per.phones.push_back(word);
        persons.push_back(per);
    }
    finput.close();

    for (const PersonInfo &entry : persons) {
        // 将数据从entry写入std::ostringstream中
        std::ostringstream formatted, badNums;
        for (const std::string &nums : entry.phones) {
            if (!valid(nums))
                badNums << " " << nums;     // 将std::string nums数据写入流badNums中
            else
                formatted << " " << format(nums);   // 将合法的电话号码格式化
        }
        if (badNums.str().empty())  // 若某个人的所有电话都合法
            std::cout << entry.name << " " << formatted.str() << std::endl;
        else
            std::cerr << "input error: " << entry.name << " invalid number(s) " << badNums.str() << std::endl;
    }
    return 0;
}

int main (void) {
#if TEST_SSTREAM_1
    test_sstream_1();
#endif
#if TEST_SSTREAM_2
    test_sstream_2();
#endif
#if TEST_SSTREAM_3
    test_sstream_3();
#endif
    return 0;
}
