/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 20:27:56 by schung            #+#    #+#             */
/*   Updated: 2022/05/07 23:08:02 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	env_init(void)
{
	extern char		**environ;
	int				i;

	i = split_count(environ);
	if (i == 0)
		return (0);
	g_env = malloc((i + 1) * sizeof(char *));
	if (g_env == NULL)
		return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM)));
	i = 0;
	while (environ[i])
	{
		g_env[i] = ft_strdup(environ[i]);
		if (g_env[i] == NULL)
		{
			ft_free(&g_env);
			return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM)));
		}
		i++;
	}
	g_env[i] = NULL;
	return (0);
}

char	*env_get_value(char *name)
{
	char	*env_var;

	env_var = env_find_var(name);
	if (env_var)
		return (ft_strchr(env_var, '=') + 1);
	else
		return (NULL);
}

char	*env_find_var(char *name)
{
	int		i;
	int		len;

	if (name == NULL || g_env == NULL)
		return (NULL);
	if (ft_strchr(name, '='))
		len = ft_strchr(name, '=') - name;
	else
		len = ft_strlen(name);
	i = 0;
	while (g_env[i])
	{
		if (!ft_strncmp(name, g_env[i], len) && g_env[i][len] == '=')
			return (g_env[i]);
		i++;
	}
	return (NULL);
}
