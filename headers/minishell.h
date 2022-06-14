/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:44:38 by schung            #+#    #+#             */
/*   Updated: 2022/06/14 20:19:41 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <signal.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <term.h>
# include <termcap.h>
# include <termios.h>
# include <stdbool.h>
# include <errno.h>
# include <limits.h>

# define LMAGENTA 			"\033[1;35m"
# define DEFAULT 			"\033[0m"

# define PROMPT 			"\033[1;35mminishell> \033[0m"
# define SHELL_NAME			"minishell"
# define DEBUG_ENV			"DEBUG"
# define ERROR				-1

# define FALSE 				0
# define TRUE 				1

# define STDIN 				0
# define STDOUT 			1
# define STDERR 			2
# define ARGERR 			"minishell: too many arguments"
# define INIT_ERR 			"Initialization error"
# define ERR_SYNTAX			"syntax error"
# define ERR_SYNTAX_EXIT	2
# define ERR_QUOTE			"unclosed quotation mark"

# define WHITESPACES		" \t\n"
# define QUOTE_MARKS		"\'\""

# define ERR_UNO_BRACKET	"unopened brackets"
# define ERR_UNC_BRACKET	"unclosed brackets"
# define ERR_EMPTY_BRACKET	"empty brackets"
# define ERR_REDIR			"invalid redirection"
# define ERR_QUOTE			"unclosed quotation mark"
# define ERR_LIST			"incomplete command list"
# define ERR_MISS_OP		"missing operator"
# define ERR_PIPE			"incomplete pipe" 

# define TOK_TEXT			1
# define TOK_S_QUOTE		2
# define TOK_D_QUOTE		4
# define TOK_REDIR_FILE		8
# define TOK_CONNECTED		16
# define TOK_BL				32
# define TOK_PIPE			64
# define TOK_B_BRACKET		128
# define TOK_E_BRACKET		254
# define TOK_REDIR			512
# define TOK_HEREDOC		1024
# define TOK_WILDCARD		2048

# define CMD_SCMD			1
# define CMD_AND			2
# define CMD_OR				4
# define CMD_PIPE			8
# define CMD_O_BRACKET		16
# define CMD_C_BRACKET		32
# define CMD_PIPELINE		64
# define CMD_GROUP			128
# define CMD_L_SCMD			256
# define CMD_L_CMD			512

// REDIR_TYPES
# define REDIR_OUT			1
# define REDIR_OUT_APP		2
# define REDIR_IN			3
# define REDIR_HEREDOC		4

// REDIR_FDs
# define REDIR_FILE			0
# define REDIR_NUM			1

typedef struct s_token_content
{
	int		flag;
	char	*str;
}	t_token;

typedef struct s_scmd_content
{
	int		type;
	t_list	*l_argv;
	t_list	*l_redir;
}	t_c_scmd;

typedef struct s_cmd_content
{
	int		type;
	t_list	*l_element;
}	t_c_cmd;

extern char		**g_env;

/* ************************************************************************** */
/* 									ENVI									  */
/* ************************************************************************** */

/*________utils.c__________*/
char		*env_get_value(char *name);
char		*env_find_var(char *name);
int			env_init(void);

/* ************************************************************************** */
/* 									SIGNALS									  */
/* ************************************************************************** */

/*________signals.c__________*/
void		signal_tckl(int sig);
int			termios_change(bool echo_ctl);
void		signal_ctlc_heredoc(int sig);

/* ************************************************************************** */
/* 									UTILS									  */
/* ************************************************************************** */

/*________utils.c__________*/
void		ft_free(char ***src);
int			split_count(char **split);
int			print_error(char *s1, char *s2, char *s3, char *message);
int			print_error_errno(char *s1, char *s2, char *s3);

/*________utils_str.c__________*/
char		*str_append_char(char *str, char append);
char		str_last_char(char *str);
char		*str_append_str(char *str, char *append);


/* ************************************************************************** */
/* 									LEXER									  */
/* ************************************************************************** */

/*________lexer.c__________*/
t_list		*lexer(char *input);

/*________lexer_token.c__________*/
int			lexer_token_bl(char *str, int *i, t_list **l_token);
int			lexer_token_pipe(char *str, int *i, t_list **l_token);
int			lexer_token_bracket(char *str, int *i, t_list **l_token);
int			lexer_token_redir(char *str, int *i, t_list **l_token);

/*________lexer_token_add.c__________*/
int			lexer_token_text(char *str, int *i, t_list **l_token);
int			lexer_token_quote(char *str, int *i, t_list **l_token);

/*________lexer_syntax.c__________*/
int			lexer_syntax_check(t_list *token);

/* ************************************************************************** */
/* 									PARSER									  */
/* ************************************************************************** */

/*________parser.c__________*/

/*________parser_heredoc.c__________*/
int			parser_heredoc(t_list	*l_token);

/* ************************************************************************** */
/* 									EXPANDER								  */
/* ************************************************************************** */

/*________expander.c__________*/

/* ************************************************************************** */
/* 									TOKEN									  */
/* ************************************************************************** */

/*________token.c__________*/
t_list		*token_create(char *str, int type);
t_token		*token_content(t_list *token);
void		c_token_destroy(void *token);
bool		token_is_cmd(t_list *token);
char		*token_to_str(t_list *token);

/* ************************************************************************** */
/* 									EXECUTOR								  */
/* ************************************************************************** */

/*________exec_exit_status.c__________*/
int			exec_exit_status_get(void);
void		exec_exit_status_set(int status);

/* ************************************************************************** */
/* 									PRINTER 								  */
/* ************************************************************************** */

/*________printer_token.c__________*/
void		printer_token(t_list *l_token);

/* ************************************************************************** */
/* 									CMD      								  */
/* ************************************************************************** */

/*________cmd.c__________*/
int			cmd_type_from_token(t_list *token);
int			cmd_type(t_list *cmd);
void		c_cmd_destroy(void *c_cmd);
t_list		*cmd_create(int type);

/*________scmd.c__________*/
t_list		*scmd_create(int type);
t_c_scmd	*scmd_content(t_list *scmd);
void		c_scmd_destroy(void *c_scmd);

#endif