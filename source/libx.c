/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:43:52 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/13 16:43:18 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_fill(t_matrix ***matrix, t_size *size, t_image *image)
{
	int	x;
	int	y;

	x = 0;
	while (x < size->x)
	{
		y = 0;
		while (y < size->y)
		{
			if (x > 0)
				ft_print_line(matrix[x - 1][y], matrix[x][y], image);
			if (y > 0)
				ft_print_line(matrix[x][y - 1], matrix[x][y], image);
			y++;
		}
		x++;
	}
}

void	ft_create_img(t_matrix ***matrix, t_size *size, t_image *image)
{
	int			x;
	int			y;
	t_limits	*limits;

	limits = (t_limits *)malloc(1 * sizeof(t_limits));
	ft_calc_max_width(matrix, size, limits);
	ft_calc_max_height(matrix, size, limits);
	x = 0;
	while (x < size->x)
	{
		y = 0;
		while (y < size->y)
		{
			free(matrix[x][y]->iso);
			matrix[x][y]->iso = ft_to_isometric_2(matrix[x][y], limits);
			y++;
		}
		x++;
	}
	ft_fill(matrix, size, image);
	free(limits);
}
