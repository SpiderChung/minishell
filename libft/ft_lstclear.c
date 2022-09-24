/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:19:33 by schung            #+#    #+#             */
/*   Updated: 2022/09/24 19:19:34 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name: ft_lstclear
 * Description: Deletes and frees the given element and every successor of that
 * element, using the function ’del’ and free(3). Finally, the pointer to the
 * list must be set to NULL.
 * Parameters: #1. The adress of a pointer to an element. #2. The adress of
 * the function used to delete the content of the element.
 * Return value: None														  */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*curr_lst;
	t_list	*next_lst;

	curr_lst = *lst;
	while (curr_lst)
	{
		next_lst = curr_lst->next;
		ft_lstdelone(curr_lst, del);
		curr_lst = next_lst;
	}
	*lst = NULL;
}
