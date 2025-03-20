/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:40:43 by marcnava          #+#    #+#             */
/*   Updated: 2025/03/20 08:28:33 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	create_pipe(int pipe_fds[2])
{
	if (pipe(pipe_fds) == -1)
		ft_error(ERR_PIPE, STDERR_FILENO);
}

static pid_t	create_process(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_error(ERR_NOPID, STDERR_FILENO);
	return (pid);
}

static void	validate_arguments(int argc, char **argv)
{
	if (argc != 5)
		ft_error(ERR_ARGS, STDERR_FILENO);
	if (argv[2][0] == '\0' || argv[3][0] == '\0')
		ft_error(ERR_NULL, STDERR_FILENO);
}

int	main(int argc, char **argv, char **env)
{
	int		pipe_fds[2];
	pid_t	pid1;
	pid_t	pid2;

	validate_arguments(argc, argv);
	create_pipe(pipe_fds);
	pid1 = create_process();
	if (pid1 == 0)
		child_process(argv, pipe_fds, env);
	pid2 = create_process();
	if (pid2 == 0)
		parent_process(argv, pipe_fds, env);
	close(pipe_fds[0]);
	close(pipe_fds[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
