#include "generic_algorithm.h"

int test_generic_algorithm_1 (void) {
	std::vector<int> v;
	std::vector<int>::size_type size = 10;
	std::srand(std::time(nullptr));
	for (std::vector<int>::size_type i = 0 ; i < size ; ++i)
		v.push_back(std::rand() % 2);
	int result = std::count(v.cbegin(), v.cend(), 1);
	std::cout << result << std::endl;
	return 0;
}

/**
 * 练习10.3：用accumulate求一个vector<int>中的元素之和
 * @return 0
 */
int test_generic_algorithm_2 (void) {
	std::vector<int> v;
	std::srand(std::time(nullptr));
	for (std::vector<int>::size_type i = 0 ; i < 10 ; ++i)
		v.push_back(std::rand() % 10);
	int sum = std::accumulate(v.cbegin(), v.cend(), 0);
	std::cout << sum << std::endl;
	return 0;
}

/**
 * 练习10.4：用double代替int计算上题
 * @return 0
 */
int test_generic_algorithm_3 (void) {
	std::vector<double> v;
	std::srand(std::time(nullptr));
	for (std::vector<double>::size_type i = 0 ; i < 10 ; ++i)
		v.push_back((double)(std::rand() % 7) / 7);
	double sum = std::accumulate(v.cbegin(), v.cend(), 0.0);
	std::cout << sum << std::endl;
	return 0;
}

/**
 * 练习10.6：使用fill_n将一个序列中的int值都设置为0
 * @return 0
 */
int test_generic_algorithm_4 (void) {
	std::vector<int> v = {0,1,2,3,4,5,6,7,8,9};
	std::fill_n(v.begin(), v.size(), 0);
	return 0;
}

/**
 * 练习10.9
 * @return 0
 */
