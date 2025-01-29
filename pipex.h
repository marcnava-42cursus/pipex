/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:39:34 by marcnava          #+#    #+#             */
/*   Updated: 2025/01/24 16:31:34 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libs/libft/includes/libft.h"
# include <sys/types.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>

typedef enum e_errors
{
	ERR_PIPE = 1,
	ERR_ARGS = 2,
	ERR_NOPID = 3,
	ERR_FD = 4,
	ERR_EXEC = 127
}		t_errors;

// Error Handler

void	ft_error(int error_code, int fd);

// Processes

void	child_process(char **argv, int *pipe_fds, char **env);
void	parent_process(char **argv, int *pipe_fds, char **env);

// Utils

char	*get_path(char *command, char **env);
int		get_fd(char *path, int rw);

#endif