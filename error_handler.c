/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:41:21 by marcnava          #+#    #+#             */
/*   Updated: 2024/12/11 04:01:07 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	error_usage(int fd)
{
	ft_putendl_fd("Error: invalid number of arguments.", fd);
	ft_putendl_fd("Usage: ./pipex <file1> <command1> <command2> <file2>", fd);
}

static void	error_pipes(int fd)
{
	ft_putendl_fd("Error: Cannot handle pipe file descriptors.", fd);
}

static void	error_pid(int fd)
{
	ft_putendl_fd("Error: Cannot access process.", fd);
}

static void	error_fd(int fd)
{
	ft_putendl_fd("Error: Cannot open file descriptor.", fd);
}

void	ft_error(int error_code, int fd)
{
	if (error_code == ERR_ARGS)
		error_usage(fd);
	if (error_code == ERR_PIPE)
		error_pipes(fd);
	if (error_code == ERR_NOPID)
		error_pid(fd);
	if (error_code == ERR_FD)
		error_fd(fd);
	exit(error_code);
}
