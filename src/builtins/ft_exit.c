/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnguyen <wnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:22:06 by wnguyen           #+#    #+#             */
/*   Updated: 2024/01/20 16:29:35 by wnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	is_valid_exit_num(const char *str)
{
	int	i;
	int	num;

	i = 0;
	if (str[i] == '-')
		return (0);
	while (str[i] == '0')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	num = ft_atoi(str);
	if (num < 0 || num > 255)
		return (0);
	return (1);
}

static void	exit_with_error(char *arg)
{
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putendl_fd(": numeric argument required", 2);
	exit(2);
}

void	ft_exit(char **args)
{
	int	exit_status;

	exit_status = 0;
	if (!args[1])
		exit(exit_status);
	if (!is_valid_exit_num(args[1]))
		exit_with_error(args[1]);
	exit_status = ft_atoi(args[1]);
	if (args[2])
	{
		ft_putendl_fd("minishell: exit: too many arguments", 2);
		return ;
	}
	ft_putendl_fd("exit", 2);
	exit(exit_status);
}
