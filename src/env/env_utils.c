/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnguyen <wnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:58:57 by wnguyen           #+#    #+#             */
/*   Updated: 2024/01/19 14:39:03 by wnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	update_env_var(t_env **env_head, const char *key, const char *value)
{
	t_env	*current;
	t_env	*prev;
	t_env	*new_var;

	current = *env_head;
	prev = NULL;
	while (current)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = strdup(value);
			return ;
		}
		prev = current;
		current = current->next;
	}
	new_var = malloc(sizeof(t_env));
	new_var->key = strdup(key);
	new_var->value = strdup(value);
	new_var->next = NULL;
	if (prev)
		prev->next = new_var;
	else
		*env_head = new_var;
}

char	*get_env_var(t_env *env, const char *key)
{
	while (env)
	{
		if (strcmp(env->key, key) == 0)
			return (env->value);
		env = env->next;
	}
	return (NULL);
}
