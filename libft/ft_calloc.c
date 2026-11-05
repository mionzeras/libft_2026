/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos <gcampos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 11:40:07 by gcampos           #+#    #+#             */
/*   Updated: 2026/11/05 11:52:38 by gcampos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	len;
	void	*p;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	len = nmemb * size;
	p = malloc(len);
	if (!p)
		return (NULL);
	ft_memset(p, 0, len);
	return (p);
}
