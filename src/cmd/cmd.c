/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:59:05 by schung            #+#    #+#             */
/*   Updated: 2022/09/24 18:59:08 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cmd.h"

t_list	*cmd_create(int type)
{
	t_c_cmd	*c_cmd;
	t_list	*cmd;

	c_cmd = malloc(sizeof(t_c_cmd));
	if (!c_cmd)
		return (NULL);
	c_cmd->type = type;
	c_cmd->l_element = NULL;
	cmd = ft_lstnew(c_cmd);
	if (!cmd)
	{
		c_cmd_destroy(c_cmd);
		return (NULL);
	}
	cmd->next = NULL;
	return (cmd);
}

t_c_cmd	*cmd_content(t_list *cmd)
{
	return ((t_c_cmd *)cmd->content);
}

void	c_cmd_destroy(void *c_cmd)
{
	if (((t_c_cmd *)c_cmd)->type == CMD_SCMD)
		c_scmd_destroy(c_cmd);
	else
	{
		if (((t_c_cmd *)c_cmd)->l_element)
			ft_lstclear(&(((t_c_cmd *)c_cmd)->l_element), c_cmd_destroy);
		free(c_cmd);
	}
}

int	cmd_type(t_list *cmd)
{
	return (*(int *)(cmd->content));
}

int	cmd_type_from_token(t_list *token)
{
	if (!token)
		return (ERROR);
	else if (token_content(token)->flags & (TOK_TEXT | TOK_REDIR))
		return (CMD_SCMD);
	else if (token_content(token)->flags & TOK_BIN_OP)
	{
		if (token_content(token)->str[0] == '&')
			return (CMD_AND);
		else if (token_content(token)->str[0] == '|')
			return (CMD_OR);
	}
	else if (token_content(token)->flags & TOK_PIPE)
		return (CMD_PIPE);
	else if (token_content(token)->flags & TOK_O_BRACKET)
		return (CMD_O_BRACKET);
	else if (token_content(token)->flags & TOK_C_BRACKET)
		return (CMD_C_BRACKET);
	return (ERROR);
}
