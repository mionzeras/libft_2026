/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos <gcampos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 01:08:00 by gcampos           #+#    #+#             */
/*   Updated: 2026/11/18 20:40:22 by gcampos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (!*lst)
		*lst = new;
	else
	{
		node = ft_lstlast(*lst);
		node->next = new;
	}
}

/*int	main(void)
{
	t_list	*lst;
	t_list	*new;
	t_list	*current;

	lst = ft_lstnew("Primeiro");
	new = ft_lstnew("Segundo");
	ft_lstadd_back(&lst, new);

	new = ft_lstnew("Terceiro");
	ft_lstadd_back(&lst, new);

	current = lst;
	while (current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	return (0);
}
*/