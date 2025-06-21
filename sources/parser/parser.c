/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 20:00:48 by made-jes          #+#    #+#             */
/*   Updated: 2025/06/15 21:11:47 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	syntax_error(char *token)
{
	printf("minishell: syntax error near unexpected token %s\n", token);
	return (1);
}

int	validate_syntax(t_token *tokens)
{
	t_token	*prev;

	prev = NULL;
	while (tokens)
	{
		if (tokens->type == PIPE)
		{
			if (!prev || prev->type == PIPE)
				return (syntax_error("|"));
			if (!tokens->next || tokens->next->type == PIPE)
				return (syntax_error("|"));
		}
		if (tokens->type == REDIR_IN || tokens->type == REDIR_OUT
			|| tokens->type == APPEND || tokens->type == HEREDOC)
		{
			if (!tokens->next || (tokens->next->type != WORD
					&& tokens->next->type != STR))
				return (syntax_error(tokens->value));
		}
		prev = tokens;
		tokens = tokens->next;
	}
	return (0);
}
