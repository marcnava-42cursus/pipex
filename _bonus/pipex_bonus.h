/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:42:12 by marcnava          #+#    #+#             */
/*   Updated: 2025/01/29 17:19:54 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libs/libft/includes/libft.h"
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
	ERR_EXEC = 127
}		t_errors;

// Error Handler

void	ft_error(int error_code, int fd);

// Processes

void	new_pipe(char *command, char **env);
void	run(char *command, char **env);

// Utils

char	*get_path(char *command, char **env);
int		get_fd(char *path, int rw);
void	here_doc(char **argv);

#endif