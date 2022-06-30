/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:32:07 by schung            #+#    #+#             */
/*   Updated: 2022/06/30 20:32:47 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

int	builtin_echo(int argc __attribute((unused)), char **argv)
{
	int		i;
	bool	new_line;

	new_line = FALSE;
	i = 1;
	while (argv[i] && !ft_strncmp(argv[i], "-n", 3))
		i++;
	if (i == 1)
		new_line = TRUE;
	while (argv[i])
	{
		ft_putstr_fd(argv[i], 1);
		if (argv[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (new_line)
		ft_putchar_fd('\n', 1);
	return (0);
}
