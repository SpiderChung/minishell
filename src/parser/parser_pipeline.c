/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_pipeline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:06:31 by schung            #+#    #+#             */
/*   Updated: 2022/09/24 19:06:32 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parser.h"

static t_list	*pipeline_start(t_list *l_cmd)
{
	t_list	*iter;

	iter = l_cmd;
	while (iter)
	{
		if ((cmd_content(iter)->type & (CMD_SCMD | CMD_PIPELINE | CMD_GROUP)) \
				&& iter->next && cmd_content(iter->next)->type == CMD_PIPE \
				&& iter->next->next && (cmd_content(iter->next->next)->type \
				& (CMD_SCMD | CMD_GROUP | CMD_PIPELINE)))
			return (iter);
		iter = iter->next;
	}
	return (NULL);
}

static t_list	*pipeline_end(t_list *pipeline)
{
	t_list	*iter;

	iter = pipeline;
	while (iter)
	{
		if ((cmd_content(iter)->type & (CMD_SCMD | CMD_PIPELINE | CMD_GROUP)) \
					&& iter->next && cmd_content(iter->next)->type == CMD_PIPE \
					&& iter->next->next && (cmd_content(iter->next->next)->type \
					& (CMD_SCMD | CMD_PIPELINE | CMD_GROUP)))
			iter = iter->next->next;
		else
			return (iter);
	}
	return (NULL);
}

static void	pipeline_cleanup(t_c_cmd *c_pl, t_list *start, t_list *end)
{
	t_list	*next;
	t_list	*iter;

	iter = start;
	while (iter != end->next)
	{
		next = iter->next;
		if (cmd_content(iter)->type == CMD_PIPE)
			ft_lstdelone(iter, c_cmd_destroy);
		else if (cmd_content(iter)->type == CMD_PIPELINE)
		{
			ft_lstadd_back(&(c_pl->l_element), cmd_content(iter)->l_element);
			cmd_content(iter)->l_element = NULL;
			ft_lstdelone(iter, c_cmd_destroy);
		}
		else
		{
			ft_lstadd_back(&(c_pl->l_element), iter);
			if (iter != end)
				iter->next = NULL;
		}
		iter = next;
	}
	end->next = NULL;
}

int	parser_cmd_pipeline_merge(t_list **l_cmd)
{
	t_list	*pipeline;
	t_list	*start;
	t_list	*end;

	start = pipeline_start(*l_cmd);
	end = pipeline_end(start);
	if (!start || !end)
		return (0);
	pipeline = cmd_create(CMD_PIPELINE);
	if (pipeline == NULL)
		return (ERROR);
	lst_relink(l_cmd, pipeline, start, end);
	pipeline_cleanup(cmd_content(pipeline), start, end);
	return (1);
}
