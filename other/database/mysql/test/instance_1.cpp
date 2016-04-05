#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
#include <memory>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cctype>
#include <string>

#define TEST_CONNECTION_TO_MYSQL 1
#define TEST_PREPARED_STATEMENT 1

void print_result_set(std::unique_ptr<sql::ResultSet> &res) {
    while (res->next()) {       // 循环输出每一列
        std::cout << "stu_num = " << res->getString("stu_num") << " | ";
        std::cout << "stu_name = " << res->getString("stu_name") << " | ";
        std::cout << "stu_age = " << res->getString("stu_age") << " | ";
        std::cout << "stu_grade = " << res->getString("stu_grade") << " | ";
        std::cout << "stu_score = " << res->getString("stu_score") << std::endl;
    }
}

class Exception_1 {};
class Exception_2 {};

int test_prepared_statement(std::unique_ptr<sql::Connection> &con_ptr) {
    std::unique_ptr<sql::PreparedStatement> pstmt(con_ptr->prepareStatement("update student_info set ? = ? where stu_name = \'ChenSu\'"));
    std::string word;
    std::string value_str;
    int value_int;
    std::vector<std::string> words = {"stu_num","stu_name","stu_age","stu_grade","stu_score"};
    std::vector<std::string> words_str = {"stu_num","stu_name","stu_grade"};
    std::vector<std::string> words_int = {"stu_age","stu_score"};
    std::cin >> word;
    try {
        if (std::find(words.begin(), words.end(), word) == words.end())
            throw Exception_1();
    } catch (Exception_1) {
        std::cout << "attribute out of range" << std::endl;
        exit(0);
    }
    if (std::find(words_str.begin(), words_str.end(), word) != words_str.end()) {
        std::cin >> value_str;
        unsigned int pos = static_cast<unsigned int>(std::find(words.begin(), words.end(), word) - words.begin());
        pstmt->setString(pos, value_str);
        pstmt->executeUpdate();
    } else if (std::find(words_int.begin(), words_int.end(), word) != words_int.end()) {
        std::cin >> value_int;
        unsigned int pos = static_cast<unsigned int>(std::find(words.begin(), words.end(), word) - words.begin());
        pstmt->setInt(pos, value_int);
        pstmt->executeUpdate();
    }
    return 0;
}

int test_connection_to_mysql() {
    sql::Driver *driver_ptr(get_driver_instance());
    try {
        if (driver_ptr == nullptr)
            throw Exception_1();
    } catch (Exception_1) {
        std::cout << "error during getting driver instance !" << std::endl;
        exit(0);
    }
    std::unique_ptr<sql::Connection> con_ptr(driver_ptr->connect("localhost", "root", "cs1992107123"));
    con_ptr->setSchema("student");
    std::unique_ptr<sql::Statement> stmt_ptr(con_ptr->createStatement());
    std::unique_ptr<sql::ResultSet> res1(stmt_ptr->executeQuery("select * from student_info"));
    print_result_set(res1);
    test_prepared_statement(con_ptr);
    std::unique_ptr<sql::ResultSet> res2(stmt_ptr->executeQuery("select * from student_info"));
    print_result_set(res2);
    return 0;
}

int main() {
#if TEST_CONNECTION_TO_MYSQL
    test_connection_to_mysql();
#endif
    return 0;
}
