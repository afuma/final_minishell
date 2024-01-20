/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnguyen <wnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:14:49 by wnguyen           #+#    #+#             */
/*   Updated: 2024/01/20 11:25:44 by wnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool is_builtin(t_node *node)
{
	if (!node->tab_exec || !node->tab_exec[0])
		return (false);
	if (strcmp(node->tab_exec[0], "echo") == 0 ||
		strcmp(node->tab_exec[0], "cd") == 0 ||
		strcmp(node->tab_exec[0], "pwd") == 0 ||
		strcmp(node->tab_exec[0], "export") == 0 ||
		strcmp(node->tab_exec[0], "unset") == 0 ||
		strcmp(node->tab_exec[0], "env") == 0 ||
		strcmp(node->tab_exec[0], "exit") == 0)
		return (true);
	return (false);
}

void execute_builtin(t_node *node)
{
	if (strcmp(node->tab_exec[0], "echo") == 0)
		ft_echo(node);
	else if (strcmp(node->tab_exec[0], "cd") == 0)
		ft_cd(node);
	else if (strcmp(node->tab_exec[0], "pwd") == 0)
		ft_pwd(node);
	else if (strcmp(node->tab_exec[0], "export") == 0)
		ft_export(node);
	else if (strcmp(node->tab_exec[0], "unset") == 0)
		ft_unset(node);
	else if (strcmp(node->tab_exec[0], "env") == 0)
		ft_env(node);
	else if (strcmp(node->tab_exec[0], "exit") == 0)
		ft_exit(node);
}

void	execute_command_node(t_node *node)
{
	char	*cmd;

	cmd = node->tab_exec[0];
	if (!cmd)
		exit(EXIT_FAILURE);
	if (node->type != AST_COMMAND)
	{
		perror("Tentative d'exécution d'un type de nœud non-commande");
		return ;
	}
	if (is_builtin(node))
		execute_builtin(node);
	else
	{
		if (fork() == 0)
		{
			execvp(cmd, node->tab_exec);
			perror("execvp");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL); // Attendre que le processus enfant se termine
		}
	}
}
