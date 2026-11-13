This project has been created as part of the 42 curriculum by gcampos.

*Description*

Libft is a project from the 42 School curriculum whose main goal is to recreate several functions from the standard C library, as well as implement additional utility functions.

The objective is to build a personal C library from scratch, gaining a deeper understanding of the C language and its fundamental concepts, such as pointers, memory allocation, string manipulation and data structures.

The project results in a static library named libft.a, which can be reused in future C projects.

Instructions
Compilation

The project uses a Makefile to automate the compilation process.

To compile the library, run:

bash
make


This command compiles the source files and generates the static library libft.a.

Makefile Rules

The following commands are available:

Command	Description
make	Compiles the library.
make all	Executes the default compilation rule.
make clean	Removes all object files (.o).
make fclean	Removes object files and the library (libft.a).
make re	Removes previously generated files and recompiles the library.
Using the Library

To use Libft in another C project:

Include the library header in your source file:
c
#include "libft.h"

Compile your program together with the library:
bash
cc main.c -L. -lft -I. -o program

Run the executable:
bash
./program


Make sure that libft.a and libft.h are accessible from the specified paths.

Testing

The library can be tested using custom test programs and external testers.

To test the project:

Clone the repository.
Compile the library using make.
Run your custom test program or an external Libft tester.

Some useful external testers are:

libftTester – Tripouille
libft-unit-test – alelievr

These testers help check the behaviour of the implemented functions, including edge cases and memory management.

After testing, generated files can be removed using:

bash
make fclean

Library Overview

The Libft library contains several groups of functions, each designed for a specific purpose.

1. Character Functions

Functions used to check and manipulate individual characters.

ft_isalpha – Checks whether a character is alphabetic.
ft_isdigit – Checks whether a character is a digit.
ft_isalnum – Checks whether a character is alphanumeric.
ft_isascii – Checks whether a character belongs to the ASCII character set.
ft_isprint – Checks whether a character is printable.
ft_toupper – Converts a lowercase character to uppercase.
ft_tolower – Converts an uppercase character to lowercase.
2. String Functions

Functions for manipulating and analysing strings.

ft_strlen – Calculates the length of a string.
ft_strlcpy – Copies a string with size limitation.
ft_strlcat – Concatenates strings with size limitation.
ft_strchr – Searches for a character in a string.
ft_strrchr – Searches for the last occurrence of a character.
ft_strncmp – Compares two strings.
ft_strnstr – Searches for a substring within a string.
ft_strdup – Duplicates a string.
3. Memory Functions

Functions for allocating, manipulating and comparing memory blocks.

ft_memset – Fills a memory area with a specified value.
ft_bzero – Sets a memory area to zero.
ft_memcpy – Copies data between memory areas.
ft_memmove – Copies memory while handling overlapping areas.
ft_memchr – Searches for a byte in a memory area.
ft_memcmp – Compares two memory areas.
ft_calloc – Allocates memory and initialises it to zero.
4. Conversion Functions

Functions for converting values between different data types.

ft_atoi – Converts a string into an integer.
ft_itoa – Converts an integer into a string.
5. Additional String Functions

Utility functions that extend the basic string manipulation functionality.

ft_substr – Extracts a substring from a string.
ft_strjoin – Joins two strings into a new string.
ft_strtrim – Removes specified characters from the beginning and end of a string.
ft_split – Splits a string into an array of strings using a delimiter.
ft_strmapi – Applies a function to each character of a string.
ft_striteri – Applies a function to each character using its index.
6. File Descriptor Functions

Functions for writing characters, strings and numbers to file descriptors.

ft_putchar_fd – Writes a character to a file descriptor.
ft_putstr_fd – Writes a string to a file descriptor.
ft_putendl_fd – Writes a string followed by a newline.
ft_putnbr_fd – Writes an integer to a file descriptor.
7. Linked List Functions (Bonus)

The bonus part of Libft introduces singly linked lists, allowing the creation and manipulation of dynamic data structures.

Each node is represented by the t_list structure, which contains:

content – A pointer to the data stored in the node.
next – A pointer to the next node in the list.

The linked list functions include:

ft_lstnew – Creates a new list node.
ft_lstadd_front – Adds a node to the beginning of the list.
ft_lstsize – Returns the number of nodes in the list.
ft_lstlast – Returns the last node.
ft_lstadd_back – Adds a node to the end of the list.
ft_lstdelone – Deletes a node and frees its content.
ft_lstclear – Deletes and frees an entire list.
ft_lstiter – Applies a function to the content of each node.
ft_lstmap – Creates a new list by applying a function to each node's content.
Resources

The following resources were used during the development of this project.

Makefile

These resources helped me understand how Makefiles work, including compilation rules, dependencies and build automation.

GeeksforGeeks – How to Use Make Utility to Build C Projects
Makefile Tutorial
YouTube – Makefile Tutorial
Linked Lists

These videos helped me understand linked lists, their structure, node management and the operations performed on them.

YouTube – Linked Lists Tutorial
YouTube – Linked Lists Tutorial
C Documentation
cppreference – C Language
Artificial Intelligence

AI tools were used as supplementary learning and productivity resources during the development of this project.

They were used for:

Understanding concepts: Clarifying certain C programming concepts, particularly memory functions, memory allocation and pointer manipulation.
Testing support: Helping with the creation and organisation of a main.c file to test the implemented functions.
Documentation: Assisting with the structure and writing of this README file.

AI was used to support learning, clarify doubts and improve development efficiency. The generated suggestions were reviewed and adapted during the development process.

Final Notes

Libft was an important opportunity to strengthen my understanding of C programming, particularly memory management, pointers, string manipulation and data structures.

The library will also serve as a foundation for future projects throughout the 42 curriculum.
