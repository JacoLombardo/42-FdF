/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:32:43 by jalombar          #+#    #+#             */
/*   Updated: 2024/08/13 17:26:34 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

float	ft_zoom(t_limits *limits)
{
	float	zoom_x;
	float	zoom_y;

	zoom_x = (float)WIDTH / (limits->max_x - limits->min_x);
	zoom_y = (float)HEIGHT / (limits->max_y - limits->min_y);
	if (zoom_x < zoom_y)
		return (round(zoom_x / 2));
	else
		return (round(zoom_y / 2));
}

t_2D	*ft_to_isometric_2(t_matrix *point, t_limits *limits)
{
	t_2D	*iso;
	float	zoom;
	int		offset_x;
	int		offset_y;

	iso = (t_2D *)malloc(1 * sizeof(t_2D));
	zoom = ft_zoom(limits);
	/* offset_x = (WIDTH - ((limits->max_x * zoom) - (limits->min_x * zoom))) / 2
		- (limits->min_x * zoom);
	offset_y = (HEIGHT - ((limits->max_y * zoom) - (limits->min_y * zoom))) / 2
		- (limits->min_y * zoom); */
	offset_x = (WIDTH - (limits->max_x - limits->min_x)) / 2
		- limits->min_x;
	offset_y = (HEIGHT - (limits->max_y - limits->min_y)) / 2
		- limits->min_y;
	/* offset_x = (WIDTH / 2) - ((limits->max_x) + (limits->min_x) / 2);
	offset_y = (HEIGHT / 2) - ((limits->max_y) + (limits->min_y) / 2); */
	iso->x = ((round(point->x * COS) - round(point->y * COS)) * zoom)
		+ offset_x;
	iso->y = (((round(point->x * SIN) + round(point->y * SIN)) / 2 - point->z)
			* zoom) + offset_y / 2;
	return (iso);
}

t_2D	*ft_to_isometric(t_matrix *point)
{
	t_2D	*iso;

	iso = (t_2D *)malloc(1 * sizeof(t_2D));
	iso->x = round(point->x * COS) - round(point->y * COS);
	iso->y = (round(point->x * SIN) + round(point->y * SIN)) / 2 - point->z;
	return (iso);
}
