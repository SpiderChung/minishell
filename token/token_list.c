/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:13:27 by schung            #+#    #+#             */
/*   Updated: 2022/06/27 22:17:25 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

static int	l_token_append_connected(t_list **l_token, char **split_str)
{
	char	*temp;

	while (token_content(*l_token)->flag & TOK_CONNECTED)
	{
		temp = *split_str;
		*split_str = ft_strjoin(*split_str,
				token_content((*l_token)->next)->str);
		free(temp);
		if (*split_str == NULL)
			return (ERROR);
		*l_token = (*l_token)->next;
	}
	return (0);
}

static int	l_token_count_strings(t_list *l_token)
{
	int	i;

	i = 0;
	while (l_token)
	{
		if (!(token_content(l_token)->flag & TOK_CONNECTED))
			i++;
		l_token = l_token->next;
	}
	return (i);
}

char	**l_token_to_split(t_list *l_token)
{
	t_list	*iter;
	char	**split;
	int		i;

	if (l_token == NULL)
		return (0);
	split = malloc((l_token_count_strings(l_token) + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	i = 0;
	iter = l_token;
	while (iter)
	{
		split[i] = ft_strdup(token_content(iter)->str);
		if (split[i] == NULL
			|| l_token_append_connected(&iter, &split[i]) == ERROR)
		{
			ft_free_split(&split);
			return (NULL);
		}
		iter = iter->next;
		i++;
	}
	split[i] = NULL;
	return (split);
}
