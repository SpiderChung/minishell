/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exit_status.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:59:40 by schung            #+#    #+#             */
/*   Updated: 2022/09/24 18:59:43 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/exec.h"

static int	*exit_status_pointer(void)
{
	static int	last_exit_status = 0;

	return (&last_exit_status);
}

int	exec_exit_status_get(void)
{
	return (*exit_status_pointer());
}

void	exec_exit_status_set(int status)
{
	if (status == ERROR)
		status = EXIT_FAILURE;
	*exit_status_pointer() = status;
}
