/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos <gcampos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 00:20:25 by gcampos           #+#    #+#             */
/*   Updated: 2026/11/18 20:58:34 by gcampos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/*int	main(void)
{
	t_list	*node;

	node = ft_lstnew("Ola Libft!");

	if (!node)
	{
		printf("Erro ao criar o no.\n");
		return (1);
	}

	printf("Conteudo: %s\n", (char *)node->content);

	if (node->next == NULL)
		printf("Next: NULL\n");

	free(node);
	return (0);
}
*/