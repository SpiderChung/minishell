/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:25:13 by schung            #+#    #+#             */
/*   Updated: 2022/09/24 19:25:14 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* re-code the functions memmove                                              */
/* man memmove                                                                */
/* The memmove() function copies len bytes from string src to string dst.	  */
/* The two strings may overlap; the copy is always done in a non-destructive  */
/* manner.																	  */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;

	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
	{
		d = (unsigned char *)dst;
		s = (unsigned char *)src;
		while (len--)
			*d++ = *s++;
	}
	else
	{
		d = (unsigned char *)dst + (len - 1);
		s = (unsigned char *)src + (len - 1);
		while (len--)
			*d-- = *s--;
	}
	return (dst);
}
