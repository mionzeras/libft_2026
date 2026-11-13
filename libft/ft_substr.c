/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos <gcampos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 18:43:53 by gcampos           #+#    #+#             */
/*   Updated: 2026/11/13 16:18:34 by gcampos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	real_size;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	real_size = ft_strlen(s) - start;
	if (real_size > len)
		real_size = len;
	str = malloc(sizeof(char) * (real_size + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, real_size + 1);
	return (str);
}
