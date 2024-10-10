#include <stdio.h>

unsigned long long facto_r(unsigned long long n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * facto_r(n - 1);
    }
}