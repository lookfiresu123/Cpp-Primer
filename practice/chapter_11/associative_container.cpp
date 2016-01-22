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
    return 0;
}
