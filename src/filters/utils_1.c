/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:36:42 by edesaint          #+#    #+#             */
/*   Updated: 2024/01/24 22:28:01 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// X 
// ne devrais plus etre utile car on gere les doubles quotes en amont mais on peut toujours y faire reference
// si besoin avec le type_token->rstick/lstick
// bool is_empty_token(t_token *token)
// {
// 	if (!token)
// 		return (true);
// 	if (token && token->str[0] == '\0'
// 		&& (token->type_str == S_QUOTE
// 		|| token->type_str == D_QUOTE))
// 	{
// 		return (true);
// 	}
// 	return (false);
// }

// if (token->type_token == T_COMMAND && token->rstick_token == is_quote(token->str))

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

bool is_noreserved_word(char *str)
{
    return (!is_reserved_word(str));
}

bool is_reserved_word(char *str)
{
    return (
        ft_strcmp(str, "if") == 0 || 
        ft_strcmp(str, "then") == 0 || 
        ft_strcmp(str, "elif") == 0 || 
        ft_strcmp(str, "else") == 0 || 
        ft_strcmp(str, "time") == 0 || 
        ft_strcmp(str, "for") == 0 || 
        ft_strcmp(str, "in") == 0 || 
        ft_strcmp(str, "until") == 0 || 
        ft_strcmp(str, "while") == 0 || 
        ft_strcmp(str, "done") == 0 || 
        ft_strcmp(str, "case") == 0 || 
        ft_strcmp(str, "esac") == 0 || 
        ft_strcmp(str, "coproc") == 0 || 
        ft_strcmp(str, "select") == 0 || 
        ft_strcmp(str, "{") == 0 || 
        ft_strcmp(str, "}") == 0 || 
        ft_strcmp(str, "[[") == 0 || 
        ft_strcmp(str, "]]") == 0 || 
        ft_strcmp(str, "!") == 0);
}
