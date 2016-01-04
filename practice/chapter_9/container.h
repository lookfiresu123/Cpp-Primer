#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <list>
#include <forward_list>
#include <deque>
#include <array>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <sstream>
#include <stack>
#include <queue>

#define TEST_CONTAINER_1 0
#define TEST_CONTAINER_2 0
#define TEST_CONTAINER_3 0
#define TEST_CONTAINER_4 0
#define TEST_CONTAINER_5 0
#define TEST_CONTAINER_6 0
#define TEST_CONTAINER_7 0
#define TEST_CONTAINER_8 0
#define TEST_CONTAINER_9 0
#define TEST_CONTAINER_10 0
#define TEST_CONTAINER_11 0
#define TEST_CONTAINER_12 0
#define TEST_CONTAINER_13 0
#define TEST_CONTAINER_14 0
#define TEST_CONTAINER_15 0
#define TEST_CONTAINER_16 0
#define TEST_CONTAINER_17 0
#define TEST_CONTAINER_18 0
#define TEST_CONTAINER_19 0
#define TEST_CONTAINER_20 0
#define TEST_CONTAINER_21 0
#define TEST_CONTAINER_22 0
#define TEST_CONTAINER_23 0
#define TEST_CONTAINER_24 0
#define TEST_CONTAINER_25 0
#define TEST_CONTAINER_26 0
#define TEST_CONTAINER_27 0
#define TEST_CONTAINER_28 1

class Date {
private:
	unsigned year;
	unsigned month;
	unsigned day;
public:
	Date(const std::string &s) {
		// 找到第一个字母
		std::string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
		std::string digits = "0123456789";
		std::string::size_type pos;
		if ((pos = s.find_first_of(alpha, 0)) == std::string::npos) {
			// 1/1/1990 format
			pos = s.find_first_of(digits, 0);
			std::string::size_type next_pos = s.find_first_of('/', pos);
			std::string month_str(s, pos, next_pos - pos);
			month = stoi(month_str);
			pos = next_pos + 1;
			next_pos = s.find_first_of('/', pos);
			day = stoi(std::string(s, pos, next_pos - pos));
			pos = next_pos + 1;
			year = stoi(std::string(s, pos, s.size() - pos));
		} else {
			// Jan 1 1990 format or January 1, 1900 format
			std::string::size_type next_pos = s.find_first_of(' ', pos);
			std::string month_str = std::string(s, pos, next_pos - pos);
			// 获得月份
			if (month_str == "January" || month_str == "Jan")
				month = 1;
			else if (month_str == "February" || month_str == "Feb")
				month = 2;
			else if (month_str == "March" || month_str == "Mar")
				month = 3;
			else if (month_str == "April" || month_str == "Apr")
				month = 4;
			else if (month_str == "May")
				month = 5;
			else if (month_str == "June" || month_str == "Jun")
				month = 6;
			else if (month_str == "July" || month_str == "Jul")
				month = 7;
			else if (month_str == "August" || month_str == "Aug")
				month = 8;
			else if (month_str == "September" || month_str == "Sep")
				month = 9;
			else if (month_str == "October" || month_str == "Oct")
				month = 10;
			else if (month_str == "November" || month_str == "Nov")
				month = 11;
			else if (month_str == "December" || month_str == "Dec")
				month = 12;
			// 获得年和日
			pos = next_pos + 1;
			pos = s.find_first_of(digits, pos);
			next_pos = s.find_first_of(", ", pos);
			day = static_cast<unsigned>(stoi(std::string(s, pos, next_pos - pos)));
			pos = next_pos + 1;
			pos = s.find_first_of(digits, pos);
			next_pos = s.size();
			year = static_cast<unsigned>(stoi(std::string(s, pos, next_pos - pos)));
		}
	}
};
