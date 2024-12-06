/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:39:34 by marcnava          #+#    #+#             */
/*   Updated: 2024/12/06 19:22:50 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libs/libft/headers/libft.h"

// Error Handler

void	error_usage(int exit_code);
void	error_pipes(int exit_code);

// Processes

void	child_process(char **argv, int *pipe_fds, char **env);
void	parent_process(char **argv, int *pipe_fds, char **env);

#endif