/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:25:51 by schung            #+#    #+#             */
/*   Updated: 2022/09/24 19:25:52 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* re-code the functions strdup                                               */
/* man strdup                                                                 */
/* strdup - save a copy of a string. The strdup() function allocates		  */
/* sufficient memory for a copy of the string s1, does the copy, and returns  */
/* a pointer to it.															  */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str_cpy;
	size_t	i;

	i = ft_strlen(s1) + 1;
	str_cpy = (char *)malloc(sizeof(char) * i);
	if (NULL == str_cpy)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str_cpy[i] = s1[i];
		i++;
	}
	str_cpy[i] = '\0';
	return (str_cpy);
}
