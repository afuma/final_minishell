/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   off_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:26:34 by blax              #+#    #+#             */
/*   Updated: 2024/01/24 20:07:14 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int				g_info;

int main(int argc, char *argv[])
{
    t_data *data;
    t_env	my_env;

    if (argc < 2)
        return (0);
    // if (!env || !env[0])
	// 	my_env = init_mini_env();
	// else
	// 	my_env = init_env(env);
    data = init_data(argv[1]);
    if (!is_closed_quotes(data))
        ft_error_2("unclosed quotes");
    ft_lexer(data);
    determine_token_types(data);
    if (!verif_syntax(data->token))
    {
        free_tokens(data->token);
        ft_error_2("syntax_erreur");
    }
    if (!pass_on_filters(data))
        ft_error_2("syntax_erreur");
    expand_tokens(data, &my_env);
    parser(data);
    print_tokens(data->token);
    print_nodes(data);
    free_all(data);
    return (0);
}