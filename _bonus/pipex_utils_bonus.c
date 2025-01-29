/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:13:02 by marcnava          #+#    #+#             */
/*   Updated: 2025/01/29 17:29:20 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	free_matrixes(char **m1, char **m2)
{
	ft_free_matrix((void **)m1);
	ft_free_matrix((void **)m2);
}

static char	*get_env(char *name, char **env)
{
	int		i;
	int		j;
	char	*env_name;

	i = 0;
	if (env == NULL || *env == NULL)
		ft_error(ERR_ENV, STDERR_FILENO);
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

char	*get_path(char *command, char **env)
{
	int		i;
	char	*path;
	char	*full_path;
	char	**paths;
	char	**split_command;

	i = 0;
	paths = ft_split(get_env("PATH", env), ':');
	split_command = ft_split(command, ' ');
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
	if (rw == 2)
		fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
		ft_error(ERR_FD, STDERR_FILENO);
	return (fd);
}
