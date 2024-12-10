/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:41:21 by marcnava          #+#    #+#             */
/*   Updated: 2024/12/10 21:20:57 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	error_usage(void)
{
	ft_putendl("Error: invalid number of arguments.");
	ft_putendl("Usage: ./pipex <file1> <command1> <command2> <file2>");
}

static void	error_pipes(void)
{
	ft_putendl("Error: Cannot handle pipe file descriptors.");
}

static void	error_pid(void)
{
	ft_putendl("Error: Cannot access process.");
}

void	ft_error(int error_code)
{
	if (error_code == ERR_ARGS)
		error_usage();
	if (error_code == ERR_PIPE)
		error_pipes();
	if (error_code == ERR_NOPID)
		error_pid();
	exit(error_code);
}
