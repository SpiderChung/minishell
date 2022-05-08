/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 21:28:43 by schung            #+#    #+#             */
/*   Updated: 2022/05/08 22:06:45 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static int	text_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr(WHITESPACES, str[i]))
			break ;
		else if (other_len(&str[i]) > 0)
			break ;
		else if (ft_strchr(QUOTE_MARKS, str[i]))
			break ;
		i++;
	}
	return (i);
}

static int	other_len(char *chr)
{
	if (*chr == '(' || *chr == ')')
		return (1);
	else if (*chr == '<' && *(chr + 1) != '<')
		return (1);
	else if (*chr == '<' && *(chr + 1) == '<')
		return (2);
	else if (*chr == '>' && *(chr + 1) != '>')
		return (1);
	else if (*chr == '>' && *(chr + 1) == '>')
		return (2);
	else if (*chr == '|' && *(chr + 1) != '|')
		return (1);
	else if (*chr == '|' && *(chr + 1) == '|')
		return (2);
	else if (*chr == '&' && *(chr + 1) == '&')
		return (2);
	return (0);
}

int	lexer_token_text(char *str, int *i, t_list **l_token)
{
	t_list	*token;
	char	*token_str;
	int		len;

	len = text_len(&str[*i]);
	if (len > 0)
	{
		if (str[*i + len] == str[*i + len + 1])
			len++;
		len++;
		token_str = ft_substr(str, *i, len);
		if (token_str == NULL)
			return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM)));
		token = token_create(token_str, TOK_REDIR);
		if (token == NULL)
		{
			free(token_str);
			return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM)));
		}
		ft_lstadd_back(l_token, token);
		*i += len;
	}
	return (0);
}