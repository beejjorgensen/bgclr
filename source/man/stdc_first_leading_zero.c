#include <stdio.h>
#include <limits.h>
#include <stdbit.h>

int main(void)
{
    unsigned int value = UINT_MAX;
    unsigned int index = stdc_first_leading_zero_ui(value);

    printf("%u\n", index);

    unsigned long long value2 = UINT_MAX >> 2;
    auto index2 = stdc_first_leading_zero(value2);

    printf("%u\n", index2);
}
