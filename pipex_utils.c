/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:31:23 by marcnava          #+#    #+#             */
/*   Updated: 2024/12/12 20:21:35 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_env(char *name, char **env)
{
	int		i;
	int		j;
	char	*env_name;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		env_name = ft_substr(env[i], 0, j);
		if (ft_strcmp(env_name, name) == 0)
		{
			free(env_name);
			return (env[i] + j + 1);
		}
		free(env_name);
		i++;
	}
	return (NULL);
}

static void	free_matrixes(char **m1, char **m2)
{
	ft_free_matrix((void **)m1);
	ft_free_matrix((void **)m2);
}

char	*get_path(char *command, char **env)
{
	int		i;
	char	*path;
	char	*full_path;
	char	**paths;
	char	**split_command;

	paths = ft_split(get_env("PATH", env), ':');
	split_command = ft_split(command, ' ');
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		if (!path)
			return (free_matrixes(split_command, paths), NULL);
		full_path = ft_strjoin(path, split_command[0]);
		free(path);
		if (!full_path)
			return (free_matrixes(split_command, paths), NULL);
		if (access(full_path, F_OK | X_OK) == 0)
			return (free_matrixes(split_command, paths), full_path);
		free(full_path);
		i++;
	}
	return (free_matrixes(split_command, paths), command);
}

int	get_fd(char *path, int rw)
{
	int	fd;

	if (rw == 0)
		fd = open(path, O_RDONLY, 0777);
	if (rw == 1)
		fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		ft_error(ERR_FD, 2);
	return (fd);
}
