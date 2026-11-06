/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos <gcampos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 19:30:57 by gcampos           #+#    #+#             */
/*   Updated: 2026/11/06 21:59:29 by gcampos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (j > i && ft_strchr(set, s1[j - 1]))
		j--;
	trimmed = ft_substr(s1, i, j - i);
	return (trimmed);
}

// int	main(void)
// {
// 	char	*result;

// 	printf("===== TESTES FT_STRTRIM =====\n\n");

// 	// Teste 1: Remover caracteres do início e do fim
// 	result = ft_strtrim("42Porto42", "42");
// 	printf("Teste 1: %s\n", result);
// 	free(result);

// 	// Teste 2: String completamente composta pelo set
// 	result = ft_strtrim("xxxxx", "x");
// 	printf("Teste 2: '%s'\n", result);
// 	free(result);

// 	// Teste 3: Nenhum carácter para remover
// 	result = ft_strtrim("Porto", "x");
// 	printf("Teste 3: %s\n", result);
// 	free(result);

// 	// Teste 4: Remover espaços
// 	result = ft_strtrim("  Porto  ", " ");
// 	printf("Teste 4: %s\n", result);
// 	free(result);

// 	// Teste 5: String vazia
// 	result = ft_strtrim("", "x");
// 	printf("Teste 5: '%s'\n", result);
// 	free(result);

// 	// Teste 6: Set vazio
// 	result = ft_strtrim("Porto", "");
// 	printf("Teste 6: %s\n", result);
// 	free(result);

// 	// Teste 7: Apenas caracteres no início
// 	result = ft_strtrim("xxxPorto", "x");
// 	printf("Teste 7: %s\n", result);
// 	free(result);

// 	// Teste 8: Apenas caracteres no fim
// 	result = ft_strtrim("Portoxxx", "x");
// 	printf("Teste 8: %s\n", result);
// 	free(result);

// 	printf("\n===== FIM DOS TESTES =====\n");

// 	return (0);
// }