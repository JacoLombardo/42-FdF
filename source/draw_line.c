/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:06:18 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/13 16:06:31 by jalombar         ###   ########.fr       */
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
		ft_mlx_pixel_put(image, line->x1, line->y1, line->color1);
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
