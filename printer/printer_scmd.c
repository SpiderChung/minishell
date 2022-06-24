/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_scmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:00:52 by schung            #+#    #+#             */
/*   Updated: 2022/06/24 20:39:38 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	printer_scmd_redir(t_list *l_redir)
{
	while (l_redir)
	{
		if (token_content(l_redir)->flag & TOK_REDIR)
			printf("\033[0;35m%s \033[m", token_content(l_redir)->str);
		else
		{
			if (token_content(l_redir)->flag & TOK_HEREDOC)
				printf("\033[0;34mhere_doc \033[m");
			else
				printf("\033[0;34m%s \033[m", token_content(l_redir)->str);
		}
		l_redir = l_redir->next;
	}
}

void	printer_other(int type)
{
	if (type == CMD_AND)
		printf("\033[0;31m&& \033[m");
	else if (type == CMD_OR)
		printf("\033[0;31m|| \033[m");
	else if (type == CMD_PIPE)
		printf("\033[0;31m| \033[m");
	else if (type == CMD_O_BRACKET)
		printf("\033[0;36m( \033[m");
	else if (type == CMD_C_BRACKET)
		printf("\033[0;36m) \033[m");
	else
		printf("ERROR ");
}

void	printer_scmd_pipeline(t_list *l_scmd_pipeline, bool line)
{	
	while (l_scmd_pipeline)
	{
		printer_scmd(scmd_content(l_scmd_pipeline));
		if (l_scmd_pipeline->next)
			printer_other(CMD_PIPE);
		l_scmd_pipeline = l_scmd_pipeline->next;
	}
	if (line)
		printf('\n');
}

static void	printer_scmd_argv(t_list *l_argv)
{
	bool	command;

	command = TRUE;
	while (l_argv)
	{
		if (command == TRUE)
		{
			printf("\033[0;33m%s \033[m", token_content(l_argv)->str);
			command = FALSE;
		}
		else
			printf("\033[0;32m%s \033[m", token_content(l_argv)->str);
		l_argv = l_argv->next;
	}
}

void	printer_scmd(t_c_scmd *scmd)
{
	printer_scmd_argv(scmd->l_argv);
	printer_scmd_redir(scmd->l_redir);
}
