/* ************************************************************************** */
/*                                                                            */
/*   main.c - testes da libft (mostra o resultado de cada funcao)             */
/*                                                                            */
/*   Compilar:  cc -Wall -Wextra -Werror main.c libft.a -o teste && ./teste   */
/*   Leaks:     valgrind --leak-check=full ./teste                            */
/*                                                                            */
/*   ft:   resultado da sua funcao                                            */
/*   orig: resultado da funcao original da libc (quando existe)               */
/*   esp:  resultado esperado (quando nao existe original)                    */
/*                                                                            */
/*   Obs.: este arquivo NAO segue a Norma e NAO deve ser entregue.            */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define RED "\033[0;31m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"
#define DIFF RED "  <-- diferente" RESET

/* ========================= AUXILIARES ========================= */

static void	header(const char *name)
{
	printf("\n" BLUE "**************** %s ****************" RESET "\n", name);
}

static int	sign(int n)
{
	return ((n > 0) - (n < 0));
}

static void	show_int(const char *call, int ft, int orig)
{
	printf("%-36s ft: %-12d orig: %-12d%s\n", call, ft, orig,
		ft != orig ? DIFF : "");
}

static void	show_int_esp(const char *call, long ft, long esp)
{
	printf("%-36s ft: %-12ld esp:  %-12ld%s\n", call, ft, esp,
		ft != esp ? DIFF : "");
}

/* compara so o sinal (memcmp/strncmp podem retornar valores diferentes) */
static void	show_cmp(const char *call, int ft, int orig)
{
	printf("%-36s ft: %-12d orig: %-12d%s\n", call, ft, orig,
		sign(ft) != sign(orig) ? DIFF : "");
}

static void	show_str(const char *call, const char *ft, const char *orig,
		const char *label)
{
	int	diff;

	if (!ft || !orig)
		diff = (ft != orig);
	else
		diff = strcmp(ft, orig) != 0;
	printf("%-36s ft: ", call);
	if (ft)
		printf("\"%s\"", ft);
	else
		printf("NULL");
	printf("  %s: ", label);
	if (orig)
		printf("\"%s\"", orig);
	else
		printf("NULL");
	printf("%s\n", diff ? DIFF : "");
}

/* mostra um buffer byte a byte; bytes nao imprimiveis aparecem como '.' */
static void	print_mem(const unsigned char *p, size_t n)
{
	size_t	i;

	printf("[");
	for (i = 0; i < n; i++)
		putchar(isprint(p[i]) ? p[i] : '.');
	printf("]");
}

static void	show_mem(const char *call, const void *ft, const void *orig,
		size_t n)
{
	printf("%-36s ft: ", call);
	print_mem(ft, n);
	printf("  orig: ");
	print_mem(orig, n);
	printf("%s\n", memcmp(ft, orig, n) ? DIFF : "");
}

static void	print_split(char **t)
{
	int	i;

	if (!t)
	{
		printf("NULL");
		return ;
	}
	printf("{");
	for (i = 0; t[i]; i++)
		printf("\"%s\", ", t[i]);
	printf("NULL}");
}

static void	free_split(char **t)
{
	int	i;

	if (!t)
		return ;
	for (i = 0; t[i]; i++)
		free(t[i]);
	free(t);
}

