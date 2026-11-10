*This activity has been created as part of the 42 curriculum by basianno.*

# DESCRIPTION

The goal of this project is to recode the `printf()` function from the libc, as a static library called `libftprintf.a`.
The main point of the project is to learn how variadic functions work in C (functions that take a variable number of arguments).

Prototype:

```c
int	ft_printf(const char *format, ...);
```

`ft_printf` writes the format string on the standard output, replaces each conversion with the matching argument, and returns the number of characters printed.

# INSTRUCTIONS

Commands to use:

```
make        = compile the library (libftprintf.a)
make re     = recompile everything after a change
make clean  = remove the .o files but keep libftprintf.a
make fclean = remove the .o files and libftprintf.a
```

Include the header in your source files: `#include "ft_printf.h"`.

To use the library, compile your program with it: `cc main.c libftprintf.a`

Example:

```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("%s is %d years old, %x in hex\n", "Bob", 20, 20);
	return (0);
}
```

# RESOURCES

Man pages (`man 3 printf`, `man 3 stdarg`, `man 2 write`), Stack Overflow, GitHub, YouTube tutorials.

I used AI as a teacher: it explained notions I did not know (variadic functions and `va_start` / `va_arg` / `va_end`, type promotion, Makefile rules), guided me when needed.
AI also helped me with testing programs that compare `ft_printf` with the real `printf`.
All the code of the project was written by me.

# DETAILED DESCRIPTION OF THE PROJECT

## Supported conversions

`%c` = prints a single character\
`%s` = prints a string (`(null)` if the pointer is NULL)\
`%p` = prints a pointer address in hexadecimal with the `0x` prefix (`(nil)` if NULL)\
`%d` = prints a signed decimal number\
`%i` = prints a signed integer in base 10 (same as `%d`)\
`%u` = prints an unsigned decimal number\
`%x` = prints an unsigned number in lowercase hexadecimal\
`%X` = prints an unsigned number in uppercase hexadecimal\
`%%` = prints a percent sign

## Functions

`ft_printf` = reads the format string, prints normal characters and sends each conversion to `check_char`\
`check_char` = reads the next argument with the right type and calls the matching print function\
`ft_putchar` = prints a character\
`ft_putstr` = prints a string\
`ft_putnbr` = prints a signed int in base 10\
`ft_base` = prints an unsigned number in any base, given as a string (`"0123456789"`, `"0123456789abcdef"`...)\
`ft_hex` = prints a pointer address (prefix, then `ft_base`)

Every print function returns the number of characters it wrote, and `ft_printf` adds them up to get its return value.

## Algorithm and data structure

**Reading the format.** `ft_printf` goes through the format string once, character by character. A normal character is printed directly with `write`. When it finds a `%`, it sends the next character (the conversion) to `check_char`, then skips both characters.

**Reading the arguments.** The variable arguments are read with a `va_list`, the only structure needed by the project. `ft_printf` passes the **address** of the `va_list` to `check_char` (`va_list *`), so each `va_arg` done in a helper function moves the same cursor, and the next conversion reads the next argument. The type given to `va_arg` must match the type that was passed: `char` is promoted to `int` in variadic arguments, so `%c` reads an `int`.

**Printing numbers.** Numbers are printed with recursion: the function first prints the number without its last digit (`n / base`), then prints the last digit (`n % base`). This prints the digits in the right order without any buffer or memory allocation.

**One function for every base.** `ft_base` receives the digits of the base as a string. The base is the length of this string, and each digit is found with its index (`str[n % base]`). So the same function prints `%u`, `%x`, `%X` and `%p` by only changing the string. It takes an `unsigned long` so that it can also hold a 64-bit address for `%p` (the `void *` is cast to `unsigned long`).

**Why this design.** Each function has one job and returns its own count, so there is no global variable, no `malloc` (so no possible leak), and the code stays within the Norm limits (25 lines per function, 5 functions per file).

## Technical choices for special cases

`ft_printf(NULL)` = returns -1, like the glibc `printf`\
`%` at the end of the string = returns -1, like the glibc. The characters before it are already printed, because the subject forbids to recode the buffer of the real `printf`\
Unknown conversion (example: `%k`) = prints `%` and the character, like the glibc\
`write` errors = not handled, because the subject does not ask for it
