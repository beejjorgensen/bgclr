<!-- Beej's guide to C

# vim: ts=4:sw=4:nosi:et:tw=72
-->

# The C Language

This is just a quick overview of the fashionable and fun highlights of
the syntax, keywords, and other animals in the C menagerie.

## Background

Some things you'll need to make sense of the examples, below.

### Comments

Comments to the end of line begin with `//`.

Multiline comments begin with `/*` and are terminated with `*/`.

### Separators

Expressions in C are separated by semicolons (`;`). These tend to appear
at the ends of lines.

### Expressions

If it's not a keyword or other reserved punctuation, it tends to be an
expression. Think "math including function calls".

### Booleans

Ignoring the `bool` type, zero is false and non-zero is true.

### Blocks

Multiple expressions and flow control keywords can be wrapped up in a
block, made up of `{` followed by one or more expressions or statements,
followed by `}`.

## Operators

TODO

## Types

TODO

### Type Specifiers

TODO

### Type Qualifiers

TODO

## `if` Statement

``` {.c}
if (boolean_expression) expression;

if (boolean_expression) {
    expression;
    expression;
    expression;
}

if (boolean_expression) {
    expression;
    expression;
} else
    expression;

if (boolean_expression) {
    expression;
    expression;
} else if {
    expression;
    expression;
    expression;
} else {
    expression;
}
```

## `while` Statement

This loop won't enter if the Boolean expression is false. The
continuation test happens before the loop.

``` {.c}

while (boolean_expression) expression;

while (boolean_expression) {
    expression;
    expression;
}
```

## `do`-`while` Statement

This loop will run at least once even if the Boolean expression is
false. The continuation test doesn't happen until after the loop.

``` {.c}

do expression while (boolean_expression);

do {
    expression;
    expression;
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
        expression;
        expression;
        break;

    case constant:
        expression;
        expression;
        break;

    default:
        expression;
        break;
}
```

If the `break` isn't present, the `case` falls through to the next one.
It's nice to put a comment to that effect so other devs don't hate you.

``` {.c}
switch (expression) {
    case constant:
        expression;
        expression;
        // fall through!

    case constant:
        expression;
        break;
}
```

## `break` Statement

TODO

```
auto
break
char
const
continue
default
double
enum


extern
float
for
goto
inline
int
long
register
restrict
return
short
signed


sizeof
static
struct
typedef
union
unsigned
void
volatile


_Alignas
_Alignof
_Atomic
_BitInt
_Bool
_Complex
_Generic
_Imaginary
_Noreturn
_Static_assert
_Thread_local
```
