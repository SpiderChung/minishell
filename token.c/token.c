/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:17:19 by schung            #+#    #+#             */
/*   Updated: 2022/05/08 18:24:08 by schung           ###   ########.fr       */
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