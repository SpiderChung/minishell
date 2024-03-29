/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:13:36 by schung            #+#    #+#             */
/*   Updated: 2022/09/24 19:13:38 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "global.h"
# include "token.h"

# define CMD_SCMD		1
# define CMD_AND		2
# define CMD_OR			4
# define CMD_PIPE		8
# define CMD_O_BRACKET	16
# define CMD_C_BRACKET	32
# define CMD_PIPELINE	64
# define CMD_GROUP		128
# define CMD_L_SCMD		256
# define CMD_L_CMD		512

typedef struct s_scmd_content
{
	int		type;
	t_list	*l_argv;
	t_list	*l_redir;
}	t_c_scmd;

typedef struct s_cmd_content
{
	int		type;
	t_list	*l_element;
}	t_c_cmd;

// src/cmd/cmd.c
t_list		*cmd_create(int type);
t_c_cmd		*cmd_content(t_list *cmd);
void		c_cmd_destroy(void *c_cmd);
int			cmd_type(t_list *cmd);
int			cmd_type_from_token(t_list *token);

// src/cmd/scmd.c
t_list		*scmd_create(int type);
t_c_scmd	*scmd_content(t_list *scmd);
void		c_scmd_destroy(void *c_scmd);

#endif
