<!-- Beej's guide to C

# vim: ts=4:sw=4:nosi:et:tw=72
-->

# The C Language

This is just a quick overview of the fashionable and fun highlights of
the syntax, keywords, and other animals in the C menagerie.

## Background

Some things you'll need to make sense of the examples, below.

### Comments

Comments in C start with `//` and go to the end of a line.

Multiline comments begin with `/*` and continue until a closing `*/`.

### Separators

Expressions in C are separated by semicolons (`;`). These tend to appear
at the ends of lines.

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

### Arithmetic Operators

The arithmetic operators: `+`, `-`, `*`, `/`, `%` (remainder).

Division is integer if all arguments are integers. Otherwise it's a
floating result.

You can also negate an expression by putting `-` in front of it. (You
can also put a `+` in front of it---this doesn't do anything
mathematically, but it causes the Usual Arithmetic Conversions to be
performed on the expression.)

### Pre- and Post-Increment and -Decrement

The post-increment (`++`) and post-decrement (`--`) operators (after the
variable) do their work _after_ the rest of the expression has been
evaluated.

``` {.c}
int x = 10;
int y = 20;
int z = 30;

int w = (x++) + (y--) + (z++);

print("%d %d %d %d\n", x, y, z, w);  // 11 19 31 60
```

The pre-increment (`++`) and pre-decrement (`--`) operators (before the
variable) do their work _before_ the rest of the expression has been
evaluated.

``` {.c}
int x = 10;
int y = 20;
int z = 30;

int w = (++x) + (--y) + (++z);

print("%d %d %d %d\n", x, y, z, w);  // 11 19 31 61
```

### Comparison Operators

All of these return a Boolean true-y or false-y value.

Less than, greater than, and equal to are: `<`, `>`, `==`, respectively.

Less than or equal to and greater than or equal to are `<=` and `>=`.

Not equal to is `!=`.

### Pointer Operators

`*` in front of a pointer variable dereferences that variable.

`&` in front of a variable gives the address of that variable.

`+` and `-` arithmetic operators work on pointers for pointer
arithmetic.

### Structure and Union Operators

The dot operator (`.`) can get a field value out of a `struct` or
`union`.

The arrow operator (`->`) can get a field value out of a pointer to a
`struct` or `union`. These two are equivalent, assuming `p` is just such
a pointer:

``` {.c}
(*p).bar;
p->bar;
```

### Array Operators

The square bracket operators can reference a value in an array:

``` {.c}
a[10] = 99;
```

This is syntactic sugar over pointer arithmetic and referencing. The
above line is equivalent to:

``` {.c}
*(a + 10) = 99;
```

### Bitwise Operators

Bit shift right: `>>`, bit shift left: `<<`.

```
int i = x << 3;  // left shift 3 bits
```

Whether or not a right shift on a signed value is sign-extended is
implementation-defined.

Bitwise AND, OR, NOT, and XOR are `&`, `|`, `~`, and `^`, respectively.

### Assignment Operators

A standalone `=` is your basic assignment.

But there are also compound assignments that are like a shorthand
version. For example, these two are basically equivalent:

``` {.c}
x = x + 1;
x += 1;
```

There are compound assignment operators for many of the other operators.

Arithmetic: `+=`, `-=`, `*=`, `/=`, and `%=`.

Bitwise: `|=`, `&=`, `~=`, and `^=`.

### The `sizeof` Operator

This is a compile-time operator that gives you the size in bytes of the
type of the argument. The type of the expression is used; the expression
is not evaluated. `sizeof` works with any type, even user-defined
composite types.

The return type is the integer type `size_t`.

```
float f;
size_t x = sizeof f;

printf("f is %zu bytes\n", x);
```

You can also specify a raw type name in there by wrapping it in
parentheses:

``` {.c}
size_t x = sizeof(int);

printf("int is %zu bytes\n", x);
```

### Type Casts

You can force an expression to be another type (within reason) by
_casting_ to that type.

You give the new type name in parentheses.

