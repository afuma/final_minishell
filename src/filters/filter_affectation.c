/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_affectation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 21:57:56 by edesaint          #+#    #+#             */
/*   Updated: 2024/01/24 22:41:33 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool is_valid_affectation(char *str)
{
    char *sign_equal;
    
    sign_equal = ft_strchr(str, '=');
    if (!sign_equal)
        return (false);
    if (!is_valid_affectation_varname(str, sign_equal))
        return (false);
    // if (!is_valid_affectation_content(str))
    //     return (false);
    return (true);
}

bool is_valid_affectation_varname(char *str, char *sign_equal)
{
    int i;

    i = 0;
    if (!ft_isalpha(str[0]))
        return (false);
    while (str[i] && str[i] != *sign_equal)
    {
        if (!ft_isalnum(str[i]) && str[i] != '_')
            return (false);
        i++;
    }
    return (true);
}

// bool is_valid_affectation_content(char *str)
// {
//     return (true);
// }
