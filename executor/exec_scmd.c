/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_scmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 21:22:44 by schung            #+#    #+#             */
/*   Updated: 2022/06/27 22:22:58 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

int	exec_scmd_preparation(t_list *scmd, char ***argv)
{
	t_list	*l_redir_undo;
	int		status;

	status = 0;
	*argv = NULL;
	if (expand_var(scmd_content(scmd)) == ERROR)
		return (ERROR);
	if (expand_wildcard(scmd_content(scmd)) == ERROR)
		return (ERROR);
	if (scmd_content(scmd)->l_argv)
	{
		*argv = l_token_to_split(scmd_content(scmd)->l_argv);
		if (*argv == NULL)
			return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM)));
	}
	else if (scmd_content(scmd)->l_redir)
	{
		status = redir(scmd_content(scmd)->l_redir, &l_redir_undo);
		if (redir_undo(&l_redir_undo) == ERROR)
			status = ERROR;
	}
	return (status);
}

int	exec_scmd(t_list *scmd, bool subshell, t_list *l_free)
{
	char	**argv;
	int		pid;
	int		status;

	if (exec_scmd_preparation(scmd, &argv) == ERROR)
		return (ERROR);
	if (!(scmd_content(scmd)->l_argv))
		return (0);
	if (scmd_)
}