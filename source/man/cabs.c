#include <stdio.h>
#include <complex.h>

int main(void)
{
    double complex x = 1 + 2 * I;

    double complex y = cabs(x);

    printf("Result: %f + %fi\n", creal(y), cimag(y));
}

