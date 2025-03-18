/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:07:17 by marcnava          #+#    #+#             */
/*   Updated: 2025/03/18 18:09:40 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*join_path(char *dir, char *file)
{
	char *path;
	char *full_path;

	path = ft_strjoin(dir, "/");
	if (!path)
		return (NULL);
	full_path = ft_strjoin(path, file);
	ft_free((void **)&path);
	return (full_path);
}

static char	**get_env_paths(char **env)
{
	char *path_env;

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
		return (free_matrixes(NULL, paths), NULL);
	result = search_in_paths(paths, split_command[0]);
	free_matrixes(split_command, paths);
	return (result);
}
