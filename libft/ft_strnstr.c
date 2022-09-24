/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:26:31 by schung            #+#    #+#             */
/*   Updated: 2022/09/24 19:26:32 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* re-code the functions strnstr                                              */
/* man strnstr                                                                */
/* locate a substring in a string. The strnstr() function locates the first   */
/* occurrence of the null-terminated string needle in the string haystack, 	  */
/* where not more than len characters are searched							  */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	j = 0;
	while (haystack[i] && (i + j) < len)
	{
		if (haystack[i + j] == needle[j])
		{
			if (needle[++j] == '\0')
				return ((char *)haystack + i);
		}
		else
		{
			j = 0;
			i++;
		}
	}
	return (NULL);
}
