/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 21:02:13 by schung            #+#    #+#             */
/*   Updated: 2022/06/29 19:15:46 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

static void	pipeline_scmd(t_list *scmd, t_list *l_free)
{
	char	**argv;
	int		status;

	if (exec_scmd_preparation(scmd, &argv) == ERROR)
		exec_scmd_free_exit(EXIT_FAILURE, argv, l_free);
	if (redir(scmd_content(scmd)->l_redir, NULL) == ERROR)
		exec_scmd_free_exit(EXIT_FAILURE, argv, l_free);
	if (!(scmd_content(scmd)->l_argv))
		exec_scmd_free_exit(EXIT_SUCCESS, argv, l_free);
	if (builtin_check(argv))
		status = builtin_exec(argv, TRUE, l_free);
	else
		status = exec_scmd_exec(argv);
	exec_scmd_free_exit(status, argv, l_free);
}

static int	pipeline_element(t_list *element, int pipes[2][2], int i,
				t_list *l_free)
{
	int	fd[2];
	int	status;

	exec_pipeline_pipes_set(fd, pipes, i, (element->next == NULL));
	dup2(fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	exec_pipeline_pipes_close(pipes, -1, FALSE);
	if (cmd_type(element) == CMD_SCMD)
		pipeline_scmd

}

static int	pipeline_pipe_fork(t_list *iter, int pipes[2][2], int i,
				t_list *l_free)
{
	int	pid;

	if (iter->next && pipe(pipes[i % 2]) < 0)
	{
		print_error_errno(SHELL_NAME, "pipe error", NULL);
		return (-1);
	}
	pid = fork();
	if (pid == -1)
	{
		print_error_errno(SHELL_NAME, "frok error", NULL);
		return (-1);
	}
	if (pid == 0)
		pipeline_element
}

int	exec_pipeline(t_list *pipeline, t_list *l_free)
{
	t_list	*iter;
	int		pipes[2][2];
	int		pid;
	int		i;

	exec_pipeline_pipes_init(pipes);
	pid = -1;
	i = 0;
	iter = cmd_content(pipeline)->l_element;
	while (iter)
	{
		pid = pipeline_pipe_fork(iter, pipes, i, l_free);
		if (pid == -1)
		{
			exec_pipeline_pipes_close(pipes, -1, FALSE);
			break ;
		}
		exec_pipeline_pipes_close(pipes, i, (iter->next == NULL));
		iter = iter->next;
		i++;
	}
	return (exec_wait_for_all(pid));
}