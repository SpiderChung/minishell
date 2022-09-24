/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:25:27 by schung            #+#    #+#             */
/*   Updated: 2022/09/24 19:25:28 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function name: ft_putendl_fd
 * Description: Outputs the string ’s’ to the given file descriptor, followed
 * by a newline.
 * Parameters: #1. The string to output. #2. The file descriptor on which to
 * write.
 * Return value: None									 					  */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
