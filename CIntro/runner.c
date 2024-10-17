#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "facto_i.c"
#include "facto_r.c"
#include <time.h>

void write_times_to_file(const char *filename, int factorial, double timei, double timer) {
    FILE *file = fopen(filename, "r+");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[256];
    char new_content[1024] = "";
    int found = 0;

    while (fgets(line, sizeof(line), file)) {
        int current_factorial;
        double python_timei, python_timer;
        sscanf(line, "%d, %lf, %lf", &current_factorial, &python_timei, &python_timer);

        if (current_factorial == factorial) {
            sprintf(line, "%d, %lf, %lf, %lf, %lf\n", factorial, python_timei, python_timer, timei, timer);
            found = 1;
        }
        strcat(new_content, line);
    }

    if (!found) {
        sprintf(line, "%d, 0, 0, %lf, %lf\n", factorial, timei, timer);
        strcat(new_content, line);
    }

    freopen(filename, "w", file);
    fputs(new_content, file);
    fclose(file);
}

int main() {
    for (int i = 1; i < 21; i++) {
        clock_t starti = clock();
        for (int j = 0; j < 10000000; j++) {
            facto_r(i);
        }
        clock_t endi = clock();
        double timei = (double)(endi - starti) / CLOCKS_PER_SEC;

        clock_t startr = clock();
        for (int j = 0; j < 10000000; j++) {
            facto_i(i);
        }
        clock_t endr = clock();
        double timer = (double)(endr - startr) / CLOCKS_PER_SEC;

        write_times_to_file("time.txt", i, timei, timer);
    }
    return 0;
}