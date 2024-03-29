/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:13:32 by schung            #+#    #+#             */
/*   Updated: 2022/09/24 19:13:33 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <stdio.h>

# include "global.h"

struct s_builtins
{
	char	*name;
	int		(*func)(int argc, char **argv);
};

// src/builtin/builtin.c
int	builtin_check(char **argv);
int	builtin_exec(char **argv, bool subshell, t_list *l_free);

// src/builtin/builtin_cd.c
int	builtin_cd(int argc, char **argv);

// src/builtin/builtin_echo.c
int	builtin_echo(int argc, char **argv);

// src/builtin/builtin_env.c
int	builtin_env(int argc, char **argv);

// src/builtin/builtin_exit.c
int	builtin_exit(int argc, char **argv, bool subshell, t_list *l_free);

// src/builtin/builtin_export.c
int	builtin_export(int argc, char **argv);

// src/builtin/builtin_pwd.c
int	builtin_pwd(int argc, char **argv);

// src/builtin/builtin_unset.c
int	builtin_unset(int argc, char **argv);

#endif
