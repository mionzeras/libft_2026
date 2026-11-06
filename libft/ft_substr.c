/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos <gcampos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 18:43:53 by gcampos           #+#    #+#             */
/*   Updated: 2026/11/06 19:06:49 by gcampos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

// int	main(void)
// {
// 	char	*str;

// 	str = ft_substr("Hello World", 0, 5);
// 	printf("Test 1: %s\n", str);
// 	free(str);

// 	str = ft_substr("Hello World", 6, 5);
// 	printf("Test 2: %s\n", str);
// 	free(str);

// 	str = ft_substr("Hello World", 2, 3);
// 	printf("Test 3: %s\n", str);
// 	free(str);

// 	str = ft_substr("Hello World", 0, 20);
// 	printf("Test 4: %s\n", str);
// 	free(str);

// 	str = ft_substr("Hello World", 20, 5);
// 	printf("Test 5: '%s'\n", str);
// 	free(str);

// 	str = ft_substr("Hello World", 3, 0);
// 	printf("Test 6: '%s'\n", str);
// 	free(str);

// 	return (0);
// }