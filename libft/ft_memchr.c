/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:20:09 by schung            #+#    #+#             */
/*   Updated: 2022/09/24 19:24:59 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* re-code the functions memchr                                               */
/* man memchr                                                                 */
/* locate byte in byte string. The memchr() function locates the first 		  */
/* occurrence of c (converted to an unsigned char) in string s.				  */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
