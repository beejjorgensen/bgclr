#include <stdio.h>
#include <stdbit.h>

int main(void)
{
    switch(__STDC_ENDIAN_NATIVE__) {
        case __STDC_ENDIAN_BIG__:
            puts("Big-endian!");
            break;

        case __STDC_ENDIAN_LITTLE__:
            puts("Little-endian!");
            break;

        default:
            puts("Other-endian!");
    }
}
