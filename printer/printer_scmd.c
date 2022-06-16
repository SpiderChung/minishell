/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_scmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:00:52 by schung            #+#    #+#             */
/*   Updated: 2022/06/16 19:07:55 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	printer_scmd(t_c_scmd *scmd)
{
	printer_scmd_argv(scmd->l_argv);
	printer_scmd_redir(scmd->l_redir);
}

void	printer_scmd_argv(t_list *l_argv)
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

