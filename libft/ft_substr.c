/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:26:47 by schung            #+#    #+#             */
/*   Updated: 2022/09/24 19:26:48 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name: ft_substr
 * Description: Allocates (with malloc(3)) and returns a substring from the
 * string ’s’. The substring begins at index ’start’ and is of maximum size
 * ’len’.
 * Parameters: #1. The string from which to create the substring. #2. The
 * start index of the substring in the string ’s’. #3.The maximum length of
 * the substring.
 * Return value: The substring.  NULL if the allocation fails.				  */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	sub_len;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	sub_len = ft_strlen(s + start);
	if (sub_len < len)
		len = sub_len;
	sub_str = (char *)malloc(sizeof(char) * (len + 1));
	if (NULL == sub_str)
		return (NULL);
	ft_strlcpy(sub_str, s + start, len + 1);
	return (sub_str);
}
