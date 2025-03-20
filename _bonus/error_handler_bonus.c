/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:01:04 by marcnava          #+#    #+#             */
/*   Updated: 2025/03/20 08:41:11 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	error_usage(int fd)
{
	const char	*cmdfile = "<command1> <command2> <output>";
	const char	*heredoc = ft_strjoin("'here_doc' <DELIMITER> ", cmdfile);

	ft_putendl_fd("Error: invalid number of arguments.", fd);
	ft_printf("Usages:\n\t./pipex <input> %s\n", cmdfile);
	ft_printf("\t./pipex %s\n", heredoc);
	ft_free((void *)&heredoc);
	exit(ERR_ARGS);
}

static void	error_unknown(int fd)
{
	ft_putendl_fd("Unknown error occurred", fd);
	exit(EXIT_FAILURE);
}

static void	error_handler(char *err_msg)
{
	perror(err_msg);
	exit(errno);
}

void	ft_error(int error_code, int fd)
{
	if (error_code == ERR_ARGS)
		error_usage(fd);
	else if (error_code == ERR_PIPE)
		error_handler("Error: Cannot handle pipe file descriptors");
	else if (error_code == ERR_NOPID)
		error_handler("Error: Cannot access process");
	else if (error_code == ERR_FD)
		error_handler("Error: Cannot open file descriptor");
	else if (error_code == ERR_ENV)
		error_handler("Error: Cannot access environment variables");
	else if (error_code == ERR_NULL)
		error_handler("Error: Null command");
	else if (error_code == ERR_EXEC)
		error_handler("Error: Command not found");
	else
		error_unknown(fd);
}
