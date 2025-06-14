/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:52:17 by made-jes          #+#    #+#             */
/*   Updated: 2025/06/14 19:49:02 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_shell	*get_shell(void)
{
	static t_shell	shell;

	return (&shell);
}

int	main(void)
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
		get_shell()->tokens = tokens;
		while (tokens)
		{
			printf("Token: %-10s Type: %d\n", tokens->value, tokens->type);
			tokens = tokens->next;
		}
		free_token_list(tokens);
		free(line);
	}
	return (0);
}
