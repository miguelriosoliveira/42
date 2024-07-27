# Libft

> Your very first own library

This project is about coding a C library.<br/>
It will contain a lot of general purpose functions your programs will rely upon.

## Introduction

C programming can be very tedious when one doesn't have access to the highly useful standard functions.
This project is about understanding the way these functions work, implementing and learning to use them. Your will create your own library. It will be helpful since you will use it in your next C school assignments.

Take the time to expand your libft throughout the year. However, when working on a new project, don't forget to ensure the functions used in your library are allowed in the project guidelines.

## Mandatory Part

| Key                | Value                                                                                         |
|--------------------|-----------------------------------------------------------------------------------------------|
| Program name       | `libft.a`                                                                                     |
| Turn in files      | `Makefile`, `libft.h`, `ft_*.c`                                                               |
| Makefile           | `NAME`, `all`, `clean`, `fclean`, `re`                                                        |
| External functions | Detailed below                                                                                |
| Libft authorized   | n/a                                                                                           |
| Description        | Write your own library: a collection of functions that will be a useful tool for your cursus. |

### Technical considerations

- Declaring global variables is forbidden.
- If you need helper functions to split a more complex function, define them as `static` functions. This way, their scope will be limited to the appropriate file.
- Place all your files at the root of your repository.
- Turning in unused files is forbidden.
- Every `.c` files must compile with the flags `-Wall -Wextra -Werror`.
- You must use the command `ar` to create your library. Using the `libtool` command is forbidden.
- Your `libft.a` has to be created at the root of your repository.

### Part 1 - Libc functions

To begin, you must redo a set of functions from the `libc`.
Your functions will have the same prototypes and implement the same behaviors as the originals.
They must comply with the way they are defined in their `man`.
The only difference will be their names. They will begin with the `'ft_'` prefix.
For instance, `strlen` becomes `ft_strlen`.

> 💡 Some of the functions' prototypes you have to redo use the `'restrict'` qualifier.This keyword is part of the `c99` standard.
> It is therefore forbidden to include it in your own prototypes and to compile your code with the `-std=c99` flag.

You must write your own function implementing the following original ones. They do not require any external functions:

- [x] `isalpha`
- [x] `isdigit`
- [x] `isalnum`
- [x] `isascii`
- [x] `isprint`
- [x] `strlen`
- [x] `memset`
- [x] `bzero`
- [x] `memcpy`
- [x] `memmove`
- [x] `strlcpy`
- [x] `strlcat`
- [x] `toupper`
- [x] `tolower`
- [x] `strchr`
- [x] `strrchr`
- [x] `strncmp`
- [x] `memchr`
- [x] `memcmp`
- [x] `strnstr`
- [x] `atoi`

In order to implement the two following functions, you will use `malloc()`:

- [x] `calloc`
- [x] `strdup`

### Part 2 - Additional functions

In this second part, you must develop a set of functions that are either not in the `libc`, or that are part of it but in a different form.

> 💡 Some of the following functions can be useful for writing the functions of Part 1.

- [x] `ft_substr`
- [x] `ft_strjoin`
- [x] `ft_strtrim`
- [x] `ft_split`
- [x] `ft_itoa`
- [x] `ft_strmapi`
- [x] `ft_striteri`
- [x] `ft_putchar_fd`
- [x] `ft_putstr_fd`
- [x] `ft_putendl_fd`
- [x] `ft_putnbr_fd`

## Bonus Part

If you completed the mandatory part, do not hesitate to go further by doing this extra one.
It will bring bonus points if passed successfully.

Functions to manipulate memory and strings is very useful. But you will soon discover that manipulating lists is even more useful.

You have to use the following structure to represent a node of your list. Add its declaration to your `libft.h` file:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

The members of the `t_list` struct are:
- `content`: The data contained in the node.<br/>
	`void *` allows to store any kind of data.
- `next`: The address of the next node, or `NULL` if the next node is the last one.

In your Makefile, add a `make bonus` rule to add the bonus functions to your `libft.a`.

Implement the following functions in order to easily use your lists.

- [x] `ft_lstnew`
- [x] `ft_lstadd_front`
- [x] `ft_lstsize`
- [x] `ft_lstlast`
- [x] `ft_lstadd_back`
- [x] `ft_lstdelone`
- [x] `ft_lstclear`
- [x] `ft_lstiter`
- [x] `ft_lstmap`
