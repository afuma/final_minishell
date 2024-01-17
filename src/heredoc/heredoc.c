/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnguyen <wnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:50:37 by wnguyen           #+#    #+#             */
/*   Updated: 2024/01/17 15:08:54 by wnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

#define READ_END 0
#define WRITE_END 1


void	handle_heredoc(char *delimiter, int write_end)
{
	char	*line;
	size_t	len;

	len = 0;
	line = NULL;
	while (getline(&line, &len, stdin) > 0)
	{
		if (strcmp(line, delimiter) == 0)
			break ;
		write(write_end, line, strlen(line));
		free(line);
		line = NULL;
	}
	free(line);
	close(write_end);
}

void	execute_command_with_heredoc(char **cmd, int read_end)
{
	dup2(read_end, STDIN_FILENO);
	close(read_end);
	execve(cmd[0], cmd, NULL);
	perror("execve");
	_exit(EXIT_FAILURE);
}

void	setup_heredoc(char *delimiter, char **cmd)
{
	int		pipe_fds[2];
	pid_t	pid;

	if (pipe(pipe_fds) == -1)
		return (perror("pipe"), g_signal = 1);
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		g_signal = 1;
		return ;
	}
	if (pid == 0)
	{
		close(pipe_fds[WRITE_END]);
		execute_command_with_heredoc(cmd, pipe_fds[READ_END]);
	}
	else
	{
		close(pipe_fds[READ_END]);
		handle_heredoc(delimiter, pipe_fds[WRITE_END]);
		waitpid(pid, NULL, 0);
	}
}
