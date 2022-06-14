/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_scmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:43:25 by schung            #+#    #+#             */
/*   Updated: 2022/06/06 21:12:47 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_list	*parser_scmd_tokens(t_list *l_token)
{
	t_list	*l_scmd;
	t_list	*scmd;
	t_list	*next;

	l_scmd = NULL;
	while (l_token != NULL)
	{
		scmd = scmd_create(cmd_type_from_token(l_token));
	}
}