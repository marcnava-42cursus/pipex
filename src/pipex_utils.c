/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:31:23 by marcnava          #+#    #+#             */
/*   Updated: 2025/03/18 18:04:03 by marcnava         ###   ########.fr       */
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

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[i])
	{
		ft_free((void **)&matrix[i]);
		i++;
	}
	ft_free((void **)&matrix);
}

static void	free_matrixes(char **m1, char **m2)
{
	free_matrix(m1);
	free_matrix(m2);
}

char	*get_path(char *command, char **env)
{
	int		i;
	char	*path;
	char	*full_path;
	char	**paths;
	char	**split_command;

	if (!command || !*command || !env)
		return (NULL);
	if (access(command, F_OK | X_OK) == 0)
		return (command);
	paths = ft_split(get_env("PATH", env), ':');
	if (!paths)
		return (NULL);
	split_command = ft_split(command, ' ');
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		if (!path)
			return (free_matrixes(split_command, paths), NULL);
		full_path = ft_strjoin(path, split_command[0]);
		ft_free((void **)&path);
		if (!full_path)
			return (free_matrixes(split_command, paths), NULL);
		if (access(full_path, F_OK | X_OK) == 0)
			return (free_matrixes(split_command, paths), full_path);
		ft_free((void **)&full_path);
		i++;
	}
	return (free_matrixes(split_command, paths), NULL);
}
