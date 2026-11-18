/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos <gcampos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 00:33:33 by gcampos           #+#    #+#             */
/*   Updated: 2026/11/18 20:40:33 by gcampos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*int	main(void)
{
	t_list	*lst;
	t_list	*new;
	t_list	*current;

	lst = ft_lstnew("Primeiro");

	new = ft_lstnew("Segundo");
	ft_lstadd_front(&lst, new);

	new = ft_lstnew("Terceiro");
	ft_lstadd_front(&lst, new);

	current = lst;
	while (current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	return (0);
}
*/