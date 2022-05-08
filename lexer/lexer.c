/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 17:25:42 by schung            #+#    #+#             */
/*   Updated: 2022/05/08 21:25:28 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_list	*lexer(char *input)
{
	t_list	*l_token;

	l_token = token_list_get(input);
	if (l_token == NULL)
		return (NULL);
	if (lexer_syntax_check(l_token) == ERROR)
	{

	}
}

static t_list	token_list_get(char *input)
{
	t_list	*l_token;
	int		i;

	l_token = NULL;
	i = 0;
	while (input && input[i])
	{
		if (lexer_token_bl(input, &i, &l_token) == ERROR)
			break ;
		if (lexer_token_pipe(input, &i, &l_token) == ERROR)
			break ;
		if (lexer_token_bracket(input, &i, &l_token) == ERROR)
			break ;
		if (lexer_token_redir(input, &i, &l_token) == ERROR)
			break ;
		if (lexer_token_text(input, &i, &l_token) == ERROR)
			break ;
		if (lexer_token_quote(input, &i, &l_token) == ERROR)
			break ;
		while (input[i] && ft_strchr(WHITESPACES, input[i]))
			i++;
	}
}