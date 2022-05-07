/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:44:38 by schung            #+#    #+#             */
/*   Updated: 2022/05/07 23:46:43 by schung           ###   ########.fr       */
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

# define LMAGENTA "\033[1;35m"
# define DEFAULT "\033[0m"

# define PROMPT 	"\033[1;35mminishell> \033[0m"
# define SHELL_NAME	"minishell"
# define DEBUG_ENV	"DEBUG"
# define ERROR	-1

# define FALSE 0
# define TRUE 1

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define ARGERR "minishell: too many arguments\n"
# define INIT_ERR "Initialization error\n"

# define D_KEY_ESCAPE 27
# define D_KEY_SPACE 32
# define D_KEY_UP 4283163
# define D_KEY_DOWN 4348699
# define D_KEY_RIGHT 4414235
# define D_KEY_LEFT 4479771
# define D_KEY_ENTER 10
# define D_KEY_BACKSPACE 127
# define D_KEY_CTRL_C 3
# define D_KEY_CTRL_D 4

extern char		**g_env;

/* ************************************************************************** */
/* 									ENVI									  */
/* ************************************************************************** */

/*________utils.c__________*/
char	*env_get_value(char *name);
char	*env_find_var(char *name);
int		env_init(void);

/* ************************************************************************** */
/* 									SIGNALS									  */
/* ************************************************************************** */

/*________signals.c__________*/
void	signal_tckl(int sig);
int		termios_change(bool echo_ctl);

/* ************************************************************************** */
/* 									UTILS									  */
/* ************************************************************************** */

/*________utils.c__________*/
void	ft_free(char ***src);
int		split_count(char **split);
int		print_error(char *s1, char *s2, char *s3, char *message);

/*________utils.c__________*/

/* ************************************************************************** */
/* 									LEXER									  */
/* ************************************************************************** */

/*________lexer.c__________*/

/* ************************************************************************** */
/* 									PARSER									  */
/* ************************************************************************** */

/*________parser.c__________*/

/* ************************************************************************** */
/* 									EXPANDER								  */
/* ************************************************************************** */

/*________expander.c__________*/

/* ************************************************************************** */
/* 									EXECUTOR								  */
/* ************************************************************************** */

/*________executor.c__________*/

#endif