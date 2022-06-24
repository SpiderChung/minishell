/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 21:34:37 by schung            #+#    #+#             */
/*   Updated: 2022/06/24 22:53:28 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

static int	expanded_str_append_exit_code(char **str)
{
	char	*exit_str;

	exit_str = ft_itoa(exec_exit_status_get());
	if (exit_str == NULL)
		return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM)));
	*str = str_append_str(*str, exit_str);
	free(exit_str);
	if (*str == NULL)
		return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM)));
	return (0);
}

static int	expanded_str_get(t_token *c_token, char **str, int *i)
{
	if (c_token->str[*i] == '$' && c_token->str[*i + 1] == '?')
	{
		if (expanded_str_append_exit_code(str) == ERROR)
			return (ERROR);
		(*i)++;
	}
	else if (c_token->str[*i] == '$' && (env_is_var_char(c_token->str[*i + 1])
			|| (c_token->str[*i + 1] == '\0'
				&& !(c_token->flag & (TOK_S_QUOTE | TOK_D_QUOTE))
				&& c_token->flag & TOK_CONNECTED)))
	{
		if(expa)
	}
	

}

static int	expand_var_token(t_token *c_token)
{
	char	*str;
	int		i;

	if (c_token->str == NULL || (c_token->flag & TOK_S_QUOTE)
		|| !ft_strchr(c_token->str, '$')
		|| (c_token->flag & TOK_REDIR_FILE && c_token->flag & TOK_D_QUOTE))
		return (0);
	str = ft_strdup("");
	if (str == NULL)
		return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM)));
	i = 0;
	while (c_token->str[i])
	{
		while (c_token->str[i] == '$' && c_token->str[i + 1] == '$')
			i++;
		if (e)
	}
}	

int	expand_var_token_list(t_list *l_token)
{
	t_list	*iter;

	iter = l_token;
	while (iter)
	{
		if (expand_var_token())
	}
}