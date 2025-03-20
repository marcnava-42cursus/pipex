/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:39:34 by marcnava          #+#    #+#             */
/*   Updated: 2025/03/18 20:11:33 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libs/libft/includes/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
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
	ERR_ENV = 5,
	ERR_NULL = 6,
	ERR_MEM = 12,
	ERR_EXEC = 127
}		t_errors;

// Error Handler

void	ft_error(int error_code, int fd);

// Processes

void	child_process(char **argv, int *pipe_fds, char **env);
void	parent_process(char **argv, int *pipe_fds, char **env);

// Utils

char	*get_path(char *command, char **env);
void	free_matrix(char **matrix);
void	free_matrixes(char **m1, char **m2);

#endif