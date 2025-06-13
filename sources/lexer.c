/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:47:37 by made-jes          #+#    #+#             */
/*   Updated: 2025/06/05 19:32:46 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	lexer(char *line)
{
	//int		i;
	char	**result;

	//i = 0;
	if (!line)
		return ;
	result = ft_split(line, '|');
	if (!result)
		return ;
	/*while (result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}*/
}