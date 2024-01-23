/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:10:16 by blax              #+#    #+#             */
/*   Updated: 2024/01/23 12:15:37 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void remove_quotes(char *input, char type_quote)
{
    size_t len;

    len = ft_strlen(input);
    if (len >= 2 && input[0] == type_quote && input[len - 1] == type_quote)
    {
        ft_memmove(input, input + 1, len - 2);
        input[len - 2] = '\0';
    }
}

void parse_quote_tokens(t_data *data)
{
	t_token *cur_token;

	cur_token = data->token;
    while (cur_token)
	{
        if (cur_token->type_str == S_QUOTE)
			remove_quotes(cur_token->str, '\'');
		else if (cur_token->type_str == D_QUOTE)
			remove_quotes(cur_token->str, '"');
        cur_token = cur_token->next;
    }
}