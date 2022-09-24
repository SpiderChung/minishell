/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:19:59 by schung            #+#    #+#             */
/*   Updated: 2022/09/24 19:20:00 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name: ft_lstnew
 * Description: Allocates (with malloc(3)) and returns a new element. The
 * variable ’content’ is initialized with the value of the parameter ’content’.
 * The variable ’next’ is initialized to NULL.
 * Parameters: #1. The content to create the new element with.
 * Return value: The new element.											  */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (NULL == lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}