static void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("[%s] -> ", (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

/* ========================= PARTE 1 ========================= */

static void	test_is(const char *name, int (*ft)(int), int (*orig)(int))
{
	const int	chars[] = {'a', 'Z', '5', ' ', '~', '\n', '\t', 0, 127, 128,
		-1, 255};
	char		call[64];
	int			i;

	header(name);
	printf("(original convertido para 0/1, porque a libc pode retornar outros valores)\n");
	for (i = 0; i < 12; i++)
	{
		if (isprint(chars[i]))
			snprintf(call, sizeof(call), "%s('%c')", name, chars[i]);
		else
			snprintf(call, sizeof(call), "%s(%d)", name, chars[i]);
		show_int(call, ft(chars[i]), !!orig(chars[i]));
	}
}

static int	orig_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

static void	test_to(const char *name, int (*ft)(int), int (*orig)(int))
{
	const int	chars[] = {'a', 'z', 'A', 'Z', '5', ' ', '{', '@', -1, 200};
	char		call[64];
	int			i;

	header(name);
	for (i = 0; i < 10; i++)
	{
		if (isprint(chars[i]))
			snprintf(call, sizeof(call), "%s('%c')", name, chars[i]);
		else
			snprintf(call, sizeof(call), "%s(%d)", name, chars[i]);
		show_int(call, ft(chars[i]), orig(chars[i]));
	}
}

static void	test_strlen(void)
{
	header("ft_strlen");
	show_int("ft_strlen(\"\")", ft_strlen(""), strlen(""));
	show_int("ft_strlen(\"a\")", ft_strlen("a"), strlen("a"));
	show_int("ft_strlen(\"Hello 42\")", ft_strlen("Hello 42"), strlen("Hello 42"));
	show_int("ft_strlen(\"ab\\0cd\")", ft_strlen("ab\0cd"), strlen("ab\0cd"));
}

static void	test_memset_bzero(void)
{
	char	a[12];
	char	b[12];

	header("ft_memset");
	memset(a, '-', 12);
	memset(b, '-', 12);
	show_int("retorno == ponteiro recebido (1 = sim)",
		ft_memset(a, 'A', 5) == a, memset(b, 'A', 5) == b);
	show_mem("memset(buf, 'A', 5)", a, b, 12);
	ft_memset(a, 'B', 0);
	show_mem("memset(buf, 'B', 0)", a, b, 12);
	ft_memset(a + 2, 'Z' + 256, 3);
	memset(b + 2, 'Z' + 256, 3);
	show_mem("memset(buf + 2, 'Z' + 256, 3)", a, b, 12);

	header("ft_bzero");
	printf("('.' = byte zero)\n");
	memset(a, '-', 12);
	memset(b, '-', 12);
	ft_bzero(a, 4);
	memset(b, 0, 4);
	show_mem("bzero(buf, 4)", a, b, 12);
	ft_bzero(a + 6, 0);
	show_mem("bzero(buf + 6, 0)", a, b, 12);
}

static void	test_memcpy_memmove(void)
{
	char	a[12];
	char	b[12];

	header("ft_memcpy");
	memset(a, '-', 12);
	memset(b, '-', 12);
	show_int("retorno == dst (1 = sim)",
		ft_memcpy(a, "Hello", 5) == a, memcpy(b, "Hello", 5) == b);
	show_mem("memcpy(buf, \"Hello\", 5)", a, b, 12);
	ft_memcpy(a + 6, "ab\0cd", 5);
	memcpy(b + 6, "ab\0cd", 5);
	show_mem("memcpy(buf + 6, \"ab\\0cd\", 5)", a, b, 12);
	ft_memcpy(a, "zzz", 0);
	show_mem("memcpy(buf, \"zzz\", 0)", a, b, 12);
	printf("%-36s ft: %s\n", "ft_memcpy(NULL, NULL, 0)",
		ft_memcpy(NULL, NULL, 0) == NULL ? "NULL (sem crash)" : "nao NULL");

	header("ft_memmove");
	strcpy(a, "0123456789");
	strcpy(b, "0123456789");
	ft_memmove(a + 2, a, 5);
	memmove(b + 2, b, 5);
	show_mem("memmove(s + 2, s, 5)  (dst > src)", a, b, 11);
	strcpy(a, "0123456789");
	strcpy(b, "0123456789");
	ft_memmove(a, a + 3, 6);
	memmove(b, b + 3, 6);
	show_mem("memmove(s, s + 3, 6)  (dst < src)", a, b, 11);
	strcpy(a, "0123456789");
	strcpy(b, "0123456789");
	show_int("retorno == dst (1 = sim)",
		ft_memmove(a + 1, a, 3) == a + 1, memmove(b + 1, b, 3) == b + 1);
	printf("%-36s ft: %s\n", "ft_memmove(NULL, NULL, 0)",
		ft_memmove(NULL, NULL, 0) == NULL ? "NULL (sem crash)" : "nao NULL");
}

static void	test_memchr_memcmp(void)
{
	const char	*s = "Hello\0World";

	header("ft_memchr");
	show_str("memchr(s, 'l', 11)", ft_memchr(s, 'l', 11), memchr(s, 'l', 11), "orig");
	show_str("memchr(s, 'W', 11)  (depois do \\0)", ft_memchr(s, 'W', 11),
		memchr(s, 'W', 11), "orig");
	show_str("memchr(s, 'z', 11)", ft_memchr(s, 'z', 11), memchr(s, 'z', 11), "orig");
	show_str("memchr(s, 'o', 4)", ft_memchr(s, 'o', 4), memchr(s, 'o', 4), "orig");
	show_str("memchr(s, 'H' + 256, 5)", ft_memchr(s, 'H' + 256, 5),
		memchr(s, 'H' + 256, 5), "orig");
	show_str("memchr(s, 'H', 0)", ft_memchr(s, 'H', 0), memchr(s, 'H', 0), "orig");

	header("ft_memcmp");
	printf("(so o sinal precisa ser igual: negativo, zero ou positivo)\n");
	show_cmp("memcmp(\"abc\", \"abc\", 3)", ft_memcmp("abc", "abc", 3), memcmp("abc", "abc", 3));
	show_cmp("memcmp(\"abc\", \"abd\", 3)", ft_memcmp("abc", "abd", 3), memcmp("abc", "abd", 3));
	show_cmp("memcmp(\"abd\", \"abc\", 3)", ft_memcmp("abd", "abc", 3), memcmp("abd", "abc", 3));
	show_cmp("memcmp(\"a\\0b\", \"a\\0c\", 3)", ft_memcmp("a\0b", "a\0c", 3),
		memcmp("a\0b", "a\0c", 3));
	show_cmp("memcmp(\"\\200\", \"\\0\", 1)", ft_memcmp("\200", "\0", 1), memcmp("\200", "\0", 1));
	show_cmp("memcmp(\"abc\", \"xyz\", 0)", ft_memcmp("abc", "xyz", 0), memcmp("abc", "xyz", 0));
}

static void	test_strlcpy_strlcat(void)
{
	char	d[20];

	header("ft_strlcpy");
	printf("(nao existe na glibc por padrao: compara com o valor esperado)\n");
	memset(d, 0, 20);
	show_int_esp("strlcpy(d, \"Hello\", 20) retorno", ft_strlcpy(d, "Hello", 20), 5);
	show_str("  -> d", d, "Hello", "esp ");
	show_int_esp("strlcpy(d, \"Hello\", 3) retorno", ft_strlcpy(d, "Hello", 3), 5);
	show_str("  -> d", d, "He", "esp ");
	strcpy(d, "xxx");
	show_int_esp("strlcpy(d, \"Hello\", 0) retorno", ft_strlcpy(d, "Hello", 0), 5);
	show_str("  -> d (nao muda)", d, "xxx", "esp ");
	show_int_esp("strlcpy(d, \"\", 20) retorno", ft_strlcpy(d, "", 20), 0);
	show_str("  -> d", d, "", "esp ");

	header("ft_strlcat");
	printf("(nao existe na glibc por padrao: compara com o valor esperado)\n");
	strcpy(d, "abc");
	show_int_esp("d=\"abc\" strlcat(d, \"def\", 20)", ft_strlcat(d, "def", 20), 6);
	show_str("  -> d", d, "abcdef", "esp ");
	strcpy(d, "abc");
	show_int_esp("d=\"abc\" strlcat(d, \"defgh\", 6)", ft_strlcat(d, "defgh", 6), 8);
	show_str("  -> d", d, "abcde", "esp ");
	strcpy(d, "abc");
	show_int_esp("d=\"abc\" strlcat(d, \"def\", 2)", ft_strlcat(d, "def", 2), 5);
	show_str("  -> d (nao muda)", d, "abc", "esp ");
	strcpy(d, "abc");
	show_int_esp("d=\"abc\" strlcat(d, \"def\", 0)", ft_strlcat(d, "def", 0), 3);
	show_str("  -> d (nao muda)", d, "abc", "esp ");
}

static void	test_strchr_strrchr(void)
{
	const char	*s = "Hello world";

	header("ft_strchr");
	show_str("strchr(s, 'o')", ft_strchr(s, 'o'), strchr(s, 'o'), "orig");
	show_str("strchr(s, 'z')", ft_strchr(s, 'z'), strchr(s, 'z'), "orig");
	show_str("strchr(s, '\\0')", ft_strchr(s, '\0'), strchr(s, '\0'), "orig");
	show_str("strchr(s, 'w' + 256)", ft_strchr(s, 'w' + 256), strchr(s, 'w' + 256), "orig");
	show_str("strchr(\"\", 'a')", ft_strchr("", 'a'), strchr("", 'a'), "orig");
	show_int("strchr(s, '\\0') == s + 11 (1 = sim)", ft_strchr(s, '\0') == s + 11, 1);

	header("ft_strrchr");
	show_str("strrchr(s, 'o')", ft_strrchr(s, 'o'), strrchr(s, 'o'), "orig");
	show_str("strrchr(s, 'z')", ft_strrchr(s, 'z'), strrchr(s, 'z'), "orig");
	show_str("strrchr(s, '\\0')", ft_strrchr(s, '\0'), strrchr(s, '\0'), "orig");
	show_str("strrchr(s, 'l' + 256)", ft_strrchr(s, 'l' + 256), strrchr(s, 'l' + 256), "orig");
	show_str("strrchr(s, 'H')", ft_strrchr(s, 'H'), strrchr(s, 'H'), "orig");
}

static void	test_strncmp_strnstr(void)
{
	const char	*h = "Hello world";

	header("ft_strncmp");
	printf("(so o sinal precisa ser igual: negativo, zero ou positivo)\n");
	show_cmp("strncmp(\"abc\", \"abc\", 3)", ft_strncmp("abc", "abc", 3), strncmp("abc", "abc", 3));
	show_cmp("strncmp(\"abc\", \"abd\", 3)", ft_strncmp("abc", "abd", 3), strncmp("abc", "abd", 3));
	show_cmp("strncmp(\"abd\", \"abc\", 3)", ft_strncmp("abd", "abc", 3), strncmp("abd", "abc", 3));
	show_cmp("strncmp(\"abcX\", \"abcY\", 3)", ft_strncmp("abcX", "abcY", 3),
		strncmp("abcX", "abcY", 3));
	show_cmp("strncmp(\"ab\\0x\", \"ab\\0y\", 4)", ft_strncmp("ab\0x", "ab\0y", 4),
		strncmp("ab\0x", "ab\0y", 4));
	show_cmp("strncmp(\"ab\", \"abc\", 5)", ft_strncmp("ab", "abc", 5), strncmp("ab", "abc", 5));
	show_cmp("strncmp(\"\\200\", \"a\", 1)", ft_strncmp("\200", "a", 1), strncmp("\200", "a", 1));
	show_cmp("strncmp(\"abc\", \"xyz\", 0)", ft_strncmp("abc", "xyz", 0), strncmp("abc", "xyz", 0));

	header("ft_strnstr");
	printf("(nao existe na glibc: compara com o valor esperado)\n");
	show_str("strnstr(h, \"world\", 11)", ft_strnstr(h, "world", 11), "world", "esp ");
	show_str("strnstr(h, \"world\", 10)", ft_strnstr(h, "world", 10), NULL, "esp ");
	show_str("strnstr(h, \"\", 5)", ft_strnstr(h, "", 5), h, "esp ");
	show_str("strnstr(h, \"42\", 11)", ft_strnstr(h, "42", 11), NULL, "esp ");
	show_str("strnstr(h, \"H\", 0)", ft_strnstr(h, "H", 0), NULL, "esp ");
	show_str("strnstr(\"aaab\", \"aab\", 4)", ft_strnstr("aaab", "aab", 4), "aab", "esp ");
}

static void	test_atoi(void)
{
	const char	*t[] = {"0", "42", "-42", "+42", "   \t\n\v\f\r 7",
		"2147483647", "-2147483648", "12abc", "abc", "--1", "+-1",
		"- 1", "", "  -0012", NULL};
	char		call[64];
	int			i;

	header("ft_atoi");
	for (i = 0; t[i]; i++)
	{
		snprintf(call, sizeof(call), "atoi(\"%s\")", t[i]);
		if (i == 4)
			snprintf(call, sizeof(call), "atoi(\"   \\t\\n\\v\\f\\r 7\")");
		show_int(call, ft_atoi(t[i]), atoi(t[i]));
	}
}

static void	test_calloc_strdup(void)
{
	unsigned char	*p;
	unsigned char	*o;
	char			*s;
	char			*so;

	header("ft_calloc");
	p = ft_calloc(5, sizeof(int));
	o = calloc(5, sizeof(int));
	if (p && o)
		show_mem("calloc(5, sizeof(int))  ('.' = 0)", p, o, 5 * sizeof(int));
	free(p);
	free(o);
	p = ft_calloc(0, 0);
	printf("%-36s ft: %s\n", "calloc(0, 0)", p ? "ponteiro valido (pode dar free)" : "NULL");
	free(p);
	p = ft_calloc(0, 5);
	printf("%-36s ft: %s\n", "calloc(0, 5)", p ? "ponteiro valido (pode dar free)" : "NULL");
	free(p);

	header("ft_strdup");
	s = ft_strdup("Hello 42");
	so = strdup("Hello 42");
	show_str("strdup(\"Hello 42\")", s, so, "orig");
	free(s);
	free(so);
	s = ft_strdup("");
	so = strdup("");
	show_str("strdup(\"\")", s, so, "orig");
	free(s);
	free(so);
}

/* ========================= PARTE 2 ========================= */

static void	test_substr_join_trim(void)
{
	char	*p;

	header("ft_substr");
	p = ft_substr("Hello world", 6, 5);
	show_str("substr(\"Hello world\", 6, 5)", p, "world", "esp ");
	free(p);
	p = ft_substr("Hello", 1, 100);
	show_str("substr(\"Hello\", 1, 100)", p, "ello", "esp ");
	free(p);
	p = ft_substr("Hello", 10, 3);
	show_str("substr(\"Hello\", 10, 3)", p, "", "esp ");
	free(p);
	p = ft_substr("Hello", 0, 0);
	show_str("substr(\"Hello\", 0, 0)", p, "", "esp ");
	free(p);

	header("ft_strjoin");
	p = ft_strjoin("Hello ", "42");
	show_str("strjoin(\"Hello \", \"42\")", p, "Hello 42", "esp ");
	free(p);
	p = ft_strjoin("", "");
	show_str("strjoin(\"\", \"\")", p, "", "esp ");
	free(p);
	p = ft_strjoin("abc", "");
	show_str("strjoin(\"abc\", \"\")", p, "abc", "esp ");
	free(p);

	header("ft_strtrim");
	p = ft_strtrim("  xxHello worldxx  ", " x");
	show_str("strtrim(\"  xxHello worldxx  \", \" x\")", p, "Hello world", "esp ");
	free(p);
	p = ft_strtrim("xxxx", "x");
	show_str("strtrim(\"xxxx\", \"x\")", p, "", "esp ");
	free(p);
	p = ft_strtrim("Hello", "");
	show_str("strtrim(\"Hello\", \"\")", p, "Hello", "esp ");
	free(p);
	p = ft_strtrim("", "abc");
	show_str("strtrim(\"\", \"abc\")", p, "", "esp ");
	free(p);
	p = ft_strtrim("abcHelloabc", "cba");
	show_str("strtrim(\"abcHelloabc\", \"cba\")", p, "Hello", "esp ");
	free(p);
}

static void	split_case(const char *call, const char *s, char c, const char *esp)
{
	char	**t;

	t = ft_split(s, c);
	printf("%-36s ft: ", call);
	print_split(t);
	printf("\n%-36s esp: %s\n", "", esp);
	free_split(t);
}

static void	test_split(void)
{
	header("ft_split");
	split_case("split(\"  Hello  42 Porto  \", ' ')", "  Hello  42 Porto  ", ' ',
		"{\"Hello\", \"42\", \"Porto\", NULL}");
	split_case("split(\"Hello\", ' ')", "Hello", ' ', "{\"Hello\", NULL}");
	split_case("split(\"\", ' ')", "", ' ', "{NULL}");
	split_case("split(\"     \", ' ')", "     ", ' ', "{NULL}");
	split_case("split(\"a,b,,c\", ',')", "a,b,,c", ',', "{\"a\", \"b\", \"c\", NULL}");
	split_case("split(\"Hello\", '\\0')", "Hello", '\0', "{\"Hello\", NULL}");
}

static void	test_itoa(void)
{
	const int	n[] = {0, 1, -1, 42, -42, 2147483647, -2147483648, 1000};
	const char	*e[] = {"0", "1", "-1", "42", "-42", "2147483647",
		"-2147483648", "1000"};
	char		call[64];
	char		*p;
	int			i;

	header("ft_itoa");
	for (i = 0; i < 8; i++)
	{
		snprintf(call, sizeof(call), "itoa(%d)", n[i]);
		p = ft_itoa(n[i]);
		show_str(call, p, e[i], "esp ");
		free(p);
	}
}

static char	map_f(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (toupper((unsigned char)c));
	return (c);
}

static void	iter_f(unsigned int i, char *c)
{
	*c = *c + i;
}

static void	test_mapi_iteri(void)
{
	char	*p;
	char	s[10];

	header("ft_strmapi");
	printf("(f = maiuscula nos indices pares)\n");
	p = ft_strmapi("abcdef", map_f);
	show_str("strmapi(\"abcdef\", f)", p, "AbCdEf", "esp ");
	free(p);
	p = ft_strmapi("", map_f);
	show_str("strmapi(\"\", f)", p, "", "esp ");
	free(p);

	header("ft_striteri");
	printf("(f = soma o indice ao caractere)\n");
	strcpy(s, "aaaa");
	ft_striteri(s, iter_f);
	show_str("s=\"aaaa\" striteri(s, f)", s, "abcd", "esp ");
}

static void	test_put_fd(void)
{
	header("ft_putchar_fd");
	printf("%-36s ft: [", "putchar_fd('A', 1)");
	fflush(stdout);
	ft_putchar_fd('A', 1);
	printf("]  esp: [A]\n");

	header("ft_putstr_fd");
	printf("%-36s ft: [", "putstr_fd(\"Hello 42\", 1)");
	fflush(stdout);
	ft_putstr_fd("Hello 42", 1);
	printf("]  esp: [Hello 42]\n");

	header("ft_putendl_fd");
	printf("%-36s ft: [", "putendl_fd(\"Hello\", 1)");
	fflush(stdout);
	ft_putendl_fd("Hello", 1);
	printf("]  esp: [Hello\\n]\n");

	header("ft_putnbr_fd");
	{
		const int	n[] = {0, 42, -42, 2147483647, -2147483648};
		char		call[64];
		int			i;

		for (i = 0; i < 5; i++)
		{
			snprintf(call, sizeof(call), "putnbr_fd(%d, 1)", n[i]);
			printf("%-36s ft: [", call);
			fflush(stdout);
			ft_putnbr_fd(n[i], 1);
			printf("]  esp: [%d]\n", n[i]);
		}
	}
	printf("%-36s (deve sair na saida de erro)\n", "putstr_fd(\"stderr ok\\n\", 2)");
	fflush(stdout);
	ft_putstr_fd("stderr ok\n", 2);
}

/* ========================= PARTE 3 ========================= */

static int	g_del_count = 0;

static void	del_f(void *content)
{
	g_del_count++;
	free(content);
}

static void	upper_f(void *content)
{
	char	*s;

	s = content;
	while (*s)
	{
		*s = toupper((unsigned char)*s);
		s++;
	}
}

static void	*dup_upper_f(void *content)
{
	char	*s;

	s = strdup(content);
	if (s)
		upper_f(s);
	return (s);
}

static void	test_list(void)
{
	t_list	*lst;
	t_list	*n;
	t_list	*map;

	header("ft_lstnew");
	n = ft_lstnew("42");
	printf("lstnew(\"42\")      content: \"%s\"  next: %s\n",
		n ? (char *)n->content : "?", n && n->next == NULL ? "NULL" : "?");
	free(n);

	header("ft_lstadd_front");
	lst = NULL;
	ft_lstadd_front(&lst, ft_lstnew(strdup("b")));
	ft_lstadd_front(&lst, ft_lstnew(strdup("a")));
	printf("add_front(b), add_front(a)\n  ft:  ");
	print_list(lst);
	printf("  esp: [a] -> [b] -> NULL\n");

	header("ft_lstadd_back");
	ft_lstadd_back(&lst, ft_lstnew(strdup("c")));
	printf("add_back(c)\n  ft:  ");
	print_list(lst);
	printf("  esp: [a] -> [b] -> [c] -> NULL\n");
	n = NULL;
	ft_lstadd_back(&n, ft_lstnew(strdup("x")));
	printf("add_back(x) numa lista vazia\n  ft:  ");
	print_list(n);
	printf("  esp: [x] -> NULL\n");
	ft_lstclear(&n, del_f);

	header("ft_lstsize");
	show_int_esp("lstsize([a]->[b]->[c])", ft_lstsize(lst), 3);
	show_int_esp("lstsize(NULL)", ft_lstsize(NULL), 0);

	header("ft_lstlast");
	show_str("lstlast([a]->[b]->[c])", ft_lstlast(lst)->content, "c", "esp ");
	printf("%-36s ft: %s\n", "lstlast(NULL)", ft_lstlast(NULL) == NULL ? "NULL" : "nao NULL");

	header("ft_lstmap");
	printf("(f = copia em maiusculas; a lista original nao pode mudar)\n");
	map = ft_lstmap(lst, dup_upper_f, del_f);
	printf("  nova:     ");
	print_list(map);
	printf("  esp:      [A] -> [B] -> [C] -> NULL\n");
	printf("  original: ");
	print_list(lst);
	printf("  esp:      [a] -> [b] -> [c] -> NULL\n");

	header("ft_lstiter");
	printf("(f = transforma em maiusculas)\n");
	ft_lstiter(lst, upper_f);
	printf("  ft:  ");
	print_list(lst);
	printf("  esp: [A] -> [B] -> [C] -> NULL\n");

	header("ft_lstdelone");
	g_del_count = 0;
	ft_lstdelone(ft_lstnew(strdup("tmp")), del_f);
	show_int_esp("vezes que del foi chamada", g_del_count, 1);

	header("ft_lstclear");
	g_del_count = 0;
	ft_lstclear(&lst, del_f);
	show_int_esp("vezes que del foi chamada", g_del_count, 3);
	printf("%-36s ft: %s\n", "lista depois do clear", lst == NULL ? "NULL" : "nao NULL");
	ft_lstclear(&map, del_f);
}

int	main(void)
{
	printf(BLUE "\n=================== PARTE 1 - Funcoes da libc ===================\n" RESET);
	test_is("ft_isalpha", ft_isalpha, isalpha);
	test_is("ft_isdigit", ft_isdigit, isdigit);
	test_is("ft_isalnum", ft_isalnum, isalnum);
	test_is("ft_isascii", ft_isascii, orig_isascii);
	test_is("ft_isprint", ft_isprint, isprint);
	test_to("ft_toupper", ft_toupper, toupper);
	test_to("ft_tolower", ft_tolower, tolower);
	test_strlen();
	test_memset_bzero();
	test_memcpy_memmove();
	test_memchr_memcmp();
	test_strlcpy_strlcat();
	test_strchr_strrchr();
	test_strncmp_strnstr();
	test_atoi();
	test_calloc_strdup();
	printf(BLUE "\n=================== PARTE 2 - Funcoes adicionais ===================\n" RESET);
	test_substr_join_trim();
	test_split();
	test_itoa();
	test_mapi_iteri();
	test_put_fd();
	printf(BLUE "\n=================== PARTE 3 - Listas ligadas ===================\n" RESET);
	test_list();
	printf("\n");
	return (0);
}
