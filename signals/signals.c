/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 19:17:38 by schung            #+#    #+#             */
/*   Updated: 2022/05/08 16:50:03 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	signal_tckl(int sig)
{
	if (sig == SIGINT)
	{
		write(STDERR_FILENO, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

int	termios_change(bool echo_ctl)
{
	struct termios	my_termios;
	int				status;

	status = tcgetattr(STDOUT_FILENO, &my_termios);
	if (status == -1)
		return (ERROR);
	if (echo_ctl)
		my_termios.c_lflag |= ECHOCTL;
	else
		my_termios.c_lflag &= ~(ECHOCTL);
	status = tcsetattr(STDOUT_FILENO, TCSANOW, &my_termios);
	if (status == -1)
		return (ERROR);
	return (0);
}