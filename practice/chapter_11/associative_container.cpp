#include "associative_container.h"

// 统计每个单词出现的次数
int test_associative_container_1(void) {
    map<string, size_t> word_count;     // string到size_t的空map
    unordered_map<string, size_t> unordered_word_count;
    vector<string> words = {"hello","world","world","my","name","is","is","chensu"};
    for (vector<string>::size_type i = 0 ; i < words.size() ; ++i) {
        ++word_count[words[i]];
        ++unordered_word_count[words[i]];
    }
    return 0;
}

// 只统计不在exclude中的单词出现的次数
int test_associative_container_2(void) {
    map<string, size_t> word_count;
    set<string> exclude = {"world","is"};
    vector<string> words = {"hello","world","world","my","name","is","is","chensu"};
    for (vector<string>::size_type i = 0 ; i < words.size() ; ++i) {
        if (exclude.find(words[i]) == exclude.end())
            ++word_count[words[i]];
    }
    return 0;
}

void processing(vector<string> &words) {
    for (string &str : words) {
        // 将大写字母转换为小写字母
        for (char &c : str)
            c = tolower(c);
        // 去掉标点符号及其后面的数据
        str.erase(remove_if(str.begin(), str.end(), ispunct), str.end());
    }
}

// 练习11.4：统计每个单词出现的次数，忽略大小写和标点符号
int test_associative_container_3(void) {
    map<string, size_t> word_count;     // string到size_t的空map
    vector<string> words = {"hello","World","world,","my.","namE","IS!","is","chensu"};
    // 处理words
    processing(words);
    for (vector<string>::size_type i = 0 ; i < words.size() ; ++i) {
        ++word_count[words[i]];
    }
    return 0;
}

void add_family(map<string, vector<string>> &families, const string &family_name, vector<string> &init_member) {
    families.insert(std::make_pair(family_name, init_member));
}

void add_member(map<string, vector<string>> &families, const string &family_name, const string &child_name) {
    families[family_name].push_back(child_name);
}

// 练习11.7：定义一个map，关键字是家庭的姓，值是一个vector，保存家中孩子的名，实现添加
// 新的家庭以及向已有家庭中添加新的孩子
int test_associative_container_4(void) {
    map<string, vector<string>> families;      // 定义家庭组，其中一个元素(pair)表示一个家庭
    string family_name;     // 家庭的关键字——姓
    vector<string> init_member;     // 家庭的值——孩子的名（初始值为空）
    string child_name;
    while (cin >> family_name)
        add_family(families, family_name, init_member);
    cin.clear();
    cin.sync();
    while (cin >> child_name)
        add_member(families, family_name, child_name);
    return 0;
}

// 练习11.8：编写一个程序，在一个vector而不是一个set中保存不重复的单词
int test_associative_container_5(void) {
    vector<string> vec;
    string word;
    while (cin >> word) {
        if (std::find(vec.cbegin(), vec.cend(), word) != vec.cend())
            vec.push_back(word);
    }
    return 0;
}

int main() {
#if TEST_ASSOCIATIVE_CONTAINER_1
    test_associative_container_1();
#endif
#if TEST_ASSOCIATIVE_CONTAINER_2
    test_associative_container_2();
#endif
#if TEST_ASSOCIATIVE_CONTAINER_3
    test_associative_container_3();
#endif
#if TEST_ASSOCIATIVE_CONTAINER_4
    test_associative_container_4();
#endif
#if TEST_ASSOCIATIVE_CONTAINER_5
    test_associative_container_5();
#endif
    return 0;
}
