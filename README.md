*This project has been created as part of the 42 curriculum by abait.br.*

# Libft - Your Very First C Library

## Description

**Libft** is the foundational project of the 42 core curriculum. The objective of this project is to code a custom C standard library from scratch. C programming can be tedious without access to basic utility functions; by re-implementing standard library (`libc`) functions and additional memory/string manipulation helpers, this library serves as a reusable toolset for all subsequent C projects in the school curriculum.

The project is structured into three main sections:
1. **Part 1 - Libc Functions:** Re-implementing a set of standard `libc` functions adhering strictly to their standard `man` page behaviors, prefixed with `ft_`.
2. **Part 2 - Additional Functions:** Developing utility functions for string creation, manipulation, splitting, type conversion, and file-descriptor outputs.
3. **Part 3 - Linked List Functions :** Implementing a set of functions to manipulate a custom singly-linked list structure (`t_list`).

---

## Technical Considerations & Rules

- **Language & Compiler:** Written strictly in C, following the 42 School **Norm**.
- **Flags:** Compiles with `-Wall -Wextra -Werror` using `cc`.
- **Memory Management:** Zero memory leaks allowed. Dynamic memory allocations (`malloc`) are checked and properly handled/freed.
- **Global Variables:** Explicitly forbidden.
- **Library Generation:** Built using the `ar` command (`ar rcs`). The use of `libtool` is prohibited.
- **C99 Restrict:** Prototype declarations do not use the `restrict` qualifier, and compilation is not restricted to C99 flags.

---

## Instructions

### Compilation

The project includes a Makefile at the root directory that compiles all source files without unnecessary relinking.

To compile the mandatory library:
```bash
make
```

Other available rules:
- `make clean`: Removes generated object files (`.o`).
- `make fclean`: Removes object files and the static library binary (`libft.a`).
- `make re`: Re-compiles the entire project from scratch.

### Usage

To integrate `libft` into another C project:

1. Copy the `libft/` directory (containing all `.c`, `.h`, and the `Makefile`) into your project repository.
2. Call the library's Makefile within your main project's Makefile.
3. Include the library header in your source code:
   ```c
   #include "libft.h"
   ```
4. Compile your program by linking the static library `libft.a`:
   ```bash
   cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
   ```

---

## Library Functions Reference

### Part 1: Libc Functions

| Category | Function | Description |
| :--- | :--- | :--- |
| **Character Checks** | `ft_isalpha` | Checks for an alphabetic character. |
| | `ft_isdigit` | Checks for a digit (0 through 9). |
| | `ft_isalnum` | Checks for an alphanumeric character. |
| | `ft_isascii` | Checks whether `c` fits on the ASCII character set. |
| | `ft_isprint` | Checks for any printable character. |
| **String Utilities** | `ft_strlen` | Calculates the length of a string. |
| | `ft_strlcpy` | Copy string to a specific size buffer. |
| | `ft_strlcat` | Concatenate string to a specific size buffer. |
| | `ft_strchr` | Locates character in string (first occurrence). |
| | `ft_strrchr` | Locates character in string (last occurrence). |
| | `ft_strncmp` | Compares two strings up to `n` bytes. |
| | `ft_strnstr` | Locates a substring in a string with length limitation. |
| | `ft_atoi` | Converts a string to an integer. |
| | `ft_toupper` | Converts char to uppercase. |
| | `ft_tolower` | Converts char to lowercase. |
| **Memory Utilities** | `ft_memset` | Fills memory with a constant byte. |
| | `ft_bzero` | Erases data in the n bytes of the memory by writing zeros. |
| | `ft_memcpy` | Copies memory area. |
| | `ft_memmove` | Copies memory area handling overlapping regions. |
| | `ft_memchr` | Scans memory for a character. |
| | `ft_memcmp` | Compares memory areas. |
| | `ft_calloc` | Allocates memory and sets contents to zero. |
| | `ft_strdup` | Duplicates a string using `malloc`. |

### Part 2: Additional Functions

| Function | Prototype | Description |
| :--- | :--- | :--- |
| `ft_substr` | `char *ft_substr(char const *s, unsigned int start, size_t len)` | Allocates and returns a substring from `s`. |
| `ft_strjoin` | `char *ft_strjoin(char const *s1, char const *s2)` | Concatenates `s1` and `s2` into a new allocated string. |
| `ft_strtrim` | `char *ft_strtrim(char const *s1, char const *set)` | Trims specified character set from start and end of `s1`. |
| `ft_split` | `char **ft_split(char const *s, char c)` | Splits string `s` using character `c` as delimiter into array of strings. |
| `ft_itoa` | `char *ft_itoa(int n)` | Converts integer `n` into a string. |
| `ft_strmapi` | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))` | Applies function `f` to each character of string `s` to create a new string. |
| `ft_striteri` | `void ft_striteri(char *s, void (*f)(unsigned int, char*))` | Applies function `f` to each character of string `s` by reference. |
| `ft_putchar_fd`| `void ft_putchar_fd(char c, int fd)` | Outputs character `c` to file descriptor `fd`. |
| `ft_putstr_fd` | `void ft_putstr_fd(char *s, int fd)` | Outputs string `s` to file descriptor `fd`. |
| `ft_putendl_fd` | `void ft_putendl_fd(char *s, int fd)` | Outputs string `s` followed by newline to `fd`. |
| `ft_putnbr_fd` | `void ft_putnbr_fd(int n, int fd)` | Outputs integer `n` to file descriptor `fd`. |

### Part 3: Linked List Functions

The linked list structure is defined as:
```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}                   t_list;
```

| Function | Description |
| :--- | :--- |
| `ft_lstnew` | Creates a new list node with initialized content and `next = NULL`. |
| `ft_lstadd_front` | Adds a node to the beginning of the list. |
| `ft_lstsize` | Counts the number of nodes in the list. |
| `ft_lstlast` | Returns the last node of the list. |
| `ft_lstadd_back` | Adds a node to the end of the list. |
| `ft_lstdelone` | Frees a single node's content using a `del` function and frees the node itself. |
| `ft_lstclear` | Deletes and frees a given node and all its successors, setting list pointer to `NULL`. |
| `ft_lstiter` | Iterates over the list and applies function `f` to each node's content. |
| `ft_lstmap` | Creates a new list resulting from successive applications of `f` to each node. |

---

## Resources & AI Usage Disclosure

### Resources
- C Standard Library Manual Pages (`man 3 malloc`, `man 3 memcpy`, etc.)
- 42 School Norminette Rules & Guidelines
- POSIX Standard String and Memory Management Specifications

### AI Usage Disclosure
In accordance with 42 AI guidelines:
- **Conceptual Clarification:** AI assistance was used to analyze complex edge cases (e.g., memory overlapping logic in `ft_memmove` and handling null-terminations in edge cases for `ft_split`).
- **Logic & Implementation:** All source code implementations were written, tested, and validated manually to ensure core reasoning and programming skills were properly anchored.
