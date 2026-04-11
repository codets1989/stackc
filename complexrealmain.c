#include <stdio.h>
#include "linear.h"
#include "quad.h"

// fs
// Computer Programming II
// Calculate the solution of a quadratic equation
// Command Line Argument
// /stdout

int main(int argc, char *argv[]) {
    int a, b, c;

    if (argc == 4) {
        sscanf(argv[1], "%d", &a); // Scanning the arguments and assigning them
        sscanf(argv[2], "%d", &b);
        sscanf(argv[3], "%d", &c);

        if (a == 0) {
            if (b == 0)
                printf("Error! Degenerate Equation error\n");
            else
                solve_linear(b, c);
        } else {
            solve_quad(a, b, c);
        }
    } else {
        printf("Error! Need to provide 3 coefficents on command line");
    }

    return 0;
}