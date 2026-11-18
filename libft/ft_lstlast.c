/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos <gcampos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 01:05:04 by gcampos           #+#    #+#             */
/*   Updated: 2026/11/18 20:51:59 by gcampos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

/*int	main(void)
{
	t_list	*lst;
	t_list	*new;
	t_list	*last;

	lst = ft_lstnew("Primeiro");
	new = ft_lstnew("Segundo");
	ft_lstadd_front(&lst, new);
	new = ft_lstnew("Terceiro");
	ft_lstadd_front(&lst, new);
	last = ft_lstlast(lst);
	printf("\nUltimo elemento: %s\n", (char *)last->content);

	return (0);
}
*/