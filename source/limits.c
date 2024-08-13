/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:05:23 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/13 16:15:29 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_calc_max_width(t_matrix ***matrix, t_size *size, t_limits *limits)
{
	int	i;
	int	j;
	int	max;
	int	min;

	i = 0;
	max = 0;
	min = 0;
	while (i < size->x)
	{
		j = 0;
		while (j < size->y)
		{
			if (matrix[i][j]->iso->x > max)
				max = matrix[i][j]->iso->x;
			if (matrix[i][j]->iso->y < min)
				min = matrix[i][j]->iso->y;
			j++;
		}
		i++;
	}
	limits->max_x = max;
	limits->min_x = min;
}

void	ft_calc_max_height(t_matrix ***matrix, t_size *size, t_limits *limits)
{
	int	i;
	int	j;
	int	max;
	int	min;

	i = 0;
	max = 0;
	min = 0;
	while (i < size->x)
	{
		j = 0;
		while (j < size->y)
		{
			if (matrix[i][j]->iso->y > max)
				max = matrix[i][j]->iso->y;
			if (matrix[i][j]->iso->y < min)
				min = matrix[i][j]->iso->y;
			j++;
		}
		i++;
	}
	limits->max_y = max;
	limits->min_y = min;
}
