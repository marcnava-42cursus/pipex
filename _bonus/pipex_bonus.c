/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:41:00 by marcnava          #+#    #+#             */
/*   Updated: 2025/03/20 10:16:03 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static int	handle_heredoc_mode(int *index, int argc, char **argv)
{
	if (argc < 6)
		ft_error(ERR_ARGS, STDERR_FILENO);
	*index = 3;
	here_doc(argv);
	return (get_fd(argv[argc - 1], 2));
}

static int	handle_standard_mode(int *index, int argc, char **argv)
{
	int	in;

	*index = 2;
	in = get_fd(argv[1], 0);
	dup2(in, STDIN_FILENO);
	close(in);
	return (get_fd(argv[argc - 1], 1));
}

int	main(int argc, char **argv, char **env)
{
	int		index;
	int		fd_output;

	if (argc < 5)
		ft_error(ERR_ARGS, STDERR_FILENO);
	if (ft_strcmp(argv[1], "here_doc") == 0)
		fd_output = handle_heredoc_mode(&index, argc, argv);
	else
		fd_output = handle_standard_mode(&index, argc, argv);
	while (index < argc - 2)
		new_pipe(argv[index++], env);
	dup2(fd_output, STDOUT_FILENO);
	close(fd_output);
	run(argv[argc - 2], env);
	while (wait(NULL) > 0)
		;
	return (0);
}
