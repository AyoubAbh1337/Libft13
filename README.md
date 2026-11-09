*This project has been created as part of the 42 curriculum by ayblmouh.*

# Libft

## Description

**Libft** is the first project of the 42 curriculum. The goal is to build, from scratch, a personal C library (`libft.a`) that re-implements a set of standard C library functions, adds a collection of useful utility functions, and provides a basic linked-list API. This library is meant to be reused and extended in all later 42 projects.

The project teaches:

- Rigorous C programming under the **Norm** (42's coding standard).
- Manual memory management (`malloc` / `free`) and avoiding leaks.
- Pointer arithmetic, string and memory manipulation.
- Building a static library with `ar` and automating the build with a `Makefile`.
- Writing clean, reusable, well-structured code.

### Library overview

The library is organized in three parts.

#### Part 1 — Libc functions
Re-implementations of standard functions, with the same prototypes and behavior as the originals (prefixed with `ft_`):

| Category | Functions |
|---|---|
| Character checks | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` |
| Character conversion | `ft_toupper`, `ft_tolower` |
| String functions | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup` |
| Memory functions | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc` |
| Conversion | `ft_atoi` |

#### Part 2 — Additional functions
Functions that are not in libc, or that are part of it in a different form:

| Function | Description |
|---|---|
| `ft_substr` | Returns a substring of a string (allocated). |
| `ft_strjoin` | Concatenates two strings into a new allocated string. |
| `ft_strtrim` | Trims a set of characters from the start and end of a string. |
| `ft_split` | Splits a string into an array of strings using a delimiter character. |
| `ft_itoa` | Converts an integer to an allocated string. |
| `ft_strmapi` | Applies a function to each character (with its index) and returns a new string. |
| `ft_striteri` | Applies a function to each character (with its index) in place. |
| `ft_putchar_fd` | Writes a character to a file descriptor. |
| `ft_putstr_fd` | Writes a string to a file descriptor. |
| `ft_putendl_fd` | Writes a string followed by a newline to a file descriptor. |
| `ft_putnbr_fd` | Writes an integer to a file descriptor. |

#### Part 3 — Linked list functions
Functions to manipulate singly linked lists, using the following structure:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new node. |
| `ft_lstadd_front` | Adds a node at the beginning of the list. |
| `ft_lstsize` | Counts the nodes in the list. |
| `ft_lstlast` | Returns the last node of the list. |
| `ft_lstadd_back` | Adds a node at the end of the list. |
| `ft_lstdelone` | Frees one node's content with a given function, then the node. |
| `ft_lstclear` | Deletes and frees a node and all its successors. |
| `ft_lstiter` | Applies a function to the content of each node. |
| `ft_lstmap` | Creates a new list by applying a function to each node's content. |

## Instructions

### Compilation

```bash
make          # builds libft.a
make clean    # removes object files
make fclean   # removes object files and libft.a
make re       # fclean + all
```

### Usage

1. Include the header in your source file:

```c
#include "libft.h"
```

2. Compile your program and link it against the library:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
```

### Usage example

```c
#include "libft.h"

int	main(void)
{
	char	*str;

	str = ft_strjoin("Hello ", "42");
	
    ft_putendl_fd(str, 1);
	free(str);
	return (0);
}
```

## Resources

### References

- Linux manual pages: `man 3 <function>` (e.g. `man 3 strlcpy`, `man 3 memmove`)
- [GNU C Library documentation](https://www.gnu.org/software/libc/manual/)
- [cppreference — C standard library](https://en.cppreference.com/w/c)
- [Static libraries and `ar`](https://man7.org/linux/man-pages/man1/ar.1.html)
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html)
- [Subject File](https://cdn.intra.42.fr/pdf/pdf/226739/en.subject.pdf)
- [42 Norm](https://github.com/42School/norminette)

### Use of AI

AI was used as a support tool only, for the following tasks:

- **Makefile**: understanding how a `Makefile` works (rules, variables, dependencies, building a static library with `ar`).
- **Concepts**: explaining some C and project-related concepts.