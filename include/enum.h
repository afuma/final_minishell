/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blax <blax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:22:37 by blax              #+#    #+#             */
/*   Updated: 2023/12/19 16:27:00 by blax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

typedef enum e_status {
	SUCCESS = 1,
	FAILURE = 0
}	t_status;

typedef enum e_redir {
	OUT = 1,
	IN = 0
}	t_redir;

typedef enum e_ast_node_type {
    AST_COMMAND,
    AST_PIPE,
    AST_REDIRECT
} t_ast_node_type;

typedef enum e_state {
	T_COMMAND,
	T_OPTION,
	T_ARGUMENT,
	T_PIPE,
	T_NOREDIR,
	T_NULL,
	T_FILE,
	T_REDIR_IN,      // <
    T_REDIR_OUT,     // >
    T_REDIR_APPEND,  // >>
    T_REDIR_HEREDOC  // <<
}	t_state;

typedef enum e_stick_token {
	S_QUOTE,
	D_QUOTE,
	S_CHAR,
	S_SPACE,
	S_NULL
}	t_stick_token;

#endif