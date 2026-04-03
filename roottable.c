#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {

    int start, stop, step;
    int num;
    float result;

    if (argc == 4) {

        sscanf(argv[1], "%d", &start);
        sscanf(argv[2], "%d", &stop);
        sscanf(argv[3], "%d", &step);

        // Valid increasing loop
        if (start <= stop && step > 0) {
            for (num = start; num <= stop; num += step) {
                if (num < 0) {
                    result = sqrtf((float)abs(num));
                    printf("%d\t%.2fi\n", num, result);
                } else {
                    result = sqrtf((float)num);
                    printf("%d\t%.2f\n", num, result);
                }
            }
        }
        // Valid decreasing loop
        else if (start >= stop && step < 0) {
            for (num = start; num >= stop; num += step) {
                if (num < 0) {
                    result = sqrtf((float)abs(num));
                    printf("%d\t%.2fi\n", num, result);
                } else {
                    result = sqrtf((float)num);
                    printf("%d\t%.2f\n", num, result);
                }
            }
        }
        // Invalid loop
        else {
            printf("Error: start, stop and step do not produce valid loop\n");
        }

    } else {
        printf("Error: 3 numbers needed were not provided\n");
    }

    return 0;
}