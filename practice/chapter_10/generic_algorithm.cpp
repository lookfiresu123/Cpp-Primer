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

int main (void) {
#if TEST_GENERIC_ALGORITHM_1
	test_generic_algorithm_1();
#endif
	return 0;
}
