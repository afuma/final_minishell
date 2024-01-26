/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 23:04:42 by blax              #+#    #+#             */
/*   Updated: 2024/01/26 12:27:30 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int g_last_exit_status = 0;

// // Fonction pour obtenir le dernier statut de sortie
// int get_last_exit_status(void)
// {
//     // Supposons que vous avez une variable globale ou une structure qui stocke cette information
//     return (g_last_exit_status); // Remplacez par votre propre mécanisme de stockage
// }

bool is_expandable(t_token *token)
{
    if (!token)
        return (false);
    return (token->type_str == D_QUOTE || token->type_str == S_CHAR);
}

void expand_tokens(t_env *env, char *str)
{
    char *str_expand;

    if (!ft_strchr_bool(str, '$'))
        return ;
    str_expand = expand_variables(env, str);
    if (str_expand)
        replaceString(&str, str_expand);
}

void replaceString(char **original, const char *newString)
{
    free(*original);
    *original = malloc(strlen(newString) + 1);
    strcpy(*original, newString);
}
