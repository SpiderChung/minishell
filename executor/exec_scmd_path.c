/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_scmd_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:00:39 by schung            #+#    #+#             */
/*   Updated: 2022/06/29 18:35:52 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

static int	path_split_append_slash(char **path_split)
{
	char	*temp;
	int		i;

	i = 0;
	while (path_split && path_split[i])
	{
		if (path_split[i][ft_strlen(path_split[i]) - 1] != '/')
		{
			temp = path_split[i];
			path_split[i] = ft_strjoin(path_split[i], "/");
			if (path_split[i] == NULL)
			{
				path_split[i] = temp;
				return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM)));
			}
			free(temp);
		}
		i++;
	}
	return (0);
}
static char	**path_split_get(void)
{
	char	**path_split;

	path_split = NULL;
	if (env_get_value("PATH"))
	{
		path_split = ft_split(env_get_value("PATH"), ':');
		if (path_split == NULL)
		{
			print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM));
			return (NULL);
		}
	}
	if (path_split_append_slash(path_split) == ERROR)
	{
		ft_free_split(&path_split);
		return (NULL);
	}
	return (path_split);
}

static int	path_find(char **path_split, char **argv)
{
	struct stat	s;
	char		*temp;
	int			i;

	i = 0;
	while (path_split && path_split[i])
	{
		temp = ft_strjoin(path_split[i], *argv);
		if (temp == NULL)
		{
			print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM));
			return (ERROR);
		}
		if (access(temp, F_OK) == 0 && (!stat(temp, &s) && !S_ISDIR(s.st_mode)))
		{
			free(*argv);
			*argv = temp;
			return (0);
		}
		free(temp);
		i++;
	}
	return (ERROR);
}

int	exec_scmd_search_path(char **argv)
{
	char	**path_split;

	path_split = NULL;
	if (env_get_value("PATH") && argv[0][0] != '\0')
	{
		path_split = path_split_get();
		if (path_split == NULL)
			return (ERROR);
		if (path_find(path_split, argv) == 0)
		{
			ft_free_split(&path_split);
			return (0);
		}
	}
		if (path_split)
			ft_free_split(&path_split);
		return (ERROR);
}
