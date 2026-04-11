#include "complex.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void solve_complex(int a, int b, int c) {
    float x_real, x_img;

    x_real = -b / (2.0 * a);
    x_img = sqrt(abs(b*b - 4*a*c)) / (2 * a);

    printf("X = %f + %fi and %f - %fi\n", x_real, x_img, x_real, x_img);
}