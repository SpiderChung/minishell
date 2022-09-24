/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:19:11 by schung            #+#    #+#             */
/*   Updated: 2022/09/24 19:19:12 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* re-code the functions isdigit                                              */
/* man isdigit                                                                */
/* The isdigit() function tests for a decimal digit character.				  */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
