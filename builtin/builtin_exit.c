/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:13:23 by schung            #+#    #+#             */
/*   Updated: 2022/06/30 20:31:36 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

static bool	num_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
	{
		print_error(SHELL_NAME, "exit", str, "numeric argument required");
		return (FALSE);
	}
	else if ((str[0] == '-' || str[0] == '+') && str[1] != '\0')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			print_error(SHELL_NAME, "exit", str, "numeric argument required");
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

int	builtin_exit(int argc, char **argv, bool subshell, t_list *l_free)
{
	int	exit_num;

	if (!subshell && isatty(STDERR_FILENO))
		ft_putstr_fd("exit\n", STDERR_FILENO);
	exit_num = exec_exit_status_get();
	if (argc >= 2 && num_is_numeric(argv[1]) == FALSE)
		exit_num = 255;
	else if (argc == 2)
		exit_num = ft_atoi(argv[1]);
	else if (argc > 2)
	{
		print_error(SHELL_NAME, "exit", NULL, "too many arguments");
		return (EXIT_FAILURE);
	}
	exec_free_all(argv, l_free);
	exit(exit_num);
}
