/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampos <gcampos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 03:21:27 by gcampos           #+#    #+#             */
/*   Updated: 2026/11/18 21:01:01 by gcampos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

/*void	*to_upper(void *content)
{
	char	*str;
	int		i;

	str = ft_strdup((char *)content);
	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str[i] = toupper((unsigned char)str[i]);
		i++;
	}
	return (str);
}

void	del_content(void *content)
{
	free(content);
}

void	print_content(void *content)
{
	printf("%s\n", (char *)content);
}

int	main(void)
{
	t_list	*lst;
	t_list	*new_lst;

	lst = ft_lstnew(ft_strdup("ola"));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("mundo")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("libft")));

	printf("Lista original:\n");
	ft_lstiter(lst, print_content);

	new_lst = ft_lstmap(lst, to_upper, del_content);

	printf("\nNova lista (maiusculas):\n");
	ft_lstiter(new_lst, print_content);

	ft_lstclear(&lst, del_content);
	ft_lstclear(&new_lst, del_content);

	return (0);
}
*/