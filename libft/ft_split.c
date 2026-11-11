/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos <gcampos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 22:23:27 by gcampos           #+#    #+#             */
/*   Updated: 2026/11/11 00:03:13 by gcampos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') && s[i] != c)
			words++;
		i++;
	}
	return (words);
}

int	ft_word_len(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	*ft_create_word(char const *s, int len)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	*ft_free_matrix(char **matrix, int i)
{
	while (i > 0)
	{
		i--;
		free(matrix[i]);
	}
	free(matrix);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		wcount;
	int		wlen;
	char	**matrix;

	if (!s)
		return (NULL);
	wcount = ft_count_words(s, c);
	matrix = malloc(sizeof(char *) * (wcount + 1));
	if (!matrix)
		return (NULL);
	matrix[wcount] = NULL;
	i = 0;
	while (i < wcount)
	{
		while (*s == c)
			s++;
		wlen = ft_word_len(s, c);
		matrix[i] = ft_create_word(s, wlen);
		if (!matrix[i])
			return (ft_free_matrix(matrix, i));
		s += wlen;
		i++;
	}
	return (matrix);
}
