/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:16:41 by schung            #+#    #+#             */
/*   Updated: 2022/09/24 19:16:42 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIR_H
# define REDIR_H

# include "global.h"
# include "token.h"

# define REDIR_OUT		1
# define REDIR_OUT_APP	2
# define REDIR_IN		3
# define REDIR_HEREDOC	4

# define REDIR_FILE		0
# define REDIR_NUM		1

typedef struct s_redir_undo_content
{
	int		fd_repl;
	int		fd_repl_dup;
}	t_c_redir_undo;

// src/redir/redir.c
int		redir(t_list *l_token, t_list **l_undo);
int		redir_type(char *redir);

// src/redir/redir_undo.c
int		redir_undo(t_list **l_undo);
int		redir_undo_add_fd(t_list **l_undo, int fd);

#endif
