/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:50:01 by made-jes          #+#    #+#             */
/*   Updated: 2025/06/14 15:08:34 by made-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/history.h>
# include <readline/readline.h>
# include "../libft/libft.h"
# include <signal.h>
# include <stdlib.h>
# include <stdlib.h>

typedef enum e_token_type
{
	WORD,
	STR,
	PIPE,
	REDIR_IN, // <
	REDIR_OUT, // >
	APPEND, // >>
	HEREDOC, // <<
	UNKNOWN
}				t_token_type;

typedef struct s_token
{
	char			*value;
	t_token_type	type;
	struct s_token	*next;
}				t_token;

//Lexer
t_token			*lexer(char *line);
t_token_type	get_token_type(char *line);

//Freeing
void			free_split(char **arr);
void			free_token_list(t_token *tokens);

#endif
