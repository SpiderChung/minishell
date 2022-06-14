/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:17:19 by schung            #+#    #+#             */
/*   Updated: 2022/06/14 18:57:10 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_list	*token_create(char *str, int type)
{
	t_token	*c_token;
	t_list	*token;

	c_token = malloc(sizeof(t_token));
	if (c_token == NULL)
		return (NULL);
	c_token->flag = type;
	c_token->str = str;
	token = ft_lstnew(c_token);
	if (token == NULL)
		return (NULL);
	token->next = NULL;
	return (token);
}

t_token	*token_content(t_list *token)
{
	return ((t_token *)token->content);
}

void	c_token_destroy(void *token)
{
	free(((t_token *)token)->str);
	((t_token *)token)->str = NULL;
	free(token);
}

bool	token_is_cmd(t_list *token)
{
	if (token == NULL)
		return (FALSE);
	if (token_content(token)->flag & (TOK_TEXT | TOK_REDIR))
		return (TRUE);
	return (FALSE);
}

char	*token_to_str(t_list *token)
{
	char	*str;
	char	*tmp;

	if (token == NULL || token_content(token)->str == NULL)
		return (NULL);
	str = ft_strdup(token_content(token)->str);
	while (token && (token_content(token)->flag & TOK_CONNECTED))
	{
		tmp = str;
		str = ft_strjoin(str, token_content(token->next)->str);
		free(tmp);
		if (str == NULL)
			return (NULL);
		token = token->next;
	}
	return (str);
}
