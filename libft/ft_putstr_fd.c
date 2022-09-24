/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:25:36 by schung            #+#    #+#             */
/*   Updated: 2022/09/24 19:25:37 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name: ft_putstr_fd
 * Description: Outputs the string ’s’ to the given file descriptor.
 * Parameters: #1. The string to output. #2. The file descriptor on which to
 * write.
 * Return value: None														  */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s && fd >= 0)
		write(fd, s, ft_strlen(s));
}
