#include <stdio.h>
#include <stdbit.h>

int main(void)
{
    unsigned int value = 3490;
    unsigned int count = stdc_leading_zeros_ui(value);

    printf("%d\n", count);

    unsigned long long value2 = 3490;
    auto count2 = stdc_leading_zeros(value2);

    printf("%d\n", count2);
}
