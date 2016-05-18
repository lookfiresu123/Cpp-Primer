#include <iostream>
#include <string>
#include <mysql/mysql.h>

using namespace std;

// configure information
class MySQL_Config {
public:
    string host;
    string user;
    string password;
    string dbname;
    unsigned int port = 3306;
    string unix_socket;
    unsigned int flag = 0;
    MySQL_Config() = default;
    virtual ~MySQL_Config() { }
    void setConfig(const string &_host, const string &_user, const string &_password, const string &_dbname, unsigned int _port, const string &_unix_socket, unsigned int _flag) {
        host = _host;
        user = _user;
        password = _password;
        dbname = _dbname;
        port = _port;
        unix_socket = _unix_socket;
        flag = _flag;
    }
};

// important member variable
class MySQL_Base {
public:
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    MySQL_Base(MYSQL *_conn, MYSQL_RES *_res, MYSQL_ROW _row) :
        conn(_conn), res(_res), row(_row) { }
    virtual ~MySQL_Base() { }
};

class MySQL : public MySQL_Base, public MySQL_Config {
public:
    MySQL() : MySQL_Base(NULL, NULL, NULL), MySQL_Config() { }
    ~MySQL() { }
    void Init();
    void Query(const string &cmd, unsigned int col_sz);
    void Connect(const string &_host, const string &_user, const string &_password, const string &_dbname, unsigned int _port, const string &_unix_socket, unsigned int _flag);
    void Close();
    const char *string_to_cstr(const string &str);
};

void MySQL::Init() {
    conn = mysql_init(NULL);
}

void MySQL::Connect(const string &_host, const string &_user, const string &_password, const string &_dbname, unsigned int _port, const string &_unix_socket, unsigned int _flag) {
    setConfig(_host, _user, _password, _dbname, _port, _unix_socket, _flag);
    const char *host_cstr = string_to_cstr(host);
    const char *user_cstr = string_to_cstr(user);
    const char *password_cstr = string_to_cstr(password);
    const char *dbname_cstr = string_to_cstr(dbname);
    const char *unix_socket_cstr = string_to_cstr(unix_socket);
    if (!mysql_real_connect(conn, host_cstr, user_cstr, password_cstr, dbname_cstr, port, unix_socket_cstr, flag)) {
        cout << "Error: " << string(mysql_error(conn)) << " [" << mysql_errno(conn) << "]" << endl;
        exit(1);
    }
    cout << "Connection Successful!" << endl;
}

void MySQL::Query(const string &cmd, unsigned int col_sz) {
    mysql_query(conn, cmd.c_str());
    res = mysql_store_result(conn);
    while (row = mysql_fetch_row(res)) {
        for (unsigned int i = 0 ; i < col_sz ; ++i)
            cout << row[i] << " ";
        cout << endl;
    }
    mysql_free_result(res);
}

void MySQL::Close() {
    mysql_close(conn);
    cout << "Exit Successful!" << endl;
}

const char *MySQL::string_to_cstr(const string &str) {
    if (str.empty())
        return NULL;
    return str.c_str();
}

int main() {
    MySQL mysql;
    mysql.Init();
    mysql.Connect("localhost", "root", "cs1992107123", "source", 3306, "", 0);
    mysql.Query("select * from Products", 4);
    mysql.Close();
    return 0;
}
