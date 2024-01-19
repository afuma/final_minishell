/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnguyen <wnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:59:16 by wnguyen           #+#    #+#             */
/*   Updated: 2024/01/19 15:09:57 by wnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	cd_error(const char *message)
{
	ft_putstr_fd("cd: ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

int	change_directory(const char *path, t_env *env)
{
	char	old_path[PATH_MAX];
	char	new_path[PATH_MAX];

	if (getcwd(old_path, PATH_MAX) == NULL)
		return (cd_error("Error retrieving current directory"));
	if (chdir(path) == -1)
		return (cd_error("No such file or directory"));
	if (getcwd(new_path, PATH_MAX) == NULL)
		return (cd_error("Error getting new directory"));
	update_env_var(&env, "OLDPWD", old_path);
	update_env_var(&env, "PWD", new_path);
	return (0);
}

int	ft_cd(char **argv, t_env *env)
{
	char	*path;

	if (argv[1] == NULL)
	{
		path = get_env_var(env, "HOME");
		if (path == NULL)
			return (cd_error("HOME not set"));
	}
	else if (strcmp(argv[1], "-") == 0)
	{
		path = get_env_var(env, "OLDPWD");
		if (path == NULL)
			return (cd_error("OLDPWD not set"));
	}
	else
		path = argv[1];
	return (change_directory(path, env));
}
