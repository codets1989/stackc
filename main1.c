#include <stdio.h>
#include <string.h>
#include "rpn.h"

int main(void)  {
    char string_input[101];
    printf("Enter an RPN expression : ");
    gets(string_input);
    printf("%f \n",rpneval(string_input));
    return 0;
}