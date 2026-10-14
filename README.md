*This project has been created as part of the 42 curriculum by tchern-h.*

# ft_printf

## Description

<!-- Write this in your own words: the goal of the project and a short overview. -->
ft_printf is a recreation of the C library function `printf()`. It handles the
conversions `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X` and `%`, and builds on
variadic functions (`va_start`, `va_arg`, `va_end`). It is packaged as the static
library `libftprintf.a`.

## Instructions

Compile the library from the root of the repository:

```bash
make
```

Other rules: `make clean`, `make fclean`, `make re`.

Use it in your own program:

```c
#include "ft_printf.h"

int main(void)
{
	ft_printf("Hello %s, you are %d years old\n", "world", 42);
	return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o test
```

## Algorithm and data structure

The program uses va_start to begin going through the string argument 'format', it will look fo %, upon seeing % it will call a helper function ft_format_variable, the ft_format_variable will check if the next character is cspdiuxX if it is will call a respective helper function to print the variable accordingly otherwise it will just print what was in the 'format'.  

## Resources

- `man 3 printf`
- `man 3 stdarg`

**AI usage:**
AI was used to help to understand concepts, code generation and testing.
