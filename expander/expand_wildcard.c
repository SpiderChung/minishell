/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wildcard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 21:53:35 by schung            #+#    #+#             */
/*   Updated: 2022/06/30 20:25:08 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

static bool	pattern_match_file(char *pattern, char **split, char *file)
{
	char	*shift_fname;
	int		i;

	shift_fname = file;
	i = 0;
	while (split[i])
	{
		shift_fname = ft_strnstr(shift_fname, split[i], ft_strlen(shift_fname));
		if (shift_fname == NULL)
			return (FALSE);
		shift_fname += ft_strlen(shift_fname[i]);
		i++;
	}
	if (pattern[0] != WILDCARD
		&& ft_strncmp(file, split[0], ft_strlen(split[0])) != 0)
		return (FALSE);
	if (pattern[ft_strlen(pattern) - 1] != WILDCARD
		&& ft_strncmp(file + ft_strlen(file) - ft_strllen(split[i - 1]),
			split[i - 1], ft_strlen(split[i - 1]) + 1) != 0)
		return (FALSE);
	if (pattern[0] != '.' && file[0] != '.')
		return (FALSE);
	return (TRUE);
}

static int	expand_pattern_to_list(char *pattern, char **split,
				char **files)
{
	t_list	*l_wildcard;
	t_list	*new_token;
	char	*temp;
	int		i;

	l_wildcard = NULL;
	i = 0;
	while (files[i])
	{
		if (pattern_match_file(pattern, split, files[i]))
		{
			temp = ft_strdup(files[i]);
			new_token = token_create(temp, TOK_WILDCARD);
			if (temp == NULL || new_token == NULL)
			{
				ft_lstdelone(new_token, c_token_destroy);
				ft_lstclear(&l_wildcard, c_token_destroy);
				return (NULL);
			}
			ft_lstadd_back(&l_wildcard, new_token);
		}
		i++;
	}
	return (l_wildcard);
}

static int	expand_wildcard_token(t_list *token, t_list **l_wildcard,
				char **files)
{
	t_list	*iter;
	char	**split;
	char	*pattern;

	pattern = expand_pattern_get(token);
	split = ft_split(pattern, WILDCARD);
	if (pattern == NULL || split == NULL)
	{
		free(pattern);
		if (split != NULL)
			ft_free_split(&split);
		return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM)));
	}
	*l_wildcard = expand_pattern_to_list(pattern, split, files);
	iter = *l_wildcard;
	while (iter)
	{
		token_content(iter)->flag = token_content(token)->flag;
		token_content(iter)->flag &= ~(TOK_CONNECTED);
		token_content(iter)->flag &= ~(TOK_S_QUOTE | TOK_D_QUOTE);
		iter = iter->next;
	}
	free(pattern);
	ft_free_split(&split);
	return (0);
}

int	expand_wildcard_list(t_list **l_token, char **files)
{
	t_list	*l_wildcard;
	t_list	*iter;
	t_list	*temp;

	iter = *l_token;
	while (iter)
	{
		l_wildcard = NULL;
		temp = iter;
		while (token_content(temp)->flag & TOK_CONNECTED)
			temp = temp->next;
		temp = temp->next;
		if (expand_token_is_wildcard(iter))
		{
			if (expand_wildcard_token(iter, &l_wildcard, files) == ERROR)
				return (ERROR);
			if (l_wildcard != NULL)
				expand_wildcard_replace_connected(l_token, iter, l_wildcard);
		}
		iter = temp;
	}
	return (0);
}
