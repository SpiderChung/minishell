/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:37:41 by schung            #+#    #+#             */
/*   Updated: 2022/05/08 16:50:18 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

char	**g_env = NULL;

static char	*get_input(void)
{
	char	*input;
	char	*prompt;

	prompt = env_get_value("PS1");
	if (prompt == NULL)
		prompt = PROMPT;
	if (isatty(STDIN_FILENO))
		input = readline(prompt);
	else
		input = get_next_line(STDIN_FILENO);
	if (input == NULL)
		return (NULL);
	else if (isatty(STDIN_FILENO) && input && input[0])
		add_history(input);
	return (input);
}

static void	process_input(char *input)
{
	ft_putstr_fd(input, STDOUT_FILENO);
}

int	main(void)
{
	char		*input;

	signal(SIGQUIT, SIG_IGN);
	if (env_init() == ERROR)
		return (EXIT_FAILURE);
	while (42)
	{
		signal(SIGINT, signal_tckl);
		termios_change(FALSE);
		input = get_input();
		if (input == NULL)
		{
			if (isatty(STDERR_FILENO))
				ft_putendl_fd("exit", STDERR_FILENO);
			termios_change(TRUE);
			break ;
		}
		process_input(input);
	}
	rl_clear_history();
	if (g_env)
		ft_free(&g_env);
	exit (0);
}
