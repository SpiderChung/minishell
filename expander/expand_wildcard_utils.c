/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wildcard_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 21:13:23 by schung            #+#    #+#             */
/*   Updated: 2022/06/27 21:15:20 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

bool    expand_token_is_wildcard(t_list *token)
{
    while (token && token_content(token)->flag & TOK_CONNECTED)
    {
        if (!(token_content(token)->flag & (TOK_D_QUOTE | TOK_S_QUOTE)) 
            && ft_strchr(token_content(token)->str, '*'))
            return (TRUE);
        token = token->next;
    }
    if (token && !(token_content(token)->flag & (TOK_D_QUOTE | TOK_S_QUOTE))
        && ft_strchr(token_content(token)->str, '*'))
        return (TRUE);
    return (FALSE);
}

char    **expand_files_current_dir(void)
{
    DIR             *dir;
    struct dirent   *dirent;
    char            **file_names;
    char            *fname;

    file_names = NULL;
    dir = opendir("./");
    if (dir == NULL)
        print_error_errno(SHELL_NAME, NULL, NULL);
    if (dir == NULL)
        return (NULL);
    dirent = readdir(dir);
    while (dirent)
    {
        fname = ft_strdup(dirent->d_name);
        if (fname == NULL || split_append_str(&file_names, fname) == ERROR)
        {
            free(fname);
            ft_free_split(&file_names);
            return (NULL);
        }
        dirent = readdir(dir);
    }
    closedir(dir);
    return (file_names);
}

void	expand_wildcard_replace_connected(t_list **l_token,
			t_list	*old, t_list *new)
{
	t_list	*prev;
	t_list	*iter;
	t_list	*temp;

	iter = old;
	prev = lst_node_prev(*l_token, old);
	while (iter && token_content(iter)->flag & TOK_CONNECTED)
	{
		temp = iter->next;
		lst_node_remove(l_token, iter, c_token_destroy);
		iter = temp;
	}
	ft_lstlast(new)->next = iter->next;
	lst_node_remove(l_token, iter, c_token_destroy);
	if (prev == old)
		*l_token = new;
	else
		prev->next = new;
}