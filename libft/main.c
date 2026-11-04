/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos <gcampos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:30:17 by gcampos           #+#    #+#             */
/*   Updated: 2026/11/04 20:12:15 by gcampos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	char			*str;
	char			g[50];
	unsigned int	result;

	str = "Gabriel";
	g[0] = 'a';
	g[1] = 'b';
	g[2] = 'c';
	g[3] = '\0';
	printf("Before: %s\n", g);
	result = ft_strlcpy(g, str, 8);
	printf("After: %s\n", g);
	printf("Return: %u\n", result);

	char	*big;
	char	*little;
	char	*result1;

	big = "42 Lisboa";
	little = "Lisboa";

	result1 = ft_strnstr(big, little, 5);

	if (result1)
		printf("Encontrado: %s\n", result1);
	else
		printf("Nao encontrado!\n");

	return (0);
}
