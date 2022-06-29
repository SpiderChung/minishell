/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_group.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:17:44 by schung            #+#    #+#             */
/*   Updated: 2022/06/29 19:20:45 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

int	exec_group(t_list *l_cmd, t_list *l_free)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid == -1)
		return (print_error_errno(SHELL_NAME, NULL, NULL));
	if (pid == 0)
	{
		status = exec_recursive(cmd_content(l_cmd)->l_element, TRUE, l_free);
		exec_free_all(NULL, l_free);
		exit(status);
	}
	return (exec_wait_pid(pid, NULL));
}

