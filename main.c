/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos <gcampos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2026/11/17 16:41:33 by gcampos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/* funcoes auxiliares usadas nos testes */

char	maiuscula_par(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (ft_toupper(c));
	return (c);
}

void	soma_indice(unsigned int i, char *c)
{
	*c = *c + i;
}

void	para_maiuscula(void *content)
{
	char	*s;

	s = content;
	while (*s)
	{
		*s = ft_toupper(*s);
		s++;
	}
}

void	*copia_maiuscula(void *content)
{
	char	*s;

	s = ft_strdup(content);
	if (s)
		para_maiuscula(s);
	return (s);
}

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("[%s] -> ", (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

int	main(void)
{
	/* ======================= PARTE 1 ======================= */

	printf("\n****************** ft_isalpha ******************\n");
	printf("ft:   %d %d %d\n", ft_isalpha('d'), ft_isalpha('Z'), ft_isalpha('8'));
	printf("orig: %d %d %d\n", !!isalpha('d'), !!isalpha('Z'), !!isalpha('8'));

	printf("\n****************** ft_isdigit ******************\n");
	printf("ft:   %d %d %d\n", ft_isdigit('4'), ft_isdigit('0'), ft_isdigit('B'));
	printf("orig: %d %d %d\n", !!isdigit('4'), !!isdigit('0'), !!isdigit('B'));

	printf("\n****************** ft_isalnum ******************\n");
	printf("ft:   %d %d %d\n", ft_isalnum('a'), ft_isalnum('0'), ft_isalnum('/'));
	printf("orig: %d %d %d\n", !!isalnum('a'), !!isalnum('0'), !!isalnum('/'));

	printf("\n****************** ft_isascii ******************\n");
	printf("ft:   %d %d %d\n", ft_isascii('a'), ft_isascii(127), ft_isascii(130));
	printf("esp:  1 1 0\n");

	printf("\n****************** ft_isprint ******************\n");
	printf("ft:   %d %d %d\n", ft_isprint('a'), ft_isprint(' '), ft_isprint('\n'));
	printf("orig: %d %d %d\n", !!isprint('a'), !!isprint(' '), !!isprint('\n'));

	printf("\n****************** ft_toupper ******************\n");
	printf("ft:   %c %c %c\n", ft_toupper('g'), ft_toupper('G'), ft_toupper('5'));
	printf("orig: %c %c %c\n", toupper('g'), toupper('G'), toupper('5'));

	printf("\n****************** ft_tolower ******************\n");
	printf("ft:   %c %c %c\n", ft_tolower('G'), ft_tolower('g'), ft_tolower('5'));
	printf("orig: %c %c %c\n", tolower('G'), tolower('g'), tolower('5'));

	printf("\n****************** ft_strlen ******************\n");
	printf("ft:   %zu %zu\n", ft_strlen("Gabriel Augusto"), ft_strlen(""));
	printf("orig: %zu %zu\n", strlen("Gabriel Augusto"), strlen(""));

	printf("\n****************** ft_memset ******************\n");
	char	m1[] = "Olha la quem vem";
	char	m2[] = "Olha la quem vem";
	ft_memset(m1, 'x', 3);
	memset(m2, 'x', 3);
	printf("ft:   %s\n", m1);
	printf("orig: %s\n", m2);

	printf("\n****************** ft_bzero ******************\n");
	char	b1[] = "Gabriel";
	char	b2[] = "Gabriel";
	ft_bzero(b1, 3);
	bzero(b2, 3);
	printf("ft:   ");
	for (int i = 0; i < 7; i++)
		printf("[%c]", b1[i] ? b1[i] : '0');
	printf("\norig: ");
	for (int i = 0; i < 7; i++)
		printf("[%c]", b2[i] ? b2[i] : '0');
	printf("\n(o '0' representa o byte zerado)\n");

	printf("\n****************** ft_memcpy ******************\n");
	char	c1[15] = "";
	char	c2[15] = "";
	ft_memcpy(c1, "Ola mundo", 10);
	memcpy(c2, "Ola mundo", 10);
	printf("ft:   %s\n", c1);
	printf("orig: %s\n", c2);

	printf("\n****************** ft_memmove ******************\n");
	char	mv1[] = "0123456789";
	char	mv2[] = "0123456789";
	ft_memmove(mv1 + 2, mv1, 5);
	memmove(mv2 + 2, mv2, 5);
	printf("ft:   %s\n", mv1);
	printf("orig: %s\n", mv2);
	printf("(origem e destino se sobrepoem, o memcpy nao garante isso)\n");

	printf("\n****************** ft_strlcpy ******************\n");
	char	dst[15];
	size_t	ret;
	ret = ft_strlcpy(dst, "Aqui vai", 4);
	printf("ft:   %zu, \"%s\"\n", ret, dst);
	printf("esp:  8, \"Aqu\"\n");

	printf("\n****************** ft_strlcat ******************\n");
	char	dest[14] = "123";
	ret = ft_strlcat(dest, "456", 14);
	printf("ft:   %zu, \"%s\"\n", ret, dest);
	printf("esp:  6, \"123456\"\n");
	char	dest2[14] = "123";
	ret = ft_strlcat(dest2, "456789", 5);
	printf("ft:   %zu, \"%s\"\n", ret, dest2);
	printf("esp:  9, \"1234\"\n");

	printf("\n****************** ft_strchr ******************\n");
	char	g[] = "If i had money";
	printf("ft:   %s\n", ft_strchr(g, 'a'));
	printf("orig: %s\n", strchr(g, 'a'));

	printf("\n****************** ft_strrchr ******************\n");
	char	g1[] = "My name is Gabriel";
	printf("ft:   %s\n", ft_strrchr(g1, 'a'));
	printf("orig: %s\n", strrchr(g1, 'a'));

	printf("\n****************** ft_strncmp ******************\n");
	printf("ft:   %d %d %d\n", ft_strncmp("abcdef", "abcxyz", 3),
		ft_strncmp("abcdef", "abcxyz", 6), ft_strncmp("abc", "abcd", 4));
	printf("orig: %d %d %d\n", strncmp("abcdef", "abcxyz", 3),
		strncmp("abcdef", "abcxyz", 6), strncmp("abc", "abcd", 4));
	printf("(o valor pode ser diferente, mas o sinal deve ser igual)\n");

	printf("\n****************** ft_memchr ******************\n");
	char	f3[] = "Gabriel sou eu";
	printf("ft:   %s\n", (char *)ft_memchr(f3, 's', 14));
	printf("orig: %s\n", (char *)memchr(f3, 's', 14));

	printf("\n****************** ft_memcmp ******************\n");
	printf("ft:   %d %d\n", ft_memcmp("abcdef", "abcdef", 6),
		ft_memcmp("abcdef", "abcdzz", 6));
	printf("orig: %d %d\n", memcmp("abcdef", "abcdef", 6),
		memcmp("abcdef", "abcdzz", 6));
	printf("(o valor pode ser diferente, mas o sinal deve ser igual)\n");

	printf("\n****************** ft_strnstr ******************\n");
	char	big[] = "Gabriel Augusto Campos Rodrigues";
	printf("ft:   %s\n", ft_strnstr(big, "Campos", 40));
	printf("esp:  Campos Rodrigues\n");
	printf("ft:   %s\n", ft_strnstr(big, "Campos", 10));
	printf("esp:  (null)\n");

	printf("\n****************** ft_atoi ******************\n");
	printf("ft:   %d %d %d %d\n", ft_atoi("\t\n\r\v\f  469 \n"), ft_atoi("-42abc"),
		ft_atoi("-2147483648"), ft_atoi("--5"));
	printf("orig: %d %d %d %d\n", atoi("\t\n\r\v\f  469 \n"), atoi("-42abc"),
		atoi("-2147483648"), atoi("--5"));

	printf("\n****************** ft_calloc ******************\n");
	int		*arr;
	arr = ft_calloc(4, sizeof(int));
	printf("ft:   %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3]);
	printf("esp:  0 0 0 0\n");
	free(arr);

	printf("\n****************** ft_strdup ******************\n");
	char	*d1;
	char	*d2;
	d1 = ft_strdup("Gabriel Augusto");
	d2 = strdup("Gabriel Augusto");
	printf("ft:   %s\n", d1);
	printf("orig: %s\n", d2);
	free(d1);
	free(d2);

	/* ======================= PARTE 2 ======================= */

	char	*s;

	printf("\n****************** ft_substr ******************\n");
	s = ft_substr("Gabriel Augusto", 3, 4);
	printf("ft:   \"%s\"\n", s);
	printf("esp:  \"riel\"\n");
	free(s);
	s = ft_substr("Gabriel", 20, 4);
	printf("ft:   \"%s\"\n", s);
	printf("esp:  \"\"\n");
	free(s);

	printf("\n****************** ft_strjoin ******************\n");
	s = ft_strjoin("Gabriel", " Augusto");
	printf("ft:   \"%s\"\n", s);
	printf("esp:  \"Gabriel Augusto\"\n");
	free(s);

	printf("\n****************** ft_strtrim ******************\n");
	s = ft_strtrim("aaacaaGabrielaaaaba", "abc");
	printf("ft:   \"%s\"\n", s);
	printf("esp:  \"Gabriel\"\n");
	free(s);

	printf("\n****************** ft_split ******************\n");
	char	**words;
	words = ft_split("  Gabriel Augusto  Campos Rodrigues ", ' ');
	printf("ft:   ");
	for (int i = 0; words[i]; i++)
		printf("\"%s\" ", words[i]);
	printf("NULL\n");
	printf("esp:  \"Gabriel\" \"Augusto\" \"Campos\" \"Rodrigues\" NULL\n");
	for (int i = 0; words[i]; i++)
		free(words[i]);
	free(words);

	printf("\n****************** ft_itoa ******************\n");
	s = ft_itoa(-2147483648);
	printf("ft:   %s", s);
	free(s);
	s = ft_itoa(0);
	printf(" %s", s);
	free(s);
	s = ft_itoa(42);
	printf(" %s\n", s);
	free(s);
	printf("esp:  -2147483648 0 42\n");

	printf("\n****************** ft_strmapi ******************\n");
	s = ft_strmapi("gabriel", maiuscula_par);
	printf("ft:   \"%s\"\n", s);
	printf("esp:  \"GaBrIeL\"\n");
	free(s);

	printf("\n****************** ft_striteri ******************\n");
	char	it[] = "aaaa";
	ft_striteri(it, soma_indice);
	printf("ft:   \"%s\"\n", it);
	printf("esp:  \"abcd\"\n");

	printf("\n****************** ft_putchar_fd ******************\n");
	printf("ft:   ");
	fflush(stdout);
	ft_putchar_fd('H', 1);
	printf("\nesp:  H\n");

	printf("\n****************** ft_putstr_fd ******************\n");
	printf("ft:   ");
	fflush(stdout);
	ft_putstr_fd("Helloooo", 1);
	printf("\nesp:  Helloooo\n");

	printf("\n****************** ft_putendl_fd ******************\n");
	printf("ft:   ");
	fflush(stdout);
	ft_putendl_fd("Helloooo", 1);
	printf("esp:  Helloooo (com quebra de linha)\n");

	printf("\n****************** ft_putnbr_fd ******************\n");
	printf("ft:   ");
	fflush(stdout);
	ft_putnbr_fd(-2147483648, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(0, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(42, 1);
	printf("\nesp:  -2147483648 0 42\n");

	/* ======================= PARTE 3 ======================= */

	t_list	*lst;
	t_list	*copia;

	printf("\n****************** ft_lstnew ******************\n");
	lst = ft_lstnew(ft_strdup("b"));
	printf("ft:   ");
	print_list(lst);
	printf("esp:  [b] -> NULL\n");

	printf("\n****************** ft_lstadd_front ******************\n");
	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("a")));
	printf("ft:   ");
	print_list(lst);
	printf("esp:  [a] -> [b] -> NULL\n");

	printf("\n****************** ft_lstadd_back ******************\n");
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("c")));
	printf("ft:   ");
	print_list(lst);
	printf("esp:  [a] -> [b] -> [c] -> NULL\n");

	printf("\n****************** ft_lstsize ******************\n");
	printf("ft:   %d\n", (int)ft_lstsize(lst));
	printf("esp:  3\n");

	printf("\n****************** ft_lstlast ******************\n");
	printf("ft:   %s\n", (char *)ft_lstlast(lst)->content);
	printf("esp:  c\n");

	printf("\n****************** ft_lstmap ******************\n");
	copia = ft_lstmap(lst, copia_maiuscula, free);
	printf("ft:   ");
	print_list(copia);
	printf("esp:  [A] -> [B] -> [C] -> NULL\n");
	printf("original (nao pode mudar): ");
	print_list(lst);

	printf("\n****************** ft_lstiter ******************\n");
	ft_lstiter(lst, para_maiuscula);
	printf("ft:   ");
	print_list(lst);
	printf("esp:  [A] -> [B] -> [C] -> NULL\n");

	printf("\n****************** ft_lstdelone ******************\n");
	t_list	*sozinho;
	sozinho = ft_lstnew(ft_strdup("tchau"));
	ft_lstdelone(sozinho, free);
	printf("(sem saida: confira com o valgrind se nao ha leak)\n");

	printf("\n****************** ft_lstclear ******************\n");
	ft_lstclear(&lst, free);
	ft_lstclear(&copia, free);
	printf("ft:   %p %p\n", (void *)lst, (void *)copia);
	printf("esp:  (nil) (nil)\n");

	printf("\n");
	return (0);
}
