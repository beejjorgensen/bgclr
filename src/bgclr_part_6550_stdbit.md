<!-- Beej's guide to C

# vim: ts=4:sw=4:nosi:et:tw=72
-->

# `<stdbit.h>` Bit-Related Functions {#stdbit}

[i[`stdbit.h` header file]i]

This header file and all the included functions are new in C23!

Caveat: none of my compilers support this, so all the code is untested!

|Function|Description|
|-------------------------|------------------------------------------|
|[`stdc_bit_ceil()`](#man-stdc_bit_ceil)|Return the smallest power of 2 not less than a number|
|[`stdc_bit_floor()`](#man-stdc_bit_floor)|Return the largest power of 2 not greater than a number|
|[`stdc_bit_width()`](#man-stdc_bit_width)|Return the number of bits needed to store a value|
|[`stdc_count_ones()`](#man-stdc_count_ones)|Count the ones in an unsigned number|
|[`stdc_count_zeros()`](#man-stdc_count_zeros)|Count the zeros in an unsigned number|
|[`stdc_first_leading_one()`](#man-stdc_first_leading_one)|Find the first leading one in an unsigned number|
|[`stdc_first_leading_zero()`](#man-stdc_first_leading_zero)|Find the first leading zero in an unsigned number|
|[`stdc_first_trailing_one()`](#man-stdc_first_trailing_one)|Find the first trailing one in an unsigned number|
|[`stdc_first_trailing_zero()`](#man-stdc_first_trailing_zero)|Find the first trailing zero in an unsigned number|
|[`stdc_has_single_bit()`](#man-stdc_has_single_bit)|Test to see if an unsigned integer has only a single bit set|
|[`stdc_leading_ones()`](#man-stdc_leading_ones)|Count the leading ones in an unsigned number|
|[`stdc_leading_zeros()`](#man-stdc_leading_zeros)|Count the leading zeros in an unsigned number|
|[`stdc_trailing_ones()`](#man-stdc_trailing_ones)|Count the trailing ones in an unsigned number|
|[`stdc_trailing_zeros()`](#man-stdc_trailing_zeros)|Count the trailing zeros in an unsigned number|

## Existence Macro

Since this is a new feature, you can test for its existence by making
sure the `__STDC_VERSION_STDBIT_H__` [i[`__STDC_VERSION_STDBIT_H__`
macro]] macro exists and is `202311L` or greater.

## Endianess Macros {#endianess-macros}

[i[Endianess]<]
[i[`__STDC_ENDIAN_NATIVE__` macro]<]
[i[`__STDC_ENDIAN_BIG__` macro]<]
[i[`__STDC_ENDIAN_LITTLE__` macro]<]

This header file defines a number of macros that can be used to
determine the _endianess_ of the system. (That is, in a multibyte value,
do the first byte represent the most significant part of the value, or
least? Or neither?)

There are two different values for the defined endianesses
`__STDC_ENDIAN_BIG__` and `__STDC_ENDIAN_LITTLE__`.

Additionally, there's a macro `__STDC_ENDIAN_NATIVE__` that gives you
the endianess of _this_ system. You can compare that against the other
two macros to see what you've got. If it doesn't compare equal to either
of them, you must be on some other mixed-endian system.

Let's see what this system is:

``` {.c}
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
```
[i[Endianess]>]
[i[`__STDC_ENDIAN_NATIVE__` macro]>]
[i[`__STDC_ENDIAN_BIG__` macro]>]
[i[`__STDC_ENDIAN_LITTLE__` macro]>]

## General Structure of These Functions

All the functions in this header follow a standard pattern, so we might
as well go over it once here up-front to save extraneous and excessive
verbosity later.

Each function comes in six amazing forms, depending on the types
involved.

First of all, they're just going to operate on unsigned integer types,
so we'll get that out of the way.

And they're _mostly_ going to return `unsigned int`.

And they come in two subforms: the type-specific and type-generic forms.

Let's look at the type specific forms first. We'll use the function that
counts the leading zero bits in a value as an example. Here it is:

``` {.c}
unsigned int stdc_leading_zeros_uc(unsigned char value);
unsigned int stdc_leading_zeros_us(unsigned short value);
unsigned int stdc_leading_zeros_ui(unsigned int value);
unsigned int stdc_leading_zeros_ul(unsigned long value);
unsigned int stdc_leading_zeros_ull(unsigned long long value);
```

Yikes. OK, what do we have?

Well, in order to prevent namespace pollution, they all start with
`stdc_`.

And what about this `uc`, `us`, `ull`, etc. stuff? Those correspond to
the type of the argument, you'll see with a little inspection.

|Suffix|Parameter Type|
|-|-|
|`_uc`|`unsigned char`|
|`_us`|`unsigned short`|
|`_ui`|`unsigned int`|
|`_ul`|`unsigned long`|
|`_ull`|`unsigned long long`|

But wait! There's more!

Each of these function families in the header also has a _generic_
variant.

So, again with `count_leading_zeros` as an example, there's a version
that doesn't need types to be specified, and it's just the function
without any suffix.

``` {.c}
generic_return_type stdc_leading_zeros(generic_value_type value);
```

In that example, the words `generic_return_type` and
`generic_value_type` are **not** C keywords. They're just placeholders
to let you know you need to put the right thing there.

``` {.c}
unsigned short x = 3490;

unsigned int a = stdc_leading_zeros(x);
auto b = stdc_leading_zeros(1234);
```

The generic functions work with all unsigned types, not counting `bool`.

[[manbreak]]
## `stdc_leading_zeros()` {#man-stdc_leading_zeros}

[i[`stdc_leading_zeros()` function]i]

Count the leading zeros in an unsigned number

### Synopsis {.unnumbered .unlisted}

New in C23!

``` {.c}
#include <stdbit.h>

unsigned int stdc_leading_zeros_uc(unsigned char value);
unsigned int stdc_leading_zeros_us(unsigned short value);
unsigned int stdc_leading_zeros_ui(unsigned int value);
unsigned int stdc_leading_zeros_ul(unsigned long value);
unsigned int stdc_leading_zeros_ull(unsigned long long value);

generic_return_type stdc_leading_zeros(generic_value_type value);
```

### Description {.unnumbered .unlisted}

This function returns the number of leading zero bits on a particular
value, starting from the most-significant bit. The number will be
influenced by the size of the argument.

### Return Value {.unnumbered .unlisted}

Returns the number of leading zero bits.

### Example {.unnumbered .unlisted}

``` {.c .numberLines}
#include <stdio.h>
#include <stdbit.h>

int main(void)
{
    unsigned int value = 3490;
    unsigned int count = stdc_leading_zeros_ui(value);

    printf("%u\n", count);

    unsigned long long value2 = 3490;
    auto count2 = stdc_leading_zeros(value2);

    printf("%u\n", count2);
}
```

### See Also {.unnumbered .unlisted}

[`stdc_leading_ones()`](#man-stdc_leading_ones),
[`stdc_trailing_zeros()`](#man-stdc_trailing_zeros)

[[manbreak]]
## `stdc_leading_ones()` {#man-stdc_leading_ones}

[i[`stdc_leading_ones()` function]i]

Count the leading ones in an unsigned number

### Synopsis {.unnumbered .unlisted}

New in C23!

``` {.c}
#include <stdbit.h>

unsigned int stdc_leading_ones_uc(unsigned char value);
unsigned int stdc_leading_ones_us(unsigned short value);
unsigned int stdc_leading_ones_ui(unsigned int value);
unsigned int stdc_leading_ones_ul(unsigned long value);
unsigned int stdc_leading_ones_ull(unsigned long long value);

generic_return_type stdc_leading_ones(generic_value_type value);
```

### Description {.unnumbered .unlisted}

This function returns the number of leading one bits on a particular
value starting from the most-significant bit. The number will be
influenced by the size of the argument.

### Return Value {.unnumbered .unlisted}

Returns the number of leading one bits.

### Example {.unnumbered .unlisted}

``` {.c .numberLines}
#include <stdio.h>
#include <stdbit.h>

int main(void)
{
    unsigned int value = 3490;
    unsigned int count = stdc_leading_ones_ui(value);

    printf("%u\n", count);

    unsigned long long value2 = 3490;
    auto count2 = stdc_leading_ones(value2);

    printf("%u\n", count2);
}
```

### See Also {.unnumbered .unlisted}

[`stdc_leading_zeros()`](#man-stdc_leading_zeros),
[`stdc_trailing_ones()`](#man-stdc_trailing_ones)

[[manbreak]]
## `stdc_trailing_zeros()` {#man-stdc_trailing_zeros}

[i[`stdc_trailing_zeros()` function]i]

Count the trailing zeros in an unsigned number

### Synopsis {.unnumbered .unlisted}

New in C23!

``` {.c}
#include <stdbit.h>

unsigned int stdc_trailing_zeros_uc(unsigned char value);
unsigned int stdc_trailing_zeros_us(unsigned short value);
unsigned int stdc_trailing_zeros_ui(unsigned int value);
unsigned int stdc_trailing_zeros_ul(unsigned long value);
unsigned int stdc_trailing_zeros_ull(unsigned long long value);

generic_return_type stdc_trailing_zeros(generic_value_type value);
```

### Description {.unnumbered .unlisted}

This function returns the number of trailing zero bits on a particular
value, starting from the least-significant bit. The number will be
influenced by the size of the argument.

### Return Value {.unnumbered .unlisted}

Returns the number of trailing zero bits.

### Example {.unnumbered .unlisted}

``` {.c .numberLines}
#include <stdio.h>
#include <stdbit.h>

int main(void)
{
    unsigned int value = 3490;
    unsigned int count = stdc_trailing_zeros_ui(value);

    printf("%u\n", count);

    unsigned long long value2 = 3490;
    auto count2 = stdc_trailing_zeros(value2);

    printf("%u\n", count2);
}
```

### See Also {.unnumbered .unlisted}

[`stdc_trailing_ones()`](#man-stdc_trailing_ones),
[`stdc_leading_zeros()`](#man-stdc_leading_zeros)

[[manbreak]]
## `stdc_trailing_ones()` {#man-stdc_trailing_ones}

[i[`stdc_trailing_ones()` function]i]

Count the trailing ones in an unsigned number

### Synopsis {.unnumbered .unlisted}

New in C23!

``` {.c}
#include <stdbit.h>

unsigned int stdc_trailing_ones_uc(unsigned char value);
unsigned int stdc_trailing_ones_us(unsigned short value);
unsigned int stdc_trailing_ones_ui(unsigned int value);
unsigned int stdc_trailing_ones_ul(unsigned long value);
unsigned int stdc_trailing_ones_ull(unsigned long long value);

generic_return_type stdc_trailing_ones(generic_value_type value);
```

### Description {.unnumbered .unlisted}

This function returns the number of trailing one bits on a particular
value, starting from the least-significant bit. The number will be
influenced by the size of the argument.

### Return Value {.unnumbered .unlisted}

Returns the number of trailing one bits.

### Example {.unnumbered .unlisted}

``` {.c .numberLines}
#include <stdio.h>
#include <stdbit.h>

int main(void)
{
    unsigned int value = 3490;
    unsigned int count = stdc_trailing_ones_ui(value);

    printf("%u\n", count);

    unsigned long long value2 = 3490;
    auto count2 = stdc_trailing_ones(value2);

    printf("%u\n", count2);
}
```

### See Also {.unnumbered .unlisted}

[`stdc_trailing_zeros()`](#man-stdc_trailing_zeros),
[`stdc_leading_ones()`](#man-stdc_leading_ones)

[[manbreak]]
## `stdc_first_leading_zero()` {#man-stdc_first_leading_zero}

[i[`stdc_first_leading_zero()` function]i]

Find the first leading zero in an unsigned number

### Synopsis {.unnumbered .unlisted}

New in C23!

``` {.c}
#include <stdbit.h>

unsigned int stdc_first_leading_zero_uc(unsigned char value);
unsigned int stdc_first_leading_zero_us(unsigned short value);
unsigned int stdc_first_leading_zero_ui(unsigned int value);
unsigned int stdc_first_leading_zero_ul(unsigned long value);
unsigned int stdc_first_leading_zero_ull(unsigned long long value);

generic_return_type stdc_first_leading_zero(generic_value_type value);
```

### Description {.unnumbered .unlisted}

This finds the index of the first leading zero in a number. Indexes are
numbered starting from `1` being the most significant ("leftmost") bit
position. (This might be in contrast to how you might be used to
numbering bit indexes.)

It's one-based so that you can quickly use the return value as a
Boolean expression for if it found a zero bit or not.

### Return Value {.unnumbered .unlisted}

Returns the 1-based index from the most significant bit of the first
zero bit in the `value`, or `0` if there are no zero bits.

### Example {.unnumbered .unlisted}

``` {.c .numberLines}
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
```

### See Also {.unnumbered .unlisted}

[`stdc_first_leading_one()`](#man-stdc_first_leading_one),
[`stdc_first_trailing_zero()`](#man-stdc_first_trailing_zero)

[[manbreak]]
## `stdc_first_leading_one()` {#man-stdc_first_leading_one}

[i[`stdc_first_leading_one()` function]i]

Find the first leading one in an unsigned number

### Synopsis {.unnumbered .unlisted}

New in C23!

``` {.c}
#include <stdbit.h>

unsigned int stdc_first_leading_one_uc(unsigned char value);
unsigned int stdc_first_leading_one_us(unsigned short value);
unsigned int stdc_first_leading_one_ui(unsigned int value);
unsigned int stdc_first_leading_one_ul(unsigned long value);
unsigned int stdc_first_leading_one_ull(unsigned long long value);

generic_return_type stdc_first_leading_one(generic_value_type value);
```

### Description {.unnumbered .unlisted}

This finds the index of the first leading one in a number. Indexes are
numbered starting from `1` being the most significant ("leftmost") bit
position. (This might be in contrast to how you might be used to
numbering bit indexes.)

It's one-based so that you can quickly use the return value as a
Boolean expression for if it found a one bit or not.

### Return Value {.unnumbered .unlisted}

Returns the 1-based index from the most significant bit of the first
one bit in the `value`, or `0` if there are no one bits.

### Example {.unnumbered .unlisted}

``` {.c .numberLines}
#include <stdio.h>
#include <limits.h>
#include <stdbit.h>

int main(void)
{
    unsigned int value = UINT_MAX;
    unsigned int index = stdc_first_leading_one_ui(value);

    printf("%u\n", index);

    unsigned long long value2 = UINT_MAX >> 2;
    auto index2 = stdc_first_leading_one(value2);

    printf("%u\n", index2);
}
```

### See Also {.unnumbered .unlisted}

[`stdc_first_leading_zero()`](#man-stdc_first_leading_zero),
[`stdc_first_trailing_one()`](#man-stdc_first_trailing_one)

[[manbreak]]
## `stdc_first_trailing_zero()` {#man-stdc_first_trailing_zero}

[i[`stdc_first_trailing_zero()` function]i]

Find the first trailing zero in an unsigned number

### Synopsis {.unnumbered .unlisted}

New in C23!

``` {.c}
#include <stdbit.h>

unsigned int stdc_first_trailing_zero_uc(unsigned char value);
unsigned int stdc_first_trailing_zero_us(unsigned short value);
unsigned int stdc_first_trailing_zero_ui(unsigned int value);
unsigned int stdc_first_trailing_zero_ul(unsigned long value);
unsigned int stdc_first_trailing_zero_ull(unsigned long long value);

generic_return_type stdc_first_trailing_zero(generic_value_type value);
```

### Description {.unnumbered .unlisted}

This finds the index of the first trailing zero in a number. Indexes are
numbered starting from `1` being the most significant ("leftmost") bit
position. (This might be in contrast to how you might be used to
numbering bit indexes.)

It's one-based so that you can quickly use the return value as a
Boolean expression for if it found a zero bit or not.

### Return Value {.unnumbered .unlisted}

Returns the 1-based index from the most significant bit of the first
zero bit in the `value`, or `0` if there are no zero bits.

### Example {.unnumbered .unlisted}

``` {.c .numberLines}
#include <stdio.h>
#include <limits.h>
#include <stdbit.h>

int main(void)
{
    unsigned int value = UINT_MAX;
    unsigned int index = stdc_first_trailing_zero_ui(value);

    printf("%u\n", index);

    unsigned long long value2 = UINT_MAX >> 2;
    auto index2 = stdc_first_trailing_zero(value2);

    printf("%u\n", index2);
}
```

### See Also {.unnumbered .unlisted}

[`stdc_first_leading_zero()`](#man-stdc_first_leading_zero),
[`stdc_first_trailing_one()`](#man-stdc_first_trailing_one)

[[manbreak]]
## `stdc_first_trailing_one()` {#man-stdc_first_trailing_one}

[i[`stdc_first_trailing_one()` function]i]

Find the first trailing one in an unsigned number

### Synopsis {.unnumbered .unlisted}

New in C23!

``` {.c}
#include <stdbit.h>

unsigned int stdc_first_trailing_one_uc(unsigned char value);
unsigned int stdc_first_trailing_one_us(unsigned short value);
unsigned int stdc_first_trailing_one_ui(unsigned int value);
unsigned int stdc_first_trailing_one_ul(unsigned long value);
unsigned int stdc_first_trailing_one_ull(unsigned long long value);

generic_return_type stdc_first_trailing_one(generic_value_type value);
```

### Description {.unnumbered .unlisted}

This finds the index of the first trailing one in a number. Indexes are
numbered starting from `1` being the most significant ("leftmost") bit
position. (This might be in contrast to how you might be used to
numbering bit indexes.)

It's one-based so that you can quickly use the return value as a
Boolean expression for if it found a one bit or not.

### Return Value {.unnumbered .unlisted}

Returns the 1-based index from the most significant bit of the first
one bit in the `value`, or `0` if there are no one bits.

### Example {.unnumbered .unlisted}

``` {.c .numberLines}
#include <stdio.h>
#include <limits.h>
#include <stdbit.h>

int main(void)
{
    unsigned int value = UINT_MAX;
    unsigned int index = stdc_first_trailing_one_ui(value);

    printf("%u\n", index);

    unsigned long long value2 = UINT_MAX >> 2;
    auto index2 = stdc_first_trailing_one(value2);

    printf("%u\n", index2);
}
```

### See Also {.unnumbered .unlisted}

[`stdc_first_leading_one()`](#man-stdc_first_leading_one),
[`stdc_first_trailing_zero()`](#man-stdc_first_trailing_zero)

[[manbreak]]
## `stdc_count_zeros()` {#man-stdc_count_zeros}

[i[`stdc_count_zeros()` function]i]

Count the zeros in an unsigned number

### Synopsis {.unnumbered .unlisted}

New in C23!

``` {.c}
#include <stdbit.h>

unsigned int stdc_count_zeros_uc(unsigned char value);
unsigned int stdc_count_zeros_us(unsigned short value);
unsigned int stdc_count_zeros_ui(unsigned int value);
unsigned int stdc_count_zeros_ul(unsigned long value);
unsigned int stdc_count_zeros_ull(unsigned long long value);

generic_return_type stdc_count_zeros(generic_value_type value);
```

### Description {.unnumbered .unlisted}

This function returns the number of zero bits in a particular value. The
number will be influenced by the size of the argument.

### Return Value {.unnumbered .unlisted}

Returns the number of zero bits.

### Example {.unnumbered .unlisted}

``` {.c .numberLines}
#include <stdio.h>
#include <stdbit.h>

int main(void)
{
    unsigned int value = 3490;
    unsigned int count = stdc_count_zeros_ui(value);

    printf("%u\n", count);

    unsigned long long value2 = 123456;
    auto count2 = stdc_count_zeros(value2);

    printf("%u\n", count2);
}
```

### See Also {.unnumbered .unlisted}

[`stdc_count_ones()()`](#man-stdc_count_ones),
[`stdc_leading_zeros()()`](#man-stdc_leading_zeros),
[`stdc_trailing_zeros()()`](#man-stdc_trailing_zeros)

[[manbreak]]
## `stdc_count_ones()` {#man-stdc_count_ones}

[i[`stdc_count_ones()` function]i]

Count the ones in an unsigned number

### Synopsis {.unnumbered .unlisted}

New in C23!

``` {.c}
#include <stdbit.h>

unsigned int stdc_count_ones_uc(unsigned char value);
unsigned int stdc_count_ones_us(unsigned short value);
unsigned int stdc_count_ones_ui(unsigned int value);
unsigned int stdc_count_ones_ul(unsigned long value);
unsigned int stdc_count_ones_ull(unsigned long long value);

generic_return_type stdc_count_ones(generic_value_type value);
```

### Description {.unnumbered .unlisted}

This function returns the number of one bits in a particular value. The
number will be influenced by the size of the argument.

### Return Value {.unnumbered .unlisted}

Returns the number of one bits.

### Example {.unnumbered .unlisted}

``` {.c .numberLines}
#include <stdio.h>
#include <stdbit.h>

int main(void)
{
    unsigned int value = 3490;
    unsigned int count = stdc_count_ones_ui(value);

    printf("%u\n", count);

    unsigned long long value2 = 123456;
    auto count2 = stdc_count_ones(value2);

    printf("%u\n", count2);
}
```

### See Also {.unnumbered .unlisted}

[`stdc_count_zeros()()`](#man-stdc_count_zeros),
[`stdc_leading_ones()()`](#man-stdc_leading_ones),
[`stdc_trailing_ones()()`](#man-stdc_trailing_ones)


[[manbreak]]
## `stdc_has_single_bit()` {#man-stdc_has_single_bit}

[i[`stdc_has_single_bit()` function]i]

Test to see if an unsigned integer has only a single bit set

### Synopsis {.unnumbered .unlisted}

New in C23!

``` {.c}
#include <stdbit.h>

bool stdc_has_single_bit_uc(unsigned char value);
bool stdc_has_single_bit_us(unsigned short value);
bool stdc_has_single_bit_ui(unsigned int value);
bool stdc_has_single_bit_ul(unsigned long value);
bool stdc_has_single_bit_ull(unsigned long long value);

bool stdc_has_single_bit(generic_value_type value);
```

### Description {.unnumbered .unlisted}

These functions return true if exactly one bit is `1` in an unsigned
`value`.

If true, it also means the `value` is a power of 2.

### Return Value {.unnumbered .unlisted}

Return true if `value` has exactly a single bit set to `1`.

### Example {.unnumbered .unlisted}

``` {.c .numberLines}
#include <stdio.h>
#include <stdbit.h>

int main(void)
{
    unsigned int value = 0b0001000;
    unsigned int result = stdc_has_single_bit_ui(value);

    printf("%d\n", result);    // 1

    unsigned long long value2 = 0b000011000
    auto result2 = stdc_has_single_bit(value2);

    printf("%d\n", result2);   // 0
}
```

<!--
### See Also {.unnumbered .unlisted}

[`example()`](#man-example),
-->

[[manbreak]]
## `stdc_bit_width()` {#man-stdc_bit_width}

[i[`stdc_bit_width()` function]i]

Return the number of bits needed to store a value

### Synopsis {.unnumbered .unlisted}

New in C23!

``` {.c}
#include <stdbit.h>

unsigned int stdc_bit_width_uc(unsigned char value);
unsigned int stdc_bit_width_us(unsigned short value);
unsigned int stdc_bit_width_ui(unsigned int value);
unsigned int stdc_bit_width_ul(unsigned long value);
unsigned int stdc_bit_width_ull(unsigned long long value);

generic_return_type stdc_bit_width(generic_value_type value);
```

### Description {.unnumbered .unlisted}

Given an unsigned integer value, what's the smallest number of bits
needed to store it? That's the question this function answers.

### Return Value {.unnumbered .unlisted}

Returns the number of bits needed to store a positive `value`. Returns
`0` if the `value` passed in is `0`.

### Example {.unnumbered .unlisted}

``` {.c .numberLines}
#include <stdio.h>
#include <stdbit.h>

int main(void)
{
    unsigned int value = 0b0001000;
    unsigned int result = stdc_bit_width_ui(value);

    printf("%d\n", result);    // 4

    unsigned long long value2 = 0b000011010
    auto result2 = stdc_bit_width(value2);

    printf("%d\n", result2);   // 5
}
```

<!--
### See Also {.unnumbered .unlisted}

[`example()`](#man-example),
-->

[[manbreak]]
## `stdc_bit_floor()` {#man-stdc_bit_floor}

[i[`stdc_bit_floor()` function]i]

Return the largest power of 2 not greater than a number

### Synopsis {.unnumbered .unlisted}

New in C23!

``` {.c}
#include <stdbit.h>

unsigned char stdc_bit_floor_uc(unsigned char value);
unsigned short stdc_bit_floor_us(unsigned short value);
unsigned int stdc_bit_floor_ui(unsigned int value);
unsigned long stdc_bit_floor_ul(unsigned long value);
unsigned long long stdc_bit_floor_ull(unsigned long long value);

generic_value_type stdc_bit_floor(generic_value_type value);
```

### Description {.unnumbered .unlisted}

This function returns the largest power of 2 that is not greater than
the `value`.

In other words "is less than or equal to" the `value`.

In other words, floor down to the nearest power of two.

In other words, return the value of the highest set bit in a number

For example:
|`value`|Return|
|-|-|
|`0b101`|`0b100`|
|`0b1000`|`0b1000`|
|`0b100101`|`0b100000`|

### Return Value {.unnumbered .unlisted}

Returns the largest power of 2 not greater than `value`. Returns `0` if
the `value` is `0`.

### Example {.unnumbered .unlisted}

``` {.c .numberLines}
#include <stdio.h>
#include <stdbit.h>

int main(void)
{
    unsigned int value = 0b0001000;
    unsigned int result = stdc_bit_floor_ui(value);

    printf("%b\n", result);    // 1000

    unsigned long long value2 = 0b000011010
    auto result2 = stdc_bit_floor(value2);

    printf("%b\n", result2);   // 10000
}
```

### See Also {.unnumbered .unlisted}

[`stdc_bit_ceil()`](#man-stdc_bit_ceil)

[[manbreak]]
## `stdc_bit_ceil()` {#man-stdc_bit_ceil}

[i[`stdc_bit_ceil()` function]i]

Return the smallest power of 2 not less than a number

### Synopsis {.unnumbered .unlisted}

New in C23!

``` {.c}
#include <stdbit.h>

unsigned char stdc_bit_ceil_uc(unsigned char value);
unsigned short stdc_bit_ceil_us(unsigned short value);
unsigned int stdc_bit_ceil_ui(unsigned int value);
unsigned long stdc_bit_ceil_ul(unsigned long value);
unsigned long long stdc_bit_ceil_ull(unsigned long long value);

generic_value_type stdc_bit_ceil(generic_value_type value);
```

### Description {.unnumbered .unlisted}

This function returns the smallest power of 2 that is not less than the
`value`.

In other words "is greater than or equal to" the `value`.

In other words, ceil up to the nearest power of two.

For example:
|`value`|Return|
|-|-|
|`0b101`|`0b1000`|
|`0b1000`|`0b1000`|
|`0b100101`|`0b1000000`|

If the result doesn't fit in the return type, the behavior is undefined.

### Return Value {.unnumbered .unlisted}

Returns the smallest power of 2 not less than `value`.

### Example {.unnumbered .unlisted}

``` {.c .numberLines}
#include <stdio.h>
#include <stdbit.h>

int main(void)
{
    unsigned int value = 0b0001000;
    unsigned int result = stdc_bit_ceil_ui(value);

    printf("%b\n", result);    // 1000

    unsigned long long value2 = 0b000011010
    auto result2 = stdc_bit_ceil(value2);

    printf("%b\n", result2);   // 100000
}
```

### See Also {.unnumbered .unlisted}

[`stdc_bit_floor()`](#man-stdc_bit_floor)

<!--
[[manbreak]]
## `example()` {#man-example}

[i[`example()` function]i]

### Synopsis {.unnumbered .unlisted}

New in C23!

``` {.c}
```

### Description {.unnumbered .unlisted}

### Return Value {.unnumbered .unlisted}

### Example {.unnumbered .unlisted}

``` {.c .numberLines}
```

### See Also {.unnumbered .unlisted}

[`example()`](#man-example),
-->
