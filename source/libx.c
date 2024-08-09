/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:43:52 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/09 17:06:30 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_draw_line(t_line *line, t_image *image)
{
	int	i;
	int	x;
	int	y;

	x = line->x1;
	y = line->y1;
	i = 0;
	while (i < line->step)
	{
		if (i < line->step / 2)
		{
			ft_mlx_pixel_put(image, x + WIDTH / 2, y + HEIGHT / 2,
				line->color1);
		}
		else
		{
			ft_mlx_pixel_put(image, x + WIDTH / 2, y + HEIGHT / 2,
				line->color2);
		}
		x += line->dx;
		y += line->dy;
		i++;
	}
}

t_line	*ft_to_line(t_matrix *first, t_matrix *second)
{
	t_line	*line;

	line = (t_line *)malloc(1 * sizeof(t_line));
	line->x1 = first->iso->x;
	line->y1 = first->iso->y;
	line->color1 = first->color;
	line->x2 = second->iso->x;
	line->y2 = second->iso->y;
	line->color2 = second->color;
	line->dx = line->x2 - line->x1;
	line->dy = line->y2 - line->y1;
	if (line->dx < 0)
		line->dx *= -1;
	if (line->dy < 0)
		line->dy *= -1;
	if (line->dx >= line->dy)
		line->step = line->dx;
	else
		line->step = line->dy;
	line->dx = (line->x2 - line->x1) / line->step;
	line->dy = (line->y2 - line->y1) / line->step;
	return (line);
}

void	ft_create_lines(t_matrix ***matrix, t_size *size, t_image *image)
{
	int		i;
	int		j;
	t_line	*line;

	i = 0;
	line = NULL;
	while (i < size->x)
	{
		j = 0;
		while (j < size->y)
		{
			if (j > 0 && i > 0)
			{
				line = ft_to_line(matrix[i - 1][j - 1], matrix[i][j]);
				ft_draw_line(line, image);
				free(line);
			}
			j++;
		}
		i++;
	}
}

void	ft_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_create_img(t_matrix ***matrix, t_size *size, t_image *image)
{
	int	i;
	int	j;

	i = 0;
	while (i < size->x)
	{
		j = 0;
		while (j < size->y)
		{
			ft_mlx_pixel_put(image, matrix[i][j]->iso->x + WIDTH / 2,
				matrix[i][j]->iso->y + HEIGHT / 2, matrix[i][j]->color);
			j++;
		}
		i++;
	}
	ft_create_lines(matrix, size, image);
}
