/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:33:09 by schung            #+#    #+#             */
/*   Updated: 2022/06/30 19:52:19 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

int	builtin_pwd(int argc __attribute((unused)),
	char **argv __attribute((unused)))
{
	char	buf[PATH_MAX];

	if (getcwd(buf, sizeof(buf)))
	{
		ft_putendl_fd(buf, STDOUT_FILENO);
		return (0);
	}
	else
	{
		print_error_errno(SHELL_NAME, "pwd", NULL);
		return (EXIT_FAILURE);
	}
}
