/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:31:23 by marcnava          #+#    #+#             */
/*   Updated: 2025/03/20 08:28:35 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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

void	free_matrixes(char **m1, char **m2)
{
	free_matrix(m1);
	free_matrix(m2);
}
