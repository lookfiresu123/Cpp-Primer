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
	return 0;
}
