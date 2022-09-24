/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:58:27 by schung            #+#    #+#             */
/*   Updated: 2022/09/24 18:58:29 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/builtin.h"

int	builtin_pwd( \
	int argc __attribute__((unused)), \
	char **argv __attribute__((unused)))
{
	char	buf[PATH_MAX];

	if (getcwd(buf, sizeof(buf)))
	{
		ft_putendl_fd(buf, STDOUT_FILENO);
		return (EXIT_SUCCESS);
	}
	print_error_errno(SHELL_NAME, "pwd", NULL);
	return (EXIT_FAILURE);
}
