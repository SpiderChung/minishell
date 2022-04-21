/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:51:03 by schung            #+#    #+#             */
/*   Updated: 2022/04/21 21:07:47 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

void	init_terminal(char *termtype)
{
	int	success;

	success = tgetent(0, termtype);
	if (success < 0)
		error_message("Could not access the termcap data base");
	else if (success == 0)
		error_message("Terminal type is not defined in termcap library");
	success = 
}