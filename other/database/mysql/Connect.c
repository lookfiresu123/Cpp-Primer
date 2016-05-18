#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

static char *host = "localhost";
static char *user = "root";
static char *password = "cs1992107123";
static char *dbname = "source";

unsigned int port = 3306;
static char *unix_socket = NULL;
unsigned int flag = 0;

int main() {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, host, user, password, dbname, port, unix_socket, flag)) {
        fprintf(stderr, "Error: %s [%d]\n",mysql_error(conn), mysql_errno(conn));
        exit(1);
    }
    printf("Connection Successful!\n\n");

    mysql_query(conn, "select * from Products");

    res = mysql_store_result(conn);

    while (row = mysql_fetch_row(res))
        printf("%s\t%s\t%s\t%s\n", row[0], row[1], row[2], row[3]);

    mysql_free_result(res);
    mysql_close(conn);
    return EXIT_SUCCESS;
}