Here we are forcing the subexpression `x` to be type `float` just before
the division^[This doesn't change the type of `x` in other
contexts---it's just in this one usage in this expression.]. This causes
the division, which would otherwise be an integer division, to be a
floating point division.

``` {.c}
int x = 17;
int y = 2;

float f = (float)x / y;
```

### `_Alignof` Operator

You can get the byte alignment of any type with the `_Alignof`
compile-time operator. If you include `<stdalign.h>`, you can use
`alignof` instead.

Any type can be the argument to the operator, which must be in
parenthesis. Unlike `sizeof`, the argument cannot be an expression.

``` {.c}
printf("Alignment of int is %zu\n", alignof(int));
```

### Comma Operator

You can separate subexpressions with commas, and each will be evaluated
from left to right, and the value of the entire expression will be the
value of the subexpression after the last comma.

``` {.c}
int x = (1, 2, 3);  // Silly way to assign `x = 3`
```

Usually this is used in the various clauses in loops. For example, we
can do multiple assignments in a `for` loop, and have multiple post
expressions like this:

``` {.c}
for (i = 2, j = 10; i < 100; i++, j += 4) { ... }
```

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

## Constant Types

You can declare constants to be of specific types (though it might be a
larger type). In the following example unqualified types, case doesn't
matter, and the `U` can come before or after the `L` or `LL`.

``` {.c}
123              int or larger
123L             long int or larger
123LL            long long int

123U             unsigned int or larger
123UL            unsigned long int or larger
123ULL           unsigned long long int

123.4F           float
123.4            double
123.4L           long double

'a'              char
"hello, world"   char* (string)
```

You can specify the constant in other bases as well:

``` {.c}
123              decimal
0x123            hexadecimal
0123             octal
```

You can also specify floating constants in base-10 exponential notation:

``` {.c}
1.2e3            1.2 x 10^3
```

And you can specify floats in hex! Except in this case the exponent is
still in decimal, and the base is 2 instead of 10:

``` {.c}
0x1.2p3          0x1.2 x 2^3
```

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
struct animal *p = &b;  // b from above

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

## Initializers

You can do this when the variable is defined, but not elsewhere.

Initializing basic types:

``` {.c}
int x = 12;
float y = 1.2;
char c = 'a';
char *s = "Hello, world!";
```

Initializing array types:

``` {.c}
int a[3] = {1,2,3};
int a[] = {1,2,3};   // Same as a[3]

int a[3] = {1, 2};   // Same as {1, 2, 0}
int a[3] = {1};      // Same as {1, 0, 0}
int a[3] = {0};      // Same as {0, 0, 0}
```

Initializing pointer types:

``` {.c}
int q;
int *p = &q;
```

Initializing `struct`s:

``` {.c}
struct s {
    int a;
    float b;
};

struct s x0 = {1, 2.2}; // Initialize fields in order

struct s x0 = {.a=1, .b=2.2}; // Initialize fields by name
struct s x0 = {.b=2.2, .a=1}; // Same thing

struct s x0 = {.b=2.2}; // All other fields initialized to 0
struct s x0 = {.b=2.2, .a-=0};  // Same thing
```

Initializing `union`s:

``` {.c}
union u {
    int a;
    float b;
};

union u x0 = {1};  // Initialize the first field (a)

union u x0 = {.a=1};  // Initialize fields by name
union u x0 = {.b=2.2};

//union u x0 = {1, 2};       // ILLEGAL
//union u x0 = {.a1, ,b=2};  // ILLEGAL
```

## Compound Literals

You can declare "unnamed" objects in C. This is often useful for passing
a `struct` to a function that otherwise doesn't need a name.

You use the type name in parens followed by an initializer to make the
object.

Here's an example of passing a compound literal to a function. Note that
there's no `struct s` variable in `main()`:

``` {.c .numberLines}
#include <stdio.h>

struct s {
    int a, b;
};

int add(struct s x)
{
    return x.a + x.b;
}

int main(void)
{
    int t = add((struct s){.a=2, .b=4});  // <-- Here

    printf("%d\n", t);
}
```

Compound literals have the lifetime of their scope.

You can also pass a pointer to a compound literal by taking its address:

``` {.c}
foo(&(struct s){1, 2});
```

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

#### C23 Qualified Pseudo-Types: `QVoid*`, `QChar*`, etc.

There are some generic functions in C23 that will return a
`const`-qualified type if one of the parameters is `const`, but not
otherwise.

The spec makes up a fake type for this, with a `Q` at the front (for
"qualified"). This is not a real type and will not compile---it's just
for documentation purposes.

These pseudotypes are:

* `QVoid *`
* `QChar *`
* `QWchar_t *`

For example, the `strchr()` function, which searches a string for a
character, has this prototype in the spec:

``` {.c}
QChar *strchr(QChar *s, int c);
```

What is it? It basically means that if `s` is type `const char *`, then
the return type of the function will also be `const char *`.

If `s` is merely `char *`, the return type of the function will merely
be `char *`.

In other words, the `const`-ness of `s` is preserved in the return
value.

Another way to look at it is that this:

``` {.c}
QChar *strchr(QChar *s, int c);
```

is the same as:

``` {.c}
char *strchr(char *s, int c);
const char *strchr(const char *s, int c);
```

The TLDR is when you see this, drop the leading `Q` and change the next
letter to lowercase and you're there.

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

``` {.c}
int increment(int a)
{
    return a + 1;
}
```

## `_Static_assert` Statement

This is a way to prevent _compilation_ of a program if a certain
constant condition is not met.

``` {.c}
_Static_assert(__STDC_VERSION__ >= 201112L, "You need at least C11!")
```

## Functions

You need to specify the return type and parameter types for the
function, and the body goes in a block afterward.

Variables in the function are local to that function.

``` {.c}
// Function that adds two numbers

int add(int x, int y)
{
    int sum = x + y;

    return sum;
}
```

Functions that return nothing should be return type `void`. Functions
that accept no parameters should have `void` as the parameter list.

``` {.c}
// All side effects, all the time!

void foo(void)
{
    some_global = 12;
    printf("Here we go!\n");
}
```

### `main()` Function

This is the function that runs when you first start the program. It will
be one of these forms:

``` {.c}
int main(void)
int main(int argc, char *argv[])
```

The first form ignores all command line parameters.

The second form stores the count of the command line parameters in
`argc`, and stores the parameters themselves as an array of strings in
`argv`. The first of these, `argv[0]`, is typically the name of the
executable. The last `argv` pointer has the value `NULL`.

The return values usually show up as exit status codes in the OS.
If there is no `return`, falling off the end of `main()` is an implied
`return 0`^[Note that this implication only for `main()`, and not for
any other functions.].

### Variadic Functions

Some functions can take a variable number of arguments. Every function
must have at least one argument. The remaining arguments are specified
by `...` and can be read with the `va_start()`, `va_arg()`, and
`va_end()` macros.

Here's an example that adds up a variable number of integer values.

``` {.c}
int add(int count, ...)
{
    int total = 0;
    va_list va;

    va_start(va, count);   // Start with arguments after "count"

    for (int i = 0; i < count; i++) {
        int n = va_arg(va, int);   // Get the next int

        total += n;
    }

    va_end(va);  // All done

    return total;
}
```
