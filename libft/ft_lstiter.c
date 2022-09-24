/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:19:43 by schung            #+#    #+#             */
/*   Updated: 2022/09/24 19:19:44 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name: ft_lstiter
 * Description: Iterates the list ’lst’ and applies the function ’f’ to the
 * content of each element.
 * Parameters: #1. The adress of a pointer to an element. #2. The adress of
 * the function used to iterate on the list.
 * Return value: None														  */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst && f)
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}
