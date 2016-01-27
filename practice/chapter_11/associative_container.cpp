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

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() < rhs.isbn();
}

// 练习11.11：不使用decltype的情况下重新定义bookstore
int test_associative_container_6(void) {
    using ptr_compareIsbn = bool (*) (const Sales_data &, const Sales_data &rhs);
    multiset<Sales_data, ptr_compareIsbn> bookstore(compareIsbn);
    return 0;
}

// 练习11.10：vector<int>::iterator中有<操作，而list<int>::iterator中没有<操作
int test_associative_container_7(void) {
    // declaration is valid
    map<vector<int>::iterator, int> example_map;
    map<list<int>::iterator, int> example_set;
    // defination is invalid, because list has no operator <
    vector<int> vec = {0,1,2,3,4,5,6,7,8,9};
    list<int> lst = {9,8,7,6,5,4,3,2,1,0};
    example_map.insert(std::make_pair(vec.begin(), vec.front()));
    // example_set.insert(std::make_pair(lst.begin(), lst.front()));
    return 0;
}

// 练习11.12和11.13：用三种方法保存pair到vector中
int test_associative_container_8(void) {
    vector<string> names = {"Jim","David","James","Lily","Steven"};
    vector<int> ages = {24, 30, 31, 27, 18};
    vector<pair<string, int> > result1, result2, result3;
    vector<string>::size_type i;
    vector<int>::size_type j;
    for (i = 0 , j = 0 ; i < names.size() && j < ages.size() ; ++i, ++j)
        result1.push_back(make_pair(names[i], ages[j]));
    for (i = 0 , j = 0 ; i < names.size() && j < ages.size() ; ++i, ++j)
        result2.push_back(pair<string, int>(names[i], ages[j]));
    for (i = 0 , j = 0 ; i < names.size() && j < ages.size() ; ++i, ++j)
        result3.push_back(pair<string, int>{names[i], ages[j]});
    return 0;
}

// 练习11.14：保存从姓到pair，其中pair保存名和生日
int test_associative_container_9(void) {
    map<string, pair<string, string> > result;
    vector<string> first_names = {"Jim", "David", "James", "Lily", "Steven"};
    vector<string> second_names = {"Scott", "Jobs", "Gates", "Alen", "Mogen"};
    vector<string> birthday = {"1992/10/6", "1994/6/8", "1997/9/25", "1991/1/7","1989/7/1"};
    for (vector<string>::size_type i = 0 ; i < first_names.size() ; ++i)
        result.insert(make_pair(first_names[i], make_pair(second_names[i], birthday[i])));
    for (auto iter = result.begin() ; iter != result.end() ; ++iter)
        cout << iter->first << " " << iter->second.first << " " << iter->second.second << endl;
    return 0;
}

// 练习11.16：使用一个map迭代器写一个表达式，将一个值赋予一个元素
int test_associative_container_10(void) {
    map<int, int> mymap = {{1,1}};
    auto iter = mymap.begin();
    iter->second = 0;
    cout << iter->first << " " << iter->second << endl;
    return 0;
}

// 练习11.20：重写11.1练习，使用insert代替下标
int test_associative_container_11(void) {
    map<string, size_t> word_count;
    set<string> exclude = {"The", "But","And","Or","An","A","the","but","and","or","an","a"};
    string word;
    pair<map<string, size_t>::iterator, bool> ret;
    while (cin >> word) {
        if (exclude.find(word) == exclude.end()) {
            ret = word_count.insert(pair<string, size_t>(word, 1));
            if (!ret.second)
                ++ret.first->second;
        }
    }
    return 0;
}

// 练习11.23：用multimap代替map重写11.2.1中的练习
int test_associative_container_12(void) {
    multimap<string, vector<string>> mymultimap;
    vector<string> eof;     // 初始为空
    string first_name;
    while (cin >> first_name)
        mymultimap.insert(pair<string, vector<string>>(first_name, eof));
    return 0;
}

