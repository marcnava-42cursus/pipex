/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcnava <marcnava@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:48:32 by marcnava          #+#    #+#             */
/*   Updated: 2024/12/11 22:15:29 by marcnava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

void	free_all(int count, ...)
{
	va_list	args;
	int		i;
	void	*ptr;

	va_start(args, count);
	i = 0;
	while (i < count)
	{
		ptr = va_arg(args, void *);
		if (ptr)
			free(ptr);
		i++;
	}
	va_end(args);
}

void	free_all_matrix(int count, ...)
{
	char	**matrix;
	va_list	args;
	int		i;
	int		j;

	va_start(args, count);
	i = 0;
	while (i < count)
	{
		matrix = va_arg(args, char **);
		if (matrix)
		{
			j = 0;
			while (matrix[j])
			{
				free(matrix[j]);
				j++;
			}
			free(matrix);
		}
		i++;
	}
	va_end(args);
}
