/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:18:09 by schung            #+#    #+#             */
/*   Updated: 2022/09/24 19:18:11 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* recode atoi() function													  */
/* man atoi																	  */
/* Convert ASCII string to integer. The atoi() function converts the initial  */
/* portion of the string pointed to by str to int representation.			  */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t			i;
	int				sign;
	unsigned long	num;
	unsigned long	b;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	num = 0;
	b = __LONG_LONG_MAX__ / 10;
	while (ft_isdigit(str[i]))
	{
		if ((num > b || (num == b && (str[i] - '0') > 7)) && sign == 1)
			return (-1);
		else if ((num > b || (num == b && (str[i] - '0') > 8)) && sign == -1)
			return (0);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(sign * num));
}
