/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline_pipes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:59:57 by schung            #+#    #+#             */
/*   Updated: 2022/09/24 18:59:58 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/exec.h"

static int	pipes_close_end(int pipe_end)
{
	if (pipe_end == -1)
		return (0);
	return (close(pipe_end));
}

void	exec_pipeline_pipes_close(int pipes[2][2], int i, bool last)
{
	if (i == 0)
		pipes_close_end(pipes[0][1]);
	else if (last)
		pipes_close_end(pipes[(i + 1) % 2][0]);
	else if (i % 2 == 1)
	{
		pipes_close_end(pipes[0][0]);
		pipes_close_end(pipes[1][1]);
	}
	else if (i % 2 == 0)
	{
		pipes_close_end(pipes[1][0]);
		pipes_close_end(pipes[0][1]);
	}
	else if (i == -1)
	{
		pipes_close_end(pipes[0][0]);
		pipes_close_end(pipes[0][1]);
		pipes_close_end(pipes[1][0]);
		pipes_close_end(pipes[1][1]);
	}
}

void	exec_pipeline_pipes_set(int fd[2], int pipes[2][2], int i, bool last)
{
	if (i == 0)
	{
		fd[0] = STDIN_FILENO;
		fd[1] = pipes[0][1];
	}
	else if (last)
	{
		fd[0] = pipes[(i + 1) % 2][0];
		fd[1] = STDOUT_FILENO;
	}
	else if (i % 2 == 1)
	{
		fd[0] = pipes[0][0];
		fd[1] = pipes[1][1];
	}
	else if (i % 2 == 0)
	{
		fd[0] = pipes[1][0];
		fd[1] = pipes[0][1];
	}
}

void	exec_pipeline_pipes_init(int pipes[2][2])
{
	pipes[0][0] = -1;
	pipes[0][1] = -1;
	pipes[1][0] = -1;
	pipes[1][1] = -1;
}
