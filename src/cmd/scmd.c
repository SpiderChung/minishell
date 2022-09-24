/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scmd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:59:16 by schung            #+#    #+#             */
/*   Updated: 2022/09/24 18:59:17 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cmd.h"

t_list	*scmd_create(int type)
{
	t_c_scmd	*c_scmd;
	t_list		*scmd;

	c_scmd = malloc(sizeof(t_c_scmd));
	if (!c_scmd)
		return (NULL);
	c_scmd->type = type;
	c_scmd->l_argv = NULL;
	c_scmd->l_redir = NULL;
	scmd = ft_lstnew(c_scmd);
	if (!scmd)
	{
		c_scmd_destroy(c_scmd);
		return (NULL);
	}
	scmd->next = NULL;
	return (scmd);
}

t_c_scmd	*scmd_content(t_list *scmd)
{
	return ((t_c_scmd *)scmd->content);
}

void	c_scmd_destroy(void *c_scmd)
{
	if (((t_c_scmd *)c_scmd)->l_argv)
		ft_lstclear(&(((t_c_scmd *)c_scmd)->l_argv), c_token_destroy);
	if (((t_c_scmd *)c_scmd)->l_redir)
		ft_lstclear(&(((t_c_scmd *)c_scmd)->l_redir), c_token_destroy);
	free(c_scmd);
}
