/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_scmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 21:22:44 by schung            #+#    #+#             */
/*   Updated: 2022/06/24 21:27:11 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

int	exec_scmd_preparation(t_list *scmd, char ***argv)
{
	t_list	*l_redir_undo;
	int		status;

	status = 0;
	*argv = NULL;
}

int	exec_scmd(t_list *scmd, bool subshell, t_list *l_free)
{
	char	**argv;
	int		pid;
	int		status;

	if (exec_scmd_preparation(scmd, &argv)
}