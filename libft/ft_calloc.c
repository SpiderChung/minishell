/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:18:22 by schung            #+#    #+#             */
/*   Updated: 2022/09/24 19:18:23 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* re-code the functions calloc                                               */
/* man calloc                                                                 */
/* Memory allocation 														  */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dst;

	dst = malloc(count * size);
	if (NULL == dst)
		return (NULL);
	ft_bzero(dst, count * size);
	return (dst);
}
