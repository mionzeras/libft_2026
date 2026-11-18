/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos <gcampos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 00:55:39 by gcampos           #+#    #+#             */
/*   Updated: 2026/11/18 21:00:28 by gcampos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*void	del_content(void *content)
{
	(void)content;
}

int	main(void)
{
	t_list	*lst;
	t_list	*new;
	unsigned int	size;

	lst = ft_lstnew("Primeiro");

	new = ft_lstnew("Segundo");
	ft_lstadd_back(&lst, new);

	new = ft_lstnew("Terceiro");
	ft_lstadd_back(&lst, new);

	new = ft_lstnew("Quarto");
	ft_lstadd_back(&lst, new);

	size = ft_lstsize(lst);

	printf("Numero de nos na lista: %u\n", size);

	ft_lstclear(&lst, del_content);

	return (0);
}
*/