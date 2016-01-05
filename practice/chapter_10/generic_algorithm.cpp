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
	return 0;
}
