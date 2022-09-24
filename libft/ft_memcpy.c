/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:25:08 by schung            #+#    #+#             */
/*   Updated: 2022/09/24 19:25:09 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* re-code the functions memcpy                                               */
/* man memcpy                                                                 */
/* The memcpy() function copies n bytes from memory area src to memory area   */
/* dst.  If dst and src overlap, behavior is undefined.  Applications in which*/
/* dst and src might overlap should use memmove(3) instead.					  */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	if (!(dst || src))
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dst);
}
