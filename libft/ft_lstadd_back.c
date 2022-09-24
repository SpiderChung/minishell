/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:19:25 by schung            #+#    #+#             */
/*   Updated: 2022/09/24 19:19:26 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name: ft_lstadd_back
 * Description: Adds the element ’new’ at the end of the list.
 * Parameters: #1. The address of a pointer to the first link of a list.
 * #2. The address of a pointer to the element to be added to the list.
 * Return value: None														  */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (lst)
	{
		if (NULL == *lst)
			*lst = new;
		else
		{
			tmp = ft_lstlast(*lst);
			tmp->next = new;
		}
	}
}
