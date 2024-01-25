/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 21:57:05 by edesaint          #+#    #+#             */
/*   Updated: 2024/01/25 20:08:38 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool pass_on_filters(t_data *data)
{
    if (!process_tokens(data, &filter_authorized_word))
        return (false);
    if (!process_tokens(data, &filter_affectation))
        return (false);
    if (!process_tokens(data, &filter_quotes))
        return (false);
    if (!process_tokens(data, &filter_quotes))
        return (false);
    if (!process_tokens(data, &expand_tokens))
        return (false);
    return (true);
}