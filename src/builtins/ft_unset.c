/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnguyen <wnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:21:48 by wnguyen           #+#    #+#             */
/*   Updated: 2024/01/20 20:17:42 by wnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	is_valid_env_name(const char *str)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[i]) && str[i] != '_')
		return (0);
	i++;
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static void	remove_env_link(t_env *env, t_env_link *link)
{
	t_env_link	*current;
	t_env_link	*previous;

	current = env->first;
	previous = NULL;
	while (current)
	{
		if (current == link)
		{
			if (previous)
				previous->next = current->next;
			else
				env->first = current->next;
			free(link->name);
			free(link->content);
			free(link);
			return ;
		}
		previous = current;
		current = current->next;
	}
}

void	ft_unset(char **args, t_env *env)
{
	t_env_link	*current;
	t_env_link	*next;
	int			i;

	i = 1;
	while (args[i])
	{
		if (!is_valid_env_name(args[i]))
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(args[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			i++;
			continue ;
		}
		current = env->first;
		while (current)
		{
			next = current->next;
			if (strcmp(current->name, args[i]) == 0)
				remove_env_link(env, current);
			current = next;
		}
		i++;
	}
}

