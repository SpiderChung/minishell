/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 21:27:37 by schung            #+#    #+#             */
/*   Updated: 2022/06/30 20:03:05 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

int	expand_var(t_c_scmd *c_scmd)
{
	int	status;

	status = expand_var_token_list(c_scmd->l_argv);
	if (status != ERROR)
		status = expand_var_token_list(c_scmd->l_redir);
	if (status != ERROR)
		status = expand_var_splitting(&(c_scmd->l_argv));
	if (status != ERROR)
		status = expand_var_splitting(&(c_scmd->l_redir));
	return (status);
}

int	expand_wildcard(t_c_scmd *c_scmd)
{
	char	**files;
	int		status;

	files = expand_files_current_dir();
	if (files == NULL)
		return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM)));
	status = expand_wildcard_list(&(c_scmd->l_argv), files);
	if (status != ERROR)
		status = expand_wildcard_list(&(c_scmd->l_redir), files);
	ft_free_split(&files);
	return (status);
}
