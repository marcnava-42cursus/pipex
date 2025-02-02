/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:17:06 by marcnava          #+#    #+#             */
/*   Updated: 2025/02/02 16:52:27 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_matrix(char **matrix)
{
	int i = 0;

	while (matrix && matrix[i])
	{
		ft_free((void **)&matrix[i]);
		i++;
	}
	ft_free((void **)matrix);
}

static void	run(char *command, char **env)
{
	char	**split_command;
	char	*path;

	split_command = ft_split(command, ' ');
	if (!split_command)
		exit(ERR_MEM);
	path = get_path(split_command[0], env);
	if (execve(path, split_command, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", STDERR_FILENO);
		ft_putendl_fd(split_command[0], STDERR_FILENO);
		ft_free((void **)&path);
		free_matrix(split_command);
		exit(ERR_EXEC);
	}
}

void	parent_process(char **argv, int *pipe_fds, char **env)
{
	int	fd;

	fd = get_fd(argv[4], O_WRONLY);
	dup2(fd, STDOUT_FILENO);
	dup2(pipe_fds[0], STDIN_FILENO);
	close(pipe_fds[1]);
	run(argv[3], env);
}

void	child_process(char **argv, int *pipe_fds, char **env)
{
	int	fd;

	fd = get_fd(argv[1], O_RDONLY);
	dup2(fd, STDIN_FILENO);
	dup2(pipe_fds[1], STDOUT_FILENO);
	close(pipe_fds[0]);
	run(argv[2], env);
}
