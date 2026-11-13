/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos <gcampos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:58:05 by gcampos           #+#    #+#             */
/*   Updated: 2026/11/13 16:05:38 by gcampos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = dest;
	s = src;
	if (d < s)
		ft_memcpy(d, s, n);
	else
	{
		while (n--)
			d[n] = s[n];
	}
	return (dest);
}
