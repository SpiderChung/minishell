/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:12:49 by schung            #+#    #+#             */
/*   Updated: 2022/06/14 20:18:49 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static char	*heredoc_redline(char *limiter)
{
	char	*read_str;
	char	*here_str;

	signal(SIGINT, signal_ctlc_heredoc);
	here_str = ft_strdup("");
	if (here_str == NULL)
		return (NULL);
	read_str = readline("> ");
	while (read_str && ft_strncmp(read_str, limiter, ft_strlen(limiter) + 1))
	{
		read_str = str_append_char(read_str, '\n');
		if (read_str == NULL)
		{
			free(here_str);
			print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM));
			return (NULL);
		}
		here_str = str_append_str(here_str, read_str);
		if (here_str == NULL)
			break ;
		free(read_str);
		read_str = readline("> ");
	}
	free(read_str);
	return (here_str);
}

static char	*heredoc_gnl(char *limiter)
{

}

static int	heredoc_processing(t_list *redir_file, char **limiter)
{
	int fd;

	fd = dup(STDIN_FILENO);
	if (fd == -1)
		return (print_error_errno(SHELL_NAME, NULL, NULL));
	free(token_content(redir_file)->str);
	if (isatty(STDIN_FILENO))
		token_content(redir_file)->str = heredoc_readline(limiter);
	else
		token_content(redir_file)->str = heredoc_gnl(limiter);
}

int	parser_heredoc(t_list	*l_token)
{
	t_list	*redir_file;
	char	*limiter;

	if (l_token && redir_type(token_content(l_token)->str) == REDIR_HEREDOC)
	{
		redir_file = l_token->next;
		limiter = token_to_str(redir_file);
		if (limiter == NULL)
			return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM)));
		if (heredoc_processing(red))
	}
}