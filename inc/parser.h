/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:16:31 by schung            #+#    #+#             */
/*   Updated: 2022/09/24 19:16:32 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "global.h"
# include "cmd.h"
# include "token.h"

// src/parser/parser.c
t_list	*parser(t_list *l_token);

// src/parser/parser_group.c
int		parser_cmd_group_merge(t_list **l_cmd);

// src/parser/parser_heredoc.c
int		parser_heredoc(t_list *l_token);

// src/parser/parser_pipeline.c
int		parser_cmd_pipeline_merge(t_list **l_cmd);

// src/parser/parser_scmd.c
t_list	*parser_scmd_tokens(t_list *l_token);

#endif
