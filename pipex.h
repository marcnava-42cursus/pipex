/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:39:34 by marcnava          #+#    #+#             */
/*   Updated: 2024/12/11 21:51:01 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libs/libft/headers/libft.h"
# include <errno.h>
# include <string.h>

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

// Frees

void	free_all(int count, ...);
void	free_all_matrix(int count, ...);

#endif