#include "linear.h"
#include <stdio.h>

void solve_linear(int b, int c) {
    float x;
    x = -c / (float)b;
    printf("X is %f\n", x);
}