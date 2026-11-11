/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos <gcampos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 21:19:10 by gcampos           #+#    #+#             */
/*   Updated: 2026/11/10 17:40:38 by gcampos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size(long nb)
{
	int	i;

	i = 0 ;
	if (nb <= 0)
	{
		i++;
		nb *= -1;
	}
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

void	make_str(char *s, long n, int size)
{
	s[size--] = '\0';
	if (n < 0)
	{
		s[0] = '-';
		n *= -1;
	}
	else if (n == 0)
		s[0] = '0';
	while (n > 0)
	{
		s[size] = (n % 10) + '0';
		n /= 10;
		size--;
	}
}

char	*ft_itoa(int n)
{
	int		size;
	long	nb;
	char	*str;

	size = ft_size(n);
	nb = n;
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	make_str(str, nb, size);
	return (str);
}
