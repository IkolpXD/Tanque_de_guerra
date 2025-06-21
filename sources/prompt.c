/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 19:33:21 by made-jes          #+#    #+#             */
/*   Updated: 2025/06/19 19:09:23 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	run_prompt(void)
{
	char	*line;
	t_token	*tokens;

	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
			break ;
		if (*line)
			add_history(line);
		tokens = lexer(line);
		if (validate_syntax(tokens))
		{
			free_token_list(tokens);
			free(line);
			continue ;
		}
		t_token *current = tokens;
		while (current)
		{
			printf("Token: %-10s Type: %d\n", current->value, current->type);
			current = current->next;
		}
		get_shell()->tokens = tokens;
		free_token_list(get_shell()->tokens);
		free(line);
	}
}
