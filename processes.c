/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:17:06 by marcnava          #+#    #+#             */
/*   Updated: 2024/12/06 19:33:12 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(char **argv, int *pipe_fds, char **env)
{
	argv = NULL;
	pipe_fds = NULL;
	env = NULL;
	ft_putendl("parent process");
}

void	child_process(char **argv, int *pipe_fds, char **env)
{
	argv = NULL;
	pipe_fds = NULL;
	env = NULL;
	ft_putendl("child process");
}
