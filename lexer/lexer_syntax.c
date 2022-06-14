/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 13:26:08 by schung            #+#    #+#             */
/*   Updated: 2022/06/14 18:56:57 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	lexer_syntax_check(t_list *token)
{
	if (syntax_brackets(token) == ERROR)
		return (ERROR);
	if (syntax_bl(token) == ERROR)
		return (ERROR);
	if (syntax_pipe(token) == ERROR)
		return (ERROR);
	if (syntax_missing_op(token) == ERROR)
		return (ERROR);
	return (0);
}

static int	syntax_bl(t_list *token)
{
	if (token && token_content(token)->flag & TOK_BL)
		return (print_error(SHELL_NAME, ERR_SYNTAX, NULL, ERR_LIST));
	while (token)
	{
		if (token_content(token)->flag & TOK_BL)
		{
			if (token->next == NULL)
				return (print_error(SHELL_NAME, ERR_SYNTAX, NULL, ERR_LIST));
			else if (token_content(token->next)->flag & (TOK_BL | TOK_PIPE))
				return (print_error(SHELL_NAME, ERR_SYNTAX, NULL, ERR_LIST));
			else if (token_content(token->next)->flag & TOK_E_BRACKET)
				return (print_error(SHELL_NAME, ERR_SYNTAX, NULL, ERR_LIST));
		}
		if (token_content(token)->flag & TOK_B_BRACKET)
		{
			if (token->next && token_content(token->next)->flag & TOK_BL)
				return (print_error(SHELL_NAME, ERR_SYNTAX, NULL, ERR_LIST));
		}
		token = token->next;
	}
	return (0);
}

static int	syntax_pipe(t_list *token)
{
	if (token && token_content(token)->flag & TOK_PIPE)
		return (print_error(SHELL_NAME, ERR_SYNTAX, NULL, ERR_PIPE));
	while (token)
	{
		if (token_content(token)->flag & TOK_PIPE)
		{
			if (token->next == NULL)
				return (print_error(SHELL_NAME, ERR_SYNTAX, NULL, ERR_PIPE));
			else if (token_content(token->next)->flag & (TOK_BL | TOK_PIPE))
				return (print_error(SHELL_NAME, ERR_SYNTAX, NULL, ERR_PIPE));
			else if (token_content(token->next)->flag & TOK_E_BRACKET)
				return (print_error(SHELL_NAME, ERR_SYNTAX, NULL, ERR_PIPE));
		}
		if (token_content(token)->flag & TOK_B_BRACKET)
		{
			if (token->next && token_content(token->next)->flag & TOK_PIPE)
				return (print_error(SHELL_NAME, ERR_SYNTAX, NULL, ERR_PIPE));
		}
		token = token->next;
	}
	return (0);
}

static id_t	syntax_brackets(t_list *token)
{
	int	count;

	count = 0;
	while (token)
	{
		if (token_content(token)->flag & TOK_B_BRACKET)
		{
			count++;
			if (token->next && token_content(token->next)->flag & TOK_E_BRACKET)
			{
				print_error(SHELL_NAME, ERR_SYNTAX, NULL, ERR_EMPTY_BRACKET);
				return (ERROR);
			}
		}
		else if (token_content(token)->flag & TOK_E_BRACKET)
			count--;
		if (count < 0)
			return (print_error(SHELL_NAME, ERR_SYNTAX, NULL, ERR_UNO_BRACKET));
		token = token->next;
	}
	if (count > 0)
		return (print_error(SHELL_NAME, ERR_SYNTAX, NULL, ERR_UNC_BRACKET));
	return (0);
}

static int	syntax_missing_op(t_list *token)
{
	while (token)
	{
		if (token_content(token)->flag & TOK_E_BRACKET && token->next
			&& token_content(token->next)->flag & TOK_B_BRACKET)
			return (print_error(SHELL_NAME, ERR_SYNTAX, NULL, ERR_MISS_OP));
		else if (token_content(token)->flag & TOK_E_BRACKET
			&& token_is_cmd(token->next))
			return (print_error(SHELL_NAME, ERR_SYNTAX, NULL, ERR_MISS_OP));
		else if (token_is_cmd(token) && token->next
			&& token_content(token->next)->flag & TOK_B_BRACKET)
			return (print_error(SHELL_NAME, ERR_SYNTAX, NULL, ERR_MISS_OP));
		token = token->next;
	}
	return (0);
}
