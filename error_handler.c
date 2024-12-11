/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:01:04 by marcnava          #+#    #+#             */
/*   Updated: 2024/12/11 21:08:46 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	error_usage(int fd)
{
	ft_putendl_fd("Error: invalid number of arguments.", fd);
	ft_putendl_fd("Usage: ./pipex <file1> <command1> <command2> <file2>", fd);
}

void	ft_error(int error_code, int fd)
{
	if (error_code == ERR_ARGS)
	{
		error_usage(fd);
		exit(error_code);
	}
	else if (error_code == ERR_PIPE)
	{
		perror("Error: Cannot handle pipe file descriptors");
		exit(errno);
	}
	else if (error_code == ERR_NOPID)
	{
		perror("Error: Cannot access process");
		exit(errno);
	}
	else if (error_code == ERR_FD)
	{
		perror("Error: Cannot open file descriptor");
		exit(errno);
	}
	else
	{
		ft_putendl_fd("Unknown error occurred", fd);
		exit(EXIT_FAILURE);
	}
}
