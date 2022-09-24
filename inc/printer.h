/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:16:36 by schung            #+#    #+#             */
/*   Updated: 2022/09/24 19:16:37 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_H
# define PRINTER_H

# include <stdio.h>
# include "global.h"
# include "cmd.h"

// src/printer/printer_cmd.c
void	printer_cmd(t_list *l_cmd);
void	printer_structure(t_list *l_cmd);

// src/printer/printer_scmd.c
void	printer_scmd(t_c_scmd *scmd);
void	printer_other(int type);
void	printer_scmd_pipeline(t_list *l_scmd_pipeline, bool newline);

// src/printer/printer_token.c
void	printer_token(t_list *l_token);

#endif
