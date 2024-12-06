/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:40:43 by marcnava          #+#    #+#             */
/*   Updated: 2024/12/06 19:31:50 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		pipe_fds[2];
	pid_t	pid;

	if (argc != 5)
		error_usage(1);
	if (pipe(pipe_fds) == -1)
		error_pipes(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (!pid)
		child_process(argv, pipe_fds, env);
	parent_process(argv, pipe_fds, env);
	return (0);
}
