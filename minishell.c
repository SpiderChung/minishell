/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:37:41 by schung            #+#    #+#             */
/*   Updated: 2022/04/18 19:59:03 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

void	show_prompt(void)
{
	write(1, LMAGENTA, ft_strlen(LMAGENTA));
	write(1, "minishell$ ", strlen("minishell$ "));
	write(1, DEFAULT, ft_strlen(DEFAULT));
}

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;
	
	while(1)
	{
		show_prompt();
	}
	return (0);
}
