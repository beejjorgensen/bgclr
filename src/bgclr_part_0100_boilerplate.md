# Foreword
<!-- Beej's guide to C
# vim: ts=4:sw=4:nosi:et:tw=72
-->

<!-- No hyphenation -->
[nh[scalbn]]
[nh[scalbnf]]
[nh[scalbnl]]
[nh[scalbln]]
[nh[scalblnf]]
[nh[scalblnl]]
<!-- Can't do things that aren't letters
[nh[atan2]]
[nh[atan2f]]
[nh[atan2l]]
-->
[nh[lrint]]
[nh[lrintf]]
[nh[lrintl]]
[nh[llrint]]
[nh[llrintf]]
[nh[llrintl]]
[nh[lround]]
[nh[lroundf]]
[nh[lroundl]]
[nh[llround]]
[nh[llroundf]]
[nh[llroundl]]

<!-- Index see alsos -->
[is[String==>see `char *`]]
[is[New line==>see `\n` newline]]
[is[Ternary operator==>see `?:` ternary operator]]
[is[Addition operator==>see `+` addition operator]]
[is[Subtraction operator==>see `-` subtraction operator]]
[is[Multiplication operator==>see `*` multiplication operator]]
[is[Division operator==>see `/` division operator]]
[is[Modulus operator==>see `%` modulus operator]]
[is[Boolean NOT==>see `!` operator]]
[is[Boolean AND==>see `&&` operator]]
[is[Boolean OR==>see `||` operator]]
[is[Bell==>see `\a` operator]]
[is[Tab (is better)==>see `\t` operator]]
[is[Carriage return==>see `\r` operator]]
[is[Hexadecimal==>see `0x` hexadecimal]]

The door slowly creaks open revealing a long hall with dusty stacks of
books of lore...

I admit, maybe not that.

But you have found the Library Reference portion of Beej's Guide to C!

This isn't a tutorial, but rather is a comprehensive set of manual pages
(or _man pages_ as Unix hackers like to say) that define _every_
function in the C Standard Library, complete with examples.

> _"This book, sir, contains every word in our beloved language."_\
> _"Every single one, sir?"_\
> _"Every single one, sir!"_\
> _"Ah, well in that case, sir, I hope you will not object if I also
> offer the doctor my most enthusiastic contrafribularities."_
>
> ---Blackadder toying with Dr. Samuel Johnson

There are, in fact, a number of functions left out of this guide, most
notably all the optional "safe" functions (with a `_s` suffix).

But everything you're likely to want is definitely covered in here. With
examples.

Probably.

## Audience

This guide is for people who are at least modestly proficient in C.

