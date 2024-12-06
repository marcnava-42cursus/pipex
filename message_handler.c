/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:41:21 by marcnava          #+#    #+#             */
/*   Updated: 2024/12/06 19:09:56 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_usage(int exit_code)
{
	ft_putendl("Error: invalid number of arguments.");
	ft_putendl("Usage: ./pipex <file1> <command1> <command2> <file2>");
	exit(exit_code);
}

void	error_pipes(int exit_code)
{
	ft_putendl("Error: Cannot handle pipe file descriptors.");
	exit(exit_code);
}
