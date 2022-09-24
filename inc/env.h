/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:13:42 by schung            #+#    #+#             */
/*   Updated: 2022/09/24 19:13:43 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "global.h"

// src/env/env.c
int		env_init(void);
char	*env_get_value(char *name);
char	*env_find_var(char *name);
bool	env_var_is_value(char *var_name, char *value);
bool	env_is_var_char(char c);

// src/env/env_modify.c
int		env_unset_var(char *name);
int		env_put_var(char *str);
int		env_set_env(char *name, char *value);

#endif
