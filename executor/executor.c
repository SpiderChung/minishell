/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:57:02 by schung            #+#    #+#             */
/*   Updated: 2022/06/30 20:25:28 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

static bool	exec_operator_skip(t_list *l_cmd)
{
	if (cmd_content(l_cmd)->type & CMD_AND && exec_exit_status_get() != 0)
		return (TRUE);
	else if (cmd_content(l_cmd)->type & CMD_OR && exec_exit_status_get() == 0)
		return (TRUE);
	else
		return (FALSE);
}

void	exec_free_all(char **argv, t_list *l_free)
{
	if (argv)
		ft_free_split(&argv);
	if (l_free)
		ft_lstclear(&l_free, c_cmd_destroy);
	if (g_env)
		ft_free_split(&g_env);
	rl_clear_history();
}

int	exec_recursive(t_list *l_cmd, bool subshell, t_list *l_free)
{
	if (cmd_type(l_cmd) == CMD_SCMD)
		exec_exit_status_set(exec_scmd(l_cmd, subshell, l_free));
	else if (cmd_type(l_cmd) == CMD_PIPELINE)
		exec_exit_status_set(exec_pipeline(l_cmd, l_free));
	else if (cmd_type(l_cmd) == CMD_GROUP)
		exec_exit_status_set(exec_group(l_cmd, l_free));
	if (l_cmd->next)
	{
		l_cmd = l_cmd->next;
		while (l_cmd && exec_operator_skip(l_cmd))
			l_cmd = l_cmd->next->next;
		if (l_cmd != NULL)
			exec_exit_status_set(exec_recursive(l_cmd->next, subshell, l_free));
	}
	return (exec_exit_status_get());
}
