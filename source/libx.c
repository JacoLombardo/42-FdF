/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:43:52 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/12 17:59:55 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_line	*ft_to_line(t_line *line, t_matrix *p1, t_matrix *p2)
{
	line->x1 = p1->iso->x;
	line->y1 = p1->iso->y;
	line->color1 = p1->color;
	line->x2 = p2->iso->x;
	line->y2 = p2->iso->y;
	line->color2 = p2->color;
	line->dx = abs(p2->iso->x - p1->iso->x);
	line->dy = abs(p2->iso->y - p1->iso->y);
	if (p1->iso->x < p2->iso->x)
		line->sx = 1;
	else
		line->sx = -1;
	if (p1->iso->y < p2->iso->y)
		line->sy = 1;
	else
		line->sy = -1;
	line->err = line->dx - line->dy;
	return (line);
}

void	ft_draw_line(t_line *line, t_image *image)
{
	int	e2;

	while (1)
	{
		ft_mlx_pixel_put(image, line->x1 + (WIDTH / 2), line->y1 + (HEIGHT / 2),
			line->color1);
		if (line->x1 == line->x2 && line->y1 == line->y2)
			break ;
		e2 = 2 * line->err;
		if (e2 > -line->dy)
		{
			line->err -= line->dy;
			line->x1 += line->sx;
		}
		if (e2 < line->dx)
		{
			line->err += line->dx;
			line->y1 += line->sy;
		}
	}
}

void	ft_print_line(t_matrix *p1, t_matrix *p2, t_image *image)
{
	t_line	*line;

	line = (t_line *)malloc(1 * sizeof(t_line));
	line = ft_to_line(line, p1, p2);
	ft_draw_line(line, image);
	free(line);
}

void	ft_fill(t_matrix ***matrix, t_size *size, t_image *image)
{
	int	i;
	int	j;

	i = 0;
	while (i < size->x)
	{
		j = 0;
		while (j < size->y)
		{
			if (i > 0)
				ft_print_line(matrix[i - 1][j], matrix[i][j], image);
			if (j > 0)
				ft_print_line(matrix[i][j - 1], matrix[i][j], image);
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
	ft_fill(matrix, size, image);
}
