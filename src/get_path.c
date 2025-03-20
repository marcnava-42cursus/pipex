/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:07:17 by marcnava          #+#    #+#             */
/*   Updated: 2025/03/20 08:28:36 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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
			ft_free((void **)&env_name);
			return (env[i] + j + 1);
		}
		ft_free((void **)&env_name);
		i++;
	}
	return (NULL);
}

static char	*join_path(char *dir, char *file)
{
	char	*path;
	char	*full_path;

	path = ft_strjoin(dir, "/");
	if (!path)
		return (NULL);
	full_path = ft_strjoin(path, file);
	ft_free((void **)&path);
	return (full_path);
}

static char	**get_env_paths(char **env)
{
	char	*path_env;

	if (!env)
		return (NULL);
	path_env = get_env("PATH", env);
	if (!path_env)
		return (NULL);
	return (ft_split(path_env, ':'));
}

static char	*search_in_paths(char **paths, char *command)
{
	int		i;
	char	*full_path;

	i = 0;
	while (paths[i])
	{
		full_path = join_path(paths[i], command);
		if (!full_path)
			return (NULL);
		if (access(full_path, F_OK | X_OK) == 0)
			return (full_path);
		ft_free((void **)&full_path);
		i++;
	}
	return (NULL);
}

char	*get_path(char *command, char **env)
{
	char	**split_command;
	char	**paths;
	char	*result;

	if (!command || !*command || !env)
		return (NULL);
	if (access(command, F_OK | X_OK) == 0)
		return (command);
	paths = get_env_paths(env);
	if (!paths)
		return (NULL);
	split_command = ft_split(command, ' ');
	if (!split_command)
		return (free_matrix(paths), NULL);
	result = search_in_paths(paths, split_command[0]);
	if (!result)
	{
		free_matrixes(split_command, paths);
		return (NULL);
	}
	free_matrixes(split_command, paths);
	return (result);
}
