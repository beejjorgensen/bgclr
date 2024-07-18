<!-- Beej's guide to C

# vim: ts=4:sw=4:nosi:et:tw=72
-->

# `<tgmath.h>` Type-Generic Math Functions {#tgmath}

[i[`tgmath.h` header file]i]

These are type-generic macros that are wrappers around the math
functions in [`<math.h>`](#math) and [`<complex.h>`](#complex). This
header includes both of those.

But on the surface, you can think of them as being able to use, say, the
`sqrt()` function with any type without needed to think about if it's
`double` or `long double` or even `complex`.

These are the defined macros---some of them don't have a counterpart in
the real or complex space. Type suffixes are omitted in the table on the
Real and Complex columns. None of the generic macros have type suffixes.

[i[`acos()` function]i]
[i[`asin()` function]i]
[i[`atan()` function]i]
[i[`acosh()` function]i]
[i[`asinh()` function]i]
[i[`atanh()` function]i]
[i[`cos()` function]i]
[i[`sin()` function]i]
[i[`tan()` function]i]
[i[`cosh()` function]i]
[i[`sinh()` function]i]
[i[`tanh()` function]i]
[i[`exp()` function]i]
[i[`log()` function]i]
[i[`pow()` function]i]
[i[`sqrt()` function]i]
[i[`fabs()` function]i]
[i[`atan2()` function]i]
[i[`fdim()` function]i]
[i[`cbrt()` function]i]
[i[`floor()` function]i]
[i[`ceil()` function]i]
[i[`fma()` function]i]
[i[`copysign()` function]i]
[i[`fmax()` function]i]
[i[`erf()` function]i]
[i[`fmin()` function]i]
[i[`erfc()` function]i]
[i[`fmod()` function]i]
[i[`exp2()` function]i]
[i[`frexp()` function]i]
[i[`expm1()` function]i]
[i[`hypot()` function]i]
[i[`ilogb()` function]i]
[i[`ldexp()` function]i]
[i[`lgamma()` function]i]
[i[`llrint()` function]i]
[i[`llround()` function]i]
[i[`log10()` function]i]
[i[`log1p()` function]i]
[i[`log2()` function]i]
[i[`logb()` function]i]
[i[`lrint()` function]i]
[i[`lround()` function]i]
[i[`nearbyint()` function]i]
[i[`nextafter()` function]i]
[i[`nexttoward()` function]i]
[i[`remainder()` function]i]
[i[`remquo()` function]i]
[i[`rint()` function]i]
[i[`round()` function]i]
[i[`scalbn()` function]i]
[i[`scalbln()` function]i]
[i[`tgamma()` function]i]
[i[`trunc()` function]i]
[i[`carg()` function]i]
[i[`cimag()` function]i]
[i[`conj()` function]i]
[i[`cproj()` function]i]
[i[`creal()` function]i]

|Real Function|Complex Function|Generic Macro|
|-|-|-|
|`acos`|`cacos`|`acos`|
|`asin`|`casin`|`asin`|
|`atan`|`catan`|`atan`|
|`acosh`|`cacosh`|`acosh`|
|`asinh`|`casinh`|`asinh`|
|`atanh`|`catanh`|`atanh`|
|`cos`|`ccos`|`cos`|
|`sin`|`csin`|`sin`|
|`tan`|`ctan`|`tan`|
|`cosh`|`ccosh`|`cosh`|
|`sinh`|`csinh`|`sinh`|
|`tanh`|`ctanh`|`tanh`|
|`exp`|`cexp`|`exp`|
|`log`|`clog`|`log`|
|`pow`|`cpow`|`pow`|
|`sqrt`|`csqrt`|`sqrt`|
|`fabs`|`cabs`|`fabs`|
|`atan2`|---|`atan2`|
|`fdim`|---|`fdim`|
|`cbrt`|---|`cbrt`|
|`floor`|---|`floor`|
|`ceil`|---|`ceil`|
|`fma`|---|`fma`|
|`copysign`|---|`copysign`|
|`fmax`|---|`fmax`|
|`erf`|---|`erf`|
|`fmin`|---|`fmin`|
|`erfc`|---|`erfc`|
|`fmod`|---|`fmod`|
|`exp2`|---|`exp2`|
|`frexp`|---|`frexp`|
|`expm1`|---|`expm1`|
|`hypot`|---|`hypot`|
|`ilogb`|---|`ilogb`|
|`ldexp`|---|`ldexp`|
|`lgamma`|---|`lgamma`|
|`llrint`|---|`llrint`|
|`llround`|---|`llround`|
|`log10`|---|`log10`|
|`log1p`|---|`log1p`|
|`log2`|---|`log2`|
|`logb`|---|`logb`|
|`lrint`|---|`lrint`|
|`lround`|---|`lround`|
|`nearbyint`|---|`nearbyint`|
|`nextafter`|---|`nextafter`|
|`nexttoward`|---|`nexttoward`|
|`remainder`|---|`remainder`|
|`remquo`|---|`remquo`|
|`rint`|---|`rint`|
|`round`|---|`round`|
|`scalbn`|---|`scalbn`|
|`scalbln`|---|`scalbln`|
|`tgamma`|---|`tgamma`|
|`trunc`|---|`trunc`|
|---|`carg`|`carg`|
|---|`cimag`|`cimag`|
|---|`conj`|`conj`|
|---|`cproj`|`cproj`|
|---|`creal`|`creal`|

## Example

Here's an example where we call the type-generic `sqrt()` function on a
variety of types.

``` {.c .numberLines}
#include <stdio.h>
#include <tgmath.h>

int main(void)
{
    double x = 12.8;
    long double y = 34.9;
    double complex z = 1 + 2 * I;

    double x_result;
    long double y_result;
    double complex z_result;

    // We call the same sqrt() function--it's type-generic!
    x_result = sqrt(x);
    y_result = sqrt(y);
    z_result = sqrt(z);

    printf("x_result: %f\n", x_result);
    printf("y_result: %Lf\n", y_result);
    printf("z_result: %f + %fi\n", creal(z_result), cimag(z_result));
}
```

Output:

``` {.default}
x_result: 3.577709
y_result: 5.907622
z_result: 1.272020 + 0.786151i
```
