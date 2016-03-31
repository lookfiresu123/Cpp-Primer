/*************************************************************************
    > File Name: MyDB.cpp
    > Author: SongLee
    > E-mail: lisong.shine@qq.com
    > Created Time: 2014年05月04日 星期日 23时37分08秒
    > Personal Blog: http://songlee24.github.io
 ************************************************************************/
#include<iostream>
#include<cstdlib>
#include "MyDB.h"
using namespace std;

MyDB::MyDB()
{
	connection = mysql_init(NULL); // 初始化数据库连接变量
	if(connection == NULL)
	{
		cout << "Error:" << mysql_error(connection);
		exit(1);
	}
}

MyDB::~MyDB()
{
	if(connection != NULL)  // 关闭数据库连接
	{
		mysql_close(connection);
	}
}

bool MyDB::initDB(string host, string user, string pwd, string db_name)
{
	// 函数mysql_real_connect建立一个数据库连接
	// 成功返回MYSQL*连接句柄，失败返回NULL
	connection = mysql_real_connect(connection, host.c_str(),
			user.c_str(), pwd.c_str(), db_name.c_str(), 0, NULL, 0);
	if(connection == NULL)
	{
		cout << "Error:" << mysql_error(connection);
		exit(1);
	}
	return true;
}

bool MyDB::exeSQL(string sql)
{
	// mysql_query()执行成功返回0，失败返回非0值。与PHP中不一样
	if(mysql_query(connection, sql.c_str()))
	{
		cout << "Query Error:" << mysql_error(connection);
		exit(1);
	}
	else
	{
		result = mysql_use_result(connection); // 获取结果集
		// mysql_field_count()返回connection查询的行数，即*(result->field_count)
		for(unsigned i=0; i < mysql_field_count(connection); ++i)
		{
			// 获取下一行
			row = mysql_fetch_row(result);      // row为数组，表示一行
			if(row <= 0)
			{
				break;
			}
			// mysql_num_fields()返回结果集中的字段数
			for(unsigned j=0; j < mysql_num_fields(result); ++j)
			{
				cout << row[j] << " ";
			}
			cout << endl;
		}
		// 释放结果集的内存
		mysql_free_result(result);
	}
	return true;
}

int main()
{
    MyDB db;
    db.initDB("localhost", "root", "cs1992107123", "student");
    // db.exeSQL("insert into student_info values(\"U201002031\", \"LvTengfei\", 23, \"0704\", 78)");
    // db.exeSQL("insert into student_info values(\"U201001907\", \"LvTengfei\", 24, \"0901\", 88)");
    // db.exeSQL("delete from student_info where stu_num = \"U201002031\"");
    db.exeSQL("select * from student_info");
    // db.exeSQL("select * from student_info group by stu_name");
    return 0;
}
