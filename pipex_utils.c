/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:31:23 by marcnava          #+#    #+#             */
/*   Updated: 2024/12/11 04:12:08 by marcnava         ###   ########.fr       */
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
			ft_free((void *)&env_name);
			return (env[i] + j + 1);
		}
		ft_free((void **)&env_name);
		i++;
	}
	return (NULL);
}

char	*get_path(char *command, char **env)
{
	int		i;
	char	*path;
	char	**paths;
	char	**split_command;

	paths = ft_split(get_env("PATH", env), ':');
	split_command = ft_split(command, ' ');
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i++], ft_strjoin("/", split_command[0]));
		if (access(path, F_OK | X_OK) == 0)
		{
			ft_free_matrix((void **)&split_command);
			return (path);
		}
		ft_free((void **)&path);
	}
	ft_free_matrix((void **)&split_command);
	ft_free_matrix((void **)&paths);
	return (command);
}

int	get_fd(char *path, int rw)
{
	int	fd;

	if (rw == 0)
		fd = open(path, O_RDONLY, 0777);
	if (rw == 1)
		fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (rw == -1)
		ft_error(ERR_FD, 2);
	return (fd);
}
