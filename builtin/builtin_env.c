/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:33:18 by schung            #+#    #+#             */
/*   Updated: 2022/06/30 19:47:45 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

int	builtin_env(int argc __attribute((unused)),
	char **argv __attribute((unused)))
{
	int	i;

	if (g_env == NULL)
	{
		print_error(SHELL_NAME, "env", NULL, "environ not set");
		return (EXIT_FAILURE);
	}
	i = 0;
	while (g_env[i])
	{
		ft_putendl_fd(g_env[i], STDOUT_FILENO);
		i++;
	}
	return (0);
}
