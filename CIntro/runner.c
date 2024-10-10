#include <stdio.h>
#include "facto_i.c"
#include "facto_r.c"
#include <time.h>

int main(){
    for(int i = 1; i < 21; i++){
        clock_t starti = clock();
        for(int j = 0; j < 10000000; j++){
            facto_r(i);
        }
        clock_t endi = clock();
        double timei = (double)(endi - starti) / CLOCKS_PER_SEC;
        clock_t startr = clock();
        for(int j = 0; j < 10000000; j++){
            facto_i(i);
        }
        clock_t endr = clock();
        double timer = (double)(endr - startr) / CLOCKS_PER_SEC;
        printf("%f,  %f\n", timei, timer);
    }
    return 0;
}