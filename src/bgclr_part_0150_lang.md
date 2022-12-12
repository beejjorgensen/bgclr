<!-- Beej's guide to C

# vim: ts=4:sw=4:nosi:et:tw=72
-->

# The C Language

This is just a quick overview of the fashionable and fun highlights of
the syntax, keywords, and other animals in the C menagerie.

## Background

Some things you'll need to make sense of the examples, below.

### Expressions

If it's not a keyword or other reserved punctuation, it tends to be an
expression. Think "math including function calls".

### Statements

Think `if`, `while`, etc. Executable keywords.

### Booleans

Ignoring the `bool` type, zero is false and non-zero is true.

### Blocks

Multiple expressions and flow control keywords can be wrapped up in a
block, made up of `{` followed by one or more expressions or statements,
followed by `}`.

### Code Examples

They are meant to give an idea of how to use various statements, but not
be comprehensive in terms of examples.

In the examples, below, if either an expression or statement can be
used, the word `code` is inserted.

## Operators

### Comments

Comments to the end of line begin with `//`.

Multiline comments begin with `/*` and are terminated with `*/`.

### Separators

Expressions in C are separated by semicolons (`;`). These tend to appear
at the ends of lines.

TODO

## Type Specifiers

Integer types from smallest to largest capacity: `char`, `short`, `int`,
`long`, `long long`.

Any integer type may be prefaced with `signed` (the default except for
`char`) or `unsigned`.

Whether or not `char` is signed is implementation defined.

Floating types from least accuracy to most: `float`, `double`, `long
double`.

`void` is a type representing lack of type.

`_Bool` is a Boolean type. This becomes `bool` in C23. Earlier versions
of C must include `<stdbool.h>` to get `bool`.

`_Complex` indicates a complex floating type type, when paired with such
a type. Include `<complex.h>` to use `complex` instead.

``` {.c}
complex float x = 1.2 + 2.3*I;
complex double y = 1.2 + 2.3*I;
```

`_Imaginary` is an optional keyword used to specify an imaginary type
(the imaginary part of a complex number) when paired with a floating
type. Include `<complex.h>` to use `imaginary` instead. Neither GCC nor
clang support this.

``` {.c}
imaginary float f = 2.3*I;
```

`_Generic` is a type "switcher" that allows you to emit different code
at compile time depending on the type of the data.

## Composite Types

### `struct` Types

You can build a composite type made out of other types with `struct` and
then declare variables to be of that type.

``` {.c}
struct animal {
    char *name;
    int leg_count;
};

struct animal a;
struct animal b = {"goat", 4};
struct animal c = {.name="goat", .leg_count=4};
```

Accessing is done with the dot operator (`.`) or, if the variable is a
pointer to a `struct`, the arrow operator (`->`).

``` {.c}
struct animal *p = b;

printf("%d\n", b.leg_count);
printf("%d\n", p->leg_count);
```

### `union` Types

These are like `struct` types in usage, except that you can only use one
field at a time. (The fields all use the same region of memory.)

``` {.c}
union dt {
    float distance;
    int time;
};

union dt a;
union dt b = {6};            // Initializes "distance", the first field
union dt c = {.distance=6};  // Initializes "distance"
union dt d = {.time=6};      // Initializes "time"
```

Accessing is done with the dot operator (`.`) or, if the variable is a
pointer to a `union`, the arrow operator (`->`).

``` {.c}
union dt *p = b;

printf("%d\n", b.time);
printf("%d\n", p->time);
```

### `enum` Types

Gives you a typed way to have named constant integer values. These can
be used with `switch()`, or as an array size, or any other place
constant values are needed.

Names are conventionally capitalized.

``` {.c}
enum animal {
    ANTELOPE,
    BADGER,
    CAT,
    DOG,
    ELEPHANT,
    FISH
};

enum animal a = CAT;

if (a == CAT)
    printf("The animal is a cat.\n");
```

The names have numeric values starting with zero and counting up. (In
the example above, `DOG` would be `3`.)

The numeric value can be overridden by specifying an integer exactly.
Subsequent values increment from the specified one.

``` {.c}
enum animal {
    ANTELOPE = 4,
    BADGER,         // Will be 5
    CAT,            // Will be 6
    DOG = 3,
    ELEPHANT,       // Will be 4
    FISH            // Will be 5
};
```

As above, duplicate values are not illegal, but might be of marginal
usefulness.

## Type Aliases

You can set up a type alias for convenience or abstraction.

Here we'll make a new type called `time_counter` that is just an `int`.
It can only be used exactly like an `int`. It's just an alias for an
`int`.

``` {.c}
typedef int time_counter;

time_counter t = 3490;
```

Also works with `struct`s or `union`s:

``` {.c}
struct foo {
    int bar;
    float baz;
};

typedef struct foo funtype;

funtype f = {1, 2}; // "funtype" is an alias for "struct foo";
```

It also works inline, and with named or unnamed `struct`s or `union`s:

``` {.c}
typedef struct {
    int bar;
    float baz;
} funtype;

funtype f = {1, 2}; // "funtype" is an alias for the unnamed struct
```

## Additional Type-Related Specifiers

You can give the compiler more hints about what qualities a type should
have using these specifiers and qualifiers.

### Storage Class Specifiers

These can be placed before a type to provide more guidance about how the
type is used.

``` {.c}
auto int a
register int a
static int a
extern int a
thread_local int a
```

`auto` is the default, so it's basically never used. Indicates automatic
storage duration (things like local variables get freed automatically
when they fall out of scope). In C23 this keyword changes to indicate
type inference like C++.

`register` indicates that accessing this variable should be as quick as
possible. Restricts some usage of the variable giving the compiler a
chance to optimize. Rare in daily use.

