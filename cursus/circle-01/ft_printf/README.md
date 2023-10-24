# ft_printf

> Because `ft_putnbr()` and `ft_putstr()` aren’t enough.

The goal of this project is pretty straightforward. You will recode `printf()`.<br/>
You will mainly learn about using a variable number of arguments. How cool is that??<br/>
It is actually pretty cool :)

## Mandatory part

| Key                | Value                                                                                            |
|--------------------|--------------------------------------------------------------------------------------------------|
| Program name       | `libftprintf.a`                                                                                  |
| Turn in files      | `Makefile`, `*.h`, `*/*.h`, `*.c`, `*/*.c`                                                       |
| Makefile           | `NAME`, `all`, `clean`, `fclean`, `re`                                                           |
| External functions | `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end`                             |
| Libft authorized   | Yes                                                                                              |
| Description        | Write a library that contains `ft_printf()`, a function that will mimic the original `printf()`. |

You have to recode the `printf()` function from `libc`.

The prototype of `ft_printf()` is:

```c
int	ft_printf(const char *, ...);
```

### Requirements
- Don’t implement the buffer management of the original `printf()`.
- Your function has to handle the following conversions: `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X` and `%`
- Your function will be compared against the original `printf()`.
- You must use the command `ar` to create your library. Using the `libtool` command is forbidden.
- Your `libftprintf.a` has to be created at the root of your repository.

You have to implement the following conversions:
- [x] `%c` Prints a single character.
- [x] `%s` Prints a string (as defined by the common C convention).
- [x] `%p` The `void *` pointer argument has to be printed in hexadecimal format.
- [x] `%d` Prints a decimal (base 10) number.
- [x] `%i` Prints an integer in base 10.
- [x] `%u` Prints an unsigned decimal (base 10) number.
- [x] `%x` Prints a number in hexadecimal (base 16) lowercase format.
- [x] `%X` Prints a number in hexadecimal (base 16) uppercase format.
- [x] `%%` Prints a percent sign.

## Bonus part

> If you plan to complete the bonus part, think about the implementation of your extra features from the start. This way, you will avoid the pitfalls of a naive approach.

- Manage any combination of the following flags: `'-0.'` and the field `minimum width` under all conversions.
- Manage all the following flags: `'# +'` (Yes, one of them is a space)

| Type | `-`<br/>left align | `0`<br/>zero pad | `.`<br/>precision | `(number)`<br/>min width | `#`<br/>alternative form | `(space)`<br/>left pad with one space | `+`<br/>show signed numbers |
|:----:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| `%c` | ✅  | ✅  | n/a | ✅  | n/a | n/a | n/a |
| `%s` | ✅  | ✅  | ✅  | ✅  | n/a | n/a | n/a |
| `%p` | ✅  | ✅  | n/a | ✅  | n/a | n/a | n/a |
| `%d` |     |     |     |     |     |     |     |
| `%i` |     |     |     |     |     |     |     |
| `%u` |     |     |     |     |     |     |     |
| `%x` |     |     |     |     |     |     |     |
| `%X` |     |     |     |     |     |     |     |
| `%%` |     |     |     |     |     |     |     |
