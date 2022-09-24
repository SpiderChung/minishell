/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:16:45 by schung            #+#    #+#             */
/*   Updated: 2022/09/24 19:16:46 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "global.h"

// src/signals/signals.c
void	signal_ctlc(int sig);
void	signal_ctlc_heredoc(int sig);
int		termios_change(bool echo_ctl_chr);

#endif
