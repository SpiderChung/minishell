/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_undo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:07:55 by schung            #+#    #+#             */
/*   Updated: 2022/06/27 22:21:20 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

static t_c_redir_undo	*redir_undo_content(t_list *redir_undo)
{
	return ((t_c_redir_undo *)(redir_undo->content));
}

static t_list	*redir_undo_create(int fd_repl, int fd_repl_dup)
{
	t_c_redir_undo	*redir_undo;

	redir_undo = malloc(sizeof(t_c_redir_undo));
	if (redir_undo == NULL)
		return (NULL);
	redir_undo->fd_repl = fd_repl;
	redir_undo->fd_repl_dup = fd_repl_dup;
	return (ft_lstnew(redir_undo));
}

int	redir_undo(t_list **l_undo)
{
	t_list	*iter;
	int		fd_repl;
	int		fd_repl_dup;
	int		status;

	status = 0;
	iter = *l_undo;
	while (iter)
	{
		fd_repl = redir_undo_content(iter)->fd_repl;
		fd_repl_dup = redir_undo_content(iter)->fd_repl_dup;
		if (fd_repl_dup == -1)
			close(fd_repl);
		else if (fd_repl_dup != -1)
		{
			if (dup2(fd_repl_dup, fd_repl) == -1)
				status = print_error_errno(SHELL_NAME, NULL, NULL);
			close(fd_repl_dup);
		}
		iter = iter->next;
	}
	ft_lstclear(l_undo, free);
	return (status);
}
