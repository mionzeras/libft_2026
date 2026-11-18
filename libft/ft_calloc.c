/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos <gcampos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 11:40:07 by gcampos           #+#    #+#             */
/*   Updated: 2026/11/18 17:18:24 by gcampos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	len;
	void	*p;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	len = nmemb * size;
	p = malloc(len);
	if (!p)
		return (NULL);
	ft_memset(p, 0, len);
	return (p);
}
