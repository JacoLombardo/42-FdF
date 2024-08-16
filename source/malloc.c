/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:23:18 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/16 11:26:34 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_matrix	***ft_free_matrix(t_matrix ***matrix, t_2D *size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size->x)
	{
		j = 0;
		while (j < size->y)
		{
			free(matrix[i][j]->iso);
			free(matrix[i][j]);
			j++;
		}
		free(matrix[i]);
		i++;
	}
	free(matrix);
	matrix = NULL;
	free(size);
	return (NULL);
}

t_matrix	***ft_free_that_matrix(t_matrix ***matrix, int i, int j, t_2D *size)
{
	int	k;
	int	l;

	k = i - 1;
	if (j)
		k = i;
	while (k >= 0)
	{
		if (j && k == i)
			l = j;
		else
			l = size->y;
		while (--l >= 0)
		{
			free(matrix[k][l]);
		}
		free(matrix[k]);
		k--;
	}
	free(matrix);
	matrix = NULL;
	free(size);
	return (NULL);
}

t_matrix	***ft_malloc(t_2D *size)
{
	int			i;
	int			j;
	t_matrix	***matrix;

	i = 0;
	matrix = (t_matrix ***)malloc(size->x * sizeof(t_matrix **));
	if (!matrix)
		return (NULL);
	while (i < size->x)
	{
		j = 0;
		matrix[i] = (t_matrix **)malloc(size->y * sizeof(t_matrix *));
		if (!matrix[i])
			return (ft_free_that_matrix(matrix, i, 0, size));
		while (j < size->y)
		{
			matrix[i][j] = (t_matrix *)malloc(1 * sizeof(t_matrix));
			if (!matrix[i][j])
				return (ft_free_that_matrix(matrix, i, j, size));
			j++;
		}
		i++;
	}
	return (matrix);
}
