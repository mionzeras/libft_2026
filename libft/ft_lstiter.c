/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos <gcampos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 03:18:32 by gcampos           #+#    #+#             */
/*   Updated: 2026/11/18 20:45:13 by gcampos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*void	del_content(void *content)
{
	(void)content;
}

void	print_content(void *content)
{
	printf("%s\n", (char *)content);
}

int	main(void)
{
	t_list	*lst;
	t_list	*new;

	lst = ft_lstnew("Primeiro");

	new = ft_lstnew("Segundo");
	ft_lstadd_back(&lst, new);

	new = ft_lstnew("Terceiro");
	ft_lstadd_back(&lst, new);

	printf("Conteudo da lista:\n");
	ft_lstiter(lst, print_content);

	ft_lstclear(&lst, del_content);
	return (0);
}
*/