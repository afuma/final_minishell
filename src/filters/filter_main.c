/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 21:57:05 by edesaint          #+#    #+#             */
/*   Updated: 2024/01/24 22:24:31 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool pass_on_filters(t_data *data)
{
    if (!process_tokens(data, &is_noreserved_word))
        return (false);
    if (!process_tokens(data, &is_valid_affectation))
        return (false);
    return (true);
}