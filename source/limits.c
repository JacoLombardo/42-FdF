/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:05:23 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/16 11:26:23 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_maxmin_width(t_matrix ***matrix, t_2D *size, t_limits *limits)
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
			if (matrix[i][j]->iso->x < min)
				min = matrix[i][j]->iso->x;
			j++;
		}
		i++;
	}
	limits->max_x = max;
	limits->min_x = min;
}

void	ft_maxmin_height(t_matrix ***matrix, t_2D *size, t_limits *limits)
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

t_limits	*ft_calc_limits(t_matrix ***matrix, t_2D *size)
{
	t_limits	*limits;
	int			zoom;

	limits = (t_limits *)malloc(1 * sizeof(t_limits));
	if (!limits)
		return (NULL);
	ft_maxmin_width(matrix, size, limits);
	ft_maxmin_height(matrix, size, limits);
	zoom = round(ft_zoom(limits));
	limits->max_x *= zoom;
	limits->min_x *= zoom;
	limits->max_y *= zoom;
	limits->min_y *= zoom;
	limits->zoom = zoom;
	return (limits);
}
