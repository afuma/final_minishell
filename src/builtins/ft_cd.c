/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnguyen <wnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:59:16 by wnguyen           #+#    #+#             */
/*   Updated: 2024/01/17 13:59:26 by wnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_cd_path(char **args)
{
	char	*path;

	if (strcmp(args[1], "-") == 0)
		path = getenv("OLDPWD");
	else if (strcmp(args[1], "~") == 0 || strcmp(args[1], "") == 0)
		path = getenv("HOME");
	else
		path = args[1];

	if (!path)
	{
		ft_putstr_fd("cd: path not set\n", 2);
		return (NULL);
	}
	return (path);
}

void	update_cd_env_vars(t_data *data, char *old_pwd)
{
	char	*new_pwd;

	new_pwd = getcwd(NULL, 0);
	update_env_var(&(data->env), "OLDPWD", old_pwd);
	update_env_var(&(data->env), "PWD", new_pwd);
	free(new_pwd);
}

void	ft_cd(char **args, t_data *data)
{
	char	*path;
	char	*old_pwd;

	if (!args[1] || args[2])
	{
		ft_putstr_fd("cd: wrong number of arguments\n", 2);
		return ;
	}

	path = get_cd_path(args);
	if (!path)
		return ;

	old_pwd = getcwd(NULL, 0);
	if (!old_pwd || chdir(path) != 0)
	{
		ft_putstr_fd("cd: error changing directory\n", 2);
		free(old_pwd);
		return ;
	}

	update_cd_env_vars(data, old_pwd);
	free(old_pwd);
}
