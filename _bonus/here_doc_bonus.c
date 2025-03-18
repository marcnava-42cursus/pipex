/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:51:26 by marcnava          #+#    #+#             */
/*   Updated: 2025/03/10 19:39:57 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	get_input(char **argv, int *pipe_fds)
{
	char	*line;

	close(pipe_fds[0]);
	while ("true")
	{
		line = get_next_line(STDIN_FILENO);
		if (!line || ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0)
		{
			close(pipe_fds[1]);
			ft_free((void **)&line);
			exit(0);
		}
		ft_putstr_fd(line, pipe_fds[1]);
		ft_free((void **)&line);
	}
}

void	here_doc(char **argv)
{
	int		pipe_fds[2];
	pid_t	pid;

	if (pipe(pipe_fds) == -1)
		ft_error(ERR_PIPE, STDERR_FILENO);
	pid = fork();
	if (pid == -1)
		ft_error(ERR_NOPID, STDERR_FILENO);
	if (!pid)
	{
		close(pipe_fds[0]);
		get_input(argv, pipe_fds);
	}
	else
	{
		dup2(pipe_fds[0], STDIN_FILENO);
		close(pipe_fds[1]);
		wait(NULL);
	}
}
