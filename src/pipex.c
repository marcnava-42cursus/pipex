/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:40:43 by marcnava          #+#    #+#             */
/*   Updated: 2025/03/17 17:54:21 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		pipe_fds[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		ft_error(ERR_ARGS, STDERR_FILENO);
	if (argv[2][0] == '\0' || argv[3][0] == '\0')
		ft_error(ERR_NULL, STDERR_FILENO);
	if (pipe(pipe_fds) == -1)
		ft_error(ERR_PIPE, STDERR_FILENO);
	pid1 = fork();
	if (pid1 == -1)
	{
		close(pipe_fds[0]);
		close(pipe_fds[1]);
		ft_error(ERR_NOPID, STDERR_FILENO);
	}
	if (pid1 == 0)
		child_process(argv, pipe_fds, env);
	pid2 = fork();
	if (pid2 == -1)
	{
		close(pipe_fds[0]);
		close(pipe_fds[1]);
		ft_error(ERR_NOPID, STDERR_FILENO);
	}
	if (pid2 == 0)
		parent_process(argv, pipe_fds, env);
	close(pipe_fds[0]);
	close(pipe_fds[1]);
	return (waitpid(pid1, NULL, 0), waitpid(pid2, NULL, 0), 0);
}
