/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_manager_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:29:17 by marcnava          #+#    #+#             */
/*   Updated: 2025/03/20 10:15:04 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	run(char *command, char **env)
{
	char	**split_command;
	char	*path;

	split_command = ft_split(command, ' ');
	if (!split_command)
		exit(ERR_MEM);
	path = get_path(split_command[0], env);
	if (!path)
	{
		free_matrix(split_command);
		ft_error(ERR_EXEC, STDERR_FILENO);
	}
	if (execve(path, split_command, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", STDERR_FILENO);
		if (!split_command[0])
			ft_putendl_fd(split_command[0], STDERR_FILENO);
		ft_free((void **)&path);
		free_matrix(split_command);
		exit(ERR_EXEC);
	}
}

void	new_pipe(char *command, char **env)
{
	pid_t	pid;
	int		pipe_fds[2];

	if (pipe(pipe_fds) == -1)
		ft_error(ERR_PIPE, STDERR_FILENO);
	pid = fork();
	if (pid == -1)
	{
		close(pipe_fds[0]);
		close(pipe_fds[1]);
		ft_error(ERR_NOPID, STDERR_FILENO);
	}
	if (!pid)
	{
		dup2(pipe_fds[1], STDOUT_FILENO);
		run(command, env);
		exit(0);
	}
	else
	{
		dup2(pipe_fds[0], STDIN_FILENO);
	}
	close(pipe_fds[0]);
	close(pipe_fds[1]);
}
