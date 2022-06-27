/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 21:21:00 by schung            #+#    #+#             */
/*   Updated: 2022/06/27 21:15:25 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

int split_append_str(char ***split, char *new_str)
{
    char    **new_split;
    int     i;

    new_split = malloc((split_count(*split) + 2) * sizeof(char *));
    if (new_split  == NULL)
        return (ERROR);
    i = 0;
    while (*split && (*split)[i])
    {
        new_split[i] = (*split)[i];
        i++;
    }
    new_split[i] = new_str;
    new_split[i + 1] = NULL;
    free(*split);
    *split = new_split;
    return (0);
}

void	ft_free_split(char ***split)
{
	int	i;

	i = 0;
	while ((*split)[i] != NULL)
	{
		free((*split)[i]);
		(*split)[i] = NULL;
		i++;
	}
	free(*split);
	*split = NULL;
}
