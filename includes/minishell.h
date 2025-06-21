/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: made-jes <made-jes@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:50:01 by made-jes          #+#    #+#             */
/*   Updated: 2025/06/19 18:48:41 by made-jes         ###   ########.fr       */
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

typedef struct s_shell
{
	t_token		*tokens;
}				t_shell;

t_shell			*get_shell(void);
void			run_prompt(void);

//Lexer
t_token			*lexer(char *line);
t_token			*new_token(char *value);
t_token			*create_list(char **result);
void			fill_tokens(char **result, const char *line);
t_token_type	get_token_type(char *line);

//Parsing
int				validate_syntax(t_token *tokens);

//Freeing
void			free_split(char **arr);
void			free_token_list(t_token *tokens);

#endif
