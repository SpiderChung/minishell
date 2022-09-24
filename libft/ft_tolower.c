/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:26:51 by schung            #+#    #+#             */
/*   Updated: 2022/09/24 19:26:52 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* re-code the functions tolower                                              */
/* man tolower                                                                */
/* The tolower() function converts an upper-case letter to the corresponding  */
/* lower-case letter.														  */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
