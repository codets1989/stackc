#include <stdio.h>
#include <math.h>


int square(int n);          
int cube(int n);            
float squareRoot(int n);   

int main(void)
{
    int i;
    for (i = 1; i <= 10; i++)
    {
        printf("%5d %8d %8d %12.2f\n",
               i,
               square(i),
               cube(i),
               squareRoot(i));
    }

    return 0;
}



int square(int n)
{
    return n * n;
}


int cube(int n)
{
    return (int)pow(n, 3);
}


float squareRoot(int n)
{
    return sqrt(n);
}
