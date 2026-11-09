/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayblmouh <ayblmouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 14:12:09 by ayblmouh          #+#    #+#             */
/*   Updated: 2026/11/09 14:46:40 by ayblmouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	del(void *x)
{
	free(x);
}

void	*toupper(void *count)
{
	char	*str;
	char	*new_str;
	int		i;

	str = (char *)count;
	new_str = ft_strdup(str);
	i = 0;
	while (new_str[i])
	{
		if (new_str[i] >= 'a' && new_str[i] <= 'z')
			new_str[i] -= 32;
		i++;
	}
	return ((void *)new_str);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_list;
	void	*cont;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		cont = f(lst->content);
		new_node = ft_lstnew(cont);
		if (new_node)
			ft_lstadd_back(&new_list, new_node);
		else
		{
			del(cont);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (new_list);
}

#include <stdio.h>

int	main(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;
	t_list	*new_one;

	head = NULL;
	node1 = ft_lstnew(ft_strdup("Hello ayb"));
	node2 = ft_lstnew(ft_strdup("Hello world"));
	if (!node1 || !node2)
		return (1);
	head = node1;
	node1->next = node2;
	printf("1: %s\n", (char *)head->content);
	printf("1: %s\n", (char *)head->next->content);
	new_one = ft_lstmap(head, toUpper, del);
	printf("2: %s\n", (char *)new_one->content);
	printf("2: %s\n", (char *)new_one->next->content);
	ft_lstclear(&head, del);
	ft_lstclear(&new_one, del);
}
