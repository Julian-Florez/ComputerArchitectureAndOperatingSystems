#include <stdio.h>

unsigned long long facto_i(unsigned long long n) {
    unsigned long long c = 1;
    for (int i = 1; i <= n; i++) {
        c *= i;
    }
    return c;
}