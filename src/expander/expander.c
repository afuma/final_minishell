/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 23:04:42 by blax              #+#    #+#             */
/*   Updated: 2024/01/25 22:32:38 by edesaint         ###   ########.fr       */
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
        return (NULL);
    return (token->type_str == D_QUOTE || token->type_str == S_CHAR);
}

// a implementer dans filter_main.c
void expand_tokens(t_data *data, char *str)
{
    char *str_expand;

    if (is_expandable(str))
    {
        str_expand = expand_variables(data->env, str);
        if (str_expand)
        {
            replace_token_str(str, str_expand);
            free(str_expand);
        }
    }
}

void replace_token_str(char *str, char *new_value)
{
    free(str);
    str = ft_strdup(new_value);
}