If you are not one of those people and wish to become one of those
people, I can wholeheartedly recommend with zero bias the book
[fl[_Beej's Guide to C Programming_|https://beej.us/guide/bgc/]], freely
available wherever the Internet is sold.

## How to Read This Book

Use the contents or index to find the function or category you're after.

Then grab a bowl of your favorite cereal and devour the delicious,
delicious verbiage.

## Platform and Compiler

I'll try to stick to Plain Ol'-Fashioned [flw[ISO-standard C|ANSI_C]].
Well, for the most part. Here and there I might go crazy and start
talking about [flw[POSIX|POSIX]] or something, but we'll see.

**Unix** users (e.g. Linux, BSD, etc.) try running `cc` or `gcc` from
the command line--you might already have a compiler installed. If you
don't, search your distribution for installing `gcc` or `clang`.

**Windows** users should check out [fl[Visual Studio
Community|https://visualstudio.microsoft.com/vs/community/]]. Or, if
you're looking for a more Unix-like experience (recommended!), install
[fl[WSL|https://docs.microsoft.com/en-us/windows/wsl/install-win10]] and
`gcc`.

**Mac** users will want to install
[fl[XCode|https://developer.apple.com/xcode/]], and in particular the
command line tools.

There are a lot of compilers out there, and virtually all of them will
work for this book. And a C++ compiler will compile a lot of (but not
all!) C code. Best use a proper C compiler if you can.

## Official Homepage

This official location of this document is
[fl[`https://beej.us/guide/bgclr/`|https://beej.us/guide/bgclr/]]. There
used to be a note here about migrating off Chico State's computers (my
alma mater), but that's something that happened roughly a zillion years
ago and the wording remained here only because it was copied over from
the Network Guide, [_breath_] which I apparently haven't read in its
entirety for quite some time.

The End.

## Email Policy

I'm generally available to help out with email questions so feel free to
write in, but I can't guarantee a response. I lead a pretty busy life
and there are times when I just can't answer a question you have. When
that's the case, I usually just delete the message. It's nothing
personal; I just won't ever have the time to give the detailed answer
you require.

As a rule, the more complex the question, the less likely I am to
respond. If you can narrow down your question before mailing it and be
sure to include any pertinent information (like platform, compiler,
error messages you're getting, and anything else you think might help me
troubleshoot), you're much more likely to get a response.

If you don't get a response, hack on it some more, try to find the
answer, and if it's still elusive, then write me again with the
information you've found and hopefully it will be enough for me to help
out.

Now that I've badgered you about how to write and not write me, I'd just
like to let you know that I _fully_ appreciate all the praise the guide
has received over the years. It's a real morale boost, and it gladdens
me to hear that it is being used for good! `:-)` Thank you!

## Mirroring

You are more than welcome to mirror this site, whether publicly or
privately. If you publicly mirror the site and want me to link to it
from the main page, drop me a line at
[`beej@beej.us`](mailto:beej@beej.us).

## Note for Translators

If you want to translate the guide into another language, write me at
[`beej@beej.us`](beej@beej.us) and I'll link to your translation from
the main page. Feel free to add your name and contact info to the
translation.

Please note the license restrictions in the Copyright and Distribution
section, below.

## Copyright and Distribution

Beej's Guide to C Programming--Library Reference is Copyright © 2021
Brian "Beej Jorgensen" Hall.

With specific exceptions for source code and translations, below, this
work is licensed under the Creative Commons Attribution-Noncommercial-No
Derivative Works 3.0 License. To view a copy of this license, visit
[`https://creativecommons.org/licenses/by-nc-nd/3.0/`](https://creativecommons.org/licenses/by-nc-nd/3.0/)
or send a letter to Creative Commons, 171 Second Street, Suite 300, San
Francisco, California, 94105, USA.

One specific exception to the "No Derivative Works" portion of the
license is as follows: this guide may be freely translated into any
language, provided the translation is accurate, and the guide is
reprinted in its entirety. The same license restrictions apply to the
translation as to the original guide. The translation may also include
the name and contact information for the translator.

The C source code presented in this document is hereby granted to the
public domain, and is completely free of any license restriction.

Educators are freely encouraged to recommend or supply copies of this
guide to their students.

Contact [`beej@beej.us`](beej@beej.us) for more information.

## Dedication

The hardest things about writing these guides are:

* Learning the material in enough detail to be able to explain it
* Figuring out the best way to explain it clearly, a seemingly-endless
  iterative process
* Putting myself out there as a so-called _authority_, when really
  I'm just a regular human trying to make sense of it all, just like
  everyone else
* Keeping at it when so many other things draw my attention

A lot of people have helped me through this process, and I want to
acknowledge those who have made this book possible.

* Everyone on the Internet who decided to help share their knowledge in
  one form or another. The free sharing of instructive information is
  what makes the Internet the great place that it is.
* The volunteers at [fl[cppreference.com|https://en.cppreference.com/]]
  who provide the bridge that leads from the spec to the real world.
* The helpful and knowledgeable folks on
  [fl[comp.lang.c|https://groups.google.com/g/comp.lang.c]] and 
  [fl[r/C_Programming|https://www.reddit.com/r/C_Programming/]] who got
  me through the tougher parts of the language.
* Everyone who submitted corrections and pull-requests on everything
  from misleading instructions to typos.

Thank you! ♥
