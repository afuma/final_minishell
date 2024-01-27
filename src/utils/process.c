/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 22:29:42 by edesaint          #+#    #+#             */
/*   Updated: 2024/01/27 22:49:44 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool process_tokens(t_data *data, bool (*f)(char *str))
{
    t_token *token;

    token = data->token;
    while (token)
    {
        if (!f(token->str))
            return (false);
        token = token->next;
    }
    return (true);
}

bool process_heredoc(t_data *data, t_node *node)
{
    t_token *token;

    token = data->token;
    while (token)
    {
		if (token && token->next && in_node(data, token))
		{
			if (is_redir_heredoc(token->type_token, token->next->type_token))
			{
				if (!sub_process_heredoc(data->env, node, token->next->str))
					return (false);
			}
		}
        token = token->next;
    }
    return (true);
}