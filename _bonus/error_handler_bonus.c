/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:01:04 by marcnava          #+#    #+#             */
/*   Updated: 2025/03/10 20:25:11 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	error_usage(int error_code, int fd)
{
	const char	*cmdfile = "<command1> <command2> <output>";
	const char	*heredoc = ft_strjoin("'here_doc' <DELIMITER> ", cmdfile);

	ft_putendl_fd("Error: invalid number of arguments.", fd);
	ft_printf("Usages:\n\t./pipex <input> %s\n", cmdfile);
	ft_printf("\t./pipex %s\n", heredoc);
	ft_free((void *)&heredoc);
	close(fd);
	exit(error_code);
}

void	ft_error(int error_code, int fd)
{
	if (error_code == ERR_ARGS)
		error_usage(error_code, fd);
	else if (error_code == ERR_PIPE)
		perror("Error: Cannot handle pipe file descriptors");
	else if (error_code == ERR_NOPID)
		perror("Error: Cannot access process");
	else if (error_code == ERR_FD)
		perror("Error: Cannot open file descriptor");
	else if (error_code == ERR_ENV)
	{
		ft_putendl_fd("Error: Cannot access environment variables", fd);
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_putendl_fd("Unknown error occurred", fd);
		exit(EXIT_FAILURE);
	}
	exit(errno);
}
