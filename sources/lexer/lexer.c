/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:47:37 by made-jes          #+#    #+#             */
/*   Updated: 2025/06/14 22:25:47 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token	*lexer(char *line)
{
	char	**result;
	t_token	*token_list;

	if (!line)
		return (NULL);
	result = malloc(sizeof(char *) * (ft_strlen(line) + 1));
	if (!result)
		return (NULL);
	fill_tokens(result, line);
	token_list = create_list(result);
	free_split(result);
	get_shell()->tokens = token_list;
	return (token_list);
}
