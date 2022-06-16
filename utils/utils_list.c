/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:25:30 by schung            #+#    #+#             */
/*   Updated: 2022/06/15 20:40:46 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	lst_node_remove(t_list **list, t_list *node, void (*del)(void *))
{
	t_list	*temp;

	if (!list || !(*list) || !node)
		return (ERROR);
	if (node == *list)
		*list = node->next;
	else
	{
		temp = *list;
		while (temp->next && temp->next != node)
			temp = temp->next;
		if (temp->next != node)
			return (ERROR);
		temp->next = node->next;
	}
	ft_lstdelone(node, del);
	return (0);
}

t_list	*lst_node_prev(t_list *lst, t_list *node)
{
	if (lst == node)
		return (node);
	while (lst->next && lst->next != node)
		lst = lst->next;
	if (lst->next != node)
		return (NULL);
	return (lst);
}

int	lst_relink(t_list **lst, t_list *node, t_list *start, t_list *end)
{
	t_list	*prev;

	prev = lst_node_prev(*lst, start);
	if (prev == NULL)
		return (ERROR);
	if (start == *lst)
		*lst = node;
	else
		prev->next = node;
	if (end == NULL)
		node->next = NULL;
	else
		node->next = end->next;
	return (0);
}