/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos <gcampos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 03:03:16 by gcampos           #+#    #+#             */
/*   Updated: 2026/11/18 20:44:09 by gcampos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}

/*void	del_content(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*lst;
	t_list	*new;
	t_list	*current;

	lst = NULL;

	new = ft_lstnew(ft_strdup("Primeiro"));
	ft_lstadd_back(&lst, new);

	new = ft_lstnew(ft_strdup("Segundo"));
	ft_lstadd_back(&lst, new);

	new = ft_lstnew(ft_strdup("Terceiro"));
	ft_lstadd_back(&lst, new);

	printf("Antes de ft_lstclear:\n");
	current = lst;
	while (current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}

	ft_lstclear(&lst, del_content);

	printf("\nDepois de ft_lstclear:\n");
	if (!lst)
		printf("Lista vazia!\n");

	return (0);
}
*/