`static` at function scope indicates that this variable's value should
persist from call to call. At file scope indicates that this variable
should not be visible outside of this source file.

`extern` indicates that this variable refers to one declared in another
source file.

`_Thread_local` means that every thread gets its own copy of this
variable. You can use `thread_local` if you include `<threads.h>`.

### Type Qualifiers

These can be placed before a type to provide more guidance about how the
type is used.

``` {.c}
const int a
const int *p
int * const p
const int * const p
int * restrict p
volatile int a
atomic int a
```

`const` means the value can't be modified. You can use it with pointers,
as well:

``` {.c}
const int a = 10;        // Can't modify "a"

const int *p = &b        // Can't modify the thing "p" points to ("b")
int *const p = &b        // Can't modify "p"
const int *const p = &b  // Can't modify "p" or the thing it points to
```

`restrict` on a pointer means that there will only be one pointer to the
item in question, freeing the compiler to make some optimizations.

`volatile` indicates that the value in a variable might change at any
time and should be loaded from memory instead of being kept in a
register. Usually used with memory-mapped hardware.

`_Atomic` (or `atomic` if you include `<stdatomic.h>`) tells the
compiler that reads or writes to this type should happen atomically.
(This might be accomplished with a lock depending on the platform and
type.)

### Function Specifiers

These are used on functions to provide additional guidance for the
compiler.

`_Noreturn` indicates that a function will never return. It can only run
forever or exit the program entirely. If you include `<stdnoreturn.h>`,
you can use `noreturn` instead.

`inline` indicates that calls to this function should be as fast as
possible. The intention here is that the code of the function be moved
_inline_ to remove the overhead of the call and return. The compiler
regards `inline` as a suggestion, not a requirement.

### Alignment Specifier

You can force the alignment of a variable with memory with `_Alignas`.
If you include `<stdalign.h>` you can use `alignas` instead.

`alignas(0)` has no effect.

``` {.c}
alignas(16) int a = 12;    // 16-byte alignment
alignas(long) int b = 34;  // Same alignment as "long"
```

## `if` Statement

``` {.c}
if (boolean_expression) code;

if (boolean_expression) {
    code;
    code;
    code;
}

if (boolean_expression) {
    code;
    code;
} else
    code;

if (boolean_expression) {
    code;
    code;
} else if {
    code;
    code;
    code;
} else {
    code;
}
```

## `for` Statement

Classic `for`-loop.

The bit in parens comes in three parts separated by semicolons:

* Initialization, executed once.
* Block entry condition, evaluated every time before entering the loop
  body.
* Post expression, evaluated every time after the loop body.

For example, initialize `i` to `0`, enter the loop body while `i < 10`,
and then increment `i` after each loop iteration:

``` {.c}
for (i = 0; i < 10; i++) {
    code;
    code;
    code;
}
```

You can declare loop-local variables by specifying their type:

``` {.c}
for (int i = 0; i < 10; i++) {
    code;
    code;
}
```

You can separate parts of the expressions with the comma operator:

``` {.c}
for (i = 0, j = 5; i < 10; i++, j *= 3) {
    code;
    code;
}
```

## `while` Statement

This loop won't enter if the Boolean expression is false. The
continuation test happens before the loop.

``` {.c}

while (boolean_expression) code;

while (boolean_expression) {
    code;
    code;
}
```

## `do`-`while` Statement

This loop will run at least once even if the Boolean expression is
false. The continuation test doesn't happen until after the loop.

``` {.c}

do code while (boolean_expression);

do {
    code;
    code;
} while (boolean_expression);
```

## `switch` Statement

Performs actions based on the value of an expression. The cases that it
is compared against must be constant values.

If the optional `default` is present, that code is executed if none of
the cases match. Braces are not required around the cases.

``` {.c}
switch (expression) {
    case constant:
        code;
        code;
        break;

    case constant:
        code;
        code;
        break;

    default:
        code;
        break;
}
```

The final `break` in the `switch` is unnecessary if there are no cases
after it.

If the `break` isn't present, the `case` falls through to the next one.
It's nice to put a comment to that effect so other devs don't hate you.

``` {.c}
switch (expression) {
    case constant:
        code;
        code;
        // fall through!

    case constant:
        code;
        break;
}
```

## `break` Statement

This breaks out of a `switch` case, but it also can break out of any
loop.

``` {.c}
while (boolean_expression) {
    code;

    if (boolean_expression)
        break;

    code;
}
```

## `continue` Statement

This can be used to short-circuit a loop and go to the next continuation
condition test without completing the body of the loop.

``` {.c}
while (boolean_expression) {
    code;
    code;

    if (boolean_expression_2)
        continue;

    // If boolean_expression_2, code down here will be skipped:

    code;
    code;
}
```

## `goto` Statement

You can just jump anywhere within a function with `goto`. (You can't
`goto` between functions, only within the same function as the `goto`.)

The destination of the `goto` is a _label_, which is an identifier
followed by a colon (`:`). Labels are typically left-justified all the
way to the margin to make them visually stand out.

``` {.c}
{
    // Abusive demo code that should be a while loop

    int i = 0;

loop:

    printf("%d\n", i++);

    if (i < 10)
        goto loop;
}
```

## `return` Statement

This is how you get back from a function. You can `return` multiple
times or just once.

If a function with `void` return type falls off the end, the `return` is
implicit.

If the return type is not `void`, the `return` statement must specify a
return value of the same type.

Parentheses around the return value are not necessary (as it's a
statement, not a function).

```
int increment(int a)
{
    return a + 1;
}
```

```
_Static_assert

Operators
sizeof
Casting
_Alignof
```
