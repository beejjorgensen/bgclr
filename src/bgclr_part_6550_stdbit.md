<!-- Beej's guide to C

# vim: ts=4:sw=4:nosi:et:tw=72
-->

# `<stdbit.h>` Bit-Related Functions {#stdbit}

[i[`stdbit.h` header file]i]

This header file and all the included functions are new in C23!

Caveat: none of my compilers support this, so all the code is untested!

|Function|Description|
|-|-|
|[`TODO()`](#TODO)|TODO|

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

[[manbreak]]
## `stdc_leading_zeros()` {#man-stdc_leading_zeros}

[i[`stdc_leading_zeros()` function]i]

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

This function returns the number of leading zeros on a particular value,
starting from the most-significant bit. The number will be influenced by
the size of the argument.

### Return Value {.unnumbered .unlisted}

Returns the number of leading zeros.

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

This function returns the number of leading ones on a particular value
starting from the most-significant bit. The number will be influenced by
the size of the argument.

### Return Value {.unnumbered .unlisted}

Returns the number of leading ones.

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

This function returns the number of trailing zeros on a particular value,
starting from the least-significant bit. The number will be influenced by
the size of the argument.

### Return Value {.unnumbered .unlisted}

Returns the number of trailing zeros.

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

This function returns the number of trailing ones on a particular value,
starting from the least-significant bit. The number will be influenced by
the size of the argument.

### Return Value {.unnumbered .unlisted}

Returns the number of trailing ones.

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
