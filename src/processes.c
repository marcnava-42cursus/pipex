/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:17:06 by marcnava          #+#    #+#             */
/*   Updated: 2025/03/17 15:41:22 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	*run(char *command, char **env)
{
	char	**split_command;
	char	*path;

	split_command = ft_split(command, ' ');
	if (!split_command)
		return (free_matrix(split_command), exit(ERR_MEM), NULL);
	path = get_path(split_command[0], env);
	if (!path)
	{
		free_matrix(split_command); 
		exit(ERR_MEM);
	}
	if (execve(path, split_command, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", STDERR_FILENO);
		if (split_command[0])
			ft_putendl_fd(split_command[0], STDERR_FILENO);
		ft_free((void **)&path);
		free_matrix(split_command);
		exit(ERR_EXEC);
	}
	return (NULL);
}

void	parent_process(char **argv, int *pipe_fds, char **env)
{
	int	fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd == -1)
	{
		close(pipe_fds[0]);
		close(pipe_fds[1]);
		ft_error(ERR_FD, STDERR_FILENO);
	}
	dup2(fd, STDOUT_FILENO);
	dup2(pipe_fds[0], STDIN_FILENO);
	close(pipe_fds[0]);
	close(pipe_fds[1]);
	close(fd);
	run(argv[3], env);
	exit(0);
}

void	child_process(char **argv, int *pipe_fds, char **env)
{
	int	fd;
	
	fd = open(argv[1], O_RDONLY, 0664);
	if (fd == -1)
	{
		close(pipe_fds[0]);
		close(pipe_fds[1]);
		ft_error(ERR_FD, STDERR_FILENO);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(pipe_fds[1], STDOUT_FILENO);
	close(pipe_fds[1]);
	close(pipe_fds[0]);
	run(argv[2], env);
	exit(0);
}