// 练习11.26：map的下标操作练习
int test_associative_container_13(void) {
    map<string, int> mymap;
    multiset<string> myset = {"book","name","book","map"};
    for (multiset<string>::key_type k : myset) {
        ++mymap[k];     // 若mymap不存在关键字k，则新建一个元素（first为k，值初始化second为0）并插入，之后进行其它操作
    }
    map<string, int>::mapped_type result = mymap["book"];
    cout << result << endl;
    return 0;
}

// 练习11.18：对一个map<string,vector<int>>定义并初始化一个变量来保存在其上调用find的结果
int test_associative_container_14(void) {
    map<string, vector<int>> mymap;
    mymap.insert(pair<string, vector<int>>("book", vector<int>{1,2,3,4}));
    map<string, vector<int>>::iterator iter = mymap.find("book");
    cout << (iter != mymap.end() ? "find" : "miss") << endl;
    return 0;
}

// 练习11.31：定义一个作者及其作品的multimap，使用find和count在multimap中查找一个元素
// 并用erase删除它，确保你的程序在map中也能正常运行
int test_associative_container_15(void) {
    multimap<string, string> mymap;
    vector<string> authors = {"chensu","chenye","chensu","yuechengxu"};
    vector<string> cources = {"physics","english","chinese","math"};
    string key = "chensu";
    // init mymap
    for (vector<string>::size_type i = 0 ; i < authors.size() ; ++i)
        mymap.insert(pair<string, string>(authors[i], cources[i]));
    // find and count
    auto beg = mymap.find(key);     // 第一个key所对应的迭代器
    auto cnt = mymap.count(key);    // 返回容器中key的数量
    while (cnt) {
        mymap.erase(beg++);
        --cnt;
    }
    for (auto iter = mymap.begin() ; iter != mymap.end() ; ++iter)
        cout << iter->first << " " << iter->second << endl;
    return 0;
}

// 练习11.32：按字典序打印上题中的作者列表和作品
int test_associative_container_16(void) {
    multimap<string, string> mymap;
    vector<string> authors = {"chensu","chenye","chensu","yuechengxu"};
    vector<string> cources = {"physics","english","chinese","math"};
    // init mymap
    for (vector<string>::size_type i = 0 ; i < authors.size() ; ++i)
        mymap.insert(pair<string, string>(authors[i], cources[i]));
    set<string> author_list;    // 用不重复有序set按字典序存储作者列表
    for (auto iter = mymap.begin() ; iter != mymap.end() ; ++iter)
        author_list.insert(iter->first);
    for (auto k : author_list) {
        auto range = mymap.equal_range(k);
        multiset<string> per_books;
        // 打印
        cout << k << ": ";
        for (auto iter = range.first ; iter != range.second ; ++iter)
            per_books.insert(iter->second);
        for (auto key : per_books)
            cout << key << " ";
        cout << endl;
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
#if TEST_ASSOCIATIVE_CONTAINER_6
    test_associative_container_6();
#endif
#if TEST_ASSOCIATIVE_CONTAINER_7
    test_associative_container_7();
#endif
#if TEST_ASSOCIATIVE_CONTAINER_8
    test_associative_container_8();
#endif
#if TEST_ASSOCIATIVE_CONTAINER_9
    test_associative_container_9();
#endif
#if TEST_ASSOCIATIVE_CONTAINER_10
    test_associative_container_10();
#endif
#if TEST_ASSOCIATIVE_CONTAINER_11
    test_associative_container_11();
#endif
#if TEST_ASSOCIATIVE_CONTAINER_12
    test_associative_container_12();
#endif
#if TEST_ASSOCIATIVE_CONTAINER_13
    test_associative_container_13();
#endif
#if TEST_ASSOCIATIVE_CONTAINER_14
    test_associative_container_14();
#endif
#if TEST_ASSOCIATIVE_CONTAINER_15
    test_associative_container_15();
#endif
#if TEST_ASSOCIATIVE_CONTAINER_16
    test_associative_container_16();
#endif
#if TEST_ASSOCIATIVE_CONTAINER_17
    test_associative_container_17();
#endif
#if TEST_ASSOCIATIVE_CONTAINER_18
    test_associative_container_18();
#endif

    return 0;
}
