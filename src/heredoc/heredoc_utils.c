/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:07:13 by edesaint          #+#    #+#             */
/*   Updated: 2024/01/27 23:30:04 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*find_name_heredoc(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	str[i] = 'a';
	while (str[i] <= 'z' && access(str, F_OK) == 0)
		str[i]++;
	return (str);
}

char	*get_name_heredoc(void)
{
	char	*temp;

    temp = malloc(6);
    if (!temp)
		return (NULL);
    temp = ft_strcpy(temp, "/tmp/");
    if (!temp)
		return (NULL);
	while (access(temp, F_OK) == 0)
	{
		temp = ft_strjoin(temp, "a");
		if (!temp)
			return (NULL);
		temp = find_name_heredoc(temp);
	}
	return (temp);
}