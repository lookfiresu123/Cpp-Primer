#include <cstdarg>
#include <cstdio>

extern "C" {
    int getsum(int n, ...) {
        va_list ap;
        int cnt, sum = 0;

        va_start(ap, n);
        for (cnt = 0 ; cnt < n ; ++cnt)
            sum += va_arg(ap, int);
        va_end(ap);

        return sum;
    }


    int main() {
        int sum = getsum(5,1,2,3,4,5);
        printf("%d\n", sum);
        return 0;
    }
}
