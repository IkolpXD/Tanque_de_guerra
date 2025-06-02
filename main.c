/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:52:17 by made-jes          #+#    #+#             */
/*   Updated: 2025/06/02 19:18:15 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	main(void)
{
	char	*line;
	//t_token	*tokens;

	while (1)
	{
		line = readline("minishell$ ");
		//printf("%s\n", line);
		if (!line)
			break ;
		if (line && *line)
			add_history(line);
		//tokens = lexer(line);
		free(line);
	}
	return (0);
}
