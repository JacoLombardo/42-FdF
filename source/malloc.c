/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:23:18 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/06 12:35:38 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_matrix	***ft_free_matrix(t_matrix ***matrix, t_size *size)
{
	int			i;
	int			j;

	i = 0;
	while (i < size->x)
	{
		j = 0;
		while (j < size->y)
		{
			free(matrix[i][j]);
			j++;
		}
		free(matrix[i]);
		i++;
	}
    free(matrix);
    matrix = NULL;
	return (NULL);
}

t_matrix	***ft_free_that_matrix(t_matrix ***matrix, int i, int j, t_size *size)
{
	int	k;
	int	l;

	k = i - 1;
    //ft_printf("inside: i:%i, j:%i\n", i, j);
	if (j)
		k = i;
	while (k >= 0)
	{
		l = -1;
		if (j && k == i)
		{
			while (++l < j)
			{
				free(matrix[k][l]);
                ft_printf("Freed column: x:%i, y:%i\n", k, l);
			}
		}
		else
		{
			while (++l < size->y)
			{
				free(matrix[k][l]);
                ft_printf("Freed column: x:%i, y:%i\n", k, l);
			}
		}
		free(matrix[k]);
        ft_printf("Freed row: x:%i\n", k);
		k--;
	}
    free(matrix);
    matrix = NULL;
	return (NULL);
}

t_matrix	***ft_malloc(t_size *size)
{
	int			i;
	int			j;
	t_matrix	***matrix;

	i = 0;
	matrix = (t_matrix ***)malloc(size->x * sizeof(t_matrix **));
	while (i < size->x)
	{
		j = 0;
		matrix[i] = (t_matrix **)malloc(size->y * sizeof(t_matrix *));
		if (!matrix[i])
			return (ft_free_that_matrix(matrix, i, 0, size));
        ft_printf("Malloc row: x:%i\n", i);
		while (j < size->y)
		{
			matrix[i][j] = (t_matrix *)malloc(1 * sizeof(t_matrix));
            ft_printf("Malloc column: x:%i, y:%i\n", i, j);
            if (i == 3 && j== 6)
            {
                free(matrix[i][j]);
                return (ft_free_that_matrix(matrix, i, j, size));
            }
			if (!matrix[i][j])
				return (ft_free_that_matrix(matrix, i, j, size));
			j++;
		}
		i++;
	}
	return (matrix);
}
