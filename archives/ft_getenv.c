/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 21:17:12 by edesaint          #+#    #+#             */
/*   Updated: 2024/01/24 21:26:07 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// verifie et recupere la variable d'environnement si il y a une qui correspondance
t_env *ft_getenv(char *env_name, t_env *env)
{
    t_env_link *env_link;
    
    env_link = env->first;
    while (env_link)
    {
        if (ft_strcmp(env_name, env_link->name) == 0)
            return (ft_strdup(env_link->content)); // soit on retourne un pointeur (comme c'est que de l'affichage pourquoi pas,
                                                    // comme ca on a pas a free)
        env_link = env_link->next;
    }
    return (NULL);
}