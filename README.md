*This project has been created as part of the 42 curriculum by gcampos.*

# Libft

🇬🇧 [English](#english) | 🇧🇷 [Português](#português)

---

## English

> Your very first own library: a collection of C functions reimplemented from scratch, to be reused in future 42 projects.

### Description

C programming can be quite tedious without the standard library. The goal of **Libft** is to understand how these functions work internally by rewriting them yourself, and to build a personal static library, `libft.a`, that can be used in later projects of the 42 curriculum.

The project is divided into three parts:

1. **Libc functions**: reimplementations of standard functions (`strlen`, `memcpy`, `atoi`, `calloc`…), with the same prototypes and behavior as the originals (as described in their man pages), but with the `ft_` prefix.
2. **Additional functions**: useful functions that do not exist in the libc, or exist in a different form (`ft_split`, `ft_strjoin`, `ft_itoa`…).
3. **Linked lists**: functions to create and manipulate singly linked lists using the `t_list` structure.

#### Project rules

- Written in C, following the 42 **Norm**.
- Compiled with `cc` and the flags `-Wall -Wextra -Werror`.
- No global variables; helper functions are declared `static`.
- The library is built with `ar` (the use of `libtool` is forbidden).
- No memory leaks and no unexpected crashes (segfault, bus error, double free…).

### Library overview

#### Part 1 – Libc functions

| Category | Functions |
| --- | --- |
| Character checks | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` |
| Character conversion | `ft_toupper`, `ft_tolower` |
| Memory | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp` |
| Strings | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr` |
| Conversion | `ft_atoi` |
| Allocation (`malloc`) | `ft_calloc`, `ft_strdup` |

The character check functions return `1` if the character matches the tested class and `0` otherwise.

#### Part 2 – Additional functions

| Function | Description |
| --- | --- |
| `ft_substr` | Returns a new substring of `s`, starting at index `start`, with a maximum length of `len`. |
| `ft_strjoin` | Returns a new string made by concatenating `s1` and `s2`. |
| `ft_strtrim` | Returns a copy of `s1` with the characters in `set` removed from the beginning and the end. |
| `ft_split` | Splits `s` using the delimiter `c` and returns a `NULL`-terminated array of strings. |
| `ft_itoa` | Converts an integer (negatives included) into a newly allocated string. |
| `ft_strmapi` | Applies `f` to each character of `s` (with its index) and returns a new string with the results. |
| `ft_striteri` | Applies `f` to each character of `s`, passed by address so it can be modified in place. |
| `ft_putchar_fd` | Writes the character `c` to the file descriptor `fd`. |
| `ft_putstr_fd` | Writes the string `s` to the file descriptor `fd`. |
| `ft_putendl_fd` | Writes the string `s` followed by a newline to `fd`. |
| `ft_putnbr_fd` | Writes the integer `n` to `fd`. |

#### Part 3 – Linked lists

The following structure is declared in `libft.h`:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

- `content`: the data stored in the node (`void *` allows any type of data).
- `next`: the address of the next node, or `NULL` if it is the last one.

| Function | Description |
| --- | --- |
| `ft_lstnew` | Allocates and returns a new node with the given `content` and `next` set to `NULL`. |
| `ft_lstadd_front` | Adds a node at the beginning of the list. |
| `ft_lstadd_back` | Adds a node at the end of the list. |
| `ft_lstsize` | Counts the number of nodes in the list. |
| `ft_lstlast` | Returns the last node of the list. |
| `ft_lstdelone` | Frees the content of a node with `del`, then frees the node (but not the next one). |
| `ft_lstclear` | Deletes and frees a node and all its successors, then sets the list pointer to `NULL`. |
| `ft_lstiter` | Applies `f` to the content of every node. |
| `ft_lstmap` | Creates a new list from the results of applying `f` to each node's content (uses `del` if an allocation fails). |

### Instructions

#### Requirements

- A Unix-like system (Linux or macOS)
- `cc` (or `gcc`/`clang`) and `make`

#### Compilation

Clone the repository and build the library:

```bash
git clone https://github.com/mionzeras/libft_2026.git libft
cd libft
make
```

This creates the static library `libft.a` at the root of the repository.

#### Makefile rules

| Rule | Description |
| --- | --- |
| `make` / `make all` | Compiles the sources and creates `libft.a` |
| `make clean` | Removes the object files (`.o`) |
| `make fclean` | Removes the object files and `libft.a` |
| `make re` | Runs `fclean` and then `all` |
| `make teste` | Builds the library, compiles `main.c` and runs the tests |

#### Using the library

Include the header in your code:

```c
#include "libft.h"

int	main(void)
{
	char	*s;

	s = ft_strjoin("Hello, ", "42!");
	if (!s)
		return (1);
	ft_putendl_fd(s, 1);
	free(s);
	return (0);
}
```

Then compile your program by linking it with `libft.a`:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
./my_program
```

> **Note:** `strlcpy`, `strlcat` and `bzero` are not part of glibc by default. To compare `ft_` versions with the originals on Linux, include `<bsd/string.h>` and compile with `-lbsd`.

#### Testing

The repository includes a `main.c` that tests every function of the library. For each function it prints a header and the result of each call, side by side with the original libc function (`orig`) when one exists, or with the expected value (`esp`) otherwise:

```
**************** ft_strchr ****************
strchr(s, 'o')                       ft: "o world"  orig: "o world"
strchr(s, 'z')                       ft: NULL  orig: NULL
```

Any line where the results don't match is marked with `<-- diferente`.

```bash
make teste
```

To check for memory leaks:

```bash
valgrind --leak-check=full ./teste
```

> `main.c` and the `teste` rule are only here for study and testing. They are not part of the 42 submission.

### Resources

#### References

- Linux man pages for each original function (`man 3 strlen`, `man 3 memmove`, etc.)
- [Makefile Tutorial](https://makefiletutorial.com/): complete guide to writing Makefiles
- [Learn make in 60 seconds – Jacob Sorber](https://www.youtube.com/watch?v=a8mPKBxQ9No)
- [How To Make a Makefile for Beginners! – HenrikM Dev](https://www.youtube.com/watch?v=HmbByRhh3Sk)
- [All you need to know about linked lists, Libft – Oceano](https://www.youtube.com/watch?v=mkZYMKwKkvI)
- [Short introduction to linked lists in C – CodeVault](https://www.youtube.com/watch?v=uBZHMkpsTfg)

#### Use of AI

AI was used as a **study tool**, not to generate the project's code:

- **Understanding concepts**: to get explanations of how some functions work (for example, the difference between `memcpy` and `memmove` with overlapping memory) and of memory concepts such as dynamic allocation with `malloc`/`free`, pointers and memory leaks.
- **Documentation**: to help write and structure this README.
- **Tests**: to help create the `main.c` test file, which compares the library functions with the originals.

All the library code (`ft_*.c`, `libft.h` and `Makefile`) was written, tested and reviewed by me.

---

## Português

*Este projeto foi criado como parte do currículo da 42 por gcampos.*

> A sua primeira biblioteca: uma coleção de funções em C reimplementadas do zero, para serem reutilizadas nos próximos projetos da 42.

### Descrição

Programar em C pode ser bem trabalhoso sem a biblioteca padrão. O objetivo da **Libft** é entender como essas funções funcionam por dentro, reescrevendo-as, e criar uma biblioteca estática própria, `libft.a`, que poderá ser usada nos próximos projetos do currículo da 42.

O projeto é dividido em três partes:

1. **Funções da libc**: reimplementação de funções padrão (`strlen`, `memcpy`, `atoi`, `calloc`…), com os mesmos protótipos e comportamentos das originais (conforme as man pages), mas com o prefixo `ft_`.
2. **Funções adicionais**: funções úteis que não existem na libc, ou que existem de outra forma (`ft_split`, `ft_strjoin`, `ft_itoa`…).
3. **Listas ligadas**: funções para criar e manipular listas ligadas simples usando a estrutura `t_list`.

#### Regras do projeto

- Escrito em C, seguindo a **Norma** da 42.
- Compilado com `cc` e as flags `-Wall -Wextra -Werror`.
- Sem variáveis globais; funções auxiliares são declaradas como `static`.
- A biblioteca é criada com o comando `ar` (o uso de `libtool` é proibido).
- Sem memory leaks e sem crashes inesperados (segfault, bus error, double free…).

### Visão geral da biblioteca

#### Parte 1 – Funções da libc

| Categoria | Funções |
| --- | --- |
| Verificação de caracteres | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` |
| Conversão de caracteres | `ft_toupper`, `ft_tolower` |
| Memória | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp` |
| Strings | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr` |
| Conversão | `ft_atoi` |
| Alocação (`malloc`) | `ft_calloc`, `ft_strdup` |

As funções de verificação de caracteres retornam `1` se o caractere pertence à classe testada e `0` caso contrário.

#### Parte 2 – Funções adicionais

| Função | Descrição |
| --- | --- |
| `ft_substr` | Retorna uma nova substring de `s`, começando no índice `start`, com tamanho máximo `len`. |
| `ft_strjoin` | Retorna uma nova string resultante da concatenação de `s1` e `s2`. |
| `ft_strtrim` | Retorna uma cópia de `s1` sem os caracteres de `set` no início e no fim. |
| `ft_split` | Divide `s` usando o delimitador `c` e retorna um array de strings terminado em `NULL`. |
| `ft_itoa` | Converte um inteiro (incluindo negativos) em uma nova string alocada. |
| `ft_strmapi` | Aplica `f` a cada caractere de `s` (com o seu índice) e retorna uma nova string com os resultados. |
| `ft_striteri` | Aplica `f` a cada caractere de `s`, passado por endereço para poder ser modificado diretamente. |
| `ft_putchar_fd` | Escreve o caractere `c` no file descriptor `fd`. |
| `ft_putstr_fd` | Escreve a string `s` no file descriptor `fd`. |
| `ft_putendl_fd` | Escreve a string `s` seguida de uma quebra de linha em `fd`. |
| `ft_putnbr_fd` | Escreve o inteiro `n` em `fd`. |

#### Parte 3 – Listas ligadas

A seguinte estrutura é declarada no `libft.h`:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

- `content`: o dado guardado no nó (`void *` permite guardar qualquer tipo de dado).
- `next`: o endereço do próximo nó, ou `NULL` se for o último.

| Função | Descrição |
| --- | --- |
| `ft_lstnew` | Aloca e retorna um novo nó com o `content` recebido e `next` igual a `NULL`. |
| `ft_lstadd_front` | Adiciona um nó no início da lista. |
| `ft_lstadd_back` | Adiciona um nó no fim da lista. |
| `ft_lstsize` | Conta o número de nós da lista. |
| `ft_lstlast` | Retorna o último nó da lista. |
| `ft_lstdelone` | Libera o conteúdo de um nó com `del` e depois libera o nó (mas não o próximo). |
| `ft_lstclear` | Apaga e libera um nó e todos os seguintes, e define o ponteiro da lista como `NULL`. |
| `ft_lstiter` | Aplica `f` ao conteúdo de cada nó. |
| `ft_lstmap` | Cria uma nova lista com os resultados de aplicar `f` ao conteúdo de cada nó (usa `del` se uma alocação falhar). |

### Instruções

#### Requisitos

- Um sistema Unix (Linux ou macOS)
- `cc` (ou `gcc`/`clang`) e `make`

#### Compilação

Clone o repositório e compile a biblioteca:

```bash
git clone https://github.com/mionzeras/libft_2026.git libft
cd libft
make
```

Isso cria a biblioteca estática `libft.a` na raiz do repositório.

#### Regras do Makefile

| Regra | Descrição |
| --- | --- |
| `make` / `make all` | Compila os arquivos e cria a `libft.a` |
| `make clean` | Remove os arquivos objeto (`.o`) |
| `make fclean` | Remove os arquivos objeto e a `libft.a` |
| `make re` | Executa `fclean` e depois `all` |
| `make teste` | Compila a biblioteca e o `main.c` e roda os testes |

#### Usando a biblioteca

Inclua o header no seu código:

```c
#include "libft.h"

int	main(void)
{
	char	*s;

	s = ft_strjoin("Olá, ", "42!");
	if (!s)
		return (1);
	ft_putendl_fd(s, 1);
	free(s);
	return (0);
}
```

Depois compile o seu programa ligando-o à `libft.a`:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o meu_programa
./meu_programa
```

> **Nota:** `strlcpy`, `strlcat` e `bzero` não fazem parte da glibc por padrão. Para comparar as versões `ft_` com as originais no Linux, inclua `<bsd/string.h>` e compile com `-lbsd`.

#### Testes

O repositório inclui um `main.c` que testa todas as funções da biblioteca. Para cada função ele mostra um cabeçalho e o resultado de cada chamada, lado a lado com o da função original da libc (`orig`) quando ela existe, ou com o valor esperado (`esp`) quando não existe:

```
**************** ft_strchr ****************
strchr(s, 'o')                       ft: "o world"  orig: "o world"
strchr(s, 'z')                       ft: NULL  orig: NULL
```

Qualquer linha em que os resultados não batem é marcada com `<-- diferente`.

```bash
make teste
```

Para verificar memory leaks:

```bash
valgrind --leak-check=full ./teste
```

> O `main.c` e a regra `teste` estão aqui só para estudo e testes. Não fazem parte da entrega da 42.

### Recursos

#### Referências

- Man pages do Linux de cada função original (`man 3 strlen`, `man 3 memmove`, etc.)
- [Makefile Tutorial](https://makefiletutorial.com/): guia completo para escrever Makefiles
- [Learn make in 60 seconds – Jacob Sorber](https://www.youtube.com/watch?v=a8mPKBxQ9No)
- [How To Make a Makefile for Beginners! – HenrikM Dev](https://www.youtube.com/watch?v=HmbByRhh3Sk)
- [All you need to know about linked lists, Libft – Oceano](https://www.youtube.com/watch?v=mkZYMKwKkvI)
- [Short introduction to linked lists in C – CodeVault](https://www.youtube.com/watch?v=uBZHMkpsTfg)

#### Uso de IA

A IA foi usada como **ferramenta de estudo**, e não para gerar o código do projeto:

- **Entendimento de conceitos**: para obter explicações sobre o funcionamento de algumas funções (por exemplo, a diferença entre `memcpy` e `memmove` quando há sobreposição de memória) e sobre conceitos de memória, como alocação dinâmica com `malloc`/`free`, ponteiros e memory leaks.
- **Documentação**: para ajudar a escrever e estruturar este README.
- **Testes**: para ajudar a criar o arquivo de testes `main.c`, que compara as funções da biblioteca com as originais.

Todo o código da biblioteca (`ft_*.c`, `libft.h` e `Makefile`) foi escrito, testado e revisado por mim.
