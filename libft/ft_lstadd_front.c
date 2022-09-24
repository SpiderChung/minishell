/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:19:29 by schung            #+#    #+#             */
/*   Updated: 2022/09/24 19:19:30 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name: ft_lstadd_front
 * Description: Adds the element ’new’ at the beginning of the list.
 * Parameters: #1. The address of a pointer to the first link of a list.
 * #2. The address of a pointer to the element to be added to the list.
 * Return value: None														  */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst && new)
		new->next = *lst;
	*lst = new;
}
