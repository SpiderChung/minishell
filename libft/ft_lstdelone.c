/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:19:38 by schung            #+#    #+#             */
/*   Updated: 2022/09/24 19:19:39 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name: ft_lstdelone
 * Description: Takes as a parameter an element and frees the memory of the 
 * element’s content using the function ’del’ given as a parameter and free 
 * the element. The memory of ’next’ must not be freed.
 * Parameters: #1. The element to free. #2. The address of the function used 
 * to delete the content.
 * Return value: None														  */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
		lst = NULL;
	}
}