int test_generic_algorithm_5 (void) {
	std::vector<std::string> v = {"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
	std::sort(v.begin(), v.end());
	std::vector<std::string>::iterator end_unique = std::unique(v.begin(), v.end());
	v.erase(end_unique, v.end());
	return 0;
}

/**
 * 将words按字典序重排，并消除重复单词
 * @words：字典
 */
void elimDups(std::vector<std::string> &words) {
	// 按字典序排序words
	std::sort(words.begin(), words.end());
	std::vector<std::string>::iterator end_unique = std::unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

bool isShorter (const std::string &s1, const std::string &s2) {
	return s1.size() < s2.size();
}

/**
 * 练习10.11：使用stable_srot和isShorter对vector进行排序
 * @return 0
 */
int test_generic_algorithm_6 (void) {
	std::vector<std::string> words = {"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
	// 将words按字典序重排，并消除重复单词
	elimDups(words);
	// 将words按长度重排，长度相同的单词维持原状（即字典序）
	std::stable_sort(words.begin(), words.end(), isShorter);
	for (std::string s : words)
		std::cout << s << " ";
	std::cout << std::endl;
	return 0;
}

// 按长度排序Sales_data对象的vector
bool compareIsbn (const Sales_data &s1, const Sales_data &s2) {
	return s1.isbn().size() < s2.isbn().size();
}

/**
 * 练习10.12：比较两个Sales_data对象的isbn()成员，排序一个保存Sales_data对象的vector
 * @return 0
 */
int test_generic_algorithm_7 (void) {
	std::vector<Sales_data> v;
	v.push_back(Sales_data("google"));
	v.push_back(Sales_data("sina"));
	std::sort(v.begin(), v.end(), compareIsbn);
	return 0;
}

// 若s的长度大于等于5，则返回true，否则，返回false
bool isMore (const std::string &s) {
	return s.size() >= 5 ? true : false;
}

/**
 * 练习10.13：利用partition函数划分容器
 * @return 0
 */
int test_generic_algorithm_8 (void) {
	std::vector<std::string> words = {"google", "sina", "name", "chnsu", "short"};
	std::vector<std::string>::iterator mid_end = std::partition(words.begin(), words.end(), isMore);
	for (std::vector<std::string>::iterator index = words.begin() ; index != mid_end ; ++index)
		std::cout << *index << " ";
	std::cout << std::endl;
	return 0;
}

/**
 * 练习10.14：编写一个lambda表达式，接受两个int，返回他们的和
 * @return 0
 */
int test_generic_algorithm_9 (void) {
	auto lambda_expr = [](int a, int b){ return a+b; };
	int result = lambda_expr(1, 2);		// lambda表达式相当于定义在内部的inline函数
	std::cout << result << std::endl;
	return 0;
}

/**
 * 练习10.15：编写一个lambda，捕获所在函数的int，并接受一个int参数，返回和
 * @return  [description]
 */
int test_generic_algorithm_10 (void) {
	int a = 1;
	auto lambda_expr = [a](int b){ return a+b; };
	int result = lambda_expr(2);
	std::cout << result << std::endl;
	return 0;
}

/**
 * 练习10.17：重写10.12，用lambda代替compareIsbn
 * @return 0
 */
int test_generic_algorithm_11 (void) {
	std::vector<Sales_data> v;
	v.push_back(Sales_data("google"));
	v.push_back(Sales_data("sina"));
	std::sort(v.begin(), v.end(), [](const Sales_data &s1, const Sales_data &s2) -> bool { return s1.isbn().size() < s2.isbn().size(); });
	return 0;
}

/**
 * 练习10.18：用partition算法代替find_if重写biggies函数
 * @return 0
 */
int test_generic_algorithm_12 (void) {
	std::vector<std::string> words = {"google", "sina", "name", "chnsu", "short"};
	std::vector<std::string>::size_type sz = words.size();
	elimDups(words);	// 将words按字典序排序
	std::stable_sort(words.begin(), words.end(), [](const std::string &a, const std::string &b){ return a.size() < b.size(); });	// 按长度排序，长度相同的维持字典序
	// 获取一个迭代器，指向第一个满足size() >= sz的元素
	std::vector<std::string>::iterator wc = std::partition(words.begin(), words.end(), [sz](const std::string &a){ return a.size() >= sz; });
	// 计算满足size >= sz的元素数目
	auto count = words.end() - wc;
	std::cout << "the number of elements which large than or equal to " << sz << " is " << count << std::endl;
	std::for_each(wc, words.end(), [](const std::string &a){ std::cout << a << " "; });
	std::cout << std::endl;
	return 0;
}

/**
 * 练习10.19：用stable_partition重写前一题
 * @return 0
 */
int test_generic_algorithm_13 (void) {
	std::vector<std::string> words = {"google", "sina", "name", "chnsu", "short"};
	std::vector<std::string>::size_type sz = words.size();
	elimDups(words);	// 将words按字典序排序
	auto wc = std::stable_partition(words.begin(), words.end(), [sz](const std::string &a){ return a.size() >= sz; });	// 按sz划分，长度相同的维持字典序
	// 计算满足size >= sz的元素数目
	auto count = words.end() - wc;
	std::cout << "the number of elements which large than or equal to " << sz << " is " << count << std::endl;
	std::for_each(wc, words.end(), [](const std::string &a){ std::cout << a << " "; });
	std::cout << std::endl;
	return 0;
}

/*
 * 练习10.20：使用count_if统计有多少个单词长度超过6的部分
 * */
int test_generic_algorithm_14 (void) {
    std::vector<std::string> words = {"google", "sina", "facebook", "microsoft", "apple"};
    auto count = std::count_if(words.begin(), words.end(), [](std::string s){ return s.size() > 6;});
    std::cout << count << std::endl;
    return 0;
}

int test_generic_algorithm_15 (void) {
    std::srand(std::time(nullptr));
    int sum = std::rand() % 100;
    auto f1 = [&] { while(sum > 0) { --sum; } };
    f1();
    return 0;
}

bool check_size (const std::string &s, std::string::size_type sz) {
    return s.size() <= sz;
}

/*
 * 练习10.22：统计长度小于等于6的单词数量，使用bind
 * */
int test_generic_algorithm_16 (void) {
    std::vector<std::string> words = { "hello", "google", "facebook", "microsoft", "apple" };
    auto count = std::count_if(words.begin(), words.end(), bind(check_size, _1, 6));
    std::cout << count << std::endl;
    return 0;
}

bool check_size_int (int val, int sz) {
    return val > sz;
}

/*
 * 练习10.23
 * */
int test_generic_algorithm_17 (void) {
    std::string s = "words";
    int sz = static_cast<int>(s.size());
    std::vector<int> v = {0,1,2,3,4,5,6,7,8,9};
    std::vector<int>::iterator iter = std::find_if(v.begin(), v.end(), std::bind(check_size_int, _1, sz));
    std::cout << *iter << std::endl;
    return 0;
}

/**
 * 练习10.27：用unique_copy代替copy
 * @return 0
 */
int test_generic_algorithm_18 (void) {
    std::vector<int> vec = {1,2,3,4,5,1,2,3,7,8,9,0};
    std::list<int> lst;
    std::unique_copy(vec.begin(), vec.end(), std::back_inserter(lst));
    return 0;
}

void print (int val) {
	std::cout << val << " ";
}

/**
 * 练习10.28：分别使用inserter、back_inserter、front_inserter将元素添加到三个容器中
 * @return 0
 */
int test_generic_algorithm_19 (void) {
    std::deque<int> v = {1,2,3,4,5,6,7,8,9};
	std::deque<int> v1, v2, v3;
	std::copy(v.begin(), v.end(), std::inserter(v1, v1.begin()));
	std::copy(v.begin(), v.end(), std::back_inserter(v2));
	std::copy(v.begin(), v.end(), std::front_inserter(v3));
	std::for_each(v1.begin(), v1.end(), print);
	std::cout << std::endl;
	std::for_each(v2.begin(), v2.end(), print);
	std::cout << std::endl;
	std::for_each(v3.begin(), v3.end(), print);
	std::cout << std::endl;
	return 0;
}

/* 练习10.29：使用流迭代器读取一个文本文件，存入一个vector中的string里*/
int test_generic_algorithm_20 (void) {
    std::fstream ifs("data.txt");       // input file stream
    std::istream_iterator<std::string> iter(ifs);   // bind iterator with fstream
    std::istream_iterator<std::string> eof;
    std::vector<std::string> vec;
    while (iter != eof) {
        vec.push_back(*iter);
        ++iter;
    }
    for_each(vec.begin(), vec.end(), [](const string &s){ cout << s << " "; });
    return 0;
}

/* 练习10.30：使用流迭代器、sort、copy从标准输入读取一个整数数列 */
int test_generic_algorithm_21 (void) {
    istream_iterator<int> input_iter(cin);
    istream_iterator<int> input_eof;
    ostream_iterator<int> output_iter(cout, " ");
    vector<int> temp;
    // read data
    while (input_iter != input_eof)
        temp.push_back(*input_iter++);
    // sort temp
    sort(temp.begin(), temp.end());
    // copy to output iterator
    copy(temp.begin(), temp.end(), output_iter);
    return 0;
}

/* 练习10.31：修改前一题，只打印不重复的元素 */
int test_generic_algorithm_22 (void) {
    // 使用unique_copy代替copy，其它不变
    istream_iterator<int> input_iter(cin);
    istream_iterator<int> input_eof;
    ostream_iterator<int> output_iter(cout, " ");
    vector<int> temp;
    // read data
    while (input_iter != input_eof)
        temp.push_back(*input_iter++);
    // sort temp
    sort(temp.begin(), temp.end());
    // unique copy to output iterator
    unique_copy(temp.begin(), temp.end(), output_iter);
    return 0;
}

/* 练习10.33： 从输入文件中读取整数，分别将奇数和偶数存入两个不同的输出文件中 */
int test_generic_algorithm_23 (void) {
    ifstream ifs("input_data.txt");
    ofstream ofs_odd("output_odd.txt");
    ofstream ofs_even("output_even.txt");
    istream_iterator<int> input_iter(ifs);
    istream_iterator<int> input_eof;
    ostream_iterator<int> output_odd_iter(ofs_odd, " ");   // 保存奇数
    ostream_iterator<int> output_even_iter(ofs_even, "\n"); // 保存偶数
    vector<int> temp;
    // read data
    while (input_iter != input_eof)
        temp.push_back(*input_iter++);
    // divide into odd or even, and then write into file
    for (auto i : temp) {
        if ((i % 2) == 0)
            *output_odd_iter = i;
        else
            *output_even_iter = i;
    }
    return 0;
}

/* 练习10.34：使用reverse_iterator逆序打印一个vector */
int test_generic_algorithm_24 (void) {
    vector<int> vec = {0,1,2,3,4,5,6,7,8,9};
    for (vector<int>::reverse_iterator iter = vec.rbegin() ; iter != vec.rend() ; ++iter)
        cout << *iter << " ";
    cout << endl;
    return 0;
}

/* 练习10.35：使用普通迭代器逆序打印一个vector */
int test_generic_algorithm_25 (void) {
    vector<int> vec = {0,1,2,3,4,5,6,7,8,9};
    for (vector<int>::iterator iter = vec.end()-1 ; iter >= vec.begin(); --iter)
        cout << *iter << " ";
    cout << endl;
    return 0;
}

int test_generic_algorithm_26 (void) {
    vector<int> vec = {0,1,2,3,0,4,5,0,6,7,8,0,9};
    find(vec.rbegin(), vec.rend(), 0);
    return 0;
}

int test_generic_algorithm_27 (void) {
    vector<int> vec = {0,1,2,3,4,5,6,7,8,9};
    list<int> lst;
    int i;
    vector<int>::reverse_iterator iter;
    for (iter = vec.rbegin(), i = 0 ; iter != vec.rend() ; ++iter, ++i) {
        if (i >= 2 && i <= 6)
            lst.push_back(*iter);
    }
    return 0;
}


int main (void) {
#if TEST_GENERIC_ALGORITHM_1
	test_generic_algorithm_1();
#endif
#if TEST_GENERIC_ALGORITHM_2
	test_generic_algorithm_2();
#endif
#if TEST_GENERIC_ALGORITHM_3
	test_generic_algorithm_3();
#endif
#if TEST_GENERIC_ALGORITHM_4
	test_generic_algorithm_4();
#endif
#if TEST_GENERIC_ALGORITHM_5
	test_generic_algorithm_5();
#endif
#if TEST_GENERIC_ALGORITHM_6
	test_generic_algorithm_6();
#endif
#if TEST_GENERIC_ALGORITHM_7
	test_generic_algorithm_7();
#endif
#if TEST_GENERIC_ALGORITHM_8
	test_generic_algorithm_8();
#endif
#if TEST_GENERIC_ALGORITHM_9
	test_generic_algorithm_9();
#endif
#if TEST_GENERIC_ALGORITHM_10
	test_generic_algorithm_10();
#endif
#if TEST_GENERIC_ALGORITHM_11
	test_generic_algorithm_11();
#endif
#if TEST_GENERIC_ALGORITHM_12
	test_generic_algorithm_12();
#endif
#if TEST_GENERIC_ALGORITHM_13
	test_generic_algorithm_13();
#endif
#if TEST_GENERIC_ALGORITHM_14
	test_generic_algorithm_14();
#endif
#if TEST_GENERIC_ALGORITHM_15
	test_generic_algorithm_15();
#endif
#if TEST_GENERIC_ALGORITHM_16
	test_generic_algorithm_16();
#endif
#if TEST_GENERIC_ALGORITHM_17
	test_generic_algorithm_17();
#endif
#if TEST_GENERIC_ALGORITHM_18
	test_generic_algorithm_18();
#endif
#if TEST_GENERIC_ALGORITHM_19
	test_generic_algorithm_19();
#endif
#if TEST_GENERIC_ALGORITHM_20
	test_generic_algorithm_20();
#endif
#if TEST_GENERIC_ALGORITHM_21
	test_generic_algorithm_21();
#endif
#if TEST_GENERIC_ALGORITHM_22
	test_generic_algorithm_22();
#endif
#if TEST_GENERIC_ALGORITHM_23
	test_generic_algorithm_23();
#endif
#if TEST_GENERIC_ALGORITHM_24
	test_generic_algorithm_24();
#endif
#if TEST_GENERIC_ALGORITHM_25
	test_generic_algorithm_25();
#endif
#if TEST_GENERIC_ALGORITHM_26
	test_generic_algorithm_26();
#endif
#if TEST_GENERIC_ALGORITHM_27
	test_generic_algorithm_27();
#endif
#if TEST_GENERIC_ALGORITHM_28
	test_generic_algorithm_28();
#endif
#if TEST_GENERIC_ALGORITHM_29
	test_generic_algorithm_29();
#endif

	return 0;
}
