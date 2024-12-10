/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:40:43 by marcnava          #+#    #+#             */
/*   Updated: 2024/12/10 21:31:08 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		pipe_fds[2];
	pid_t	pid;

	if (argc != 5)
		ft_error(ERR_ARGS);
	if (pipe(pipe_fds) == -1)
		ft_error(ERR_PIPE);
	pid = fork();
	if (pid == -1)
		ft_error(ERR_NOPID);
	if (!pid)
		child_process(argv, pipe_fds, env);
	parent_process(argv, pipe_fds, env);
	return (0);
}
