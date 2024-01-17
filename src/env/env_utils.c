/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnguyen <wnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:58:57 by wnguyen           #+#    #+#             */
/*   Updated: 2024/01/17 13:59:06 by wnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	update_env_var(t_list **env, const char *key, const char *value)
{
	t_list	*node;
	char	*new_var;
	char	*temp;

	temp = ft_strjoin(key, "=");
	new_var = ft_strjoin(temp, value);
	free(temp);

	node = *env;
	while (node)
	{
		if (env_cmp(node->content, key) == 0)
		{
			free(node->content);
			node->content = new_var;
			return ;
		}
		node = node->next;
	}

	ft_lstadd_back(env, ft_lstnew(new_var));
}
