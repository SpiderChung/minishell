/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:26:05 by schung            #+#    #+#             */
/*   Updated: 2022/09/24 19:26:06 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* re-code the functions strlcat                                              */
/* man strlcat                                                                */
/* size-bounded string concatenation										  */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		i;
	size_t	l;

	l = ft_strlen(src);
	i = 0;
	if (!dstsize)
		return (l);
	while (*dst && dstsize)
	{
		dst++;
		i++;
		dstsize--;
	}
	while (*src && dstsize > 1)
	{
		*dst++ = *src++;
		dstsize--;
	}
	if (dstsize != 0)
		*dst = '\0';
	return (l + i);
}
