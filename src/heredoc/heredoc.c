/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:03:00 by edesaint          #+#    #+#             */
/*   Updated: 2024/01/27 22:57:40 by edesaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool is_redir_heredoc(t_state ttoken_1, t_state ttoken_2)
{
	return (ttoken_1 == T_REDIR_HEREDOC && ttoken_2 == T_FILE);
}

bool sub_process_heredoc(t_env *env, t_node *node, char *delimiter)
{
    int fd;
    int old_fd;
    
    old_fd = dup(STDIN_FILENO);
    fd = open(node->redir_heredoc, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
    {
        close(old_fd);
        return (false);
    }
	get_and_save_heredoc_content(env, fd, delimiter);
	node->redir_heredoc = get_name_heredoc();
    close(fd);
    if (dup2(old_fd, STDIN_FILENO) < 0)
    {
        close(old_fd);
        return (false);
    }
	close(old_fd);
    return (true);
}

void	get_and_save_heredoc_content(t_env *env, int fd, char *delimiter)
{
	char *line;

	line = readline("> ");
    while (line != NULL && ft_strcmp(line, delimiter) == 0 && errno != EINTR)
	{
        expand_string(env, line);
		write(fd, line, ft_strlen(line));
        free(line);
        line = readline("> ");
        if (!line && errno != EINTR && errno != EBADF)
			write(STDERR_FILENO, "\n", 1);
        if (errno == EINTR || errno == EBADF)
		{
			free (line);
			line = NULL;
			env->lst_exit = 128 + SIGINT;
		}
		write(fd, "\n", 1);
    }
}