/*************************************************************************
    > File Name: MyDB.h
    > Author: SongLee
    > E-mail: lisong.shine@qq.com
    > Created Time: 2014年05月04日 星期日 23时25分50秒
    > Personal Blog: http://songlee24.github.io
 ************************************************************************/
#ifndef __MYBD_H__
#include<iostream>
#include<string>
#include<mysql/mysql.h>
using namespace std;

class MyDB
{
public:
	MyDB();
	~MyDB();
	bool initDB(string host, string user, string pwd, string db_name);  // 建立sql连接
	bool exeSQL(string sql);    // 执行sql语句
private:
	MYSQL *connection;  // 数据库连接实例
	MYSQL_RES *result;  // 根据sql命令得到的结果集
	MYSQL_ROW row;      // 数组名，指向结果中某行数据的首元素
};

#endif
